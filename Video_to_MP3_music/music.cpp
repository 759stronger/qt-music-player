#include "music.h"
#include <QUuid>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QDebug>
#include <QEventLoop>
#include <QMediaMetaData>
#include<QFileInfo>

// 【推荐的添加方式】
Music::Music()
    : isLike(false)
    , isHistory(false)
    , duration(0)
    ,lastPlayedTimestamp(0)
{
    // 函数体可以是空的
}

Music::Music(const QUrl& url)
    :isLike(false),
    isHistory(false),
    musicUrl(url),
    lastPlayedTimestamp(0)
{
    musicId = QUuid::createUuid().toString();
    parseMediaMetaData();
}


void Music::setIsLike(bool isLike)
{
    this->isLike = isLike;
}
void Music::setIsHistory(bool isHistory)
{
    this->isHistory = isHistory;
}
void Music::setMusicName(const QString& musicName)
{
    this->musicName = musicName;
}
void Music::setSingerName(const QString& singerName)
{
    this ->singerName = singerName;
}
void Music::setAlbumName(const QString& albumName)
{
    this->albumName =albumName;
}

void Music::setDuartion(const qint64 duration)
{
    this->duration = duration;
}
void Music::setMusicUrl(const QUrl& musicUrl)
{
    this->musicUrl =musicUrl;
}
void Music::setMusicId(const QString& musicId)
{
    this->musicId = musicId;
}


bool Music::getIsLike()
{
    return isLike;
}
bool Music::getIsHistory()
{
    return isHistory;
}
QString Music::getMusicName()
{
    return musicName;
}
QString Music::getSingerName()
{
    return singerName;
}
QString Music::getAlbumName()
{
    return albumName;
}
qint64 Music::getDuration()
{
    return duration;
}
QString Music::getMusicId()
{
    return musicId;
}
QUrl Music::getMusicUrl()
{
    return musicUrl;
}

void Music::parseMediaMetaData()
{
    //读取歌曲文件需要
    QMediaPlayer player;
    QEventLoop loop; // 创建事件循环，用于“阻塞”等待

    // 连接 metaDataChanged 信号到 QEventLoop 的 quit() 槽
    // 当元数据可用时，这个信号会发射，从而结束我们的等待
    QObject::connect(&player, &QMediaPlayer::metaDataChanged, &loop, &QEventLoop::quit);

    // 设置媒体源，这将触发后台的元数据解析
    player.setSource(musicUrl);

    // 开始事件循环。代码会在这里“卡住”，直到 loop.quit() 被调用
    loop.exec();

    // --- 代码执行到这里，说明元数据已经加载完毕 ---

    // 使用新的 API 获取元数据
    musicName = player.metaData().value(QMediaMetaData::Title).toString();
    singerName = player.metaData().value(QMediaMetaData::Author).toString();
    albumName = player.metaData().value(QMediaMetaData::AlbumTitle).toString();

    // duration 的获取方式也变了
    duration = player.duration();

    // --- 后续的判空逻辑保持不变 ---
    // 1. 处理歌名
    if (musicName.isEmpty())
    {
        QFileInfo fileInfo(musicUrl.toLocalFile());
        musicName = fileInfo.baseName(); // baseName() 获取文件名（不含后缀）
    }

    // 2. 处理歌手名
    if (singerName.isEmpty())
    {
        // 尝试从文件名解析，常见格式是 "歌名 - 歌手" 或 "歌手 - 歌名"
        QFileInfo fileInfo(musicUrl.toLocalFile());
        QString baseName = fileInfo.baseName();

        if (baseName.contains(" - "))
        {
            QStringList parts = baseName.split(" - ");
            // 简单判断：如果前半部分短，可能是歌手名；否则后半部分是歌手名
            // 这是一个不完美的猜测，但能处理很多情况
            if (parts.first().length() < parts.last().length() && parts.first().length() < 15) {
                singerName = parts.last().trimmed();
                musicName = parts.first().trimmed();
            } else {
                singerName = parts.first().trimmed(); // trimmed() 去除前后空格
                musicName = parts.last().trimmed();
            }
        }
    }

    // 3. 最终的判空保护
    if (musicName.isEmpty()) {
        musicName = "歌曲名未知";
    }
    if (singerName.isEmpty()) {
        singerName = "歌手未知";
    }
    if (albumName.isEmpty()) {
        albumName = "专辑未知";
    }

    qDebug() << musicName << " " << singerName << " " << albumName << " " << duration;
}

QString Music::getLrcFilePath() const
{
    QString path = musicUrl.toLocalFile();
    path.replace(".mp3" , ".lrc");
    path.replace(".flac" , ".lrc");
    path.replace(".mpga" , ".lrc");
    return path;
}

void Music::insertMusicToDb()
{
    QSqlQuery query(QSqlDatabase::database());

    // --- 尝试 UPDATE ---
    // 【修改】增加对 lastPlayedTimestamp 的更新
    query.prepare("UPDATE musicInfo SET isLike = ?, isHistory = ?, lastPlayedTimestamp = ? WHERE musicUrl = ?");
    query.addBindValue(isLike ? 1 : 0);
    query.addBindValue(isHistory ? 1 : 0);
    query.addBindValue(lastPlayedTimestamp); // <--- 新增绑定值
    query.addBindValue(musicUrl.toLocalFile());


    if (!query.exec()) {
        qDebug() << "UPDATE 失败:" << query.lastError().text();
        return;
    }

    // --- 如果 UPDATE 没命中，则 INSERT ---
    if (query.numRowsAffected() == 0) {
        query.prepare("INSERT INTO musicInfo(musicId, musicName, singerName, albumName, musicUrl, duration, isLike, isHistory,lastPlayedTimestamp) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?,?)");
        query.addBindValue(musicId);
        query.addBindValue(musicName);
        query.addBindValue(singerName);
        query.addBindValue(albumName);
        query.addBindValue(musicUrl.toLocalFile());
        query.addBindValue(duration);
        query.addBindValue(isLike ? 1 : 0);
        query.addBindValue(isHistory ? 1 : 0);
        query.addBindValue(lastPlayedTimestamp); // <--- 新增绑定值


        if (!query.exec()) {
            qDebug() << "INSERT 失败:" << query.lastError().text();
        }
    }
}

void Music::setLastPlayedTimestamp(qint64 timestamp)
{
    this->lastPlayedTimestamp = timestamp;
}

qint64 Music::getLastPlayedTimestamp() const
{
    return lastPlayedTimestamp;
}



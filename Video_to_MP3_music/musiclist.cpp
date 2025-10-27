#include "musiclist.h"

MusicList::MusicList() {}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    for (const auto& musicurl : urls)
    {
        // 确保 musicurl 是本地文件
        if (!musicurl.isLocalFile()) continue;

        QMimeDatabase db;
        // 使用 toLocalFile() 获取操作系统原生路径
        QMimeType mime = db.mimeTypeForFile(musicurl.toLocalFile());

        if (!mime.name().startsWith("audio/"))
        {
            continue;
        }


        // 【核心改动】检查这首歌的 URL 是否已经存在于列表中
        bool urlExists = false;
        for ( auto& existingMusic : musicList) {
            if (existingMusic.getMusicUrl() == musicurl) {
                urlExists = true;
                break;
            }
        }

        // 如果 URL 已经存在，则跳过，不添加
        if (urlExists) {
            qDebug() << "歌曲已存在于列表中，跳过添加:" << musicurl.toLocalFile();
            continue;
        }


        Music music(musicurl);
        musicList.push_back(music);
    }

}

Iterator MusicList::begin()
{
    return  musicList.begin();
}

Iterator MusicList::end()
{
    return musicList.end();
}

Iterator MusicList::findMusicById(const QString &musicId)
{
    for(Iterator it = begin() ;it !=end(); it++)
    {
        if(it->getMusicId() == musicId)
        {
            return it;
        }
    }
    return end();
}

void MusicList::writeToDb()
{
    for(auto music :musicList)
    {
        music.insertMusicToDb();
    }
}

void MusicList::readFromDb()
{
    QSqlQuery query(QSqlDatabase::database());
    QString sql("SELECT musicUrl FROM musicInfo"); // 【核心】我们只读取URL

    if (!query.exec(sql)) {
        qDebug() << "MusicList::readFromDb - 读取查询失败:" << query.lastError().text();
        return;
    }

    QList<QUrl> urlsFromDb;
    while (query.next()) {
        urlsFromDb.append(QUrl::fromLocalFile(query.value(0).toString()));
    }

    // 清空当前列表，防止重复
    musicList.clear();

    // 【核心】使用 addMusicByUrl 来处理从数据库加载的URL
    // 这样可以确保所有歌曲都经过了 parseMediaMetaData，并且不会重复添加
    addMusicByUrl(urlsFromDb);

    // 现在，我们需要将数据库中的 isLike 和 isHistory 状态同步到内存中的对象
    QSqlQuery stateQuery(QSqlDatabase::database());

    // 【修改这里】在 SELECT 语句中加入 lastPlayedTimestamp
    stateQuery.prepare("SELECT musicUrl, isLike, isHistory, lastPlayedTimestamp FROM musicInfo");

    if (stateQuery.exec()) {
        while (stateQuery.next()) {
            QUrl url = QUrl::fromLocalFile(stateQuery.value(0).toString());
            bool isLike = stateQuery.value(1).toBool();
            bool isHistory = stateQuery.value(2).toBool();
            qint64 timestamp = stateQuery.value(3).toLongLong(); // <--- 读取时间戳

            // 在内存的 musicList 中找到对应的歌曲并更新状态
            for (auto it = musicList.begin(); it != musicList.end(); ++it) {
                if (it->getMusicUrl() == url) {
                    it->setIsLike(isLike);
                    it->setIsHistory(isHistory);
                    it->setLastPlayedTimestamp(timestamp); // <--- 设置时间戳
                    break; // 找到后就跳出内层循环
                }
            }
        }
    }
    qDebug() << "从数据库加载并同步了" << musicList.size() << "首歌曲的状态。";
}





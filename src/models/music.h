#ifndef MUSIC_H
#define MUSIC_H

#include <QUrl>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>

class Music
{
public:
    Music();

    Music(const QUrl& url);

    void setIsLike(bool isLike);
    void setIsHistory(bool isHistory);
    void setMusicName(const QString& musicName);
    void setSingerName(const QString& singerName);
    void setAlbumName(const QString& albumName);

    void setDuartion(const qint64 duration);
    void setMusicUrl(const QUrl& musicUrl);
    void setMusicId(const QString& musicId);


    bool getIsLike();
    bool getIsHistory();
    QString getMusicName();
    QString getSingerName();
    QString getAlbumName();
    qint64 getDuration();
    QString getMusicId();
    QUrl getMusicUrl();


    void parseMediaMetaData();
    QString getLrcFilePath() const;

    void insertMusicToDb();

    void setLastPlayedTimestamp(qint64 timestamp);
    qint64 getLastPlayedTimestamp()  const ;


private:
    bool isLike;
    bool isHistory;

    QString musicName;
    QString singerName;
    QString albumName;
    qint64 duration;

    QString musicId; //标记歌曲的唯一性
    QUrl musicUrl;  //标记歌曲在磁盘中的位置

    qint64 lastPlayedTimestamp; // <--- 新增成员

};

#endif // MUSIC_H

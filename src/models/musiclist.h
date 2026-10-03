#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QVector>
#include "music.h"
#include <QMimeDatabase>
#include <QSqlError>
#include <QSqlQuery>

typedef QVector<Music>::Iterator Iterator;

class MusicList
{
public:
    MusicList();


    void addMusicByUrl(const QList<QUrl>& urls);
    Iterator begin();
    Iterator end();
    Iterator findMusicById(const QString & musicId);

    void writeToDb();
    void readFromDb();


private:
    QVector<Music> musicList;

};

#endif // MUSICLIST_H

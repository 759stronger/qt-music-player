#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include "musiclist.h"
#include "music.h"
#include <QListWidgetItem>


namespace Ui {
class commonPage;
}


enum PageType
{
    LIKE_PAGE,
    LOCAL_PAGE,
    HISTORY_PAGE
};


class commonPage : public QWidget
{
    Q_OBJECT

public:
    explicit commonPage(QWidget *parent = nullptr);
    ~commonPage();

    void setcommonPageUi(const QString &title , const QString & Image);

    void setMusicListType(PageType pagetype);

    void addMusicToMusicPage(MusicList &musicList , const QList<QString> &orderedHistory = QList<QString>());

    void reFresh(MusicList & musicList, const QList<QString> &orderedHistory = QList<QString>());

    QVector<QString> getCurrentMusicListIds() const; // <--- 新增的 public 函数

    void setImageLabel(QPixmap pixmap);

private slots: // <--- 新增一个私有槽
    void onMusicItemDoubleClicked(QListWidgetItem *item);

signals:
    void updateLikeMusic(bool isLike ,QString musicId);

    // 修改信号，增加一个 QVector<QString> 参数来携带整个列表
    void musicDoubleClicked(const QString &musicId, const QVector<QString> &currentList);

    void playAll(PageType pagetype);

private:
    Ui::commonPage *ui;
    QVector<QString> musicListOfPage;  //具体页面的音乐只存储音乐id  歌单列表
    PageType pagetype;
};

#endif // COMMONPAGE_H

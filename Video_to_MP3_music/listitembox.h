#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include <QWidget>
namespace Ui {
class listItemBox;
}

class listItemBox : public QWidget
{
    Q_OBJECT

public:
    explicit listItemBox(QWidget *parent = nullptr);
    ~listItemBox();

    void setMusicName(const QString &name);
    void setSingerName(const QString &singer);
    void setAlbumName(const QString &album);
    void setLikeMusic(bool isLike);

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private slots:
    void on_likeBtn_clicked();
signals:
    // 让信号传递自己的 musicId，这样 commonPage 就知道是谁变了
    void likeStatusChanged(bool isLike);// 通知更新歌曲数据信号
    void setIsLike(bool isLike); // 通知更新歌曲数据信号


private:
    Ui::listItemBox *ui;
    bool isLike;

};

#endif // LISTITEMBOX_H

#ifndef VIDEO_TO_MP3_MUSIC_H
#define VIDEO_TO_MP3_MUSIC_H

#include <QWidget>
#include "volumetool.h"
#include "musiclist.h"
#include <QMediaPlayer>
#include "commonpage.h"
#include <QAudioOutput>
#include <QVector>
#include <QAudioDevice>
#include <QTimer>
#include <QRandomGenerator>
#include <QMediaMetaData>
#include <QVariant>
#include "lrcpage.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QMenu>

enum PlaybackMode
{
    LISTLOOP, //列表循环
    RANDOM,   //随机播放
    CURRENTITEMLOOP    //单曲循环
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Video_to_MP3_music;
}
QT_END_NAMESPACE

class Video_to_MP3_music : public QWidget
{
    Q_OBJECT

public:
    Video_to_MP3_music(QWidget *parent = nullptr);
    ~Video_to_MP3_music();

    //连接信号槽
    void connectSignalAndSlot();

    //推荐中的图片个数
    QJsonArray randomPiction();

    void initPlayer();

    void playCurrentMusic();



    void initUI();//初始化窗口

    void setPlayerVolume(float volume);

    void initSqlite();

    void initMusicList();

    void updateMusicFormAnimal();


private slots:

    void on_quit_clicked();
    //musicform 点击槽函数
    void onmusicFormClick(int PageId);

    void on_volume_clicked();

    void on_addlocal_clicked();

    void onUpdateLikeMusic(bool isLike, QString musicId);


    void onPlayStateChanged();

    // 修改槽函数，使其参数列表与新的信号完全匹配
    void onPlayMusic(const QString &musicId, const QVector<QString> &currentList);

    void onPlayClicked();


    void on_playprev_clicked();

    void on_playnext_clicked();

    void on_playmode_clicked();

    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

    void onPlayAll(PageType pagetype);
    void playAllOfCommonPage(commonPage *commonPage ,int index);


    void onSourseChanged();// <--- 【新增】用于更新播放历史的槽函数

    void setCurrentPlayingPage(commonPage * page);

    void setMusicSilence(bool isMuted);

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 duration);

    void setMusicSilderChanged( float value);

    void setMetadataAvailableChanged();

    void on_lrcPagebtn_clicked();



    void on_skin_clicked();

    void on_min_clicked();

    void on_max_clicked();

    void quitMusic();

protected:
    //通过相对左顶角坐标 来计算移动窗口的位置
     void mouseMoveEvent(QMouseEvent *event)override;   //函数名不要写错了
     void mousePressEvent(QMouseEvent *event)override;
    //记录光标相对于窗口标题栏的相对距离
    QPointF dragPosition;




private:
    Ui::Video_to_MP3_music *ui;
    volumeTool *voTool;
    MusicList musiclist;

    //播放器相关
    QMediaPlayer *player;
    QAudioOutput *audioOutput;// 【新增】用于控制音频输出的成员
    // 【重要】替换旧的 m_playlist 和 m_currentIndex
    QVector<QString> m_playlist_musicIds; // <--- 用这个来存储当前页面的  歌曲ID列表
    int m_currentIndex;                   // <--- 用这个来记录当前播放歌曲在  列表中的索引

    PlaybackMode m_playbackmode;  //播放模式

    commonPage * currentpage;

    QList<QString>  m_play_history; // 【新增】一个有序的列表，专门用来记录播放历史的顺序

    qint64 totalDuration; // 歌曲总时长

    LrcPage * lrcPage;

    QPropertyAnimation * lrcAnimation;

    QSqlDatabase sqlite;

    bool isDrag;  //为true才能拖拽窗口


};
#endif // VIDEO_TO_MP3_MUSIC_H

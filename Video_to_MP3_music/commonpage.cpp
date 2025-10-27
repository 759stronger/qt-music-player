#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"

commonPage::commonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::commonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 连接列表控件的双击信号到我们的新槽函数
    connect(ui->pageMusicList, &QListWidget::itemDoubleClicked, this, &commonPage::onMusicItemDoubleClicked);
    connect(ui->playAllBtn , &QPushButton::clicked ,this , [=](){
        emit playAll(pagetype);
    });
}

commonPage::~commonPage()
{
    delete ui;
}

void commonPage::setcommonPageUi(const QString &title, const QString &Image)
{
    //设置标题
    ui->pageTittle->setText(title);

    //设置封面栏
    ui->musicImageLabel->setPixmap(QPixmap(Image));
    ui->musicImageLabel->setScaledContents(true);

    //测试

}

void commonPage::setMusicListType(PageType pagetype)
{
    this->pagetype  = pagetype;
}

void commonPage::addMusicToMusicPage(MusicList & musicList, const QList<QString> &orderedHistory)
{
    musicListOfPage.clear();

    if(this->pagetype == HISTORY_PAGE)
    {
        for(const QString&musicId:orderedHistory)
        {
            musicListOfPage.push_back(musicId);
        }
    }
    else
    {
        for(auto music : musicList)
        {
            switch (this->pagetype) {
            case LOCAL_PAGE:
                musicListOfPage.push_back(music.getMusicId());
                break;
            case LIKE_PAGE:
            {
                if(music.getIsLike())
                {
                    musicListOfPage.push_back(music.getMusicId());
                }
                break;
            }
            default:
                break;
            }
        }
    }
}

void commonPage::reFresh(MusicList &musicList, const QList<QString> &orderedHistory )
{

    ui->pageMusicList->clear();
    //从muscilist中分离出当前页面的所有音乐
    //addMusicIdPageFromMusicList(musicList);
    addMusicToMusicPage(musicList ,orderedHistory);

    //遍历歌单 将歌单中的歌曲显示到页面
    for(auto musicId:musicListOfPage)
    {
        auto it = musicList.findMusicById(musicId);
        if(it == musicList.end())
            continue;

        listItemBox * lItemBox = new listItemBox(ui->pageMusicList);
        lItemBox->setMusicName(it->getMusicName());
        lItemBox->setSingerName(it->getSingerName());
        lItemBox->setAlbumName(it->getAlbumName());
        lItemBox->setLikeMusic(it->getIsLike());

        QListWidgetItem *listWidgetItem =new QListWidgetItem (ui->pageMusicList);
        listWidgetItem->setSizeHint(QSize(ui->pageMusicList->width() ,45));

        // 【关键】将 musicId 作为数据存储在 QListWidgetItem 中
        // 这样我们点击它时，就能知道是哪首歌了
        listWidgetItem->setData(Qt::UserRole, musicId);

        ui->pageMusicList->setItemWidget(listWidgetItem , lItemBox);

        connect(lItemBox ,&listItemBox::setIsLike , this , [=](bool isLike)
                {
            emit updateLikeMusic(isLike, it->getMusicId());
        });


    }

    //刷新界面
    ui->pageMusicList->repaint();
}


// 【新增】实现槽函数
void commonPage::onMusicItemDoubleClicked(QListWidgetItem *item)
{
    if (!item) return;

    // 从 item 中取出我们之前存入的 musicId
    QString musicId = item->data(Qt::UserRole).toString();

    // 如果 musicId 有效，就发射信号通知主窗口
    if (!musicId.isEmpty())
    {
        // 发射信号时，把当前页面的歌曲ID列表 (musicListOfPage) 一起传出去
        emit musicDoubleClicked(musicId, musicListOfPage);
    }
}

QVector<QString> commonPage::getCurrentMusicListIds() const
{
    return musicListOfPage;
}

void commonPage::setImageLabel(QPixmap pixmap)
{
    ui->musicImageLabel->setPixmap(pixmap);
    ui->musicImageLabel->setScaledContents(true);
}









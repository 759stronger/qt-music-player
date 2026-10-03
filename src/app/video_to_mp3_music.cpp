#include "video_to_mp3_music.h"
#include "ui_video_to_mp3_music.h"

Video_to_MP3_music::Video_to_MP3_music(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Video_to_MP3_music)
    , m_currentIndex(-1)
    ,m_playbackmode(LISTLOOP)
    ,totalDuration(0)
{
    ui->setupUi(this);
    initUI();  //这里一定要调用才能成功

    initSqlite();



    initPlayer();//初始化播放器

    initMusicList();

    connectSignalAndSlot();//响应信号槽

}

Video_to_MP3_music::~Video_to_MP3_music()
{
    delete ui;
}

void Video_to_MP3_music::initUI()
{
    // 移除所有窗口装饰（边框、标题栏、最小化/最大化/关闭按钮）
    //setWindowFlag(Qt::WindowType::FramelessWindowHint);
    setWindowFlag(Qt::WindowType::FramelessWindowHint);

    //窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowIcon(QIcon(":/images/tubiao.png"));


    // 为中央部件设置阴影效果
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#000000");
    shadowEffect->setBlurRadius(9);
    this->setGraphicsEffect(shadowEffect);

    //添加托盘 创建托盘图标
    QSystemTrayIcon * trayicon =new QSystemTrayIcon(this);
    trayicon->setIcon(QIcon(":/images/tubiao.png"));

    //创建托盘菜单
    QMenu * tarymenu = new QMenu(this);
    tarymenu ->addAction("还原",this , &QWidget::showNormal);
    tarymenu->addSeparator();
    tarymenu->addAction("退出",this , &Video_to_MP3_music::quitMusic);



    trayicon->setContextMenu(tarymenu);
    // 【新增】连接托盘图标的点击信号
    connect(trayicon, &QSystemTrayIcon::activated, this, [=](QSystemTrayIcon::ActivationReason reason){
        // 如果是单击或双击，则显示窗口
        if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick) {
            this->showNormal();
        }
    });


    trayicon->show();



    // 设置BodyLeft中6个btForm的信息
    ui->Rec->seticon(":/images/rec.png","推荐",0);
    ui->audio->seticon(":/images/radio.png","电台",1);
    ui->music->seticon(":/images/music.png","音乐馆",2);
    ui->mylike->seticon(":/images/like.png","我喜欢",3);
    ui->localmusic->seticon(":/images/local.png","本地下载",4);
    ui->recentmusic->seticon(":/images/recent.png","最近音乐",5);

    //设置默认的页面和默认的动画显示
    ui->stackedWidget->setCurrentIndex(4);
    currentpage = ui->localmusicpage_5;
    ui->localmusic->showAnima(true);

    //推荐页面添加图片和文本
    srand(time(NULL));
    ui->recmusicbox->initRecboxui(randomPiction(),1);
    ui->supplymusicbox->initRecboxui(randomPiction(),2);

    //设置我喜欢 本地 和最近音乐的标题和封面
    //ui->mylikepage_4->setMusicListType(PageType::LIKE_PAGE);
    ui->mylikepage_4->setcommonPageUi("我喜欢",":/images/rec/043.png");
    //ui->localmusicpage_5->setMusicListType(PageType::LOCAL_PAGE);
    ui->localmusicpage_5->setcommonPageUi("本地下载",":/images/rec/044.png");
    //ui->recentmusicpage_6->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentmusicpage_6->setcommonPageUi("最近播放",":/images/rec/045.png");

    //音量键的创建
    voTool = new volumeTool(this);

    ui->play->setIcon(QIcon(":/images/play.png"));  //默认为暂停图标
    ui->playmode->setIcon(QIcon(":/images/list_play.png")) ;

    lrcPage = new LrcPage(this );
    lrcPage->hide();

    lrcAnimation = new QPropertyAnimation(lrcPage,"geometry" , this);
    lrcAnimation->setDuration(400);
    lrcAnimation->setStartValue(QRect(9 ,9+lrcPage->width() , lrcPage->width() , lrcPage->height()));
    lrcAnimation->setEndValue(QRect(9, 9 , lrcPage->width() , lrcPage->height()));
}


void Video_to_MP3_music::setPlayerVolume(float volume)
{
    audioOutput->setVolume(volume);
}


void Video_to_MP3_music::initSqlite()
{
    //创建数据库链接
    sqlite = QSqlDatabase::addDatabase("QSQLITE");

    //设置数据库名称
    sqlite.setDatabaseName("musicDb");

    //打开数据库
    if(!sqlite.open())
    {
        QMessageBox::critical(this , "打开数据库失败", sqlite.lastError().text());
        return ;
    }

    //创建数据库表
    QString sql = ("CREATE TABLE IF NOT EXISTS musicInfo(\
                    id INTEGER PRIMARY KEY AUTOINCREMENT,\
                    musicId varchar(200) UNIQUE,\
                    musicName varchar(50) ,\
                    singerName varchar(50),\
                    albumName varchar(50),\
                    duration BIGINT,\
                    musicUrl varchar(256),\
                    isLike INTEGER,\
                    isHistory INTEGER,\
                    lastPlayedTimestamp BIGINT)");

    QSqlQuery query(sqlite); // 【推荐】在创建时就传入数据库连接

    if(!query.exec(sql))
    {
        QMessageBox::critical(this, "创建数据库表失败" ,query.lastError().text());
        return ;
    }
}

void Video_to_MP3_music::initMusicList()
{
    //读取歌曲信息
    musiclist.readFromDb();

    m_play_history.clear();
    QVector<Music> historyMusic;
    // 1. 筛选出所有播放过的歌曲
    for(auto it = musiclist.begin(); it != musiclist.end(); ++it)
    {
        if(it->getIsHistory())
        {
            historyMusic.push_back(*it);
        }
    }

    // 2. 根据播放时间戳进行降序排序（最新的在前）
    std::sort(historyMusic.begin(), historyMusic.end(), [](const Music& a, const Music& b){
        // 使用 const getter，不再需要 const_cast
        return a.getLastPlayedTimestamp() > b.getLastPlayedTimestamp();
    });

    // 3. 用排序后的结果填充 m_play_history
    for(auto& music : historyMusic)
    {
        m_play_history.append(music.getMusicId());
    }


    //更新页面信息
    ui->mylikepage_4->setMusicListType(PageType::LIKE_PAGE);
    ui->mylikepage_4->reFresh(musiclist);

    ui->localmusicpage_5->setMusicListType(PageType::LOCAL_PAGE);
    ui->localmusicpage_5->reFresh(musiclist);

    ui->recentmusicpage_6->setMusicListType(PageType::HISTORY_PAGE);
    // 【修改这里】将 m_play_history 传递给 reFresh 函数
    ui->recentmusicpage_6->reFresh(musiclist, m_play_history);

    // 【新增】同步初始页面的播放列表到主播放器
    // 由于 initUI() 中已将 currentpage 和默认页面设置为 localmusicpage_5，
    // 我们在这里直接使用它来设置初始播放列表。
    setCurrentPlayingPage(ui->localmusicpage_5);
}

void Video_to_MP3_music::updateMusicFormAnimal()
{
    int index = ui->stackedWidget->indexOf(currentpage);

    if(-1 == index)
    {
        return ;
    }

    QList<musicForm*> musicforms = this->findChildren<musicForm*>();
    for(auto musicform :musicforms)
    {
        if(musicform->getId() == index)
        {
            musicform->showAnima(true);
        }
        else
        {
            musicform->showAnima(false);
        }
    }


}



void Video_to_MP3_music::setMetadataAvailableChanged()
{
    // 1. 安全检查，并在索引无效时设置默认UI
    if (m_currentIndex < 0 || m_currentIndex >= m_playlist_musicIds.size()) {
        ui->label_8->setText("歌曲名");
        ui->label_9->setText("歌手");
        // 设置默认封面...
        return;
    }

    // 2. 获取当前歌曲ID
    QString currentMusicId = m_playlist_musicIds[m_currentIndex];

    // 3. 从“唯一数据源” musiclist 中找到 Music 对象
    auto it = musiclist.findMusicById(currentMusicId);

    if (it != musiclist.end()) {
        // 4. 【核心】直接使用 Music 对象中已经解析好的、干净的数据更新UI
        ui->label_8->setText(it->getMusicName());
        ui->label_9->setText(it->getSingerName());

        qDebug() << "UI已更新为 (来自Music对象):" << it->getMusicName() << "-" << it->getSingerName();

        // 5. 封面图片仍然需要从播放器即时获取
        const QMediaMetaData metaData = player->metaData();
        QVariant coverImageVariant = metaData.value(QMediaMetaData::ThumbnailImage);
        if (coverImageVariant.isValid() && !coverImageVariant.value<QImage>().isNull())
        {
            QPixmap pixmap = QPixmap::fromImage(coverImageVariant.value<QImage>());
            ui->label_7->setPixmap(pixmap);
            ui->label_7->setScaledContents(true);
            if (currentpage) {
                currentpage->setImageLabel(pixmap);
            }
        }
        else {
            QPixmap defaultPixmap(":/images/default_cover.png");
            ui->label_7->setPixmap(defaultPixmap);
            ui->label_7->setScaledContents(true);
            if (currentpage) {
                currentpage->setImageLabel(defaultPixmap);
            }
        }
    }

    //加载歌词并解析
    if(it!=musiclist.end())
    {
        lrcPage->parseLrc(it->getLrcFilePath());
    }
}

void Video_to_MP3_music::on_lrcPagebtn_clicked()
{

    lrcPage->show();
    lrcAnimation->start();

}


void Video_to_MP3_music::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton  )
    {
        isDrag = true;
        dragPosition = event->globalPosition() - frameGeometry().topLeft();
        event->accept();
        return ;
    }
    QWidget::mousePressEvent(event);
}


void Video_to_MP3_music::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton && isDrag)
    {
        move((event->globalPosition() - dragPosition).toPoint()) ;  //返回的是QPointF  所以要用topoint
        event->accept();
        return ;
    }
    QWidget::mouseMoveEvent(event);
}


void Video_to_MP3_music::on_quit_clicked()
{
    hide();
}


void Video_to_MP3_music::onmusicFormClick(int PageId)
{
    //1.获取当前页面的所有form按钮类型的对象
    QList<musicForm*> buttonList = this->findChildren<musicForm*>();

    //2.循环 清除之前点击的按钮的背景颜色
    foreach (musicForm* musicitem ,buttonList)
    {
        if(PageId != musicitem->getId())
        {
            musicitem->clearBg();
        }
    }


    ui->stackedWidget->setCurrentIndex(PageId);

    // 4. 【新增】根据PageId更新currentpage指针
    // 注意：我们只关心那些有实际音乐列表的页面
    switch(PageId)
    {
    case 3: // 我喜欢
        currentpage = ui->mylikepage_4;
        break;
    case 4: // 本地下载
        currentpage = ui->localmusicpage_5;
        break;
    case 5: // 最近音乐
        currentpage = ui->recentmusicpage_6;
        break;
    default:
        // 对于推荐、电台等页面，它们不是commonPage类型，
        // 可以暂时不处理或将currentpage设为nullptr
        break;
    }

    // 5. 【新增】调用函数来更新所有按钮的动画状态
    updateMusicFormAnimal();
    isDrag = false;

}


void Video_to_MP3_music::connectSignalAndSlot()
{
    //信号槽 来传递点击后的页面的id 自定义的form按钮点击信号，当Form点击后，设置对应的堆叠窗口
    connect(ui->Rec , &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);
    connect(ui->audio , &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);
    connect(ui->music, &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);
    connect(ui->mylike, &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);
    connect(ui->localmusic, &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);
    connect(ui->recentmusic, &musicForm::musicclick, this  , &Video_to_MP3_music::onmusicFormClick);

    // 关联CommonPage发射的updateLikeMusic信号
    connect(ui->mylikepage_4, &commonPage::updateLikeMusic, this , &Video_to_MP3_music::onUpdateLikeMusic);
    connect(ui->localmusicpage_5 ,  &commonPage::updateLikeMusic, this , &Video_to_MP3_music::onUpdateLikeMusic);
    connect(ui->recentmusicpage_6, &commonPage::updateLikeMusic, this , &Video_to_MP3_music::onUpdateLikeMusic);

    //播放控制区的信号和槽函数关联
    connect(ui->play , &QPushButton::clicked , this ,&Video_to_MP3_music::onPlayClicked);


    // 【新增】连接三个页面的双击信号到我们的播放槽函数
    connect(ui->mylikepage_4, &commonPage::musicDoubleClicked, this, &Video_to_MP3_music::onPlayMusic);
    connect(ui->localmusicpage_5, &commonPage::musicDoubleClicked, this, &Video_to_MP3_music::onPlayMusic);
    connect(ui->recentmusicpage_6, &commonPage::musicDoubleClicked, this, &Video_to_MP3_music::onPlayMusic);

    // 【新增】连接媒体状态改变信号，这是自动播放下一曲的关键
    connect(player ,&QMediaPlayer::mediaStatusChanged , this ,&Video_to_MP3_music::onMediaStatusChanged  );

    connect(ui->mylikepage_4 , &commonPage::playAll ,this , &Video_to_MP3_music::onPlayAll);
    connect(ui->localmusicpage_5 , &commonPage::playAll ,this , &Video_to_MP3_music::onPlayAll);
    connect(ui->recentmusicpage_6 , &commonPage::playAll ,this , &Video_to_MP3_music::onPlayAll);

    connect(player , &QMediaPlayer::sourceChanged , this , &Video_to_MP3_music::onSourseChanged);

    //设置静音
    connect(voTool, &volumeTool::setSilence , this , &Video_to_MP3_music::setMusicSilence);
    //设置音量大小
    connect(voTool , &volumeTool::setMusicVolume , this , &Video_to_MP3_music::setPlayerVolume);

    connect(ui->progressbar , &musicSlider::setMusicSilderPosition , this , &Video_to_MP3_music::setMusicSilderChanged);

    connect(player , &QMediaPlayer::metaDataChanged , this , &Video_to_MP3_music::setMetadataAvailableChanged);

    connect(ui->words , &QPushButton::clicked , this, &Video_to_MP3_music::on_lrcPagebtn_clicked);

}


//把每个图片添加到 推荐中
QJsonArray Video_to_MP3_music::randomPiction()
{
    QVector<QString>  vecImageName;
    vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"
    <<"007.png"<<"008.png"<<"009.png"<<"010.png"<<"011.png"
    <<"012.png"<<"013.png"<<"014.png"<<"015.png"<<"016.png"
    <<"017.png"<<"018.png"<<"019.png"<<"020.png"<<"021.png"
    <<"022.png"<<"023.png"<<"024.png"<<"025.png"<<"026.png"
    <<"027.png"<<"028.png"<<"029.png"<<"030.png"<<"031.png"<<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"
    <<"037.png"<<"038.png"<<"039.png"<<"040.png"<<"041.png"
    <<"042.png"<<"043.png"<<"044.png"<<"045.png"<<"046.png"
    <<"047.png"<<"048.png"<<"049.png"<<"050.png"<<"051.png"<<"052.png";

    std::random_shuffle(vecImageName.begin(), vecImageName.end());

    QJsonArray objArray;
    for(int i = 0 ;i < vecImageName.size();i++)
    {
        QJsonObject obj;
        obj.insert("path" , ":/images/rec/"+ vecImageName[i]);

        QString strText = QString("推荐-%1").arg(i,3,10,QChar('0')); //i表示放入%1的位置的数据 3表示最大位数 10表示十进制  QChar表示不够的用0填充
        obj.insert("text" , strText);

        objArray.append(obj);
    }
    return objArray;
}

void Video_to_MP3_music::initPlayer()
{
    //创建播放器
    player = new QMediaPlayer(this);

    audioOutput = new QAudioOutput(this);

    //创建播放列表
    //playList = new QMediaPlaylist(this);

    //设置播放模式 默认为循环模式
    //playList->setPlaybackMode(QMediaPlaylist::Loop);

    //将播放列表设置给播放器
    //player->setPlaylist(playlist);

    //默认音量
    // 确保音频输出设备正确设置
    audioOutput->setDevice(QAudioDevice()); // 使用默认设备
    player->setLoops(1); // 不循环
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.2);

    // 初始化播放状态变量
    m_currentIndex = -1;
    m_playlist_musicIds.clear();

    connect(player , &QMediaPlayer::playbackStateChanged , this , &Video_to_MP3_music::onPlayStateChanged);
    connect(player,&QMediaPlayer::durationChanged , this , &Video_to_MP3_music::onDurationChanged);
    connect(player,&QMediaPlayer::positionChanged, this , &Video_to_MP3_music::onPositionChanged);

}

//是否有问题
void Video_to_MP3_music::on_volume_clicked()
{

    if(voTool->isVisible())
    {
        voTool->hide();

    }
    else
    {
        //获取按钮左上角的坐标
        QPoint point = ui->volume->mapToGlobal(QPoint(0,0));

        QPoint  volumeLeftTop = point - QPoint(voTool->width()/2 , voTool->height() );

        //微调窗口位置
        volumeLeftTop.setX(volumeLeftTop.x()+15);
        volumeLeftTop.setY(volumeLeftTop.y()+30);

        voTool->move(volumeLeftTop);

        voTool->show();
    }
}


void Video_to_MP3_music::on_addlocal_clicked()
{
    //创建文件对话框
    QFileDialog filedialog(this);
    filedialog.setWindowTitle("添加本地音乐");

    //创建打开格式的文件对话框
    filedialog.setAcceptMode(QFileDialog::AcceptOpen);

    //设置对话框模式 只能选择文件 并可以一次性选择一个或多个文件
    filedialog.setFileMode(QFileDialog::ExistingFiles);

    //设置对话框的MIME过滤器
    QStringList mimelist;
    mimelist<<"application/octet-stream";
    filedialog.setMimeTypeFilters(mimelist);

    //设置默认打开路径  为当前路径
    QDir dir (QDir::currentPath());
    dir.cdUp();
    QString musicpath = dir.path()+"/localmusic";
    filedialog.setDirectory(musicpath);

    //显示对话框 并且接受返回值
    //模拟对话框 exec内部死循环
    if(filedialog.exec() == QFileDialog::Accepted)
    {
        ui->stackedWidget->setCurrentIndex(4);

        QList<QUrl> urls = filedialog.selectedUrls();

        //拿到歌曲文件交给musiclist处理
        musiclist.addMusicByUrl(urls);

        //更新到本地音乐列表
        ui->localmusicpage_5->reFresh(musiclist);

        setCurrentPlayingPage(ui->localmusicpage_5);

    }

}

void Video_to_MP3_music::onUpdateLikeMusic(bool isLike, QString musicId)
{
    // 1. 找到该首歌曲，并更新对应Music对象信息
    auto it = musiclist.findMusicById(musicId);

    if(it != musiclist.end())
    {
        it->setIsLike(isLike);
    }

    // 2. 通知三个页面更新自己的数据
    ui->mylikepage_4->reFresh(musiclist);

    ui->localmusicpage_5->reFresh(musiclist);
    ui->recentmusicpage_6->reFresh(musiclist , m_play_history);

    // 3. 【核心改动】通知其他页面进行“精细化”更新
    //    它们的列表项数量不变，只需要更新图标
    //ui->localmusicpage_5->updateItemIcon(musicId, isLike);
    //ui->recentmusicpage_6->updateItemIcon(musicId, isLike);


}


// 用这个版本替换你原来的 on_play_clicked
void Video_to_MP3_music::onPlayClicked()
{
    qDebug() << "播放按钮点击 - 当前状态:" << player->playbackState();


    if (m_playlist_musicIds.isEmpty()) {
        qDebug() << "播放列表为空";
        return;
    }

    if (m_currentIndex < 0 || m_currentIndex >= m_playlist_musicIds.size()) {
        m_currentIndex = 0;
    }

    // 替代方案：使用更直接的控制方式
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        qDebug() << "尝试暂停播放";

        // 方法1：正常暂停
        player->pause();

        // 方法2：如果暂停无效，尝试停止
        QTimer::singleShot(200, this, [this]() {
            if (player->playbackState() == QMediaPlayer::PlayingState) {
                qDebug() << "暂停无效，尝试停止";
                player->stop();
            }
        });

    }
    else
    {
        qDebug() << "尝试开始/继续播放";

        // 如果当前没有有效的源，重新设置
        if (player->source().isEmpty() || player->playbackState() == QMediaPlayer::StoppedState) {
            playCurrentMusic();
        } else {
            player->play();
        }
    }


}

void Video_to_MP3_music::playCurrentMusic()
{
    if (m_currentIndex < 0 || m_currentIndex >= m_playlist_musicIds.size()) {
        setMetadataAvailableChanged();
        qDebug() << "无效的当前索引";
        return;
    }

    QString musicId = m_playlist_musicIds[m_currentIndex];
    auto it = musiclist.findMusicById(musicId);

    if (it != musiclist.end()) {
        QUrl musicUrl = it->getMusicUrl();
        qDebug() << "准备播放:" << it->getMusicName() << "URL:" << musicUrl;

        player->setSource(musicUrl);
        player->play();
        setMetadataAvailableChanged();
    }
}

void Video_to_MP3_music::setMusicSilence(bool isMuted)
{
    //player->setAudioOutput(audioOutput);
    audioOutput->setMuted(isMuted);
    qDebug() << "Mute state set to:" << isMuted << ", audioOutput->isMuted() is now:" << audioOutput->isMuted();
}

void Video_to_MP3_music::onDurationChanged(qint64 duration)
{
    ui->totaltime->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
    totalDuration = duration;
}

void Video_to_MP3_music::onPositionChanged(qint64 duration)
{
    ui->currenttime->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
    ui->progressbar->setStep((float)duration /(float)totalDuration );

    // 3. 同步lrc歌词
    if(m_currentIndex>=0)
    {
        lrcPage->showLrcword(duration);
    }
}

void Video_to_MP3_music::setMusicSilderChanged(float value)
{

    //怎么获得总时长
    qint64 position =(qint64)(totalDuration * value);


    ui->currenttime->setText(QString("%1:%2").arg(position/1000/60,2,10,QChar('0')).arg(position/1000%60,2,10,QChar('0')));


    player->setPosition(position);
}



// 用这个版本替换你原来的 onPlayStateChanged
void Video_to_MP3_music::onPlayStateChanged()
{
    qDebug() << "播放状态改变:" << player->playbackState();

    switch (player->playbackState()) {
    case QMediaPlayer::PlayingState:
        ui->play->setIcon(QIcon(":/images/play_on.png"));
        qDebug() << "切换到播放图标";
        break;

    case QMediaPlayer::PausedState:
    case QMediaPlayer::StoppedState:
        ui->play->setIcon(QIcon(":/images/play.png"));
        qDebug() << "切换到暂停图标";
        break;
    }
}


// 在 video_to_mp3_music.cpp 中
void Video_to_MP3_music::onPlayMusic(const QString &musicId, const QVector<QString> &currentList)
{
    qDebug() << "接收到播放请求，音乐ID:" << musicId << "列表大小:" << currentList.size();

    // 1. 更新当前播放列表和页面指针
    //    【注意】我们需要一种方法从 currentList 推断出 commonPage*
    //    最简单的方法是通过 sender()，虽然我们之前说过它不可靠，但在这里是合理的。
    commonPage *page = qobject_cast<commonPage*>(sender());
    if(page)
    {
        setCurrentPlayingPage(page);
    }
    else
    {
        // 如果 sender() 失败，作为备用方案，只更新列表
        m_playlist_musicIds = currentList;
        qDebug() << "警告：sender() 不是 commonPage，只更新了播放列表。";
    }


    // 2. 找到被双击歌曲的索引
    m_currentIndex = m_playlist_musicIds.indexOf(musicId);

    if (m_currentIndex == -1) {
        qDebug() << "错误：歌曲不在当前列表中";
        return;
    }

    // 直接调用播放函数
    playCurrentMusic();
}



void Video_to_MP3_music::on_playprev_clicked()
{
    //列表为空 什么也不做
    if(m_playlist_musicIds.isEmpty())
    {
        qDebug() << "歌曲不在当前列表中";
        return ;
    }
    switch(m_playbackmode)
    {
    case LISTLOOP:
    case RANDOM:
        m_currentIndex--;
        if(m_currentIndex < 0 )
        {
            m_currentIndex = m_playlist_musicIds.size() -1 ;
        }
        break;
    case CURRENTITEMLOOP:
        break;
    }
    playCurrentMusic();

}

void Video_to_MP3_music::on_playnext_clicked()
{
    //列表为空 什么也不做
    if(m_playlist_musicIds.isEmpty())
    {
        qDebug() << "歌曲不在当前列表中";
        return ;
    }
    switch(m_playbackmode)
    {
    case LISTLOOP:
        m_currentIndex++;
        if(m_currentIndex >= m_playlist_musicIds.size() )
        {
            m_currentIndex = 0  ;
        }
        break;
    case CURRENTITEMLOOP:
        break;
    case RANDOM:
        if (m_playlist_musicIds.size() > 1) {
            int nextIndex;
            // 循环直到找到一个和当前索引不同的随机索引
            do {
                nextIndex = QRandomGenerator::global()->bounded(m_playlist_musicIds.size());
            } while (nextIndex == m_currentIndex);
            m_currentIndex = nextIndex;
        } else {
            // 如果列表只有一首歌，索引还是0
            m_currentIndex = 0;
        }
        break;
    }
    playCurrentMusic();
}

void Video_to_MP3_music::on_playmode_clicked()
{
    if(m_playbackmode == LISTLOOP)
    {
        m_playbackmode = RANDOM;
    }
    else if( m_playbackmode == RANDOM)
    {
        m_playbackmode = CURRENTITEMLOOP;
    }
    else if( m_playbackmode == CURRENTITEMLOOP)
    {
        m_playbackmode = LISTLOOP;
    }

    switch(m_playbackmode)
    {
        case LISTLOOP:
            ui->playmode->setIcon(QIcon(":/images/list_play.png"));
            ui->playmode->setToolTip("列表循环");
            break;
        case RANDOM:
            ui->playmode->setIcon(QIcon(":/images/shuffle_2.png"));
            ui->playmode->setToolTip("随机播放");
            break;
        case CURRENTITEMLOOP:
            ui->playmode->setIcon(QIcon(":/images/single_play.png"));
            ui->playmode->setToolTip("单曲循环");
            break;
        default:
            break;
    }

}

void Video_to_MP3_music::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    // 我们只在歌曲自然播放结束时采取行动
    if (status == QMediaPlayer::EndOfMedia && player->playbackState() != QMediaPlayer::StoppedState)
    {
        qDebug() << "歌曲播放结束，行为等同于点击“下一曲”...";

        // 直接调用“下一曲”的逻辑即可！
        // 【注意】为了避免我们之前遇到的递归崩溃问题，仍然需要使用 QTimer
        QTimer::singleShot(0, this, &Video_to_MP3_music::on_playnext_clicked);
    }
}

void Video_to_MP3_music::onPlayAll(PageType pagetype)
{
    commonPage * page = nullptr;
    switch(pagetype)
    {
    case PageType::LIKE_PAGE:
        page = ui->mylikepage_4;
        break;
    case PageType::LOCAL_PAGE:
        page = ui->localmusicpage_5;
        break;
    case PageType::HISTORY_PAGE:
        page = ui->recentmusicpage_6;
        break;
    default:
        break;

    }
    playAllOfCommonPage(page , 0 );
}

void Video_to_MP3_music::playAllOfCommonPage(commonPage *commonPage, int index)
{
    // 1. 设置当前播放页面，这也会更新播放列表
    setCurrentPlayingPage(commonPage);

    // 2. 检查播放列表是否为空
    if(m_playlist_musicIds.isEmpty())
    {
        qDebug() << "页面列表为空，无法播放所有歌曲。";
        return ;
    }
    // 3. 设置起始索引
    if (index < 0 || index >= m_playlist_musicIds.size()) {
        m_currentIndex = 0; // 索引无效则从头开始
    } else {
        m_currentIndex = index;
    }


    playCurrentMusic();
}



void Video_to_MP3_music::onSourseChanged()
{
    if(m_currentIndex <0 || m_currentIndex >= m_playlist_musicIds.size())
    {
        return ;
    }

    //获取正在播放的歌曲的id
    QString currentMusicId = m_playlist_musicIds[m_currentIndex];

    //在主音乐列表找到这首歌
    auto it = musiclist.findMusicById(currentMusicId);

    //找到就标记为已播放
    if(it != musiclist.end())
    {
        //isHistory 标记为true
        it->setIsHistory(true);

        // 记录当前播放的时间戳
        it->setLastPlayedTimestamp(QDateTime::currentMSecsSinceEpoch());

        m_play_history.removeAll(currentMusicId);
        m_play_history.prepend(currentMusicId);
        QTimer::singleShot(0 , this ,[this](){
            ui->recentmusicpage_6->reFresh(musiclist , m_play_history);
        });
    }
    else
    {
        qDebug()<<"未找到歌曲";
    }
}

void Video_to_MP3_music::setCurrentPlayingPage(commonPage *page)
{
    if(!page)
    {
        qDebug()<<"错误";
        return;
    }

    currentpage = page;
    m_playlist_musicIds = page->getCurrentMusicListIds();

    m_currentIndex = -1;

}



void Video_to_MP3_music::on_skin_clicked()
{
    QMessageBox::information(this ,"温馨提示","暂不支持该功能");
}
void Video_to_MP3_music::on_min_clicked()
{
    showMinimized();
}
void Video_to_MP3_music::on_max_clicked()
{
    QMessageBox::information(this ,"温馨提示","暂不支持该功能");
}

void Video_to_MP3_music::quitMusic()
{
    musiclist.writeToDb();

    sqlite.close();

    // 【修改】使用 qApp->quit() 来真正地终止应用程序
    qApp->quit();

    //close();
}


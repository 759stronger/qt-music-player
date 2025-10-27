#include "volumetool.h"
#include "ui_volumetool.h"

#include <QGraphicsDropShadowEffect>
#include <QPainter>
volumeTool::volumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::volumeTool)
    ,realvolumeRatio(0.2f)
    ,isMuted(false)
{
    ui->setupUi(this);


    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);

    setAttribute(Qt::WA_TranslucentBackground);
    //ui->shadow_container->setAttribute(Qt::WA_TranslucentBackground);

    // 设置阴影效果
    QGraphicsDropShadowEffect *shadowEff = new QGraphicsDropShadowEffect(this);
    shadowEff->setOffset(0,0);
    shadowEff->setColor("#646464");
    shadowEff->setBlurRadius(10);
    ui->volumeWidget->setGraphicsEffect(shadowEff);

    // 【重要】确保 volumeWidget 本身是不透明的，并且能够接收样式
    ui->volumeWidget->setAttribute(Qt::WA_StyledBackground); // 允许样式表生效
    ui->volumeWidget->setStyleSheet("background-color: white; border-radius: 5px;"); // 给它一个白色圆角背景

    //设置图标
    ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    //音量默认大小20
    //ui->outSlider->setGeometry(ui->outSlider->x() , 180-36-25,ui->outSlider->width() , 20);
    //ui->sliderBtn->move(ui->sliderBtn->x() , ui->sliderBtn->y() - ui->sliderBtn->height()/2);
    //ui->volumeRatio->setText("20%");
    updateUiByVolume(0.2f);

    connect(ui->silenceBtn, &QPushButton::clicked , this , &volumeTool::onSilenceBtnClicked1);

    //安装事件过滤器
    ui->volumeWidget->installEventFilter(this);
}

volumeTool::~volumeTool()
{
    delete ui;
}

void volumeTool::paintEvent(QPaintEvent *event)
{
    (void) event;
    QPainter qpaint(this);
    qpaint.setRenderHint(QPainter::Antialiasing, true);
    qpaint.setPen(Qt::NoPen);
    qpaint.setBrush(Qt::white);

    // 【优化】使用动态坐标来绘制倒三角，使其总是在顶部中间
    QPolygon polygon;
    int w = this->width();
    polygon << QPoint(w/2, 0);       // 顶部中心点
    polygon << QPoint(w/2 - 10, 10); // 左下点
    polygon << QPoint(w/2 + 10, 10); // 右下点

    // 注意：这个绘制逻辑假设你的主窗口背景是透明的，
    // 并且实际内容（滑块等）是从 y=10 的位置开始的，以便为三角留出空间。
    // 你原来的代码绘制的是一个向下的三角，在底部。我们也可以恢复它：
    QPolygon bottomTriangle;
    int h = this->height();
    bottomTriangle << QPoint(w/2, h);           // 底部中心点
    bottomTriangle << QPoint(w/2 - 10, h - 10); // 左上点
    bottomTriangle << QPoint(w/2 + 10, h - 10); // 右上点

    // 为了匹配你的截图，我们绘制一个向上的三角，在底部
    QPolygon topTriangle;
    int h_popup = 180; // 假设你的弹出窗口内容高度是180
    topTriangle << QPoint(w/2, h_popup);
    topTriangle << QPoint(w/2 - 10, h_popup + 10);
    topTriangle << QPoint(w/2 + 10, h_popup + 10);

    // 你原来的代码绘制的是在 y=300 附近的倒三角，这表明你的窗口高度非常大
    // 这进一步证实了布局缺失的问题。
    // 我们暂时使用你原来的逻辑，但请注意这是一个潜在的问题点。
    QPolygon originalTriangle;
    originalTriangle << QPoint(30,300) << QPoint(70,300) << QPoint(50,320);

    qpaint.drawPolygon(originalTriangle);
}


void volumeTool::onSilenceBtnClicked1()
{
    isMuted = !isMuted;

    if(isMuted)
    {
        ui->silenceBtn->setIcon(QIcon(":/images/silent.png"));
    }
    else
    {
        ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    }

    emit setSilence(isMuted);
}

float volumeTool::getVolumeRatio()
{
    return realvolumeRatio;
}

void volumeTool::setVolume()
{
    // 1. 将鼠标的位置转换为sloderBox上的相对坐标，此处只要获取y坐标
    int height = ui->volumeWidget->mapFromGlobal(QCursor().pos()).y();

    // 2. 鼠标在volumeBox中可移动的y范围在[25, 205之间]
    height = height< 25?25:height;
    height = height>205?205:height;

    // 3. 调整sloderBt的位置
    //ui->sliderBtn->move(ui->sliderBtn->x() , height - ui->sliderBtn->height()/2);

    // 4. 更新outline的位置和大小
    //ui->outSlider->setGeometry(ui->outSlider->x() , height , ui->outSlider->width(), 205- height);

    // 5. 计算音量比率
    //realvolumeRatio = (int)((int)ui->outSlider->height()/(float)180*100);
    realvolumeRatio = (float)(205 - height) / 180.0f;

    // 6. 设置给label显示出来
    //ui->volumeRatio->setText(QString::number((int)(realvolumeRatio*100))+"%");
    updateUiByVolume(realvolumeRatio);

}

void volumeTool::updateUiByVolume(float volume)
{
    // 0. 安全检查和范围限制
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;

    // 1. 更新内部的音量数据
    this->realvolumeRatio = volume;

    // 2. 根据音量反向计算出滑块的 y 坐标
    // volumeWidget 的 y 范围是 [25, 205]，总高度 180
    // volume = (205 - y) / 180
    // (205 - y) = volume * 180
    // y = 205 - (volume * 180)
    int height = 205 - (int)(volume * 180.0f);

    // 3. 调整 sliderBtn 的位置
    ui->sliderBtn->move(ui->sliderBtn->x(), height - ui->sliderBtn->height() / 2);

    // 4. 更新 outSlider 的位置和大小
    ui->outSlider->setGeometry(ui->outSlider->x(), height, ui->outSlider->width(), 205 - height);

    // 5. 更新显示的百分比文本
    ui->volumeRatio->setText(QString::number((int)(volume * 100)) + "%");

}

bool volumeTool::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->volumeWidget)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            setVolume();
        }
        else if(event->type() == QEvent::MouseMove)
        {
            setVolume();
            emit  setMusicVolume(realvolumeRatio);
        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            emit  setMusicVolume(realvolumeRatio);
        }
        return true;

    }
    return QObject::eventFilter(object, event);
}












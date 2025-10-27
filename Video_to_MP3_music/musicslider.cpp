#include "musicslider.h"
#include "ui_musicslider.h"

musicSlider::musicSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::musicSlider)
    ,currentPos(0)
    ,maxWidth(0)
{
    ui->setupUi(this);

    //currentPos = 0 ;
    //maxWidth = width();
    moveSilder();
}

musicSlider::~musicSlider()
{
    delete ui;
}

void musicSlider::moveSilder()
{
    ui->outLine->setFixedWidth(currentPos);
    //ui->outLine->setGeometry(0,9,currentPos,4);
}

void musicSlider::resizeEvent(QResizeEvent *event)
{
    maxWidth = event->size().width();
    //maxWidth = ui->inLine->width();
    QWidget::resizeEvent(event);
}

void musicSlider::setStep(float bf)
{
    currentPos = maxWidth*bf;
    moveSilder();
}

void musicSlider::mousePressEvent(QMouseEvent *event)
{
    currentPos =event->pos().x();



    // 限制范围
    if (currentPos < 0) currentPos = 0;
    if (currentPos > maxWidth) currentPos = maxWidth;

    moveSilder();
}


void musicSlider::mouseMoveEvent(QMouseEvent *event)
{
    // 如果鼠标不在MusicSlider的矩形内，不进行拖拽
    QRect rect = QRect(0,0,width() , height());
    QPoint pos = event->pos();
    if(!rect.contains(pos))
    {
        return ;
    }

    //根据鼠标滑动的位置更新outLine的宽度
    if(event->buttons() == Qt::LeftButton)
    {
        currentPos = event->pos().x();


        if(currentPos< 0)
        {
            currentPos = 0 ;
        }
        if(currentPos >maxWidth)
        {
            currentPos = maxWidth;
        }
        moveSilder();

    }
}

void musicSlider::mouseReleaseEvent(QMouseEvent *event)
{
    currentPos = event->pos().x();


    // 限制范围
    if (currentPos < 0) currentPos = 0;
    if (currentPos > maxWidth) currentPos = maxWidth;


    moveSilder();
    emit setMusicSilderPosition((float)currentPos/(float)maxWidth);

    QWidget::mouseReleaseEvent(event);
}


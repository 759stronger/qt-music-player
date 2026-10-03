#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QPropertyAnimation>
#include "QDebug"
recBoxItem::recBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBoxItem)
{
    ui->setupUi(this);
    ui->musicImageBox->installEventFilter(this);
}

recBoxItem::~recBoxItem()
{
    delete ui;
}


bool recBoxItem::eventFilter(QObject * watched , QEvent *event)
{
    //当鼠标进入按钮 就开启动画
    if(watched == ui->musicImageBox)
    {
        int ImageWidget = ui->musicImageBox->width();
        int imageHeight = ui->musicImageBox->height();

        //拦截鼠标进入事件
        if(event->type() == QEvent::Enter)
        {
            QPropertyAnimation * animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(9,10 ,ImageWidget,imageHeight));
            animation->setEndValue(QRect(9,0 ,ImageWidget,imageHeight));
            animation->start();

            //动画结束时拦截信号 销毁动画
            connect(animation, &QPropertyAnimation::finished,this , [=]()
                    {
                delete animation;
            });
            return true;
        }
        else if(event->type() == QEvent::Leave)
        {
            QPropertyAnimation * animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(9,0 ,ImageWidget,imageHeight));
            animation->setEndValue(QRect(9,10 ,ImageWidget,imageHeight));
            animation->start();

            //动画结束时拦截信号 销毁动画
            connect(animation, &QPropertyAnimation::finished,this , [=]()
                    {
                        delete animation;
                    });
            return true;
        }
    }
    return QObject::eventFilter(watched , event);

}

void recBoxItem::setrecText(const QString &text)
{
    ui->recBoxItemText->setText(text);
}

void recBoxItem::setrecImage(const QString &ImagePath)
{
    QString imgStyle = "border-image:url("+ImagePath+");";  //这里是border吗 不是background
    ui->recMusicImage->setStyleSheet(imgStyle);
}

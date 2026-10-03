#include "musicform.h"
#include "ui_musicform.h"

musicForm::musicForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::musicForm)
{
    ui->setupUi(this);

    ui->linebox->hide();
    animationLine1 = new QPropertyAnimation(ui->line1 , "geometry" , this);
    animationLine1->setDuration(1500);//动画持续时间
    animationLine1->setKeyValueAt(0 , QRect(0,15,2,0));  //这个的范围只有从0到1  然后QRect中的是对应的x 的坐标
    animationLine1->setKeyValueAt(0.5 , QRect(0,0,2,15));
    animationLine1->setKeyValueAt(1, QRect(0,15,2,0));
    animationLine1->setLoopCount(-1);//表示永久循环
    animationLine1->start(); //启动动画

    animationLine2 = new QPropertyAnimation(ui->line2 , "geometry" , this);
    animationLine2->setDuration(1600);//动画持续时间
    animationLine2->setKeyValueAt(0 , QRect(7,15,2,0));  //这个的范围只有从0到1  然后QRect中的是对应的x 的坐标
    animationLine2->setKeyValueAt(0.5 , QRect(7,0,2,15));
    animationLine2->setKeyValueAt(1, QRect(7,15,2,0));
    animationLine2->setLoopCount(-1);//表示永久循环
    animationLine2->start(); //启动动画

    animationLine3 = new QPropertyAnimation(ui->line3 , "geometry" , this);
    animationLine3->setDuration(1700);//动画持续时间
    animationLine3->setKeyValueAt(0 , QRect(14,15,2,0));  //这个的范围只有从0到1  然后QRect中的是对应的x 的坐标
    animationLine3->setKeyValueAt(0.5 , QRect(14,0,2,15));
    animationLine3->setKeyValueAt(1, QRect(14,15,2,0));
    animationLine3->setLoopCount(-1);//表示永久循环
    animationLine3->start(); //启动动画

    animationLine4 = new QPropertyAnimation(ui->line4 , "geometry" , this);
    animationLine4->setDuration(1800);//动画持续时间
    animationLine4->setKeyValueAt(0 , QRect(21,15,2,0));  //这个的范围只有从0到1  然后QRect中的是对应的x 的坐标
    animationLine4->setKeyValueAt(0.5 , QRect(21,0,2,15));
    animationLine4->setKeyValueAt(1, QRect(21,15,2,0));
    animationLine4->setLoopCount(-1);//表示永久循环
    animationLine4->start(); //启动动画

}

musicForm::~musicForm()
{
    delete ui;
}

void musicForm::seticon(const QString musicicon, const QString content, int PageId)
{
    ui->musicicon->setPixmap(QPixmap(musicicon));
    ui->musicText->setText(content);
    this->PageId = PageId;
}

int musicForm::getId()
{
    return PageId;
}

void musicForm::clearBg()
{
    //清除上一个背景颜色 恢复原来的颜色
    ui->muscistyle->setStyleSheet("#muscistyle:hover{background:#D8D8D8;}");
}

void musicForm::showAnima(bool isshow)
{
    if(isshow)
    {
        ui->linebox->show();
    }
    else
    {
        ui->linebox->hide();
    }
}


void musicForm::mousePressEvent(QMouseEvent *event)
{
    // 告诉编译器不要触发警告
    (void)event;

    //鼠标点击后 窗口的背景颜色发生变化 字体颜色变化
    ui->muscistyle->setStyleSheet("#muscistyle{background:rgba(30,206,154,0.5);}*{color:#F6F6F6;}");

    emit musicclick(this->PageId); //发送页面id的信号
}













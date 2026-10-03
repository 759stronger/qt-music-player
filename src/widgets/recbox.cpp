#include "recbox.h"
#include "ui_recbox.h"
#include "recboxitem.h"

recBox::recBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recBox),
    row(1),
    col(4)
{
    ui->setupUi(this);

}

recBox::~recBox()
{
    delete ui;
}

void recBox::initRecboxui(QJsonArray data, int row)
{
    if(2 == row ) //两行说明是下方的界面
    {
        this->row = row;
        this->col  = 8;
    }
    else
    {
        ui->recListDown->hide();  //一行就把下方的界面隐藏起来
    }

    imageList = data;

    currentIndex = 0 ; //默认显示第0组
    count = ceil(imageList.size()/col); // 向上取整

    creatRecBoxItem();
}

void recBox::creatRecBoxItem()
{
    //删除之前的旧元素
    QList<recBoxItem*> recUpList = ui->recListUp->findChildren<recBoxItem*>();
    for(auto e: recUpList)
    {
        ui->recListUpLayout->removeWidget(e);
        delete e;
    }

    QList<recBoxItem*> recDownList = ui->recListDown->findChildren<recBoxItem*>();
    for(auto e: recDownList)
    {
        ui->recListDownLayout->removeWidget(e);
        delete e;
    }

    int index1 = 0 ;

    for(int i = currentIndex*col ; i<col+ currentIndex*col ; i++)
    {
        recBoxItem *item = new recBoxItem();

        //设置音乐图片和对应的文本
        QJsonObject obj = imageList[i].toObject();
        item->setrecText(obj.value("text").toString());
        item->setrecImage(obj.value("path").toString());
        if(index1 >= col/2 && row ==2)
        {
            ui->recListDownLayout->addWidget(item);
        }
        else
        {
            ui->recListUpLayout->addWidget(item);
        }
        index1++;
    }

}

void recBox::on_leftBtn_clicked()
{
    currentIndex--;
    if(currentIndex<0)
    {
        currentIndex = count -1;
    }
    creatRecBoxItem();
}

void recBox::on_rightBtn_clicked()
{
    currentIndex++;
    if(currentIndex>=count)
    {
        currentIndex = 0;
    }
    creatRecBoxItem();
}


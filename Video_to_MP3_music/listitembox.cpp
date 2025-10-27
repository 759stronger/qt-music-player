#include "listitembox.h"
#include "ui_listitembox.h"
#include <QDebug>
listItemBox::listItemBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listItemBox),
    isLike(false)
{
    ui->setupUi(this);
    //connect(ui->likeBtn , &QPushButton::clicked, this , &listItemBox::on_likeBtn_clicked);
}

listItemBox::~listItemBox()
{
    delete ui;
}

void listItemBox::setMusicName(const QString &name)
{
    ui->musicNameLabel->setText(name);
}

void listItemBox::setSingerName(const QString &singer)
{
    ui->musicSingerLabel->setText(singer);
}

void listItemBox::setAlbumName(const QString &album)
{
    ui->albumNameLabel->setText(album);
}

void listItemBox::setLikeMusic(bool isLike)
{
    this->isLike = isLike;
    if(this->isLike)
    {
        ui->likeBtn->setIcon(QIcon(":/images/like_2.png"));
    }
    else
    {
        ui->likeBtn->setIcon(QIcon(":/images/like_3.png"));
    }
}



void listItemBox::enterEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("background-color:#EFEFEF;");
}

void listItemBox::leaveEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("");
}


void listItemBox::on_likeBtn_clicked()
{
    isLike = !isLike;
    //qDebug()<<isLike;
    setLikeMusic(isLike);
    emit setIsLike(isLike);
}





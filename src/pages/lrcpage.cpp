#include "lrcpage.h"
#include "ui_lrcpage.h"

LrcPage::LrcPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LrcPage)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint);


    lrcHideAnimation = new QPropertyAnimation(this , "geometry" , this);
    lrcHideAnimation->setDuration(400);
    lrcHideAnimation->setStartValue(QRect(9 ,9 , width() , height() ));
    lrcHideAnimation->setEndValue(QRect(9 ,9 +width(), width() , height()));

    connect(ui->hideBtn , &QPushButton::clicked , this , [=]
            {
        lrcHideAnimation->start();

    });
    connect(lrcHideAnimation ,  &QPropertyAnimation::finished , this , [=]{
        hide();
    });

}

LrcPage::~LrcPage()
{
    delete ui;
}


//根据歌词路径文件获取时间和歌词
bool LrcPage::parseLrc(const QString &lrcPath)
{
    lrclines.clear();

    //打开歌词文件
    QFile lrcFile(lrcPath);
    if(!lrcFile.open(QFile::ReadOnly))
    {
        qDebug()<<"打开文件:"<<lrcPath;
        return false ;
    }

    while(!lrcFile.atEnd())
    {
        QString word = lrcFile.readLine(1024);

        int left = word.indexOf('[');
        int right = word.indexOf(']');

        //解析时间
        qint64 linetime = 0 ;
        int start = 0 ;
        int end = 0 ;
        QString time = word.mid(left , right - left +1);

        //解析分钟
        start = 1;
        end = time.indexOf(':');
        linetime += word.mid(start , end - start).toInt()*60*1000;

        //解析秒
        start = end+1;
        end = time.indexOf('.' ,start);
        linetime += word.mid(start , end - start).toInt()*1000;

        //解析秒
        start = end+1;
        end = time.indexOf('.' ,start);
        linetime += word.mid(start , end - start).toInt();

        //解析歌词
        QString lrcword = word.mid(right+1).trimmed();

        lrclines.push_back(LrcLine(linetime, lrcword.trimmed()));


    }

    return true;

}

int LrcPage::getLineLrcwordIndex(qint64 pos)
{
    if(lrclines.isEmpty())
    {
        return -1;
    }
    if(lrclines[0].LrcTime > pos)
    {
        return 0;
    }

    // 通过时间比较，获取下标
    for(int i =1 ; i< lrclines.size() ; i++)
    {
        if(pos >lrclines[i-1].LrcTime && pos<=lrclines[i].LrcTime)
        {
            return i-1;
        }
    }

    // 如果没有找到，返回最后一行
    return lrclines.size() -1;

}

QString LrcPage::getLineLrcword(qint64 index)
{
    if(index <0 || index>= lrclines.size())
    {
        return "";
    }

    return lrclines[index].LrcText;
}

void LrcPage::showLrcword(int time)
{
    int index = getLineLrcwordIndex(time);

    if(-1 == index)
    {
        ui->label1->setText("");
        ui->label_2->setText("");
         ui->label_3->setText("");
         ui->label_5->setText("");
          ui->label_6->setText("");
          ui->label_7->setText("");
          ui->label_center->setText("当前歌曲无歌词");
    }
    else
    {
        ui->label1->setText(getLineLrcword(index-3));
        ui->label_2->setText(getLineLrcword(index-2));
        ui->label_3->setText(getLineLrcword(index-1));
        ui->label_5->setText(getLineLrcword(index+1));
        ui->label_6->setText(getLineLrcword(index+2));
        ui->label_7->setText(getLineLrcword(index+3));
        ui->label_center->setText(getLineLrcword(index));
    }
}

/********************************************************************************
** Form generated from reading UI file 'video_to_mp3_music.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_TO_MP3_MUSIC_H
#define UI_VIDEO_TO_MP3_MUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <musicslider.h>
#include "commonpage.h"
#include "musicform.h"
#include "recbox.h"

QT_BEGIN_NAMESPACE

class Ui_Video_to_MP3_music
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *background;
    QVBoxLayout *verticalLayout_2;
    QWidget *head;
    QHBoxLayout *horizontalLayout;
    QWidget *headleft;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo;
    QWidget *headright;
    QHBoxLayout *horizontalLayout_3;
    QWidget *searchbox;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QWidget *settingbox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QPushButton *min;
    QPushButton *max;
    QPushButton *quit;
    QWidget *body;
    QWidget *bodyright;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *recpage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QLabel *rectext;
    QLabel *recmusictext;
    recBox *recmusicbox;
    QLabel *supplymusictext;
    recBox *supplymusicbox;
    QWidget *audiopage_2;
    QWidget *musicpage_3;
    commonPage *mylikepage_4;
    commonPage *localmusicpage_5;
    commonPage *recentmusicpage_6;
    musicSlider *progressbar;
    QWidget *control;
    QHBoxLayout *horizontalLayout_6;
    QWidget *play1;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QWidget *play2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *playmode;
    QPushButton *playprev;
    QPushButton *play;
    QPushButton *playnext;
    QPushButton *volume;
    QPushButton *addlocal;
    QWidget *play3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *null_2;
    QLabel *currenttime;
    QLabel *line;
    QLabel *totaltime;
    QPushButton *words;
    QWidget *bodyleft;
    QVBoxLayout *verticalLayout;
    QWidget *onlinemusic;
    QVBoxLayout *verticalLayout_4;
    QLabel *onlinemusictext;
    musicForm *Rec;
    musicForm *audio;
    musicForm *music;
    QWidget *mymusic;
    QVBoxLayout *verticalLayout_5;
    QLabel *musictext;
    musicForm *mylike;
    musicForm *localmusic;
    musicForm *recentmusic;

    void setupUi(QWidget *Video_to_MP3_music)
    {
        if (Video_to_MP3_music->objectName().isEmpty())
            Video_to_MP3_music->setObjectName("Video_to_MP3_music");
        Video_to_MP3_music->resize(1040, 700);
        Video_to_MP3_music->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(Video_to_MP3_music);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        background = new QWidget(Video_to_MP3_music);
        background->setObjectName("background");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(background->sizePolicy().hasHeightForWidth());
        background->setSizePolicy(sizePolicy);
        background->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(background);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        head = new QWidget(background);
        head->setObjectName("head");
        head->setMinimumSize(QSize(0, 80));
        head->setMaximumSize(QSize(16777215, 80));
        head->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(head);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        headleft = new QWidget(head);
        headleft->setObjectName("headleft");
        headleft->setMinimumSize(QSize(200, 0));
        headleft->setMaximumSize(QSize(200, 16777215));
        headleft->setStyleSheet(QString::fromUtf8("#headleft\n"
"{\n"
"  background-color:#F0F0F0;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(headleft);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(headleft);
        logo->setObjectName("logo");
        logo->setStyleSheet(QString::fromUtf8("#logo\n"
"{\n"
"    border-radius:0px;\n"
"	backgroUnd-image:url(:/images/Logo.png);\n"
"	background-repeat: no-repeat;\n"
"	border:none;\n"
"	background-position:center center;\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(logo);


        horizontalLayout->addWidget(headleft);

        headright = new QWidget(head);
        headright->setObjectName("headright");
        headright->setStyleSheet(QString::fromUtf8("#headright\n"
"{\n"
"\n"
"  background-color:#F5F5F5;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(headright);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchbox = new QWidget(headright);
        searchbox->setObjectName("searchbox");
        searchbox->setMinimumSize(QSize(300, 0));
        searchbox->setMaximumSize(QSize(300, 16777215));
        searchbox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(searchbox);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit = new QLineEdit(searchbox);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
"{\n"
"	background-color:#E3E3E3;\n"
"	border-radius: 12px;\n"
"	padding-left:17px;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(lineEdit);


        horizontalLayout_3->addWidget(searchbox);

        settingbox = new QWidget(headright);
        settingbox->setObjectName("settingbox");
        settingbox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"		border-radisus:0px;\n"
"		background-repeat:no-repeat;\n"
" 		border:none;\n"
"		background-position:center center;\n"
"		\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#E3E3E3;\n"
"}\n"
""));
        horizontalLayout_5 = new QHBoxLayout(settingbox);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(375, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        skin = new QPushButton(settingbox);
        skin->setObjectName("skin");
        skin->setMinimumSize(QSize(30, 30));
        skin->setMaximumSize(QSize(30, 30));
        skin->setStyleSheet(QString::fromUtf8("#skin\n"
"{\n"
"	background-image:url(:/images/skin.png);\n"
"}"));

        horizontalLayout_5->addWidget(skin);

        min = new QPushButton(settingbox);
        min->setObjectName("min");
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("#min\n"
"{\n"
"	background-image:url(:/images/min.png);\n"
"}"));

        horizontalLayout_5->addWidget(min);

        max = new QPushButton(settingbox);
        max->setObjectName("max");
        max->setMinimumSize(QSize(30, 30));
        max->setMaximumSize(QSize(30, 30));
        max->setStyleSheet(QString::fromUtf8("#max\n"
"{\n"
"	background-image:url(:/images/max.png);\n"
"}"));

        horizontalLayout_5->addWidget(max);

        quit = new QPushButton(settingbox);
        quit->setObjectName("quit");
        quit->setMinimumSize(QSize(30, 30));
        quit->setMaximumSize(QSize(30, 30));
        quit->setStyleSheet(QString::fromUtf8("#quit\n"
"{\n"
"	background-image:url(:/images/quit.png);\n"
"}"));

        horizontalLayout_5->addWidget(quit);


        horizontalLayout_3->addWidget(settingbox);


        horizontalLayout->addWidget(headright);


        verticalLayout_2->addWidget(head);

        body = new QWidget(background);
        body->setObjectName("body");
        body->setStyleSheet(QString::fromUtf8("#body\n"
"{\n"
"	background-color:#F0F0F0;\n"
"}"));
        bodyright = new QWidget(body);
        bodyright->setObjectName("bodyright");
        bodyright->setGeometry(QRect(200, 0, 822, 602));
        bodyright->setMinimumSize(QSize(822, 602));
        bodyright->setMaximumSize(QSize(822, 602));
        bodyright->setStyleSheet(QString::fromUtf8("#bodyright\n"
"{\n"
"	background-color:#F5F5F5;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(bodyright);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(bodyright);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(822, 500));
        stackedWidget->setMaximumSize(QSize(822, 500));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        recpage = new QWidget();
        recpage->setObjectName("recpage");
        scrollArea = new QScrollArea(recpage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-1, -1, 820, 500));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 498));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName("verticalLayout_7");
        rectext = new QLabel(scrollAreaWidgetContents);
        rectext->setObjectName("rectext");
        rectext->setMinimumSize(QSize(0, 50));
        rectext->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(24);
        rectext->setFont(font);

        verticalLayout_7->addWidget(rectext);

        recmusictext = new QLabel(scrollAreaWidgetContents);
        recmusictext->setObjectName("recmusictext");
        recmusictext->setMinimumSize(QSize(0, 30));
        recmusictext->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(18);
        recmusictext->setFont(font1);

        verticalLayout_7->addWidget(recmusictext);

        recmusicbox = new recBox(scrollAreaWidgetContents);
        recmusicbox->setObjectName("recmusicbox");

        verticalLayout_7->addWidget(recmusicbox);

        supplymusictext = new QLabel(scrollAreaWidgetContents);
        supplymusictext->setObjectName("supplymusictext");
        supplymusictext->setMinimumSize(QSize(0, 30));
        supplymusictext->setMaximumSize(QSize(16777215, 30));
        supplymusictext->setFont(font1);

        verticalLayout_7->addWidget(supplymusictext);

        supplymusicbox = new recBox(scrollAreaWidgetContents);
        supplymusicbox->setObjectName("supplymusicbox");

        verticalLayout_7->addWidget(supplymusicbox);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(recpage);
        audiopage_2 = new QWidget();
        audiopage_2->setObjectName("audiopage_2");
        stackedWidget->addWidget(audiopage_2);
        musicpage_3 = new QWidget();
        musicpage_3->setObjectName("musicpage_3");
        stackedWidget->addWidget(musicpage_3);
        mylikepage_4 = new commonPage();
        mylikepage_4->setObjectName("mylikepage_4");
        stackedWidget->addWidget(mylikepage_4);
        localmusicpage_5 = new commonPage();
        localmusicpage_5->setObjectName("localmusicpage_5");
        stackedWidget->addWidget(localmusicpage_5);
        recentmusicpage_6 = new commonPage();
        recentmusicpage_6->setObjectName("recentmusicpage_6");
        stackedWidget->addWidget(recentmusicpage_6);

        verticalLayout_6->addWidget(stackedWidget);

        progressbar = new musicSlider(bodyright);
        progressbar->setObjectName("progressbar");
        progressbar->setMinimumSize(QSize(822, 30));
        progressbar->setMaximumSize(QSize(822, 30));
        progressbar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(progressbar);

        control = new QWidget(bodyright);
        control->setObjectName("control");
        control->setMinimumSize(QSize(822, 72));
        control->setMaximumSize(QSize(822, 72));
        control->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(control);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        play1 = new QWidget(control);
        play1->setObjectName("play1");
        play1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(play1);
        gridLayout->setObjectName("gridLayout");
        label_8 = new QLabel(play1);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(play1);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        label_7 = new QLabel(play1);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(54, 0));
        label_7->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_7, 0, 0, 2, 1);


        horizontalLayout_6->addWidget(play1);

        play2 = new QWidget(control);
        play2->setObjectName("play2");
        play2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"		border-radisus:0px;\n"
"		background-repeat:no-repeat;\n"
" 		border:none;\n"
"		background-position:center center;\n"
"		\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#E3E3E3;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(play2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        playmode = new QPushButton(play2);
        playmode->setObjectName("playmode");
        playmode->setMinimumSize(QSize(30, 30));
        playmode->setMaximumSize(QSize(30, 30));
        playmode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(playmode);

        playprev = new QPushButton(play2);
        playprev->setObjectName("playprev");
        playprev->setMinimumSize(QSize(30, 30));
        playprev->setMaximumSize(QSize(30, 30));
        playprev->setStyleSheet(QString::fromUtf8("#playprev\n"
"{\n"
"	background-image:url(:/images/up.png);\n"
"}"));

        horizontalLayout_7->addWidget(playprev);

        play = new QPushButton(play2);
        play->setObjectName("play");
        play->setMinimumSize(QSize(30, 30));
        play->setMaximumSize(QSize(30, 30));
        play->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(play);

        playnext = new QPushButton(play2);
        playnext->setObjectName("playnext");
        playnext->setMinimumSize(QSize(30, 30));
        playnext->setMaximumSize(QSize(30, 30));
        playnext->setStyleSheet(QString::fromUtf8("#playnext\n"
"{\n"
"	background-image:url(:/images/down.png);\n"
"}"));

        horizontalLayout_7->addWidget(playnext);

        volume = new QPushButton(play2);
        volume->setObjectName("volume");
        volume->setMinimumSize(QSize(30, 30));
        volume->setMaximumSize(QSize(30, 30));
        volume->setStyleSheet(QString::fromUtf8("#volume\n"
"{\n"
"	background-image:url(:/images/volumn.png);\n"
"}"));

        horizontalLayout_7->addWidget(volume);

        addlocal = new QPushButton(play2);
        addlocal->setObjectName("addlocal");
        addlocal->setMinimumSize(QSize(30, 30));
        addlocal->setMaximumSize(QSize(30, 30));
        addlocal->setStyleSheet(QString::fromUtf8("#addlocal\n"
"{\n"
"	background-image:url(:/images/add.png);\n"
"}"));

        horizontalLayout_7->addWidget(addlocal);


        horizontalLayout_6->addWidget(play2);

        play3 = new QWidget(control);
        play3->setObjectName("play3");
        horizontalLayout_8 = new QHBoxLayout(play3);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        null_2 = new QLabel(play3);
        null_2->setObjectName("null_2");
        null_2->setMinimumSize(QSize(150, 0));
        null_2->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_8->addWidget(null_2);

        currenttime = new QLabel(play3);
        currenttime->setObjectName("currenttime");

        horizontalLayout_8->addWidget(currenttime);

        line = new QLabel(play3);
        line->setObjectName("line");
        line->setMinimumSize(QSize(16, 0));
        line->setMaximumSize(QSize(16, 16777215));

        horizontalLayout_8->addWidget(line);

        totaltime = new QLabel(play3);
        totaltime->setObjectName("totaltime");

        horizontalLayout_8->addWidget(totaltime);

        words = new QPushButton(play3);
        words->setObjectName("words");
        words->setMinimumSize(QSize(30, 30));
        words->setMaximumSize(QSize(30, 30));

        horizontalLayout_8->addWidget(words);


        horizontalLayout_6->addWidget(play3);


        verticalLayout_6->addWidget(control);

        bodyleft = new QWidget(body);
        bodyleft->setObjectName("bodyleft");
        bodyleft->setGeometry(QRect(0, 0, 200, 400));
        bodyleft->setMinimumSize(QSize(200, 400));
        bodyleft->setMaximumSize(QSize(200, 400));
        bodyleft->setStyleSheet(QString::fromUtf8("#bodyleft\n"
"{\n"
"	background-color:#F0F0F0;\n"
"}"));
        verticalLayout = new QVBoxLayout(bodyleft);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        onlinemusic = new QWidget(bodyleft);
        onlinemusic->setObjectName("onlinemusic");
        onlinemusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(onlinemusic);
        verticalLayout_4->setObjectName("verticalLayout_4");
        onlinemusictext = new QLabel(onlinemusic);
        onlinemusictext->setObjectName("onlinemusictext");

        verticalLayout_4->addWidget(onlinemusictext);

        Rec = new musicForm(onlinemusic);
        Rec->setObjectName("Rec");

        verticalLayout_4->addWidget(Rec);

        audio = new musicForm(onlinemusic);
        audio->setObjectName("audio");

        verticalLayout_4->addWidget(audio);

        music = new musicForm(onlinemusic);
        music->setObjectName("music");

        verticalLayout_4->addWidget(music);


        verticalLayout->addWidget(onlinemusic);

        mymusic = new QWidget(bodyleft);
        mymusic->setObjectName("mymusic");
        mymusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(mymusic);
        verticalLayout_5->setObjectName("verticalLayout_5");
        musictext = new QLabel(mymusic);
        musictext->setObjectName("musictext");

        verticalLayout_5->addWidget(musictext);

        mylike = new musicForm(mymusic);
        mylike->setObjectName("mylike");

        verticalLayout_5->addWidget(mylike);

        localmusic = new musicForm(mymusic);
        localmusic->setObjectName("localmusic");

        verticalLayout_5->addWidget(localmusic);

        recentmusic = new musicForm(mymusic);
        recentmusic->setObjectName("recentmusic");

        verticalLayout_5->addWidget(recentmusic);


        verticalLayout->addWidget(mymusic);


        verticalLayout_2->addWidget(body);


        verticalLayout_3->addWidget(background);


        retranslateUi(Video_to_MP3_music);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Video_to_MP3_music);
    } // setupUi

    void retranslateUi(QWidget *Video_to_MP3_music)
    {
        Video_to_MP3_music->setWindowTitle(QCoreApplication::translate("Video_to_MP3_music", "Video_to_MP3_music", nullptr));
        logo->setText(QString());
        skin->setText(QString());
        min->setText(QString());
        max->setText(QString());
        quit->setText(QString());
        rectext->setText(QCoreApplication::translate("Video_to_MP3_music", "\346\216\250\350\215\220", nullptr));
        recmusictext->setText(QCoreApplication::translate("Video_to_MP3_music", "\344\273\212\346\227\245\344\270\272\344\275\240\346\216\250\350\215\220", nullptr));
        supplymusictext->setText(QCoreApplication::translate("Video_to_MP3_music", "\351\237\263\344\271\220\350\241\245\347\273\231\347\253\231", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        label_7->setText(QString());
        playmode->setText(QString());
        playprev->setText(QString());
        play->setText(QString());
        playnext->setText(QString());
        volume->setText(QString());
        addlocal->setText(QString());
        null_2->setText(QString());
        currenttime->setText(QCoreApplication::translate("Video_to_MP3_music", "00:00", nullptr));
        line->setText(QCoreApplication::translate("Video_to_MP3_music", "/", nullptr));
        totaltime->setText(QCoreApplication::translate("Video_to_MP3_music", "00:00", nullptr));
        words->setText(QCoreApplication::translate("Video_to_MP3_music", "\350\257\215", nullptr));
        onlinemusictext->setText(QCoreApplication::translate("Video_to_MP3_music", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        musictext->setText(QCoreApplication::translate("Video_to_MP3_music", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Video_to_MP3_music: public Ui_Video_to_MP3_music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_TO_MP3_MUSIC_H

/********************************************************************************
** Form generated from reading UI file 'recbox.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOX_H
#define UI_RECBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *leftBtn;
    QWidget *musicContent;
    QVBoxLayout *verticalLayout;
    QWidget *recListUp;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *recListUpLayout;
    QWidget *recListDown;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *recListDownLayout;
    QWidget *rightPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *rightBtn;

    void setupUi(QWidget *recBox)
    {
        if (recBox->objectName().isEmpty())
            recBox->setObjectName("recBox");
        recBox->resize(685, 440);
        horizontalLayout = new QHBoxLayout(recBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPage = new QWidget(recBox);
        leftPage->setObjectName("leftPage");
        leftPage->setMinimumSize(QSize(30, 0));
        leftPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_2 = new QHBoxLayout(leftPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leftBtn = new QPushButton(leftPage);
        leftBtn->setObjectName("leftBtn");
        leftBtn->setMinimumSize(QSize(0, 220));
        leftBtn->setMaximumSize(QSize(16777215, 220));
        leftBtn->setStyleSheet(QString::fromUtf8("#leftBtn\n"
"{\n"
"	background-repeat:no-repeat;\n"
"	border:none;\n"
"	background-image:url(:/images/up_page.png);\n"
"	background-position: center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#D8D8D8;\n"
"}"));

        horizontalLayout_2->addWidget(leftBtn);


        horizontalLayout->addWidget(leftPage);

        musicContent = new QWidget(recBox);
        musicContent->setObjectName("musicContent");
        verticalLayout = new QVBoxLayout(musicContent);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recListUp = new QWidget(musicContent);
        recListUp->setObjectName("recListUp");
        horizontalLayout_7 = new QHBoxLayout(recListUp);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        recListUpLayout = new QHBoxLayout();
        recListUpLayout->setObjectName("recListUpLayout");

        horizontalLayout_7->addLayout(recListUpLayout);


        verticalLayout->addWidget(recListUp);

        recListDown = new QWidget(musicContent);
        recListDown->setObjectName("recListDown");
        horizontalLayout_6 = new QHBoxLayout(recListDown);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        recListDownLayout = new QHBoxLayout();
        recListDownLayout->setObjectName("recListDownLayout");

        horizontalLayout_6->addLayout(recListDownLayout);


        verticalLayout->addWidget(recListDown);


        horizontalLayout->addWidget(musicContent);

        rightPage = new QWidget(recBox);
        rightPage->setObjectName("rightPage");
        rightPage->setMinimumSize(QSize(30, 0));
        rightPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_3 = new QHBoxLayout(rightPage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rightBtn = new QPushButton(rightPage);
        rightBtn->setObjectName("rightBtn");
        rightBtn->setMinimumSize(QSize(0, 220));
        rightBtn->setMaximumSize(QSize(16777215, 220));
        rightBtn->setStyleSheet(QString::fromUtf8("#rightBtn\n"
"{\n"
"	background-repeat:no-repeat;\n"
"	border:none;\n"
"	background-image:url(:/images/down_page.png);\n"
"	background-position: center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#D8D8D8;\n"
"}"));

        horizontalLayout_3->addWidget(rightBtn);


        horizontalLayout->addWidget(rightPage);


        retranslateUi(recBox);

        QMetaObject::connectSlotsByName(recBox);
    } // setupUi

    void retranslateUi(QWidget *recBox)
    {
        recBox->setWindowTitle(QCoreApplication::translate("recBox", "Form", nullptr));
        leftBtn->setText(QString());
        rightBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recBox: public Ui_recBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOX_H

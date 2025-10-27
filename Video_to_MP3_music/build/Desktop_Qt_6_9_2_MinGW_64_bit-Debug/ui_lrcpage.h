/********************************************************************************
** Form generated from reading UI file 'lrcpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRCPAGE_H
#define UI_LRCPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LrcPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *bgStyle;
    QVBoxLayout *verticalLayout_2;
    QWidget *lrcTop;
    QHBoxLayout *horizontalLayout;
    QPushButton *hideBtn;
    QWidget *titleBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *musicName;
    QLabel *musicSinger;
    QWidget *lrcContent;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_center;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LrcPage)
    {
        if (LrcPage->objectName().isEmpty())
            LrcPage->setObjectName("LrcPage");
        LrcPage->resize(1022, 682);
        verticalLayout = new QVBoxLayout(LrcPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bgStyle = new QWidget(LrcPage);
        bgStyle->setObjectName("bgStyle");
        bgStyle->setStyleSheet(QString::fromUtf8("#bgStyle {\n"
"    border-image: url(:/images/bg.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(bgStyle);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lrcTop = new QWidget(bgStyle);
        lrcTop->setObjectName("lrcTop");
        lrcTop->setMinimumSize(QSize(0, 50));
        lrcTop->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(lrcTop);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        hideBtn = new QPushButton(lrcTop);
        hideBtn->setObjectName("hideBtn");
        hideBtn->setMinimumSize(QSize(30, 50));
        hideBtn->setMaximumSize(QSize(30, 50));
        hideBtn->setStyleSheet(QString::fromUtf8("#hideBtn\n"
"{\n"
"   background-image:url(:/images/xiala.png);\n"
"	background-repeat: no-repeat;\n"
"    background-position: center center;\n"
"background-color: rgba(0, 0, 0, 0);\n"
"\n"
"	\n"
"}"));

        horizontalLayout->addWidget(hideBtn);

        titleBox = new QWidget(lrcTop);
        titleBox->setObjectName("titleBox");
        verticalLayout_3 = new QVBoxLayout(titleBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        musicName = new QLabel(titleBox);
        musicName->setObjectName("musicName");

        verticalLayout_3->addWidget(musicName);

        musicSinger = new QLabel(titleBox);
        musicSinger->setObjectName("musicSinger");

        verticalLayout_3->addWidget(musicSinger);


        horizontalLayout->addWidget(titleBox);


        verticalLayout_2->addWidget(lrcTop);

        lrcContent = new QWidget(bgStyle);
        lrcContent->setObjectName("lrcContent");
        verticalLayout_4 = new QVBoxLayout(lrcContent);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 123, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        label1 = new QLabel(lrcContent);
        label1->setObjectName("label1");
        label1->setMinimumSize(QSize(0, 50));
        label1->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(15);
        label1->setFont(font);
        label1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label1);

        label_2 = new QLabel(lrcContent);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setMaximumSize(QSize(16777215, 50));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(lrcContent);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 50));
        label_3->setMaximumSize(QSize(16777215, 50));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        label_center = new QLabel(lrcContent);
        label_center->setObjectName("label_center");
        label_center->setMinimumSize(QSize(0, 80));
        label_center->setMaximumSize(QSize(16777215, 80));
        QFont font1;
        font1.setPointSize(25);
        label_center->setFont(font1);
        label_center->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_center);

        label_5 = new QLabel(lrcContent);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 50));
        label_5->setMaximumSize(QSize(16777215, 50));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(lrcContent);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 50));
        label_6->setMaximumSize(QSize(16777215, 50));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(lrcContent);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(0, 50));
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        verticalSpacer = new QSpacerItem(20, 123, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_2->addWidget(lrcContent);


        verticalLayout->addWidget(bgStyle);


        retranslateUi(LrcPage);

        QMetaObject::connectSlotsByName(LrcPage);
    } // setupUi

    void retranslateUi(QWidget *LrcPage)
    {
        LrcPage->setWindowTitle(QCoreApplication::translate("LrcPage", "Form", nullptr));
        hideBtn->setText(QString());
        musicName->setText(QString());
        musicSinger->setText(QString());
        label1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_center->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LrcPage: public Ui_LrcPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCPAGE_H

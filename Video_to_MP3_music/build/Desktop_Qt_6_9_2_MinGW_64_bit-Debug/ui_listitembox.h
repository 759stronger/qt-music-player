/********************************************************************************
** Form generated from reading UI file 'listitembox.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEMBOX_H
#define UI_LISTITEMBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listItemBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *musicNameBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *likeBtn;
    QLabel *musicNameLabel;
    QLabel *VIPlabel;
    QLabel *SQlabel;
    QSpacerItem *horizontalSpacer;
    QWidget *musicSingerBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *musicSingerLabel;
    QWidget *musicAblumBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *albumNameLabel;

    void setupUi(QWidget *listItemBox)
    {
        if (listItemBox->objectName().isEmpty())
            listItemBox->setObjectName("listItemBox");
        listItemBox->resize(800, 45);
        horizontalLayout = new QHBoxLayout(listItemBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicNameBox = new QWidget(listItemBox);
        musicNameBox->setObjectName("musicNameBox");
        musicNameBox->setMinimumSize(QSize(380, 0));
        musicNameBox->setMaximumSize(QSize(380, 16777215));
        horizontalLayout_2 = new QHBoxLayout(musicNameBox);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        likeBtn = new QPushButton(musicNameBox);
        likeBtn->setObjectName("likeBtn");
        likeBtn->setMinimumSize(QSize(25, 25));
        likeBtn->setMaximumSize(QSize(25, 25));
        likeBtn->setStyleSheet(QString::fromUtf8("#likeBtn\n"
"{\n"
"   border:none;\n"
"}"));

        horizontalLayout_2->addWidget(likeBtn);

        musicNameLabel = new QLabel(musicNameBox);
        musicNameLabel->setObjectName("musicNameLabel");
        musicNameLabel->setMinimumSize(QSize(130, 0));
        musicNameLabel->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_2->addWidget(musicNameLabel);

        VIPlabel = new QLabel(musicNameBox);
        VIPlabel->setObjectName("VIPlabel");
        VIPlabel->setMinimumSize(QSize(30, 15));
        VIPlabel->setMaximumSize(QSize(30, 15));
        VIPlabel->setStyleSheet(QString::fromUtf8("#VIPlabel\n"
"{\n"
"	border:1px solid #1ECD96;\n"
"	color :#1ECD96;\n"
"	border-radius:2px;	\n"
"}"));

        horizontalLayout_2->addWidget(VIPlabel);

        SQlabel = new QLabel(musicNameBox);
        SQlabel->setObjectName("SQlabel");
        SQlabel->setMinimumSize(QSize(25, 15));
        SQlabel->setMaximumSize(QSize(25, 15));
        SQlabel->setStyleSheet(QString::fromUtf8("#SQlabel\n"
"{\n"
"	border:1px solid #FF6600;\n"
"	color :#FF6600;\n"
"	border-radius:2px;	\n"
"}"));

        horizontalLayout_2->addWidget(SQlabel);

        horizontalSpacer = new QSpacerItem(159, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addWidget(musicNameBox);

        musicSingerBox = new QWidget(listItemBox);
        musicSingerBox->setObjectName("musicSingerBox");
        musicSingerBox->setMinimumSize(QSize(200, 0));
        musicSingerBox->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_3 = new QHBoxLayout(musicSingerBox);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        musicSingerLabel = new QLabel(musicSingerBox);
        musicSingerLabel->setObjectName("musicSingerLabel");

        horizontalLayout_3->addWidget(musicSingerLabel);


        horizontalLayout->addWidget(musicSingerBox);

        musicAblumBox = new QWidget(listItemBox);
        musicAblumBox->setObjectName("musicAblumBox");
        horizontalLayout_4 = new QHBoxLayout(musicAblumBox);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        albumNameLabel = new QLabel(musicAblumBox);
        albumNameLabel->setObjectName("albumNameLabel");

        horizontalLayout_4->addWidget(albumNameLabel);


        horizontalLayout->addWidget(musicAblumBox);


        retranslateUi(listItemBox);

        QMetaObject::connectSlotsByName(listItemBox);
    } // setupUi

    void retranslateUi(QWidget *listItemBox)
    {
        listItemBox->setWindowTitle(QCoreApplication::translate("listItemBox", "Form", nullptr));
        likeBtn->setText(QString());
        musicNameLabel->setText(QCoreApplication::translate("listItemBox", "TextLabel", nullptr));
        VIPlabel->setText(QCoreApplication::translate("listItemBox", "VIP", nullptr));
        SQlabel->setText(QCoreApplication::translate("listItemBox", "SQ", nullptr));
        musicSingerLabel->setText(QCoreApplication::translate("listItemBox", "TextLabel", nullptr));
        albumNameLabel->setText(QCoreApplication::translate("listItemBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listItemBox: public Ui_listItemBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEMBOX_H

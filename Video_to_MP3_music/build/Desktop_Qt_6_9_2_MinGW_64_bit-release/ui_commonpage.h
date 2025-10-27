/********************************************************************************
** Form generated from reading UI file 'commonpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPAGE_H
#define UI_COMMONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commonPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pageTittle;
    QWidget *musicPlayBox;
    QHBoxLayout *horizontalLayout;
    QLabel *musicImageLabel;
    QWidget *playAll;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *playAllBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *listLabelBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *pageMusicList;

    void setupUi(QWidget *commonPage)
    {
        if (commonPage->objectName().isEmpty())
            commonPage->setObjectName("commonPage");
        commonPage->resize(800, 500);
        verticalLayout = new QVBoxLayout(commonPage);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(3, 0, 3, 0);
        pageTittle = new QLabel(commonPage);
        pageTittle->setObjectName("pageTittle");
        pageTittle->setMinimumSize(QSize(0, 30));
        pageTittle->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(18);
        pageTittle->setFont(font);

        verticalLayout->addWidget(pageTittle);

        musicPlayBox = new QWidget(commonPage);
        musicPlayBox->setObjectName("musicPlayBox");
        musicPlayBox->setMinimumSize(QSize(0, 150));
        musicPlayBox->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(musicPlayBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicImageLabel = new QLabel(musicPlayBox);
        musicImageLabel->setObjectName("musicImageLabel");
        musicImageLabel->setMinimumSize(QSize(150, 0));
        musicImageLabel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(musicImageLabel);

        playAll = new QWidget(musicPlayBox);
        playAll->setObjectName("playAll");
        playAll->setMinimumSize(QSize(120, 0));
        playAll->setMaximumSize(QSize(120, 16777215));
        verticalLayout_2 = new QVBoxLayout(playAll);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 93, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        playAllBtn = new QPushButton(playAll);
        playAllBtn->setObjectName("playAllBtn");
        playAllBtn->setMinimumSize(QSize(100, 30));
        playAllBtn->setMaximumSize(QSize(100, 30));
        playAllBtn->setStyleSheet(QString::fromUtf8("#playAllBtn\n"
"{\n"
"	background-color:#E3E3E3;\n"
"	border-radius:10px;\n"
"}\n"
"#playAllBtn:hover\n"
"{\n"
"	background-color:#1ECD97;\n"
"	\n"
"}\n"
""));

        verticalLayout_2->addWidget(playAllBtn);


        horizontalLayout->addWidget(playAll);

        horizontalSpacer = new QSpacerItem(521, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(musicPlayBox);

        listLabelBox = new QWidget(commonPage);
        listLabelBox->setObjectName("listLabelBox");
        listLabelBox->setMinimumSize(QSize(0, 40));
        listLabelBox->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(listLabelBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(listLabelBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(380, 0));
        label->setMaximumSize(QSize(380, 16777215));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(listLabelBox);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(200, 0));
        label_2->setMaximumSize(QSize(200, 16777215));
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(listLabelBox);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addWidget(listLabelBox);

        pageMusicList = new QListWidget(commonPage);
        pageMusicList->setObjectName("pageMusicList");
        pageMusicList->setStyleSheet(QString::fromUtf8("#pageMusicList::item::selected\n"
"{\n"
"background-color:#EFEFEF;\n"
"}"));

        verticalLayout->addWidget(pageMusicList);


        retranslateUi(commonPage);

        QMetaObject::connectSlotsByName(commonPage);
    } // setupUi

    void retranslateUi(QWidget *commonPage)
    {
        commonPage->setWindowTitle(QCoreApplication::translate("commonPage", "Form", nullptr));
        pageTittle->setText(QString());
        musicImageLabel->setText(QString());
        playAllBtn->setText(QCoreApplication::translate("commonPage", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        label->setText(QCoreApplication::translate("commonPage", "       \346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("commonPage", "\346\255\214\346\211\213\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("commonPage", "\344\270\223\350\276\221\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class commonPage: public Ui_commonPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPAGE_H

/********************************************************************************
** Form generated from reading UI file 'recboxitem.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOXITEM_H
#define UI_RECBOXITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recBoxItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *musicImageBox;
    QLabel *recMusicImage;
    QPushButton *recMusicBtn;
    QLabel *recBoxItemText;

    void setupUi(QWidget *recBoxItem)
    {
        if (recBoxItem->objectName().isEmpty())
            recBoxItem->setObjectName("recBoxItem");
        recBoxItem->resize(150, 200);
        verticalLayout = new QVBoxLayout(recBoxItem);
        verticalLayout->setObjectName("verticalLayout");
        musicImageBox = new QWidget(recBoxItem);
        musicImageBox->setObjectName("musicImageBox");
        musicImageBox->setMinimumSize(QSize(0, 150));
        musicImageBox->setMaximumSize(QSize(16777215, 150));
        musicImageBox->setStyleSheet(QString::fromUtf8(""));
        recMusicImage = new QLabel(musicImageBox);
        recMusicImage->setObjectName("recMusicImage");
        recMusicImage->setGeometry(QRect(0, 0, 150, 150));
        recMusicBtn = new QPushButton(musicImageBox);
        recMusicBtn->setObjectName("recMusicBtn");
        recMusicBtn->setGeometry(QRect(20, 30, 91, 101));
        recMusicBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        recMusicBtn->setStyleSheet(QString::fromUtf8("#recMusicBtn\n"
"{\n"
"	border:none;\n"
"}"));

        verticalLayout->addWidget(musicImageBox);

        recBoxItemText = new QLabel(recBoxItem);
        recBoxItemText->setObjectName("recBoxItemText");
        QFont font;
        font.setHintingPreference(QFont::PreferFullHinting);
        recBoxItemText->setFont(font);
        recBoxItemText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(recBoxItemText);


        retranslateUi(recBoxItem);

        QMetaObject::connectSlotsByName(recBoxItem);
    } // setupUi

    void retranslateUi(QWidget *recBoxItem)
    {
        recBoxItem->setWindowTitle(QCoreApplication::translate("recBoxItem", "Form", nullptr));
        recMusicImage->setText(QString());
        recMusicBtn->setText(QString());
        recBoxItemText->setText(QCoreApplication::translate("recBoxItem", "\346\216\250\350\215\220-a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recBoxItem: public Ui_recBoxItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOXITEM_H

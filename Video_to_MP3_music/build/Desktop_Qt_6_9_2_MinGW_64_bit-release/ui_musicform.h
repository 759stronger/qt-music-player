/********************************************************************************
** Form generated from reading UI file 'musicform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICFORM_H
#define UI_MUSICFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicForm
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *muscistyle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *musicicon;
    QLabel *musicText;
    QWidget *linebox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *line1;
    QLabel *line2;
    QLabel *line3;
    QLabel *line4;

    void setupUi(QWidget *musicForm)
    {
        if (musicForm->objectName().isEmpty())
            musicForm->setObjectName("musicForm");
        musicForm->resize(200, 35);
        horizontalLayout = new QHBoxLayout(musicForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        muscistyle = new QWidget(musicForm);
        muscistyle->setObjectName("muscistyle");
        muscistyle->setStyleSheet(QString::fromUtf8("#muscistyle:hover\n"
"{\n"
"       background:#D8D8D8;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(muscistyle);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        musicicon = new QLabel(muscistyle);
        musicicon->setObjectName("musicicon");
        musicicon->setMinimumSize(QSize(30, 0));
        musicicon->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(musicicon);

        musicText = new QLabel(muscistyle);
        musicText->setObjectName("musicText");
        musicText->setMinimumSize(QSize(90, 0));
        musicText->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(musicText);

        linebox = new QWidget(muscistyle);
        linebox->setObjectName("linebox");
        linebox->setMinimumSize(QSize(30, 0));
        linebox->setMaximumSize(QSize(30, 45646));
        linebox->setStyleSheet(QString::fromUtf8(".QLabel\n"
"{\n"
"     background-color:#FFFFFF;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(linebox);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        line1 = new QLabel(linebox);
        line1->setObjectName("line1");
        line1->setMinimumSize(QSize(2, 0));
        line1->setMaximumSize(QSize(2, 455));

        horizontalLayout_3->addWidget(line1);

        line2 = new QLabel(linebox);
        line2->setObjectName("line2");
        line2->setMinimumSize(QSize(2, 0));
        line2->setMaximumSize(QSize(2, 545));

        horizontalLayout_3->addWidget(line2);

        line3 = new QLabel(linebox);
        line3->setObjectName("line3");
        line3->setMinimumSize(QSize(2, 0));
        line3->setMaximumSize(QSize(2, 4457));

        horizontalLayout_3->addWidget(line3);

        line4 = new QLabel(linebox);
        line4->setObjectName("line4");
        line4->setMinimumSize(QSize(2, 0));
        line4->setMaximumSize(QSize(2, 457));
        QFont font;
        font.setStrikeOut(false);
        font.setKerning(true);
        line4->setFont(font);

        horizontalLayout_3->addWidget(line4);


        horizontalLayout_2->addWidget(linebox);


        horizontalLayout->addWidget(muscistyle);


        retranslateUi(musicForm);

        QMetaObject::connectSlotsByName(musicForm);
    } // setupUi

    void retranslateUi(QWidget *musicForm)
    {
        musicForm->setWindowTitle(QCoreApplication::translate("musicForm", "Form", nullptr));
        musicicon->setText(QString());
        musicText->setText(QString());
        line1->setText(QString());
        line2->setText(QString());
        line3->setText(QString());
        line4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class musicForm: public Ui_musicForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICFORM_H

/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicSlider
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *outLine;
    QFrame *inLine;

    void setupUi(QWidget *musicSlider)
    {
        if (musicSlider->objectName().isEmpty())
            musicSlider->setObjectName("musicSlider");
        musicSlider->resize(800, 20);
        horizontalLayout = new QHBoxLayout(musicSlider);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        outLine = new QFrame(musicSlider);
        outLine->setObjectName("outLine");
        outLine->setEnabled(true);
        outLine->setMinimumSize(QSize(0, 4));
        outLine->setMaximumSize(QSize(16777215, 4));
        outLine->setStyleSheet(QString::fromUtf8("#outLine\n"
"{\n"
"	background-color:#1ECC94;\n"
"}"));
        outLine->setFrameShape(QFrame::Shape::StyledPanel);
        outLine->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout->addWidget(outLine);

        inLine = new QFrame(musicSlider);
        inLine->setObjectName("inLine");
        inLine->setMinimumSize(QSize(0, 4));
        inLine->setMaximumSize(QSize(4564, 4));
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
"	background-color:#EBEEF5;\n"
"}"));
        inLine->setFrameShape(QFrame::Shape::StyledPanel);
        inLine->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout->addWidget(inLine);


        retranslateUi(musicSlider);

        QMetaObject::connectSlotsByName(musicSlider);
    } // setupUi

    void retranslateUi(QWidget *musicSlider)
    {
        musicSlider->setWindowTitle(QCoreApplication::translate("musicSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class musicSlider: public Ui_musicSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDER_H

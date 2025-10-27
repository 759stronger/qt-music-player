/********************************************************************************
** Form generated from reading UI file 'volumetool.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETOOL_H
#define UI_VOLUMETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_volumeTool
{
public:
    QWidget *volumeWidget;
    QVBoxLayout *verticalLayout;
    QWidget *silderBox;
    QFrame *outSlider;
    QFrame *inSlider;
    QPushButton *sliderBtn;
    QLabel *volumeRatio;
    QPushButton *silenceBtn;

    void setupUi(QWidget *volumeTool)
    {
        if (volumeTool->objectName().isEmpty())
            volumeTool->setObjectName("volumeTool");
        volumeTool->resize(100, 350);
        volumeWidget = new QWidget(volumeTool);
        volumeWidget->setObjectName("volumeWidget");
        volumeWidget->setGeometry(QRect(10, 10, 80, 300));
        volumeWidget->setMinimumSize(QSize(80, 300));
        volumeWidget->setMaximumSize(QSize(80, 300));
        volumeWidget->setStyleSheet(QString::fromUtf8("#volumeWidget\n"
"{\n"
"	background-color:#ffffff;\n"
"	border-radius:5px;\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(volumeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        silderBox = new QWidget(volumeWidget);
        silderBox->setObjectName("silderBox");
        silderBox->setMinimumSize(QSize(0, 225));
        silderBox->setMaximumSize(QSize(16777215, 225));
        outSlider = new QFrame(silderBox);
        outSlider->setObjectName("outSlider");
        outSlider->setGeometry(QRect(38, 25, 4, 180));
        outSlider->setStyleSheet(QString::fromUtf8("#outSlider\n"
"{\n"
"	background-color:#1ECC94;\n"
"}"));
        outSlider->setFrameShape(QFrame::Shape::StyledPanel);
        outSlider->setFrameShadow(QFrame::Shadow::Raised);
        inSlider = new QFrame(silderBox);
        inSlider->setObjectName("inSlider");
        inSlider->setGeometry(QRect(38, 25, 4, 180));
        inSlider->setStyleSheet(QString::fromUtf8("#inSlider\n"
"{\n"
"	 background-color:#ECECEC;\n"
"}"));
        inSlider->setFrameShape(QFrame::Shape::StyledPanel);
        inSlider->setFrameShadow(QFrame::Shadow::Raised);
        sliderBtn = new QPushButton(silderBox);
        sliderBtn->setObjectName("sliderBtn");
        sliderBtn->setGeometry(QRect(33, 20, 14, 14));
        sliderBtn->setMinimumSize(QSize(14, 14));
        sliderBtn->setMaximumSize(QSize(14, 14));
        sliderBtn->setStyleSheet(QString::fromUtf8("#sliderBtn\n"
"{\n"
"	background-color:#1ECC94;\n"
"	border-radius:7px;\n"
"	}"));

        verticalLayout->addWidget(silderBox);

        volumeRatio = new QLabel(volumeWidget);
        volumeRatio->setObjectName("volumeRatio");
        volumeRatio->setMinimumSize(QSize(80, 30));
        volumeRatio->setMaximumSize(QSize(80, 30));
        volumeRatio->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(volumeRatio);

        silenceBtn = new QPushButton(volumeWidget);
        silenceBtn->setObjectName("silenceBtn");
        silenceBtn->setMinimumSize(QSize(80, 45));
        silenceBtn->setMaximumSize(QSize(80, 45));
        silenceBtn->setStyleSheet(QString::fromUtf8("#silenceBtn\n"
"{\n"
"	border:none;\n"
"}\n"
"#silenceBtn:hover\n"
"{\n"
"	background-color:#f0f0f0;\n"
"}\n"
""));

        verticalLayout->addWidget(silenceBtn);


        retranslateUi(volumeTool);

        QMetaObject::connectSlotsByName(volumeTool);
    } // setupUi

    void retranslateUi(QWidget *volumeTool)
    {
        volumeTool->setWindowTitle(QCoreApplication::translate("volumeTool", "Form", nullptr));
        sliderBtn->setText(QString());
        volumeRatio->setText(QString());
        silenceBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class volumeTool: public Ui_volumeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOL_H

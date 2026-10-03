#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>

namespace Ui {
class volumeTool;
}

class volumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit volumeTool(QWidget *parent = nullptr);
    ~volumeTool();

    void paintEvent( QPaintEvent *event  );



    float getVolumeRatio();
    void setVolume();
    void updateUiByVolume(float volume); // <--- 【新增】根据音量更新UI的函数

private slots:

    bool eventFilter(QObject * object , QEvent *event);
    void onSilenceBtnClicked1();


signals:
    void setSilence(bool);
    void setMusicVolume(float);


private:
    Ui::volumeTool *ui;
    bool isMuted;   //是否静音
    float realvolumeRatio; //标记音量大小
};

#endif // VOLUMETOOL_H

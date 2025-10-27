#ifndef MUSICSLIDER_H
#define MUSICSLIDER_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class musicSlider;
}

class musicSlider : public QWidget
{
    Q_OBJECT

public:
    explicit musicSlider(QWidget *parent = nullptr);
    ~musicSlider();

    void setStep(float bf);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void moveSilder();
    void resizeEvent(QResizeEvent *event); // 【新增】用于正确获取宽度



private slots:

signals:
    void setMusicSilderPosition(float);


private:
    Ui::musicSlider *ui;
    int currentPos; // 滑动条当前位置
    int maxWidth;
};

#endif // MUSICSLIDER_H

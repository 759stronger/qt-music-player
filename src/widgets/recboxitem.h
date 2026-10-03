#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class recBoxItem;
}

class recBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit recBoxItem(QWidget *parent = nullptr);
    ~recBoxItem();

    //通过设置鼠标进入和离开的事件  让图片进行上移和恢复的动画
    bool eventFilter(QObject * watched , QEvent * event);

    //设置文本
    void setrecText(const QString& text);
    //设置图片
    void setrecImage(const QString& ImagePath);


private:
    Ui::recBoxItem *ui;
};

#endif // RECBOXITEM_H

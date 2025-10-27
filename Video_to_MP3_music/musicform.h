#ifndef MUSICFORM_H
#define MUSICFORM_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class musicForm;
}

class musicForm : public QWidget
{
    Q_OBJECT

public:
    explicit musicForm(QWidget *parent = nullptr);
    ~musicForm();


    // 设置图标 文字 id
    void seticon(const QString musicicon,const QString content , int PageId);

    int getId();  //获取页面的ID
    void clearBg();  //清除上一个点击页面的背景颜色  恢复成原来的颜色


    void showAnima(bool isshow);   //显示动画效果

signals:
    void musicclick(int PageId);

protected:
    virtual void mousePressEvent(QMouseEvent *event );


private:
    Ui::musicForm *ui;
    int PageId; //对应页面的id

    QPropertyAnimation* animationLine1;
    QPropertyAnimation* animationLine2;
    QPropertyAnimation* animationLine3;
    QPropertyAnimation* animationLine4;

};

#endif // MUSICFORM_H

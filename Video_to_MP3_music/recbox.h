#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>
namespace Ui {
class recBox;
}

class recBox : public QWidget
{
    Q_OBJECT

public:
    explicit recBox(QWidget *parent = nullptr);
    ~recBox();


    void initRecboxui(QJsonArray data , int row);
    void creatRecBoxItem();

private slots:
    void on_leftBtn_clicked();

    void on_rightBtn_clicked();

private:
    Ui::recBox *ui;

    int row ;
    int col;
    QJsonArray imageList; //保存界面上的图片 里面实际为key value 键值对
    int currentIndex;//现在的第几组
    int count;//一共几组图

};

#endif // RECBOX_H

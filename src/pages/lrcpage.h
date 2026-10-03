#ifndef LRCPAGE_H
#define LRCPAGE_H

#include <QWidget>
#include <QIcon>
#include <QPropertyAnimation>
#include <QRect>
#include <Qvector>
#include <QFile>

struct LrcLine
{
    qint64 LrcTime;
    QString LrcText;
    LrcLine(qint64 LrcTime, QString LrcText)
        :LrcTime(LrcTime)
        ,LrcText(LrcText)
    {}
};

namespace Ui {
class LrcPage;
}

class LrcPage : public QWidget
{
    Q_OBJECT

public:
    explicit LrcPage(QWidget *parent = nullptr);
    ~LrcPage();


    //解析歌词
    bool parseLrc(const QString &lrcPath);

    int getLineLrcwordIndex(qint64 pos);
    QString getLineLrcword(qint64 index);
    void showLrcword(int time);

private slots:



private:
    Ui::LrcPage *ui;
    QPropertyAnimation * lrcHideAnimation;
    QVector<LrcLine> lrclines;
};

#endif // LRCPAGE_H

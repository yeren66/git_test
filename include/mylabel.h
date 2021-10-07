#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = 0);
    ~MyLabel();

    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    MyLabel *next;

signals:
    void click(QLabel *);

};

#endif // MYLABEL_H

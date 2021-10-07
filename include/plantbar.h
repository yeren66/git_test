#ifndef PLANTBAR_H
#define PLANTBAR_H
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include "plant.h"
#include <QString>
#include "game.h"

extern int buttonState;
extern Plant* chosenPlant;
extern bool shovel;
extern PlantBar* chosenBar;

class PlantBar : public QLabel
{
    Q_OBJECT

public:
    PlantBar(QWidget *parent = 0);
    PlantBar(Plant *, QWidget *parent = 0);
    ~PlantBar();

    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    int cdtime;
//    Plant *plant = nullptr;

public slots:
    void cd();
    void reload();

signals:
    void click(QLabel *);

private:
    QString plantName;
    QString imagePath;
    QTimer *t_1;
    QLabel *display;
    QLabel *temp;
    int cost;
    int y_;
    int h_;
};

#endif // PLANTBAR_H

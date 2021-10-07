#ifndef BLOCK_H
#define BLOCK_H
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include "plant.h"
#include <QString>
#include "path.h"
#include "plantbar.h"

class Block : public QLabel
{
    Q_OBJECT
    friend class Zombo;
    friend class Plant;

public:
    Block(Path *p, QWidget *parent = 0);
    ~Block();

    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    Path *path;

signals:
    void requestConnect(Plant *plant);
    void changeSun();

public slots:
    void addPlant(Plant *plant);
    void deletePlant(Plant *plant);
    bool whetherPlant();

private:
    Plant *inner;
    Plant *outer;
    int state; // 0->idle, 1->common_plant, 2->defense_plant, 3->both



};




#endif // BLOCK_H

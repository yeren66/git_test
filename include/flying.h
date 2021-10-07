#ifndef FLYING_H
#define FLYING_H

#include <QLabel>
#include <QTimer>
#include <vector>
#include "zombo.h"
#include "path.h"


class Flying : public QLabel
{
    Q_OBJECT

public:
    Flying(int x, int y, int speed, int damage, Path *path, QWidget *parent = 0);
    ~Flying();

public slots:
    void move();

private:
    int x, y;
    int speed; // pass how many pixels in one second
    int damage;
    Path *path;
    QTimer * t_flying;

};


#endif // FLYING_H

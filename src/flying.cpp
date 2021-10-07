#include "flying.h"
#include <QLabel>
#include <QTimer>
#include <vector>
#include "zombo.h"
#include <iostream>
#include "path.h"

Flying::Flying(int x, int y, int speed, int damage, Path *path, QWidget *parent) :
    QLabel(parent)
{
    this->x = x;
    this->y = y;
    this->damage = damage;
    this->speed = 500 / speed;
    this->path = path;
    t_flying = new QTimer(this);
    connect(t_flying, SIGNAL(timeout()), this, SLOT(move()));
}

Flying::~Flying(){
    disconnect(t_flying, SIGNAL(timeout()), this, SLOT(move()));
    delete t_flying;
    path = nullptr;

}

void Flying::move(){
    x += 5;
    setGeometry(x, y, this->width(), this->height());
    for(int i = 0; i < path->v.size(); i++){
        if(x > (path->v[i])->x - 5 && x < (path->v[i])->x + 5){
            (path->v[i])->hitted(damage);
            this->~Flying();
            return;
        }
    }
    if(x > 1400){
        t_flying->stop();
        this->~Flying();
        return;
    }
    t_flying->start(speed);
}


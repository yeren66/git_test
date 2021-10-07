#include "path.h"
#include "block.h"
#include <vector>
#include "zombo.h"
#include "game.h"
#include <iostream>
#include <QTime>


Path::Path(int row, QWidget *parent){
    y += row * interval_y;
    v = std::vector<Zombo*>();
    t_path = new QTimer(this);
    connect(t_path, SIGNAL(timeout()), this, SLOT(startRandomZombo()));
}

Path::~Path(){
    t_path->stop();
    //disconnect(t_path, SIGNAL(timeout()), this, SLOT(startRandomZombo()));
    for(int i = 0; i < 9; i++){
        v_block[i]->~Block();
    }
    std::vector<Zombo*>::iterator it;
    for(it = v.begin(); it != v.end(); it ++){
        (*it)->~Zombo();
        it --;
    }
}

void Path::initial(int number, QWidget *parent){
    for(int i = 0; i < number; i++){
        Block *b = new Block(this, parent);
        b->setParent(parent);
        b->setGeometry(x+interval_x*i, y, 118, 130);
        b->setStyleSheet("QLabel {background-color: rgba(128, 128, 128, 0.1)}");
        b->setVisible(true);
        v_block[i] = b;
    }
}

void Path::addZombo(Zombo *zombo){
    connect(zombo, SIGNAL(zomboWin()), Main, SLOT(relayZomboWin()));
    v.push_back(zombo);
}

void Path::deleteZombo(Zombo *zombo){
    disconnect(zombo, SIGNAL(zomboWin()), Main, SLOT(relayZomboWin()));
    std::vector<Zombo*>::iterator it;
    for(it = v.begin(); it != v.end(); it ++){
        if(*it == zombo){
            v.erase(it);
            break;
        }
    }
}

void Path::startRandomZombo(){
    if(gameTime < 5){
        int interval = (10 + rand() % 20) * 1000;
        t_path->start(interval);
        return;
    }
    Zombo *zombo = new Zombo(this);
    zombo->setParent(Main);
    zombo->setVisible(true);
    addZombo(zombo);
    zombo->move();
    int interval = (10 + rand() % 20) * 1000;
    t_path->start(interval);
}

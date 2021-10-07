#include "zombo.h"
#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QString>
#include "block.h"
#include "path.h"
#include <iostream>

bool zomboWinEvent = false;
Zombo::Zombo(Path *path, QWidget *parent){
    x = path->v_block[8]->x() + 100;
    y = path->v_block[8]->y();
    setParent(parent);
    setGeometry(x, y, 100, 100);
    p = path;
    name = QString("Common Zombo");
    imagePath = ":/Image/src/commonZombo.png";
    setPixmap(imagePath);
    setScaledContents(true);
    workSpeed = 6;
    attackSpeed = 2000;
    healthy = 100;
    damage = 10;
    t_Zombo = new QTimer(this);
    connect(t_Zombo, SIGNAL(timeout()), this, SLOT(move()));
    block = p->v_block[8];
}

Zombo::Zombo(Path *path, QString name, QString imagePath, int workSpeed, int attackSpeed, int healthy, int damage, QWidget *parent){
    x = path->v_block[8]->x() + 100;
    y = path->v_block[8]->y();
    setParent(parent);
    setGeometry(x, y, 100, 100);
    p = path;
    this->name = name;
    this->imagePath = imagePath;
    this->workSpeed = workSpeed;
    this->attackSpeed = attackSpeed;
    this->healthy = healthy;
    this->damage = damage;
    t_Zombo = new QTimer(this);
    connect(t_Zombo, SIGNAL(timeout()), this, SLOT(move()));
    block = p->v_block[8];
}

Zombo::~Zombo(){
    p->deleteZombo(this);
//    std::cout << "zombo was deleted!" <<std::endl;
    t_Zombo->stop();
    p = nullptr;
    block = nullptr;
    disconnect(t_Zombo, SIGNAL(timeout()), this, SLOT(move()));
}

void Zombo::hitted(int damage){
    healthy -= damage;
    if(healthy < 1){
        this->~Zombo();
    }
}

void Zombo::move(){
    if(block->inner == nullptr && block->outer == nullptr){
        x --;
        setGeometry(x, y, this->width(), this->height());
        for(int i = 7; i > -1; i --){
            if(x > p->v_block[i]->x() - 80){
                block = p->v_block[i];
                break;
            }
            if(i == 0)
                block = nullptr;
        }
        if(block == nullptr){
            t_Zombo->stop();
            if(!zomboWinEvent){
                zomboWin();
                zomboWinEvent = true;
            }
            return;
        }
        t_Zombo->start(workSpeed);
    }
    if(block->outer != nullptr){
        attack(block->outer);
        t_Zombo->start(attackSpeed);
    }
    else if (block->inner != nullptr){
        attack(block->inner);
        t_Zombo->start(attackSpeed);
    }
}

void Zombo::attack(Plant *plant){
    plant->hitted(damage);
}

















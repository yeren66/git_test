#include "plant.h"
#include <QLabel>
#include <QTimer>
#include <string>
#include <iostream>
#include "block.h"

Plant::Plant(QWidget *parent):
    QLabel(parent)
{
    b = nullptr;
    name = "Plant";
    imagePath = ":/Image/src/Live2D(1).png";
    plantType = 0;
    cost = 0;
    cdtime = 10;
    healthy = 5;
    replySpeed = 1;
    t_plant = new QTimer(this);
    t_plant->setTimerType(Qt::PreciseTimer);
    this->setVisible(false);
    // connect(t_plant, SIGNAL(timeout()), this, SLOT(ablility()));
}

Plant::Plant(Block *block, QWidget *parent):
    QLabel(parent)
{
    b = block;
    name = "Plant";
    imagePath = ":/Image/src/Live2D(1).png";
    plantType = 0;
    cost = 0;
    cdtime = 10;
    healthy = 5;
    replySpeed = 1;
    t_plant = new QTimer(this);
    t_plant->setTimerType(Qt::PreciseTimer);
    this->setVisible(false);
    connect(t_plant, SIGNAL(timeout()), this, SLOT(ablility()));
}

void Plant::setBlock(Block *block){
    b = block;
}

Plant::~Plant(){
//    disconnect(t_plant, SIGNAL(timeout()), this, SLOT(ablility()));
    t_plant->stop();
    b = nullptr;
}

void Plant::ability(){
    // reload this function to implement the different plant's ability

}

void Plant::hitted(int damage){
    healthy -= damage;
    if(healthy < 1){
        if(plantType == 0){
            b->inner = nullptr;
        }
        else{
            b->outer = nullptr;
        }
        this->~Plant();
    }
}



#include "plant.h"
#include "peashooter.h"
#include <QTimer>
#include <iostream>
#include "block.h"

PeaShooter::PeaShooter(){
    name = "PeaShooter";
    imagePath = ":/Image/src/PeaShooter.png";
    plantType = 0;
    cdtime = 100;
    healthy = 50;
    cost = 100;
    replySpeed = 2000;
    peaSpeed = 20;
    damage = 10;
    connect(t_plant, SIGNAL(timeout()), this, SLOT(ability()));
}


void PeaShooter::ability(){
    shoot(b, peaSpeed, damage, b->path);
//    std::cout << "ability was called" << std::endl;
    t_plant->start(replySpeed);
}

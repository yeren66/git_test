#include "plantbar.h"
#include <QTimer>
#include <iostream>
#include "plant.h"
#include "peashooter.h"
#include <QString>
#include "game.h"
#include "nut.h"

int buttonState = 0;
Plant* chosenPlant = nullptr;
bool shovel = false;
PlantBar* chosenBar = nullptr;

PlantBar::PlantBar(QWidget *parent) : QLabel(parent){
    cdtime = 15000 / this->height();
    plantName = "None";
    imagePath = ":/Image/src/Live2D.png";
    cost = 0;
    display = new QLabel();
    display->setGeometry(0, 0, 30, 30);
    display->setText((QString("%1").arg(cost)));
    display->setVisible(true);
    display->setParent(this);

    this->setPixmap(QPixmap(imagePath));
    t_1 = new QTimer(this);
    connect(t_1, SIGNAL(timeout()), this, SLOT(reload()));

}


PlantBar::PlantBar(Plant *plant, QWidget *parent) : QLabel(parent){
    if(plant == nullptr){
        cdtime = 15000 / this->height();
        plantName = "None";
        imagePath = ":/Image/src/Live2D.png";
        cost = 0;
    }
    else{
        cdtime = 3 * plant->cdtime / this->height();
        plantName = plant->name;
        imagePath = plant->imagePath;
        cost = plant->cost;
    }
    this->setPixmap(QPixmap(imagePath));
    t_1 = new QTimer(this);
    connect(t_1, SIGNAL(timeout()), this, SLOT(reload()));
}

PlantBar::~PlantBar(){
    t_1->stop();
    buttonState = 0;
    chosenBar = nullptr;
    chosenPlant = nullptr;
    shovel = false;
    disconnect(t_1, SIGNAL(timeout()), this, SLOT(reload()));

}

void PlantBar::enterEvent(QEvent *e){
    setStyleSheet("QLabel {background-color: rgba(0, 0, 0, 0.2)}");
}

void PlantBar::leaveEvent(QEvent *e){
    setStyleSheet("QLabel {background-color: transparent;}");
}

void PlantBar::mousePressEvent(QMouseEvent *ev){
    if(buttonState == 1){
        buttonState = 0;
        shovel = false;
        delete chosenPlant;
        chosenPlant = nullptr;
        chosenBar = nullptr;
    }
    if(plantName == "PeaShooter"){
        PeaShooter p;
        if(sunMoney >= p.cost){
            chosenPlant = new PeaShooter();
            buttonState = 1;
            chosenBar = this;
        }
        else{
            std::cout << "sunMoney is less than cost" << std::endl;
        }
    }

    if(plantName == "Nut"){
        Nut n;
        if(sunMoney >= n.cost){
            chosenPlant = new Nut();
            buttonState = 1;
            chosenBar = this;
        }
        else{
            std::cout << "sunMoney is less than cost" << std::endl;
        }
    }
    
    if(plantName == QString("None")){
        chosenPlant = nullptr;
        buttonState = 1;
        shovel = true;
        chosenBar = this;
    }

    std::cout << chosenPlant << std::endl;
}

void PlantBar::mouseMoveEvent(QMouseEvent *ev){

}

void PlantBar::mouseReleaseEvent(QMouseEvent *ev){

}

void PlantBar::cd(){
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    temp = new QLabel();
    temp->setParent(this);
    temp->setStyleSheet("QLabel {background-color: rgba(0, 0, 0, 0.2)}");
//    temp->setGeometry(this->x(), this->y(), this->width(), this->height());
    temp->setVisible(true);
    temp->setGeometry(0, 0, this->width(), this->height());

    y_ = 0;
    h_ = this->height();
    reload();
}

void PlantBar::reload(){

    temp->setGeometry(0, y_, this->width(), h_);
    t_1->start(cdtime);
    y_ += 3;
    h_ -= 3;
    if(h_ < 1){
        setAttribute(Qt::WA_TransparentForMouseEvents, false);
        t_1->stop();
        delete(temp);
        temp = nullptr;
    }
}

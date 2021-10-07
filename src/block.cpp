#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include "plant.h"
#include <QString>
#include "path.h"
#include "block.h"
#include "plantbar.h"
#include <iostream>
#include "game.h"

Block::Block(Path *p, QWidget *parent){
    inner = nullptr;
    outer = nullptr;
    state = 0;
    path = p;
}

Block::~Block(){
    path = nullptr;
    if(inner != nullptr){
        inner->~Plant();
        inner = nullptr;
    }
    if(outer != nullptr){
        outer->~Plant();
        outer = nullptr;
    }
}

void Block::enterEvent(QEvent *e){
    setStyleSheet("QLabel {background-color: rgba(255, 255, 255, 0.2)}");
}

void Block::leaveEvent(QEvent *e){
    setStyleSheet("QLabel {background-color: rgba(128, 128, 128, 0.1)}");
}

void Block::mousePressEvent(QMouseEvent *ev){
    if(buttonState == 0)
        return;
    else{
        buttonState = 0;
        if(chosenPlant != nullptr && !shovel){
            if(chosenPlant->plantType == 0 && inner == nullptr){
                sunMoney -= chosenPlant->cost;
                std::cout << chosenPlant->cost << std::endl;
                changeSun();
                addPlant(chosenPlant);
                chosenPlant->setBlock(this);
                chosenBar->cd();
                inner = chosenPlant;
            }
            else if(chosenPlant->plantType == 1 && outer == nullptr){
                sunMoney -= chosenPlant->cost;
                changeSun();
                addPlant(chosenPlant);
                chosenPlant->setBlock(this);
                chosenBar->cd();
                outer = chosenPlant;
            }
            else{
                std::cout << "cannot plant this plant" << std::endl;
                delete chosenPlant;
                chosenPlant = nullptr;
            }

        }
        else if(shovel){
            shovel = false;
            if(inner != nullptr){
                deletePlant(inner);
            }
            else if (outer != nullptr){
                deletePlant(outer);
            }
            else
                std::cout << "none of plant in this bolck" << std::endl;
        }
        else{
            std::cout << "chosePlant is null" << std::endl;
        }
    }
}

void Block::mouseMoveEvent(QMouseEvent *ev){

}

void Block::mouseReleaseEvent(QMouseEvent *ev){

}

void Block::addPlant(Plant *plant){
    requestConnect(plant);
    plant->setGeometry(0, 0, 100, 100);
    plant->setPixmap(plant->imagePath);
    plant->setParent(this);
    plant->setBlock(this);
    plant->setScaledContents(true);
    plant->setVisible(true);
    plant->ability();
}

void Block::deletePlant(Plant *plant){
    plant->~Plant();
    plant = nullptr;
}

bool Block::whetherPlant(){
    if(inner != nullptr || outer != nullptr){
        return true;
    }
    else
        return false;
}







#include "game.h"
#include "ui_game.h"
#include "plantbar.h"
#include "plant.h"
#include "peashooter.h"
#include <QLabel>
#include <windows.h>
#include <iostream>
#include <QTimer>
#include <QBitmap>
#include "block.h"
#include "flying.h"
#include "path.h"
#include <QImage>
#include <QPalette>
#include "nut.h"

int sunMoney = 5000;
QWidget* Main = nullptr;
int gameTime = 0;

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    startGame();
}

Game::~Game()
{
    std::cout << "~Game" << std::endl;

    delete ui;
}


void Game::changedSun(){
    std::cout << "has changed" << std::endl;
    sun->setText(QString("%1").arg(sunMoney));
}

void Game::timePass(){
    gameTime ++;
    std::cout << gameTime << std::endl;
    if (gameTime == 3 * 60){
        gameJudge->stop();
        humanWin();
        return;
    }
    gameJudge->start(1000);
}

void Game::restartGame(){
    gameTime = 0;
    std::cout << "11111" << std::endl;
    t->stop();
    zomboWinEvent = false;
    gameJudge->stop();
    background->~QLabel();
    sun->~QLabel();
    p_1->~Plant();
    p_2->~Plant();
    bar_1->~PlantBar();
    bar_2->~PlantBar();
    pa_1->~Path();
    pa_2->~Path();
    pa_3->~Path();
    pa_4->~Path();
    pa_5->~Path();
    startGame();
}

void Game::startGame(){
    std::cout << "new Game" << std::endl;
    ui->setupUi(this);
    background = new QLabel();
    background->setParent(this);
    background->setGeometry(0, 0, this->width(), this->height());
    background->setPixmap(QString(":/Image/src/dayScene.jpg"));
    background->setScaledContents(true);
    background->lower();

    Main = this;
    sun = new QLabel(this);
    sun->setText(QString("%1").arg(sunMoney));
    sun->setGeometry(0, 0, 100, 100);
    sun->setVisible(true);

    p_1 = new PeaShooter();
    bar_1 = new PlantBar(p_1, this);
    bar_1->setGeometry(0, 200, 100, 100);
    bar_1->setScaledContents(true);

    p_2 = new Nut();
    bar_2 = new PlantBar(p_2, this);
    bar_2->setGeometry(0, 350, 100, 100);
    bar_2->setScaledContents(true);

    pa_1 = new Path(0, this);
    pa_1->initial(9, this);
    for(int i = 0; i < 9; i ++){
        connect(pa_1->v_block[i], SIGNAL(requestConnect(Plant*)), this, SLOT(respondeConnect(Plant*)));
        connect(pa_1->v_block[i], SIGNAL(changeSun()), this, SLOT(changedSun()));
    }

    pa_2 = new Path(1, this);
    pa_2->initial(9, this);
    for(int i = 0; i < 9; i ++){
        connect(pa_2->v_block[i], SIGNAL(requestConnect(Plant*)), this, SLOT(respondeConnect(Plant*)));
        connect(pa_2->v_block[i], SIGNAL(changeSun()), this, SLOT(changedSun()));
    }

    pa_3 = new Path(2, this);
    pa_3->initial(9, this);
    for(int i = 0; i < 9; i ++){
        connect(pa_3->v_block[i], SIGNAL(requestConnect(Plant*)), this, SLOT(respondeConnect(Plant*)));
        connect(pa_3->v_block[i], SIGNAL(changeSun()), this, SLOT(changedSun()));
    }

    pa_4 = new Path(3, this);
    pa_4->initial(9, this);
    for(int i = 0; i < 9; i ++){
        connect(pa_4->v_block[i], SIGNAL(requestConnect(Plant*)), this, SLOT(respondeConnect(Plant*)));
        connect(pa_4->v_block[i], SIGNAL(changeSun()), this, SLOT(changedSun()));
    }

    pa_5 = new Path(4, this);
    pa_5->initial(9, this);
    for(int i = 0; i < 9; i ++){
        connect(pa_5->v_block[i], SIGNAL(requestConnect(Plant*)), this, SLOT(respondeConnect(Plant*)));
        connect(pa_5->v_block[i], SIGNAL(changeSun()), this, SLOT(changedSun()));
    }


    pa_1->startRandomZombo();
    pa_2->startRandomZombo();
    pa_3->startRandomZombo();
    pa_4->startRandomZombo();
    pa_5->startRandomZombo();

    t = new QTimer(this);
    gameJudge = new QTimer(this);
    connect(gameJudge, SIGNAL(timeout()), this, SLOT(timePass()));
}


void Game::respondeConnect(Plant *plant){
    connect(plant, SIGNAL(shoot(Block*,int,int,Path*)), this, SLOT(addFlying(Block*,int,int,Path*)));
}


void Game::addFlying(Block *b, int speed, int damage, Path *path){
    Flying *flying = new Flying(b->x(), b->y(), speed, damage, path);
    flying->setParent(this);
    flying->setGeometry(b->x() + b->width()/2, b->y() + b->height()/2,
                       30, 30);
    flying->setPixmap(QString(":/Image/src/ball.png"));
    flying->setVisible(true);
    flying->setScaledContents(true);
    flying->move();
}

void Game::relayZomboWin(){
    zomboWin();
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include "start.h"
#include "options.h"
#include <iostream>
#include <QTimer>
#include "zombo.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    pStack = new QStackedWidget(this);
    s = new Start(this);
    o = new Options(this);
    g = new Game(this);

    pStack->addWidget(s);
    pStack->addWidget(o);
    pStack->addWidget(g);
    t_ptr = new QTimer(this);

    connect(s, SIGNAL(change()), this, SLOT(switchPage()));
    connect(o, SIGNAL(change()), this, SLOT(switchPage()));
    connect(o, SIGNAL(gameStart()), g, SLOT(timePass()));
    connect(g, SIGNAL(humanWin()), this, SLOT(returnTrueResult()));
    connect(g, SIGNAL(zomboWin()), this, SLOT(returnFalseResult()));
    connect(t_ptr, SIGNAL(timeout()), this, SLOT(sceneMove()));

    this->setCentralWidget(pStack);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete pStack;
    delete s;
    delete o;
}

void MainWindow::switchPage(){
    int count = pStack->count();
    int index = pStack->currentIndex();
    index ++;
    if(index >= count){
        index = 0;
    }
    std::cout << index << std::endl;
    pStack->setCurrentIndex(index);
}

void MainWindow::returnTrueResult(){
    final = new QLabel();
    final->setParent(this);
    final->setGeometry(1440, 0, 1840, 900);
    final->setVisible(true);
    final->setPixmap(QString(":/Image/src/finalTrueScene.png"));
    nextBtn = new QPushButton();
    nextBtn->setParent(final);
    nextBtn->setGeometry(600, 700, 150, 50);
    nextBtn->setVisible(true);
    nextBtn->setText(QString("Play again!"));
    quitBtn = new QPushButton();
    quitBtn->setParent(final);
    quitBtn->setGeometry(1200, 700, 150, 50);
    quitBtn->setVisible(true);
    quitBtn->setText(QString("quit"));
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(nextBtn_clicked()));
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(quitBtn_clicked()));
    sceneMove();
}

void MainWindow::returnFalseResult(){
    final = new QLabel();
    final->setParent(this);
    final->setGeometry(1440, 0, 1840, 900);
    final->setVisible(true);
    final->setPixmap(QString(":/Image/src/finalFalseScene.png"));
    nextBtn = new QPushButton();
    nextBtn->setParent(final);
    nextBtn->setGeometry(600, 700, 150, 50);
    nextBtn->setVisible(true);
    nextBtn->setText(QString("Play again!"));
    quitBtn = new QPushButton();
    quitBtn->setParent(final);
    quitBtn->setGeometry(1200, 700, 150, 50);
    quitBtn->setVisible(true);
    quitBtn->setText(QString("quit"));
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(nextBtn_clicked()));
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(quitBtn_clicked()));
    sceneMove();
}

void MainWindow::sceneMove(){
    x -= 30;
    final->setGeometry(x, 0, 1840, 900);
    if(x < -250){
        t_ptr->stop();
        switchPage();
        g->restartGame();
//        g->~Game();
//        g->deleteLater();
        return;
    }
    else
        t_ptr->start(30);
}

void MainWindow::quitBtn_clicked(){
    qApp->quit();
}

void MainWindow::nextBtn_clicked(){
//    std::cout << "clicked nextBtn" << std::endl;
    x = 1440;
    final->setVisible(false);
    final->~QLabel();
    nextBtn = nullptr;
    quitBtn = nullptr;
    final = nullptr;
}

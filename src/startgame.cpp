#include "startgame.h"
#include <QWidget>
#include <QMainWindow>

StartGame::StartGame(MainWindow *m):
    //QWidget(m),
    frame(new StartGame(m))
{
    m->setCentralWidget(frame);
}

StartGame::~StartGame(){
    delete frame;
}

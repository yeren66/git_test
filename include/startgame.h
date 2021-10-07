#ifndef STARTGAME_H
#define STARTGAME_H
#include <QWidget>
#include "mainwindow.h"

class StartGame: public QWidget{

    Q_OBJECT

public:
    explicit StartGame(MainWindow *m);
    ~StartGame();
private:
    StartGame *frame;
};

#endif // STARTGAME_H

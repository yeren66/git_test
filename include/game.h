#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "block.h"
#include "path.h"
#include <QPaintEvent>

extern int sunMoney;
extern QWidget* Main;
extern int gameTime;

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT
    friend class Path;

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

signals:
    void humanWin();
    void zomboWin();

public slots:
    void respondeConnect(Plant *plant);
    void addFlying(Block *b, int speed, int damage, Path *path);
    void relayZomboWin();
    void changedSun();
    void timePass();
    void restartGame();
    void startGame();

private:
    Ui::Game *ui;
    int x;
    int y;

    QTimer *t;
    QLabel *privous = nullptr;
    QLabel *present = nullptr;
    QTimer *gameJudge;
    QLabel *background;
    QLabel *sun;
    Plant *p_1, *p_2;
    PlantBar *bar_1, *bar_2;
    Path *pa_1, *pa_2, *pa_3, *pa_4, *pa_5;

};

#endif // GAME_H

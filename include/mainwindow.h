#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "start.h"
#include "options.h"
#include "game.h"
#include <QTimer>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void switchPage();
    void returnTrueResult();
    void returnFalseResult();
    void sceneMove();
    void quitBtn_clicked();
    void nextBtn_clicked();

private:
    Ui::MainWindow *ui;
    QStackedWidget *pStack;
    Start *s;
    Options *o;
    Game *g;
    QTimer *t_ptr;
    QLabel *final;
    QPushButton *nextBtn;
    QPushButton *quitBtn;
    int x = 1440;
};

#endif // MAINWINDOW_H

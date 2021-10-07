#include "mainwindow.h"
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <qtextedit.h>
#include <iostream>
#include <windows.h>
#include "start.h"
#include "options.h"
#include <QStackedWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();
    return a.exec();
}

#include "start.h"
#include "ui_start.h"
#include <QStackedWidget>
#include <iostream>

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

}

Start::~Start()
{
    delete ui;
}


void Start::on_pushButton_clicked()
{
    std::cout << "clicked" << std::endl;
    emit change();
}



#ifndef ZOMBO_H
#define ZOMBO_H
#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QString>
#include "block.h"
#include "path.h"
#include "plant.h"

extern bool zomboWinEvent;
class Zombo : public QLabel
{
    Q_OBJECT
    friend class Flying;

public:
    Zombo(Path *path, QWidget *parent = 0);
    Zombo(Path *path, QString name, QString imagePath, int workSpeed, int attackSpeed, int healthy, int damage, QWidget *parent = 0);
    ~Zombo();
    int workSpeed;
    int attackSpeed;

signals:
    void zomboWin();

public slots:
    void hitted(int);
    void move();
    void attack(Plant* plant);

protected:
    int x, y;
    QString name;
    QString imagePath;

    int healthy;
    int damage;
    Path *p;
    QTimer *t_Zombo;
    Block *block = nullptr;
};


#endif // ZOMBO_H

#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "plant.h"
#include <QTimer>
#include <QLabel>

class PeaShooter : public Plant
{
    Q_OBJECT
    
public:
    PeaShooter();
    
public slots:
    void ability();

private:
    int peaSpeed;
    int damage;
};




#endif // PEASHOOTER_H

#ifndef PLANT_H
#define PLANT_H

#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QString>


class Block;
class Path;
class PlantBar;

class Plant : public QLabel
{
    Q_OBJECT
    friend class PlantBar;
    friend class Block;

public:
    explicit Plant(QWidget *parent = 0);
    explicit Plant(Block *, QWidget *parent = 0);
    void setBlock(Block *block);
    ~Plant();
    
signals:
    void shoot(Block*, int, int, Path*);

public slots:
    void hitted(int);
    virtual void ability();

protected:
    QString name;
    QString imagePath;
    int plantType; // 0->inner, 1->outer
    int cost;
    int cdtime;
    int healthy;
    int replySpeed;
    QTimer *t_plant;
    Block *b;

};

#endif // PLANT_H

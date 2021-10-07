#ifndef PATH_H
#define PATH_H
#include <vector>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <cstdlib>

class Block;
class Zombo;


class Path : public QLabel{
    Q_OBJECT

public:
    Path(int row, QWidget *parent);
    ~Path();
    void initial(int number, QWidget *parent);
    void addZombo(Zombo *zombo);
    void deleteZombo(Zombo *zombo);
    Block *v_block[9];
    std::vector<Zombo*> v;

public slots:
    void startRandomZombo();

private:
    int x = 300;
    int y = 125;
    int interval_x = 120;
    int interval_y = 145;
    QTimer *t_path;

};

#endif // PATH_H

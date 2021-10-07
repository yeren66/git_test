#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_dayBtn_clicked();

signals:
    void change();
    void gameStart();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H

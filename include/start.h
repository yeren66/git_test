#ifndef START_H
#define START_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private slots:
    void on_pushButton_clicked();

signals:
    void change();

private:
    Ui::Start *ui;
};

#endif // START_H

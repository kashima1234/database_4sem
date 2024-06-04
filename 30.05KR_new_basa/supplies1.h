#ifndef SUPPLIES1_H
#define SUPPLIES1_H

#include <QMainWindow>

namespace Ui {
class supplies1;
}

class supplies1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit supplies1(QWidget *parent = nullptr);
    ~supplies1();

private:
    Ui::supplies1 *ui;
};

#endif // SUPPLIES1_H

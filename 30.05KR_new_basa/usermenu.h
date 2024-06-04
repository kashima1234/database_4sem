#ifndef USERMENU_H
#define USERMENU_H

#include <QMainWindow>

namespace Ui {
class usermenu;
}

class usermenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit usermenu(QWidget *parent = nullptr);
    ~usermenu();

public slots:
void on_btnOrders_clicked();
void on_btnReg_clicked();
void on_btnClose_clicked();
void on_btnGoods_clicked();
void on_btnBack_clicked();

private:
    Ui::usermenu *ui;
};

#endif // USERMENU_H

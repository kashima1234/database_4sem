#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>

namespace Ui {
class adminmenu;
}

class adminmenu : public QDialog
{
    Q_OBJECT

public:
    adminmenu(QWidget *parent = nullptr);
    ~adminmenu();

public slots:
void on_btnCustomers_clicked();
void on_btnEmployees_clicked();
void on_btnOrders_clicked();
void on_btnSupplies_clicked();
void on_btnProviders_clicked();
void on_btnClose_clicked();
void on_btnBack_clicked();
private:
    Ui::adminmenu *ui;
};

#endif // ADMINMENU_H

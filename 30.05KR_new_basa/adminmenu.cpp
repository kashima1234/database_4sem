#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "mainwindow.h"
#include "employees.h"
#include "adminorders.h"
#include "supplies.h"
#include "providers.h"
#include "auth1.h"

adminmenu::adminmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminmenu)
{
    ui->setupUi(this);
}

adminmenu::~adminmenu()
{
    delete ui;
}

void adminmenu::on_btnCustomers_clicked()
{
    this->close();
    MainWindow *mw = new MainWindow(this);
    mw->show();
}

void adminmenu::on_btnEmployees_clicked()
{
    this->close();
    employees *em = new employees(this);
    em->show();
}

void adminmenu::on_btnOrders_clicked()
{
    this->close();
    adminorders *ema = new adminorders(this);
    ema->show();
}

void adminmenu::on_btnSupplies_clicked()
{
    this->close();
    supplies *emaz = new supplies(this);
    emaz->show();
}
void adminmenu::on_btnProviders_clicked()
{
    this->close();
    providers *emaaz = new providers(this);
    emaaz->show();
}
void adminmenu::on_btnBack_clicked()
{
    this->close();
    auth1 *emaaz = new auth1(this);
    emaaz->show();
}

void adminmenu::on_btnClose_clicked()
{
    this->close();
}

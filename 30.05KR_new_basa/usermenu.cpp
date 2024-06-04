#include "usermenu.h"
#include "ui_usermenu.h"
#include "myorders.h"
#include "reg.h"
#include "order.h"
#include "auth1.h"

usermenu::usermenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usermenu)
{
    ui->setupUi(this);
}

usermenu::~usermenu()
{
    delete ui;
}


void usermenu::on_btnOrders_clicked()
{
    this->close();
    myorders *mwaaa = new myorders(this);
    mwaaa->show();
}

void usermenu::on_btnReg_clicked()
{
    this->close();
    reg *mwaaaa = new reg(this);
    mwaaaa->show();
}


void usermenu::on_btnGoods_clicked()
{
    this->close();
    order *mwaaaa = new order(this);
    mwaaaa->show();
}

void usermenu::on_btnBack_clicked()
{
    this->close();
    auth1 *emaaz = new auth1(this);
    emaaz->show();
}

void usermenu::on_btnClose_clicked()
{
    this->close();
}

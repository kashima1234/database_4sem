#include "supplies1.h"
#include "ui_supplies1.h"

supplies1::supplies1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::supplies1)
{
    ui->setupUi(this);
}

supplies1::~supplies1()
{
    delete ui;
}

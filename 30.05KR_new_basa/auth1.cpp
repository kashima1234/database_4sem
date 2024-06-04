#include "auth1.h"
#include "ui_auth1.h"
#include "adminmenu.h"
#include "usermenu.h"
#include <QMessageBox>
#include <QMessageBox>

auth1::auth1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth1)
{
    ui->setupUi(this);
}

auth1::~auth1()
{
    delete ui;
}


void auth1::on_btnEnter_clicked()
{
    QString login = ui->leLogin->text();
        QString password = ui->lePassword->text();
        if(login=="ahmed" && password=="kashima"){
            this->close();
            adminmenu *mw = new adminmenu(this);
            mw->show();
        } else if(login=="kashima" && password=="ahmed"){
            this->close();
            usermenu *mw = new usermenu(this);
            mw->show();
        } else {
            QMessageBox::warning(this,"Ошибка","Неверный логин или пароль");
        }
}

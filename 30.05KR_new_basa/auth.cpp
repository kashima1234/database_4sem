#include "auth.h"
#include "ui_auth.h"
#include "adminmenu.h"
#include "usermenu.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

auth::auth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::auth)
{

    ui->setupUi(this);
        m_errorLabel = new QLabel();
        m_errorLabel->setStyleSheet("QLabel { color : red; }");
        ui->lePassword->setEchoMode(QLineEdit::Password);
}

auth::~auth()
{
    delete ui;
}


void auth::on_btnEnter_clicked()
{
    QString login = ui->leLogin->text();
        QString password = ui->lePassword->text();
        if(login=="admin" && password=="111"){
            this->close();
            adminmenu *mw = new adminmenu(this);
            mw->show();
        } else if(login=="guest" && password=="222"){
            this->close();
            usermenu *mw = new usermenu(this);
            mw->show();
        } else {
            QMessageBox::warning(this,"Ошибка","Неверный логин или пароль");
        }
}

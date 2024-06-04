#ifndef PROVIDERS_H
#define PROVIDERS_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class providers; }
QT_END_NAMESPACE

class providers : public QMainWindow
{
    Q_OBJECT

public:
     providers(QWidget *parent = nullptr);
     void loadAuthros();
    ~providers();

public slots:
void dbconnect();
void selectAll();
void selectAll1();
void Clearr();
void add();
void add1();
void del();
void del1();
void edit();
void edit1();
void on_btnMenu_clicked();
void on_btnEdit1_clicked();
void on_btnEdit1_3_clicked();

private slots:
void on_btnSeaB_clicked();

void on_btnSeaK_clicked();

void on_comboBox_activated(const QString &arg1);

private:
    Ui::providers *ui;
    QSqlDatabase dbconn;
};

#endif // PROVIDERS_H

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class employees; }
QT_END_NAMESPACE

class employees : public QMainWindow
{
    Q_OBJECT

public:
    employees(QWidget *parent = nullptr);
    ~employees();

public slots:
    void dbconnect();
    void selectAll();
    void Clearr();
    void add();
    void del();
    void edit();
    void on_btnMenu_clicked();
    void search();
    void on_btnEdit1_clicked();
    void filterByBirthDate();
    void filterByBirthAndDeathDates();


private:
    Ui::employees *ui;
    QSqlDatabase dbconn;
};

#endif // EMPLOYEES_H

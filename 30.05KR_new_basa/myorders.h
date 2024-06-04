#ifndef MYORDERS_H
#define MYORDERS_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class myorders; }
QT_END_NAMESPACE


class myorders : public QMainWindow
{
    Q_OBJECT

public:
     myorders(QWidget *parent = nullptr);
    ~myorders();

public slots:
    void search();
    // void search2();
    // void search3();
   // void on_btnMenu_clicked();
    void dbconnect();

private slots:
    void on_btnMenu_clicked();

private:
    Ui::myorders *ui;
    QSqlDatabase dbconn;

};

#endif // MYORDERS_H

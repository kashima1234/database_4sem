//#ifndef WIDGET_H
//#define WIDGET_H

//#include <QWidget>
//#include <QSqlDatabase>

//namespace Ui {
//class Widget;

//}

//class Widget : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit Widget(QWidget *parent = 0);
//    void dbconnect();
//    ~Widget();


//private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_login_clicked();



//private:
//    Ui::Widget *ui;

//    QSqlDatabase dbconn;
//};

//#endif // WIDGET_H


#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QTableWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_login_clicked();
    void dbconnect();
    void selectAll(); // Declaration of selectAll()]
    void add();
    void del();
    void edit();
    void selectedItem(QTableWidgetItem*);

private:
    void loadSingleAbbr(QString);

private:
    Ui::Widget *ui;
    QSqlDatabase dbconn;
};

#endif // WIDGET_H

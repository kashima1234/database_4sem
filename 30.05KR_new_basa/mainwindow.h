#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
void dbconnect();
void selectAll();
void Clearr();
void add();
void del();
void edit();
void search();
void on_btnMenu_clicked();
void on_btnEdit1_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase dbconn;
};


#endif // MAINWINDOW_H

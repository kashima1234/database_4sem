#ifndef SUPPLIES_H
#define SUPPLIES_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class supplies; }
QT_END_NAMESPACE

class supplies : public QMainWindow
{
    Q_OBJECT

public:
    supplies(QWidget *parent = nullptr);
    ~supplies();

public slots:
    void selectAll();
    void on_btnMenu_clicked();
    void dbconnect();
    void search();

private slots:
    void on_btnSea_clicked();

    void on_btnSelectAll_2_clicked();

private:
    Ui::supplies *ui;
    QSqlDatabase dbconn;
};

#endif // SUPPLIES_H

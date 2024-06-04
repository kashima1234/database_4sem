#ifndef ORDER_H
#define ORDER_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class order; }
QT_END_NAMESPACE
class order : public QMainWindow
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
    ~order();

    public slots:
void dbconnect();
void selectAll();
void on_btnMenu_clicked();
void add();
void on_btnEdit_1_clicked();
void on_btnEdit_clicked();

private slots:





void on_recordFilterBtn_clicked();

private:
    Ui::order *ui;
    QSqlDatabase dbconn;
};

#endif // ORDER_H

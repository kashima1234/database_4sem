#ifndef supply_H
#define supply_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class supply; }
QT_END_NAMESPACE

class supply : public QMainWindow
{
    Q_OBJECT

public:
    supply(QWidget *parent = nullptr);
    ~supply();

public slots:
    void selectAll();
    void on_btnMenu_clicked();
    void dbconnect();
private:
    Ui::supply *ui;
    QSqlDatabase dbconn;
};

#endif // supply_H

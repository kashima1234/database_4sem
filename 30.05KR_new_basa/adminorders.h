#ifndef ADMINORDERS_H
#define ADMINORDERS_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class adminorders; }
QT_END_NAMESPACE

class adminorders : public QMainWindow
{
    Q_OBJECT

public:
    adminorders(QWidget *parent = nullptr);
    ~adminorders();

public slots:
    void selectAll();
    void on_btnMenu_clicked();
    void dbconnect();
private:
    Ui::adminorders *ui;
    QSqlDatabase dbconn;
};

#endif // ADMINORDERS_H

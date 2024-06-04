#ifndef REG_H
#define REG_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class reg; }
QT_END_NAMESPACE

class reg : public QMainWindow
{
    Q_OBJECT

public:
     reg(QWidget *parent = nullptr);
    ~reg();

public slots:
void dbconnect();
void add();
void on_btnMenu_clicked();
void search();
private:
    Ui::reg *ui;
    QSqlDatabase dbconn;

};

#endif // REG_H

#ifndef AUTH1_H
#define AUTH1_H

#include <QDialog>

namespace Ui {
class auth1;
}

class auth1 : public QDialog
{
    Q_OBJECT

public:
    explicit auth1(QWidget *parent = nullptr);
    ~auth1();

public slots:
    void on_btnEnter_clicked();
private:
    Ui::auth1 *ui;
};

#endif // AUTH1_H

#include "mainwindow.h"
#include "usermenu.h"
#include "auth1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auth1 w;
    w.show();
    return a.exec();
}

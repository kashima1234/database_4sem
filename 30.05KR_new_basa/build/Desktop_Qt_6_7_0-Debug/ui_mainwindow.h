/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnSelectAll;
    QFrame *frame;
    QTextEdit *leYea;
    QPushButton *btnEdit1;
    QPushButton *btnEdit;
    QLineEdit *leTit;
    QLabel *lbFIO;
    QLabel *lbAdress;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QTextEdit *teResult;
    QTableWidget *twCustomers;
    QPushButton *btnClear;
    QLabel *lbID_2;
    QLabel *lbID_3;
    QLabel *lbID_5;
    QLineEdit *leSearch;
    QPushButton *btnSearch;
    QLabel *lbFIO_2;
    QPushButton *btnConnect;
    QPushButton *btnMenu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1189, 660);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(580, 84, 201, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 120, 341, 341));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        leYea = new QTextEdit(frame);
        leYea->setObjectName("leYea");
        leYea->setGeometry(QRect(90, 50, 221, 101));
        leYea->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
"\n"
"\n"
""));
        btnEdit1 = new QPushButton(frame);
        btnEdit1->setObjectName("btnEdit1");
        btnEdit1->setGeometry(QRect(10, 220, 151, 31));
        btnEdit1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit = new QPushButton(frame);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(170, 220, 151, 31));
        btnEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leTit = new QLineEdit(frame);
        leTit->setObjectName("leTit");
        leTit->setGeometry(QRect(90, 20, 221, 25));
        leTit->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbFIO = new QLabel(frame);
        lbFIO->setObjectName("lbFIO");
        lbFIO->setGeometry(QRect(10, 20, 71, 21));
        lbAdress = new QLabel(frame);
        lbAdress->setObjectName("lbAdress");
        lbAdress->setGeometry(QRect(10, 50, 71, 16));
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(10, 180, 151, 31));
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnDel = new QPushButton(frame);
        btnDel->setObjectName("btnDel");
        btnDel->setGeometry(QRect(170, 180, 151, 31));
        btnDel->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(430, 260, 1081, 61));
        teResult->setReadOnly(true);
        twCustomers = new QTableWidget(centralwidget);
        twCustomers->setObjectName("twCustomers");
        twCustomers->setGeometry(QRect(360, 120, 811, 341));
        twCustomers->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(480, 84, 89, 31));
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID_2 = new QLabel(centralwidget);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(360, 70, 111, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_2->setFont(font);
        lbID_3 = new QLabel(centralwidget);
        lbID_3->setObjectName("lbID_3");
        lbID_3->setGeometry(QRect(0, 70, 161, 41));
        lbID_3->setFont(font);
        lbID_5 = new QLabel(centralwidget);
        lbID_5->setObjectName("lbID_5");
        lbID_5->setGeometry(QRect(0, 0, 171, 51));
        lbID_5->setFont(font);
        leSearch = new QLineEdit(centralwidget);
        leSearch->setObjectName("leSearch");
        leSearch->setGeometry(QRect(90, 50, 241, 25));
        leSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leSearch->setReadOnly(false);
        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(240, 14, 89, 31));
        btnSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbFIO_2 = new QLabel(centralwidget);
        lbFIO_2->setObjectName("lbFIO_2");
        lbFIO_2->setGeometry(QRect(10, 50, 67, 17));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName("btnConnect");
        btnConnect->setGeometry(QRect(570, 220, 111, 25));
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(790, 84, 89, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        btnConnect->raise();
        frame->raise();
        btnSelectAll->raise();
        teResult->raise();
        twCustomers->raise();
        btnClear->raise();
        lbID_2->raise();
        lbID_3->raise();
        lbID_5->raise();
        leSearch->raise();
        btnSearch->raise();
        lbFIO_2->raise();
        btnMenu->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1189, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\320\265 \320\270\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\260", nullptr));
        btnEdit1->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        lbFIO->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lbAdress->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 ", nullptr));
        lbID_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", nullptr));
        lbID_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        lbID_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        lbFIO_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        btnMenu->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

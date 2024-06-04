/********************************************************************************
** Form generated from reading UI file 'myorders.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYORDERS_H
#define UI_MYORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_myorders
{
public:
    QWidget *centralwidget;
    QLineEdit *leSearch;
    QPushButton *btnSelectAll;
    QTableWidget *two;
    QPushButton *btnMenu;
    QTextEdit *teResult;
    QLabel *label_2;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myorders)
    {
        if (myorders->objectName().isEmpty())
            myorders->setObjectName("myorders");
        myorders->resize(800, 422);
        myorders->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(myorders);
        centralwidget->setObjectName("centralwidget");
        leSearch = new QLineEdit(centralwidget);
        leSearch->setObjectName("leSearch");
        leSearch->setGeometry(QRect(220, 30, 241, 25));
        leSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(480, 24, 89, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        two = new QTableWidget(centralwidget);
        two->setObjectName("two");
        two->setGeometry(QRect(20, 120, 771, 211));
        two->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(700, 10, 89, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(50, 210, 104, 70));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 191, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 10, 151, 21));
        myorders->setCentralWidget(centralwidget);
        teResult->raise();
        btnSelectAll->raise();
        two->raise();
        btnMenu->raise();
        label_2->raise();
        label_4->raise();
        leSearch->raise();
        menubar = new QMenuBar(myorders);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        myorders->setMenuBar(menubar);
        statusbar = new QStatusBar(myorders);
        statusbar->setObjectName("statusbar");
        myorders->setStatusBar(statusbar);

        retranslateUi(myorders);

        QMetaObject::connectSlotsByName(myorders);
    } // setupUi

    void retranslateUi(QMainWindow *myorders)
    {
        myorders->setWindowTitle(QCoreApplication::translate("myorders", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("myorders", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        btnMenu->setText(QCoreApplication::translate("myorders", "\320\234\320\265\320\275\321\216", nullptr));
        label_2->setText(QCoreApplication::translate("myorders", "<html><head/><body><p align=\"center\">\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\272\320\275\320\270\320\263\320\270 \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("myorders", "<html><head/><body><p align=\"center\">\320\244\320\260\320\274\320\270\320\273\320\270\321\217 \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myorders: public Ui_myorders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDERS_H

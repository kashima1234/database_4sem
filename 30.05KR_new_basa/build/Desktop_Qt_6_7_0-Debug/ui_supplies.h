/********************************************************************************
** Form generated from reading UI file 'supplies.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIES_H
#define UI_SUPPLIES_H

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

class Ui_supplies
{
public:
    QWidget *centralwidget;
    QPushButton *btnMenu;
    QTableWidget *twotchet;
    QLabel *lbID_2;
    QPushButton *btnSelectAll;
    QTextEdit *teResult;
    QLineEdit *leSea;
    QPushButton *btnSea;
    QLineEdit *minCount;
    QLineEdit *maxCount;
    QPushButton *btnSelectAll_2;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *supplies)
    {
        if (supplies->objectName().isEmpty())
            supplies->setObjectName("supplies");
        supplies->resize(1414, 600);
        supplies->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(supplies);
        centralwidget->setObjectName("centralwidget");
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(520, 50, 121, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        twotchet = new QTableWidget(centralwidget);
        twotchet->setObjectName("twotchet");
        twotchet->setGeometry(QRect(2, 100, 1401, 421));
        twotchet->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        lbID_2 = new QLabel(centralwidget);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(0, -10, 1411, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_2->setFont(font);
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(380, 50, 121, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(160, 200, 104, 70));
        leSea = new QLineEdit(centralwidget);
        leSea->setObjectName("leSea");
        leSea->setGeometry(QRect(10, 50, 161, 31));
        leSea->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnSea = new QPushButton(centralwidget);
        btnSea->setObjectName("btnSea");
        btnSea->setGeometry(QRect(180, 50, 181, 31));
        btnSea->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        minCount = new QLineEdit(centralwidget);
        minCount->setObjectName("minCount");
        minCount->setGeometry(QRect(730, 50, 91, 31));
        minCount->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        maxCount = new QLineEdit(centralwidget);
        maxCount->setObjectName("maxCount");
        maxCount->setGeometry(QRect(900, 50, 91, 31));
        maxCount->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnSelectAll_2 = new QPushButton(centralwidget);
        btnSelectAll_2->setObjectName("btnSelectAll_2");
        btnSelectAll_2->setGeometry(QRect(1010, 50, 121, 31));
        btnSelectAll_2->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(660, 60, 54, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 60, 54, 17));
        supplies->setCentralWidget(centralwidget);
        teResult->raise();
        btnMenu->raise();
        twotchet->raise();
        lbID_2->raise();
        btnSelectAll->raise();
        leSea->raise();
        btnSea->raise();
        minCount->raise();
        maxCount->raise();
        btnSelectAll_2->raise();
        label->raise();
        label_2->raise();
        menubar = new QMenuBar(supplies);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1414, 22));
        supplies->setMenuBar(menubar);
        statusbar = new QStatusBar(supplies);
        statusbar->setObjectName("statusbar");
        supplies->setStatusBar(statusbar);

        retranslateUi(supplies);

        QMetaObject::connectSlotsByName(supplies);
    } // setupUi

    void retranslateUi(QMainWindow *supplies)
    {
        supplies->setWindowTitle(QCoreApplication::translate("supplies", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\272\320\275\320\270\320\263\320\260\320\274 \320\270 \320\260\320\262\321\202\320\276\321\200\320\260\320\274", nullptr));
        btnMenu->setText(QCoreApplication::translate("supplies", "\320\234\320\265\320\275\321\216", nullptr));
        lbID_2->setText(QCoreApplication::translate("supplies", "<html><head/><body><p align=\"center\">\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\272\320\275\320\270\320\263\320\260\320\274 \320\270 \320\260\320\262\321\202\320\276\321\200\320\260\320\274</p></body></html>", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("supplies", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\276\321\202\321\207\320\265\321\202", nullptr));
        btnSea->setText(QCoreApplication::translate("supplies", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \321\204\320\260\320\274\320\270\320\273\320\270\320\270", nullptr));
        btnSelectAll_2->setText(QCoreApplication::translate("supplies", "\320\244\320\270\320\273\321\214\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("supplies", "\320\234\320\270\320\275_\320\272\320\276\320\273", nullptr));
        label_2->setText(QCoreApplication::translate("supplies", "\320\234\320\260\320\272\321\201_\320\272\320\276\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class supplies: public Ui_supplies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIES_H

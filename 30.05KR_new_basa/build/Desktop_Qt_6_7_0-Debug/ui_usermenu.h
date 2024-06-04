/********************************************************************************
** Form generated from reading UI file 'usermenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMENU_H
#define UI_USERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usermenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnOrders;
    QPushButton *btnReg;
    QPushButton *btnGoods;
    QPushButton *btnBack;
    QPushButton *btnClose;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *usermenu)
    {
        if (usermenu->objectName().isEmpty())
            usermenu->setObjectName("usermenu");
        usermenu->resize(800, 435);
        usermenu->setAutoFillBackground(false);
        usermenu->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(usermenu);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, -30, 951, 131));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu Condensed")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 771, 41));
        label_2->setStyleSheet(QString::fromUtf8(""));
        btnOrders = new QPushButton(centralwidget);
        btnOrders->setObjectName("btnOrders");
        btnOrders->setGeometry(QRect(250, 110, 291, 41));
        btnOrders->setAutoFillBackground(false);
        btnOrders->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnReg = new QPushButton(centralwidget);
        btnReg->setObjectName("btnReg");
        btnReg->setGeometry(QRect(250, 170, 291, 41));
        btnReg->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnGoods = new QPushButton(centralwidget);
        btnGoods->setObjectName("btnGoods");
        btnGoods->setGeometry(QRect(250, 230, 291, 41));
        btnGoods->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnBack = new QPushButton(centralwidget);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(80, 320, 291, 41));
        btnBack->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(440, 320, 291, 41));
        btnClose->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        usermenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(usermenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        usermenu->setMenuBar(menubar);
        statusbar = new QStatusBar(usermenu);
        statusbar->setObjectName("statusbar");
        usermenu->setStatusBar(statusbar);

        retranslateUi(usermenu);

        QMetaObject::connectSlotsByName(usermenu);
    } // setupUi

    void retranslateUi(QMainWindow *usermenu)
    {
        usermenu->setWindowTitle(QCoreApplication::translate("usermenu", "\320\234\320\265\320\275\321\216 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260\321\200\321\217", nullptr));
        label->setText(QCoreApplication::translate("usermenu", "<html><head/><body><p><span style=\" font-size:20pt;\">\320\222\321\213 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\320\273\320\270\321\201\321\214 \320\272\320\260\320\272 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260\321\200\321\214</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("usermenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-style:italic;\">\320\234\320\265\320\275\321\216</span></p></body></html>", nullptr));
        btnOrders->setText(QCoreApplication::translate("usermenu", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));
        btnReg->setText(QCoreApplication::translate("usermenu", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265", nullptr));
        btnGoods->setText(QCoreApplication::translate("usermenu", "\320\227\320\260\320\277\320\270\321\201\320\270", nullptr));
        btnBack->setText(QCoreApplication::translate("usermenu", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        btnClose->setText(QCoreApplication::translate("usermenu", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usermenu: public Ui_usermenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMENU_H

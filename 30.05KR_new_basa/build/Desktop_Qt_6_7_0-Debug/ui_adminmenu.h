/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminmenu
{
public:
    QLabel *label;
    QPushButton *btnCustomers;
    QPushButton *btnEmployees;
    QPushButton *btnProviders;
    QPushButton *btnSupplies;
    QPushButton *btnBack;
    QLabel *label_2;
    QPushButton *btnClose;

    void setupUi(QWidget *adminmenu)
    {
        if (adminmenu->objectName().isEmpty())
            adminmenu->setObjectName("adminmenu");
        adminmenu->resize(966, 465);
        adminmenu->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);"));
        label = new QLabel(adminmenu);
        label->setObjectName("label");
        label->setGeometry(QRect(10, -40, 951, 131));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu Condensed")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        btnCustomers = new QPushButton(adminmenu);
        btnCustomers->setObjectName("btnCustomers");
        btnCustomers->setGeometry(QRect(330, 310, 291, 41));
        btnCustomers->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));
        btnEmployees = new QPushButton(adminmenu);
        btnEmployees->setObjectName("btnEmployees");
        btnEmployees->setGeometry(QRect(330, 130, 291, 41));
        btnEmployees->setAutoFillBackground(false);
        btnEmployees->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));
        btnProviders = new QPushButton(adminmenu);
        btnProviders->setObjectName("btnProviders");
        btnProviders->setGeometry(QRect(330, 190, 291, 41));
        btnProviders->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));
        btnSupplies = new QPushButton(adminmenu);
        btnSupplies->setObjectName("btnSupplies");
        btnSupplies->setGeometry(QRect(330, 250, 291, 41));
        btnSupplies->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));
        btnBack = new QPushButton(adminmenu);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(100, 390, 291, 41));
        btnBack->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));
        label_2 = new QLabel(adminmenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 80, 221, 41));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        btnClose = new QPushButton(adminmenu);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(580, 390, 291, 41));
        btnClose->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);"));

        retranslateUi(adminmenu);

        QMetaObject::connectSlotsByName(adminmenu);
    } // setupUi

    void retranslateUi(QWidget *adminmenu)
    {
        adminmenu->setWindowTitle(QCoreApplication::translate("adminmenu", "\320\234\320\265\320\275\321\216 \320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("adminmenu", "<html><head/><body><p><span style=\" font-size:20pt;\">\320\222\321\213 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\320\273\320\270\321\201\321\214 \320\272\320\260\320\272 \320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200.</span></p></body></html>", nullptr));
        btnCustomers->setText(QCoreApplication::translate("adminmenu", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        btnEmployees->setText(QCoreApplication::translate("adminmenu", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        btnProviders->setText(QCoreApplication::translate("adminmenu", "\320\232\320\275\320\270\320\263\320\270", nullptr));
        btnSupplies->setText(QCoreApplication::translate("adminmenu", "\320\220\320\262\321\202\320\276\321\200\321\201\321\202\320\262\320\276", nullptr));
        btnBack->setText(QCoreApplication::translate("adminmenu", "\320\222\320\265\321\200\320\275\321\203\321\202\321\201\321\217 \320\272 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("adminmenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\320\234\320\265\320\275\321\216</span></p></body></html>", nullptr));
        btnClose->setText(QCoreApplication::translate("adminmenu", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminmenu: public Ui_adminmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H

/********************************************************************************
** Form generated from reading UI file 'adminorders.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINORDERS_H
#define UI_ADMINORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminorders
{
public:
    QPushButton *btnSelectAll;
    QTableWidget *twotchet;
    QPushButton *btnMenu;
    QLabel *lbID_2;
    QTextEdit *teResult;

    void setupUi(QWidget *adminorders)
    {
        if (adminorders->objectName().isEmpty())
            adminorders->setObjectName("adminorders");
        adminorders->resize(1434, 558);
        btnSelectAll = new QPushButton(adminorders);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(580, 84, 121, 31));
        twotchet = new QTableWidget(adminorders);
        twotchet->setObjectName("twotchet");
        twotchet->setGeometry(QRect(12, 120, 1401, 421));
        btnMenu = new QPushButton(adminorders);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(720, 84, 121, 31));
        lbID_2 = new QLabel(adminorders);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(10, 20, 1401, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_2->setFont(font);
        teResult = new QTextEdit(adminorders);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(170, 220, 104, 70));
        teResult->raise();
        lbID_2->raise();
        btnSelectAll->raise();
        twotchet->raise();
        btnMenu->raise();

        retranslateUi(adminorders);

        QMetaObject::connectSlotsByName(adminorders);
    } // setupUi

    void retranslateUi(QWidget *adminorders)
    {
        adminorders->setWindowTitle(QCoreApplication::translate("adminorders", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\277\321\200\320\276\320\264\320\260\320\266\320\260\320\274", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("adminorders", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\276\321\202\321\207\320\265\321\202", nullptr));
        btnMenu->setText(QCoreApplication::translate("adminorders", "\320\234\320\265\320\275\321\216", nullptr));
        lbID_2->setText(QCoreApplication::translate("adminorders", "<html><head/><body><p align=\"center\">\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\277\321\200\320\276\320\264\320\260\320\266\320\260\320\274</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminorders: public Ui_adminorders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINORDERS_H

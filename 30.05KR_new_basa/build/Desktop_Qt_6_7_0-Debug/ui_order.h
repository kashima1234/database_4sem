/********************************************************************************
** Form generated from reading UI file 'order.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_H
#define UI_ORDER_H

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

class Ui_order
{
public:
    QWidget *centralwidget;
    QPushButton *btnSelectAll;
    QLabel *lbID_3;
    QTableWidget *twp;
    QFrame *frame;
    QPushButton *btnOrder;
    QLineEdit *leTak;
    QLabel *lbPhone_2;
    QLineEdit *leBo;
    QLabel *lbPhone;
    QPushButton *btnEdit_1;
    QLabel *lbID;
    QLineEdit *leAb;
    QLineEdit *leRet;
    QLabel *lbPhone_3;
    QPushButton *btnEdit;
    QTextEdit *teResult;
    QPushButton *btnMenu;
    QLabel *lbID_2;
    QLineEdit *leYea_2;
    QLineEdit *abonentName;
    QLineEdit *bookName;
    QPushButton *recordFilterBtn;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *order)
    {
        if (order->objectName().isEmpty())
            order->setObjectName("order");
        order->resize(926, 428);
        order->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(order);
        centralwidget->setObjectName("centralwidget");
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(600, 24, 201, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID_3 = new QLabel(centralwidget);
        lbID_3->setObjectName("lbID_3");
        lbID_3->setGeometry(QRect(10, 10, 201, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_3->setFont(font);
        twp = new QTableWidget(centralwidget);
        twp->setObjectName("twp");
        twp->setGeometry(QRect(310, 60, 601, 251));
        twp->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 60, 301, 251));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        btnOrder = new QPushButton(frame);
        btnOrder->setObjectName("btnOrder");
        btnOrder->setGeometry(QRect(20, 164, 261, 31));
        btnOrder->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leTak = new QLineEdit(frame);
        leTak->setObjectName("leTak");
        leTak->setGeometry(QRect(130, 90, 151, 25));
        leTak->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone_2 = new QLabel(frame);
        lbPhone_2->setObjectName("lbPhone_2");
        lbPhone_2->setGeometry(QRect(10, 90, 91, 21));
        leBo = new QLineEdit(frame);
        leBo->setObjectName("leBo");
        leBo->setGeometry(QRect(110, 60, 171, 25));
        leBo->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone = new QLabel(frame);
        lbPhone->setObjectName("lbPhone");
        lbPhone->setGeometry(QRect(10, 60, 67, 17));
        btnEdit_1 = new QPushButton(frame);
        btnEdit_1->setObjectName("btnEdit_1");
        btnEdit_1->setGeometry(QRect(20, 200, 131, 31));
        btnEdit_1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID = new QLabel(frame);
        lbID->setObjectName("lbID");
        lbID->setGeometry(QRect(10, 30, 91, 20));
        leAb = new QLineEdit(frame);
        leAb->setObjectName("leAb");
        leAb->setGeometry(QRect(110, 30, 171, 25));
        leAb->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leAb->setReadOnly(false);
        leRet = new QLineEdit(frame);
        leRet->setObjectName("leRet");
        leRet->setGeometry(QRect(130, 120, 151, 25));
        leRet->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone_3 = new QLabel(frame);
        lbPhone_3->setObjectName("lbPhone_3");
        lbPhone_3->setGeometry(QRect(10, 120, 111, 21));
        btnEdit = new QPushButton(frame);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(160, 200, 121, 31));
        btnEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(1060, 230, 20, 20));
        teResult->setReadOnly(true);
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(820, 24, 89, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID_2 = new QLabel(centralwidget);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(330, 10, 541, 51));
        lbID_2->setFont(font);
        leYea_2 = new QLineEdit(centralwidget);
        leYea_2->setObjectName("leYea_2");
        leYea_2->setGeometry(QRect(430, 210, 161, 25));
        abonentName = new QLineEdit(centralwidget);
        abonentName->setObjectName("abonentName");
        abonentName->setGeometry(QRect(320, 320, 171, 25));
        abonentName->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        abonentName->setReadOnly(false);
        bookName = new QLineEdit(centralwidget);
        bookName->setObjectName("bookName");
        bookName->setGeometry(QRect(320, 360, 171, 25));
        bookName->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        bookName->setReadOnly(false);
        recordFilterBtn = new QPushButton(centralwidget);
        recordFilterBtn->setObjectName("recordFilterBtn");
        recordFilterBtn->setGeometry(QRect(520, 340, 161, 31));
        recordFilterBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 320, 91, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 360, 101, 20));
        order->setCentralWidget(centralwidget);
        leYea_2->raise();
        lbID_2->raise();
        frame->raise();
        teResult->raise();
        btnSelectAll->raise();
        lbID_3->raise();
        twp->raise();
        btnMenu->raise();
        abonentName->raise();
        bookName->raise();
        recordFilterBtn->raise();
        label->raise();
        label_2->raise();
        menubar = new QMenuBar(order);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 926, 22));
        order->setMenuBar(menubar);
        statusbar = new QStatusBar(order);
        statusbar->setObjectName("statusbar");
        order->setStatusBar(statusbar);

        retranslateUi(order);

        QMetaObject::connectSlotsByName(order);
    } // setupUi

    void retranslateUi(QMainWindow *order)
    {
        order->setWindowTitle(QCoreApplication::translate("order", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("order", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        lbID_3->setText(QCoreApplication::translate("order", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270</span></p></body></html>", nullptr));
        btnOrder->setText(QCoreApplication::translate("order", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lbPhone_2->setText(QCoreApplication::translate("order", "<html><head/><body><p>\320\224\320\260\321\202\320\260 \320\262\320\267\321\217\321\202\320\270\321\217</p></body></html>", nullptr));
        lbPhone->setText(QCoreApplication::translate("order", "<html><head/><body><p>ID \320\272\320\275\320\270\320\263\320\270</p></body></html>", nullptr));
        btnEdit_1->setText(QCoreApplication::translate("order", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        lbID->setText(QCoreApplication::translate("order", " ID \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260", nullptr));
        lbPhone_3->setText(QCoreApplication::translate("order", "<html><head/><body><p>\320\224\320\260\321\202\320\260 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\320\260</p></body></html>", nullptr));
        btnEdit->setText(QCoreApplication::translate("order", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnMenu->setText(QCoreApplication::translate("order", "\320\234\320\265\320\275\321\216", nullptr));
        lbID_2->setText(QCoreApplication::translate("order", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\227\320\260\320\277\320\270\321\201\320\270</span></p></body></html>", nullptr));
        recordFilterBtn->setText(QCoreApplication::translate("order", "\320\244\320\270\320\273\321\214\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("order", "\320\277\320\276 \320\270\320\274\320\265\320\275\320\270 \320\260\320\261\320\276\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("order", "\320\277\320\276 \320\270\320\274\320\265\320\275\320\270 \320\272\320\275\320\270\320\263\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class order: public Ui_order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H

/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

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

class Ui_reg
{
public:
    QWidget *centralwidget;
    QLineEdit *leFam;
    QLabel *lbID_3;
    QFrame *frame;
    QTextEdit *leNam;
    QPushButton *btnMenu;
    QTextEdit *teResult;
    QTableWidget *twemployees;
    QLabel *lbEmail_2;
    QLineEdit *leBir;
    QPushButton *btnAdd;
    QLabel *lbAdress;
    QLineEdit *lePat;
    QLabel *lbPhone;
    QLabel *lbEmail;
    QLabel *lbFIO;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(717, 543);
        reg->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(reg);
        centralwidget->setObjectName("centralwidget");
        leFam = new QLineEdit(centralwidget);
        leFam->setObjectName("leFam");
        leFam->setGeometry(QRect(90, 80, 271, 31));
        leFam->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbID_3 = new QLabel(centralwidget);
        lbID_3->setObjectName("lbID_3");
        lbID_3->setGeometry(QRect(10, 10, 341, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_3->setFont(font);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 60, 691, 431));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        leNam = new QTextEdit(frame);
        leNam->setObjectName("leNam");
        leNam->setGeometry(QRect(80, 60, 271, 31));
        leNam->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnMenu = new QPushButton(frame);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(10, 240, 341, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        teResult = new QTextEdit(frame);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(140, 60, 41, 21));
        twemployees = new QTableWidget(frame);
        twemployees->setObjectName("twemployees");
        twemployees->setGeometry(QRect(390, 40, 191, 121));
        twemployees->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbEmail_2 = new QLabel(frame);
        lbEmail_2->setObjectName("lbEmail_2");
        lbEmail_2->setGeometry(QRect(400, 10, 181, 16));
        leBir = new QLineEdit(frame);
        leBir->setObjectName("leBir");
        leBir->setGeometry(QRect(130, 150, 221, 31));
        leBir->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(10, 200, 341, 31));
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbAdress = new QLabel(frame);
        lbAdress->setObjectName("lbAdress");
        lbAdress->setGeometry(QRect(10, 70, 67, 17));
        lePat = new QLineEdit(frame);
        lePat->setObjectName("lePat");
        lePat->setGeometry(QRect(80, 104, 271, 31));
        lePat->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone = new QLabel(frame);
        lbPhone->setObjectName("lbPhone");
        lbPhone->setGeometry(QRect(10, 110, 67, 17));
        lbEmail = new QLabel(frame);
        lbEmail->setObjectName("lbEmail");
        lbEmail->setGeometry(QRect(10, 150, 111, 21));
        teResult->raise();
        leNam->raise();
        btnMenu->raise();
        twemployees->raise();
        lbEmail_2->raise();
        leBir->raise();
        btnAdd->raise();
        lbAdress->raise();
        lePat->raise();
        lbPhone->raise();
        lbEmail->raise();
        lbFIO = new QLabel(centralwidget);
        lbFIO->setObjectName("lbFIO");
        lbFIO->setGeometry(QRect(20, 90, 67, 17));
        reg->setCentralWidget(centralwidget);
        frame->raise();
        leFam->raise();
        lbID_3->raise();
        lbFIO->raise();
        menubar = new QMenuBar(reg);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 717, 22));
        reg->setMenuBar(menubar);
        statusbar = new QStatusBar(reg);
        statusbar->setObjectName("statusbar");
        reg->setStatusBar(statusbar);

        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QMainWindow *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lbID_3->setText(QCoreApplication::translate("reg", "<html><head/><body><p align=\"center\"><span style=\" font-weight:400; font-style:italic;\">\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217</span></p></body></html>", nullptr));
        btnMenu->setText(QCoreApplication::translate("reg", "\320\234\320\265\320\275\321\216", nullptr));
        lbEmail_2->setText(QCoreApplication::translate("reg", "<html><head/><body><p><span style=\" font-weight:600; font-style:italic; text-decoration: underline;\">ID \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260:</span></p></body></html>", nullptr));
        btnAdd->setText(QCoreApplication::translate("reg", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        lbAdress->setText(QCoreApplication::translate("reg", "\320\230\320\274\321\217", nullptr));
        lbPhone->setText(QCoreApplication::translate("reg", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lbEmail->setText(QCoreApplication::translate("reg", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        lbFIO->setText(QCoreApplication::translate("reg", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H

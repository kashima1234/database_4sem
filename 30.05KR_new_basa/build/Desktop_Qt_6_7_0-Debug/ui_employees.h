/********************************************************************************
** Form generated from reading UI file 'employees.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEES_H
#define UI_EMPLOYEES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employees
{
public:
    QWidget *centralwidget;
    QLineEdit *leFam;
    QLabel *lbID;
    QLabel *lbFIO;
    QLineEdit *lename;
    QLineEdit *lePat;
    QLineEdit *leBir;
    QLabel *lbPhone;
    QLabel *lbEmail;
    QFrame *frame;
    QPushButton *btnDel;
    QPushButton *btnEdit;
    QPushButton *btnAdd;
    QPushButton *btnEdit1;
    QLineEdit *leDea;
    QLabel *lbEmail_2;
    QTextEdit *teResult;
    QTableWidget *twemployees;
    QLabel *lbID_2;
    QLabel *lbID_3;
    QPushButton *btnClear;
    QPushButton *btnSelectAll;
    QPushButton *btnMenu;
    QPushButton *btnConnect;
    QLabel *lbID_5;
    QLineEdit *leSearch;
    QPushButton *btnSearch;
    QPushButton *btnSelectAll_2;
    QPushButton *btnMenu_2;
    QRadioButton *btnFilterByDate;
    QRadioButton *btnFilterByDates;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *employees)
    {
        if (employees->objectName().isEmpty())
            employees->setObjectName("employees");
        employees->resize(1189, 586);
        employees->setAutoFillBackground(false);
        employees->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(employees);
        centralwidget->setObjectName("centralwidget");
        leFam = new QLineEdit(centralwidget);
        leFam->setObjectName("leFam");
        leFam->setGeometry(QRect(90, 140, 221, 31));
        leFam->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leFam->setReadOnly(false);
        lbID = new QLabel(centralwidget);
        lbID->setObjectName("lbID");
        lbID->setGeometry(QRect(10, 150, 67, 17));
        lbFIO = new QLabel(centralwidget);
        lbFIO->setObjectName("lbFIO");
        lbFIO->setGeometry(QRect(10, 190, 67, 17));
        lename = new QLineEdit(centralwidget);
        lename->setObjectName("lename");
        lename->setGeometry(QRect(90, 180, 221, 31));
        lename->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lePat = new QLineEdit(centralwidget);
        lePat->setObjectName("lePat");
        lePat->setGeometry(QRect(90, 220, 221, 31));
        lePat->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leBir = new QLineEdit(centralwidget);
        leBir->setObjectName("leBir");
        leBir->setGeometry(QRect(140, 260, 171, 31));
        leBir->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone = new QLabel(centralwidget);
        lbPhone->setObjectName("lbPhone");
        lbPhone->setGeometry(QRect(10, 230, 67, 17));
        lbEmail = new QLabel(centralwidget);
        lbEmail->setObjectName("lbEmail");
        lbEmail->setGeometry(QRect(10, 270, 121, 16));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 130, 331, 301));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        btnDel = new QPushButton(frame);
        btnDel->setObjectName("btnDel");
        btnDel->setGeometry(QRect(170, 220, 151, 31));
        btnDel->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit = new QPushButton(frame);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(170, 260, 151, 31));
        btnEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(10, 220, 151, 31));
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit1 = new QPushButton(frame);
        btnEdit1->setObjectName("btnEdit1");
        btnEdit1->setGeometry(QRect(10, 260, 151, 31));
        btnEdit1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leDea = new QLineEdit(frame);
        leDea->setObjectName("leDea");
        leDea->setGeometry(QRect(140, 170, 171, 31));
        leDea->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbEmail_2 = new QLabel(frame);
        lbEmail_2->setObjectName("lbEmail_2");
        lbEmail_2->setGeometry(QRect(10, 180, 121, 16));
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(460, 270, 521, 51));
        teResult->setReadOnly(true);
        twemployees = new QTableWidget(centralwidget);
        twemployees->setObjectName("twemployees");
        twemployees->setGeometry(QRect(350, 140, 811, 261));
        twemployees->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        lbID_2 = new QLabel(centralwidget);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(360, 80, 141, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_2->setFont(font);
        lbID_3 = new QLabel(centralwidget);
        lbID_3->setObjectName("lbID_3");
        lbID_3->setGeometry(QRect(0, 90, 171, 41));
        lbID_3->setFont(font);
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(490, 94, 89, 31));
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(590, 94, 201, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(800, 94, 89, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName("btnConnect");
        btnConnect->setGeometry(QRect(430, 220, 111, 25));
        lbID_5 = new QLabel(centralwidget);
        lbID_5->setObjectName("lbID_5");
        lbID_5->setGeometry(QRect(0, 10, 311, 51));
        lbID_5->setFont(font);
        leSearch = new QLineEdit(centralwidget);
        leSearch->setObjectName("leSearch");
        leSearch->setGeometry(QRect(10, 60, 221, 31));
        leSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leSearch->setReadOnly(false);
        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(240, 60, 89, 31));
        btnSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnSelectAll_2 = new QPushButton(centralwidget);
        btnSelectAll_2->setObjectName("btnSelectAll_2");
        btnSelectAll_2->setGeometry(QRect(1210, 320, 201, 25));
        btnMenu_2 = new QPushButton(centralwidget);
        btnMenu_2->setObjectName("btnMenu_2");
        btnMenu_2->setGeometry(QRect(1320, 230, 89, 25));
        btnFilterByDate = new QRadioButton(centralwidget);
        btnFilterByDate->setObjectName("btnFilterByDate");
        btnFilterByDate->setGeometry(QRect(910, 70, 211, 23));
        btnFilterByDates = new QRadioButton(centralwidget);
        btnFilterByDates->setObjectName("btnFilterByDates");
        btnFilterByDates->setGeometry(QRect(910, 100, 211, 23));
        employees->setCentralWidget(centralwidget);
        lbID_3->raise();
        btnConnect->raise();
        teResult->raise();
        frame->raise();
        leFam->raise();
        lbID->raise();
        lbFIO->raise();
        lename->raise();
        lePat->raise();
        leBir->raise();
        lbPhone->raise();
        lbEmail->raise();
        twemployees->raise();
        lbID_2->raise();
        btnClear->raise();
        btnSelectAll->raise();
        btnMenu->raise();
        lbID_5->raise();
        leSearch->raise();
        btnSearch->raise();
        btnSelectAll_2->raise();
        btnMenu_2->raise();
        btnFilterByDate->raise();
        btnFilterByDates->raise();
        menubar = new QMenuBar(employees);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1189, 22));
        employees->setMenuBar(menubar);
        statusbar = new QStatusBar(employees);
        statusbar->setObjectName("statusbar");
        employees->setStatusBar(statusbar);

        retranslateUi(employees);

        QMetaObject::connectSlotsByName(employees);
    } // setupUi

    void retranslateUi(QMainWindow *employees)
    {
        employees->setWindowTitle(QCoreApplication::translate("employees", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        lbID->setText(QCoreApplication::translate("employees", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        lbFIO->setText(QCoreApplication::translate("employees", "\320\230\320\274\321\217", nullptr));
        lbPhone->setText(QCoreApplication::translate("employees", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lbEmail->setText(QCoreApplication::translate("employees", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        btnDel->setText(QCoreApplication::translate("employees", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnEdit->setText(QCoreApplication::translate("employees", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnAdd->setText(QCoreApplication::translate("employees", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnEdit1->setText(QCoreApplication::translate("employees", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        lbEmail_2->setText(QCoreApplication::translate("employees", "\320\224\320\260\321\202\320\260 \321\201\320\274\320\265\321\200\321\202\320\270", nullptr));
        lbID_2->setText(QCoreApplication::translate("employees", "\320\222\321\213\320\262\320\276\320\264", nullptr));
        lbID_3->setText(QCoreApplication::translate("employees", "\320\222\320\262\320\276\320\264", nullptr));
        btnClear->setText(QCoreApplication::translate("employees", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 ", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("employees", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\320\265\321\205 \320\260\320\262\321\202\320\276\321\200\320\276\320\262", nullptr));
        btnMenu->setText(QCoreApplication::translate("employees", "\320\234\320\265\320\275\321\216", nullptr));
        btnConnect->setText(QCoreApplication::translate("employees", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        lbID_5->setText(QCoreApplication::translate("employees", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \321\204\320\260\320\274\320\270\320\273\320\270\320\270", nullptr));
        btnSearch->setText(QCoreApplication::translate("employees", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        btnSelectAll_2->setText(QCoreApplication::translate("employees", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\320\265\321\205 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\276\320\262", nullptr));
        btnMenu_2->setText(QCoreApplication::translate("employees", "\320\234\320\265\320\275\321\216", nullptr));
        btnFilterByDate->setText(QCoreApplication::translate("employees", "\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\264\320\260\321\202\320\260 \321\200\320\276\320\266\320\264", nullptr));
        btnFilterByDates->setText(QCoreApplication::translate("employees", "\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\264\320\260\321\202\320\260 \321\201\320\274\320\265\321\200\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employees: public Ui_employees {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEES_H

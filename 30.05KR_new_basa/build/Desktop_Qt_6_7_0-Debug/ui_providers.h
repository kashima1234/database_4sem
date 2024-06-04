/********************************************************************************
** Form generated from reading UI file 'providers.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROVIDERS_H
#define UI_PROVIDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_providers
{
public:
    QWidget *centralwidget;
    QLabel *lbID_3;
    QLabel *lbPhone;
    QLabel *lbFIO;
    QPushButton *btnSelectAll;
    QLabel *lbID;
    QLabel *lbID_2;
    QPushButton *btnMenu;
    QLineEdit *leYea;
    QLineEdit *leTit;
    QFrame *frame;
    QPushButton *btnDel;
    QPushButton *btnEdit;
    QPushButton *btnAdd;
    QPushButton *btnEdit1;
    QLineEdit *leSeaB;
    QPushButton *btnSeaB;
    QLabel *lbPublishing;
    QLineEdit *lePublishing;
    QLineEdit *leCou;
    QLabel *lbPublishing_2;
    QComboBox *authors;
    QTableWidget *twp;
    QFrame *frame_2;
    QPushButton *btnDel_3;
    QPushButton *btnEdit_3;
    QPushButton *btnAdd_3;
    QPushButton *btnEdit1_3;
    QLineEdit *leTitK;
    QLabel *lbPhone_5;
    QLineEdit *leDisc;
    QLabel *lbPhone_6;
    QLineEdit *leSeaK;
    QPushButton *btnSeaK;
    QLabel *lbID_4;
    QTextEdit *teResult;
    QLabel *lbID_7;
    QTableWidget *twp_2;
    QPushButton *btnSelectAll_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *providers)
    {
        if (providers->objectName().isEmpty())
            providers->setObjectName("providers");
        providers->resize(1451, 682);
        providers->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        centralwidget = new QWidget(providers);
        centralwidget->setObjectName("centralwidget");
        lbID_3 = new QLabel(centralwidget);
        lbID_3->setObjectName("lbID_3");
        lbID_3->setGeometry(QRect(10, 20, 171, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbID_3->setFont(font);
        lbPhone = new QLabel(centralwidget);
        lbPhone->setObjectName("lbPhone");
        lbPhone->setGeometry(QRect(20, 170, 101, 16));
        lbFIO = new QLabel(centralwidget);
        lbFIO->setObjectName("lbFIO");
        lbFIO->setGeometry(QRect(20, 130, 111, 21));
        btnSelectAll = new QPushButton(centralwidget);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(790, 34, 201, 31));
        btnSelectAll->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID = new QLabel(centralwidget);
        lbID->setObjectName("lbID");
        lbID->setGeometry(QRect(20, 90, 67, 17));
        lbID_2 = new QLabel(centralwidget);
        lbID_2->setObjectName("lbID_2");
        lbID_2->setGeometry(QRect(570, 20, 191, 51));
        lbID_2->setFont(font);
        btnMenu = new QPushButton(centralwidget);
        btnMenu->setObjectName("btnMenu");
        btnMenu->setGeometry(QRect(1020, 34, 89, 31));
        btnMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leYea = new QLineEdit(centralwidget);
        leYea->setObjectName("leYea");
        leYea->setGeometry(QRect(140, 120, 111, 31));
        leYea->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leTit = new QLineEdit(centralwidget);
        leTit->setObjectName("leTit");
        leTit->setGeometry(QRect(100, 80, 151, 25));
        leTit->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leTit->setReadOnly(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 60, 261, 361));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        btnDel = new QPushButton(frame);
        btnDel->setObjectName("btnDel");
        btnDel->setGeometry(QRect(130, 245, 111, 25));
        btnDel->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit = new QPushButton(frame);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(130, 275, 111, 25));
        btnEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(10, 245, 111, 25));
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit1 = new QPushButton(frame);
        btnEdit1->setObjectName("btnEdit1");
        btnEdit1->setGeometry(QRect(10, 275, 111, 25));
        btnEdit1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leSeaB = new QLineEdit(frame);
        leSeaB->setObjectName("leSeaB");
        leSeaB->setGeometry(QRect(10, 305, 111, 31));
        leSeaB->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leSeaB->setReadOnly(false);
        btnSeaB = new QPushButton(frame);
        btnSeaB->setObjectName("btnSeaB");
        btnSeaB->setGeometry(QRect(130, 305, 111, 31));
        btnSeaB->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbPublishing = new QLabel(frame);
        lbPublishing->setObjectName("lbPublishing");
        lbPublishing->setGeometry(QRect(10, 150, 101, 16));
        lePublishing = new QLineEdit(frame);
        lePublishing->setObjectName("lePublishing");
        lePublishing->setGeometry(QRect(120, 150, 121, 31));
        lePublishing->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        leCou = new QLineEdit(frame);
        leCou->setObjectName("leCou");
        leCou->setGeometry(QRect(120, 100, 121, 31));
        leCou->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPublishing_2 = new QLabel(frame);
        lbPublishing_2->setObjectName("lbPublishing_2");
        lbPublishing_2->setGeometry(QRect(20, 200, 101, 16));
        authors = new QComboBox(frame);
        authors->setObjectName("authors");
        authors->setGeometry(QRect(120, 190, 121, 41));
        twp = new QTableWidget(centralwidget);
        twp->setObjectName("twp");
        twp->setGeometry(QRect(570, 70, 871, 251));
        twp->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(290, 70, 251, 281));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        btnDel_3 = new QPushButton(frame_2);
        btnDel_3->setObjectName("btnDel_3");
        btnDel_3->setGeometry(QRect(130, 180, 111, 25));
        btnDel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit_3 = new QPushButton(frame_2);
        btnEdit_3->setObjectName("btnEdit_3");
        btnEdit_3->setGeometry(QRect(130, 210, 111, 25));
        btnEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnAdd_3 = new QPushButton(frame_2);
        btnAdd_3->setObjectName("btnAdd_3");
        btnAdd_3->setGeometry(QRect(10, 180, 111, 25));
        btnAdd_3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        btnEdit1_3 = new QPushButton(frame_2);
        btnEdit1_3->setObjectName("btnEdit1_3");
        btnEdit1_3->setGeometry(QRect(10, 210, 111, 25));
        btnEdit1_3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        leTitK = new QLineEdit(frame_2);
        leTitK->setObjectName("leTitK");
        leTitK->setGeometry(QRect(90, 20, 151, 25));
        leTitK->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone_5 = new QLabel(frame_2);
        lbPhone_5->setObjectName("lbPhone_5");
        lbPhone_5->setGeometry(QRect(10, 30, 67, 17));
        leDisc = new QLineEdit(frame_2);
        leDisc->setObjectName("leDisc");
        leDisc->setGeometry(QRect(10, 84, 231, 91));
        leDisc->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        lbPhone_6 = new QLabel(frame_2);
        lbPhone_6->setObjectName("lbPhone_6");
        lbPhone_6->setGeometry(QRect(10, 60, 71, 16));
        leSeaK = new QLineEdit(frame_2);
        leSeaK->setObjectName("leSeaK");
        leSeaK->setGeometry(QRect(10, 240, 111, 31));
        leSeaK->setStyleSheet(QString::fromUtf8("background-color: rgb(32,120, 215);\n"
""));
        btnSeaK = new QPushButton(frame_2);
        btnSeaK->setObjectName("btnSeaK");
        btnSeaK->setGeometry(QRect(130, 240, 111, 31));
        btnSeaK->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lbID_4 = new QLabel(centralwidget);
        lbID_4->setObjectName("lbID_4");
        lbID_4->setGeometry(QRect(290, 20, 171, 41));
        lbID_4->setFont(font);
        teResult = new QTextEdit(centralwidget);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(680, 430, 201, 121));
        teResult->setReadOnly(true);
        lbID_7 = new QLabel(centralwidget);
        lbID_7->setObjectName("lbID_7");
        lbID_7->setGeometry(QRect(570, 330, 291, 41));
        lbID_7->setFont(font);
        twp_2 = new QTableWidget(centralwidget);
        twp_2->setObjectName("twp_2");
        twp_2->setGeometry(QRect(570, 370, 871, 251));
        twp_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);\n"
""));
        btnSelectAll_2 = new QPushButton(centralwidget);
        btnSelectAll_2->setObjectName("btnSelectAll_2");
        btnSelectAll_2->setGeometry(QRect(840, 334, 201, 31));
        btnSelectAll_2->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        providers->setCentralWidget(centralwidget);
        frame_2->raise();
        frame->raise();
        lbID_3->raise();
        lbPhone->raise();
        lbFIO->raise();
        btnSelectAll->raise();
        lbID->raise();
        lbID_2->raise();
        btnMenu->raise();
        leYea->raise();
        leTit->raise();
        twp->raise();
        lbID_4->raise();
        teResult->raise();
        lbID_7->raise();
        twp_2->raise();
        btnSelectAll_2->raise();
        menubar = new QMenuBar(providers);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1451, 22));
        providers->setMenuBar(menubar);
        statusbar = new QStatusBar(providers);
        statusbar->setObjectName("statusbar");
        providers->setStatusBar(statusbar);

        retranslateUi(providers);

        QMetaObject::connectSlotsByName(providers);
    } // setupUi

    void retranslateUi(QMainWindow *providers)
    {
        providers->setWindowTitle(QCoreApplication::translate("providers", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270-\320\272\320\275\320\270\320\263\320\270", nullptr));
        lbID_3->setText(QCoreApplication::translate("providers", "\320\232\320\275\320\270\320\263\320\270", nullptr));
        lbPhone->setText(QCoreApplication::translate("providers", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lbFIO->setText(QCoreApplication::translate("providers", "\320\223\320\276\320\264 \320\277\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\320\270", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("providers", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        lbID->setText(QCoreApplication::translate("providers", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lbID_2->setText(QCoreApplication::translate("providers", "\320\222\321\213\320\262\320\276\320\264 \320\272\320\275\320\270\320\263\320\270", nullptr));
        btnMenu->setText(QCoreApplication::translate("providers", "\320\234\320\265\320\275\321\216", nullptr));
        btnDel->setText(QCoreApplication::translate("providers", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnEdit->setText(QCoreApplication::translate("providers", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnAdd->setText(QCoreApplication::translate("providers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnEdit1->setText(QCoreApplication::translate("providers", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btnSeaB->setText(QCoreApplication::translate("providers", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        lbPublishing->setText(QCoreApplication::translate("providers", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        lbPublishing_2->setText(QCoreApplication::translate("providers", "\320\230\320\274\321\217 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        btnDel_3->setText(QCoreApplication::translate("providers", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnEdit_3->setText(QCoreApplication::translate("providers", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnAdd_3->setText(QCoreApplication::translate("providers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnEdit1_3->setText(QCoreApplication::translate("providers", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        lbPhone_5->setText(QCoreApplication::translate("providers", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lbPhone_6->setText(QCoreApplication::translate("providers", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        btnSeaK->setText(QCoreApplication::translate("providers", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        lbID_4->setText(QCoreApplication::translate("providers", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        lbID_7->setText(QCoreApplication::translate("providers", "\320\222\321\213\320\262\320\276\320\264 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        btnSelectAll_2->setText(QCoreApplication::translate("providers", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class providers: public Ui_providers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROVIDERS_H

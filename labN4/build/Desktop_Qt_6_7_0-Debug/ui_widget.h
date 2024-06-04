/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_4;
    QPushButton *pushButton;
    QWidget *page_1;
    QLabel *label_3;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *pushButton_login;
    QWidget *page_2;
    QFrame *frame;
    QPushButton *btnAdd;
    QLabel *leCity;
    QLineEdit *lbCity;
    QPushButton *btnDel;
    QLineEdit *lbAbbr;
    QLabel *leAbbr;
    QLineEdit *lbTitle;
    QLabel *leInn;
    QLineEdit *lbInn;
    QPushButton *btnEdit;
    QLabel *teTitle;
    QPushButton *btnSelectAll;
    QPushButton *btnConnect;
    QTextEdit *teResult;
    QTableWidget *twOrg;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(917, 556);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 20, 901, 521));
        page = new QWidget();
        page->setObjectName("page");
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 90, 391, 291));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/social-card (1).jpg")));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 120, 80, 25));
        stackedWidget->addWidget(page);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        label_3 = new QLabel(page_1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 120, 251, 241));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/wGuh9Zxxn0g (2).jpg")));
        groupBox = new QGroupBox(page_1);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(300, 130, 281, 191));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 71, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 61, 17));
        username = new QLineEdit(groupBox);
        username->setObjectName("username");
        username->setGeometry(QRect(120, 40, 113, 25));
        password = new QLineEdit(groupBox);
        password->setObjectName("password");
        password->setGeometry(QRect(120, 70, 113, 25));
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(130, 110, 80, 25));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        frame = new QFrame(page_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 60, 301, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(40, 300, 61, 25));
        leCity = new QLabel(frame);
        leCity->setObjectName("leCity");
        leCity->setGeometry(QRect(11, 180, 54, 17));
        lbCity = new QLineEdit(frame);
        lbCity->setObjectName("lbCity");
        lbCity->setGeometry(QRect(71, 180, 191, 25));
        btnDel = new QPushButton(frame);
        btnDel->setObjectName("btnDel");
        btnDel->setGeometry(QRect(211, 300, 80, 25));
        lbAbbr = new QLineEdit(frame);
        lbAbbr->setObjectName("lbAbbr");
        lbAbbr->setGeometry(QRect(61, 10, 211, 25));
        leAbbr = new QLabel(frame);
        leAbbr->setObjectName("leAbbr");
        leAbbr->setGeometry(QRect(11, 6, 54, 21));
        lbTitle = new QLineEdit(frame);
        lbTitle->setObjectName("lbTitle");
        lbTitle->setGeometry(QRect(63, 60, 201, 91));
        leInn = new QLabel(frame);
        leInn->setObjectName("leInn");
        leInn->setGeometry(QRect(11, 230, 54, 17));
        lbInn = new QLineEdit(frame);
        lbInn->setObjectName("lbInn");
        lbInn->setGeometry(QRect(71, 230, 191, 25));
        btnEdit = new QPushButton(frame);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(121, 300, 71, 25));
        teTitle = new QLabel(frame);
        teTitle->setObjectName("teTitle");
        teTitle->setGeometry(QRect(11, 90, 54, 17));
        btnSelectAll = new QPushButton(page_2);
        btnSelectAll->setObjectName("btnSelectAll");
        btnSelectAll->setGeometry(QRect(730, 30, 80, 25));
        btnConnect = new QPushButton(page_2);
        btnConnect->setObjectName("btnConnect");
        btnConnect->setGeometry(QRect(360, 30, 80, 25));
        teResult = new QTextEdit(page_2);
        teResult->setObjectName("teResult");
        teResult->setGeometry(QRect(20, 409, 851, 111));
        twOrg = new QTableWidget(page_2);
        twOrg->setObjectName("twOrg");
        twOrg->setGeometry(QRect(340, 60, 521, 341));
        stackedWidget->addWidget(page_2);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_4->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "ClickHere", nullptr));
        label_3->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Widget", "SignIn", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Password", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Widget", "Login", nullptr));
        btnAdd->setText(QCoreApplication::translate("Widget", "Add", nullptr));
        leCity->setText(QCoreApplication::translate("Widget", "City", nullptr));
        btnDel->setText(QCoreApplication::translate("Widget", "Del", nullptr));
        leAbbr->setText(QCoreApplication::translate("Widget", "Abbr", nullptr));
        lbTitle->setText(QString());
        leInn->setText(QCoreApplication::translate("Widget", "INN", nullptr));
        btnEdit->setText(QCoreApplication::translate("Widget", "Edit", nullptr));
        teTitle->setText(QCoreApplication::translate("Widget", "Title", nullptr));
        btnSelectAll->setText(QCoreApplication::translate("Widget", "Select All ", nullptr));
        btnConnect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

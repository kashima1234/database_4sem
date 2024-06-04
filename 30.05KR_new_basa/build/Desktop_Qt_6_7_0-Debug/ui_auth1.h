/********************************************************************************
** Form generated from reading UI file 'auth1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH1_H
#define UI_AUTH1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth1
{
public:
    QLabel *lblogin;
    QLineEdit *lePassword;
    QPushButton *btnEnter;
    QLabel *lgsign;
    QLabel *lbpswd;
    QLineEdit *leLogin;

    void setupUi(QWidget *auth1)
    {
        if (auth1->objectName().isEmpty())
            auth1->setObjectName("auth1");
        auth1->resize(597, 285);
        auth1->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 180,220);\n"
""));
        lblogin = new QLabel(auth1);
        lblogin->setObjectName("lblogin");
        lblogin->setGeometry(QRect(260, 60, 125, 40));
        lblogin->setMinimumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(14);
        lblogin->setFont(font);
        lePassword = new QLineEdit(auth1);
        lePassword->setObjectName("lePassword");
        lePassword->setGeometry(QRect(80, 170, 440, 40));
        lePassword->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu")});
        lePassword->setFont(font1);
        lePassword->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);"));
        lePassword->setEchoMode(QLineEdit::Password);
        btnEnter = new QPushButton(auth1);
        btnEnter->setObjectName("btnEnter");
        btnEnter->setGeometry(QRect(80, 230, 441, 41));
        btnEnter->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 112,230);\n"
""));
        lgsign = new QLabel(auth1);
        lgsign->setObjectName("lgsign");
        lgsign->setGeometry(QRect(10, 30, 571, 40));
        lgsign->setMinimumSize(QSize(0, 40));
        lgsign->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rachana")});
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        lgsign->setFont(font2);
        lgsign->setAlignment(Qt::AlignCenter);
        lbpswd = new QLabel(auth1);
        lbpswd->setObjectName("lbpswd");
        lbpswd->setGeometry(QRect(260, 140, 125, 40));
        lbpswd->setMinimumSize(QSize(100, 40));
        lbpswd->setFont(font);
        leLogin = new QLineEdit(auth1);
        leLogin->setObjectName("leLogin");
        leLogin->setGeometry(QRect(80, 90, 440, 40));
        leLogin->setMinimumSize(QSize(0, 40));
        leLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(255,120, 115);"));
        leLogin->setInputMask(QString::fromUtf8(""));
        lblogin->raise();
        btnEnter->raise();
        lgsign->raise();
        lbpswd->raise();
        leLogin->raise();
        lePassword->raise();

        retranslateUi(auth1);

        QMetaObject::connectSlotsByName(auth1);
    } // setupUi

    void retranslateUi(QWidget *auth1)
    {
        auth1->setWindowTitle(QCoreApplication::translate("auth1", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lblogin->setText(QCoreApplication::translate("auth1", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        btnEnter->setText(QCoreApplication::translate("auth1", "\320\222\320\276\320\271\321\202\320\270 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        lgsign->setText(QCoreApplication::translate("auth1", "\320\220\320\230\320\241 \320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", nullptr));
        lbpswd->setText(QCoreApplication::translate("auth1", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class auth1: public Ui_auth1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH1_H

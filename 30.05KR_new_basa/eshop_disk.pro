QT       += core gui
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmenu.cpp \
    adminorders.cpp \
    auth1.cpp \
    employees.cpp \
    main.cpp \
    mainwindow.cpp \
    myorders.cpp \
    order.cpp \
    providers.cpp \
    reg.cpp \
    supplies.cpp \
    usermenu.cpp

HEADERS += \
    adminmenu.h \
    adminorders.h \
    auth1.h \
    employees.h \
    mainwindow.h \
    myorders.h \
    order.h \
    providers.h \
    reg.h \
    supplies.h \
    usermenu.h

FORMS += \
    adminmenu.ui \
    adminorders.ui \
    auth1.ui \
    employees.ui \
    mainwindow.ui \
    myorders.ui \
    order.ui \
    providers.ui \
    reg.ui \
    supplies.ui \
    usermenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

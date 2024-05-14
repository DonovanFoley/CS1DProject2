QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SouvenirPurchase.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    team.cpp \
    tripdialog.cpp \
    stadiumdb.cpp \
    stadiummanager.cpp\
    sqlite3.c \
    graph.cpp

HEADERS += \
    SouvenirPurchase.h \
    logindialog.h \
    mainwindow.h \
    map.h \
    team.h \
    stadiumdb.h \
    stadiummanager.h\
    tripdialog.h \
    sqlite3.h \
    graph.h

FORMS += \
    SouvenirPurchase.ui \
    logindialog.ui \
    mainwindow.ui \
    tripdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

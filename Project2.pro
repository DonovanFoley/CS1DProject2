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
<<<<<<< HEAD
<<<<<<< Updated upstream
    team.cpp
=======
    map.cpp \
    prim.cpp \
=======
    map.cpp \
>>>>>>> 1b8e45f3ac0d908b1bc28eb08542d7df5cf0bd11
    team.cpp \
    tripdialog.cpp \
    stadiumdb.cpp \
    sqlite3.c \
    graph.cpp
<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> 1b8e45f3ac0d908b1bc28eb08542d7df5cf0bd11

HEADERS += \
    SouvenirPurchase.h \
    logindialog.h \
    mainwindow.h \
<<<<<<< HEAD
<<<<<<< Updated upstream
    team.h
=======
    map.h \
    prim.h \
=======
    map.h \
>>>>>>> 1b8e45f3ac0d908b1bc28eb08542d7df5cf0bd11
    team.h \
    stadiumdb.h \
    tripdialog.h \
    sqlite3.h \
    graph.h
<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> 1b8e45f3ac0d908b1bc28eb08542d7df5cf0bd11

FORMS += \
    SouvenirPurchase.ui \
    logindialog.ui \
    mainwindow.ui \
    tripdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

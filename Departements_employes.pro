#-------------------------------------------------
#
# Project created by QtCreator 2020-04-03T18:38:43
#
#-------------------------------------------------
QT       += core gui network  printsupport
QT       +=sql
QT += widgets multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Departements_employes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    employe.cpp \
    departement.cpp \
    gestion_dep_empl.cpp \
    gestiondepartement.cpp \
    gestionemploye.cpp \
    statss.cpp \
    connexion.cpp \
    DarkStyle.cpp \
    framelesswindow/windowdragger.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    employe.h \
    departement.h \
    gestion_dep_empl.h \
    gestiondepartement.h \
    gestionemploye.h \
    statss.h \
    connexion.h \
    DarkStyle.h \
    framelesswindow/windowdragger.h \
    qcustomplot.h

FORMS += \
        mainwindow.ui \
    gestion_dep_empl.ui \
    gestiondepartement.ui \
    gestionemploye.ui \
    statss.ui

RESOURCES += \
    css.qrc \
    darkstyle.qrc \
    framelesswindow.qrc

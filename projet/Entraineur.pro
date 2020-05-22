#-------------------------------------------------
#
# Project created by QtCreator 2020-04-01T15:52:29
#
#-------------------------------------------------

QT       += core gui network  printsupport
QT       +=sql
QT += widgets multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Entraineur
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
    entraineurs.cpp \
    joueurs.cpp \
    gestion_entraineur_joueur.cpp \
    gestion_entraineur.cpp \
    gestion_joueur.cpp \
    ajouterjoueur.cpp \
    ajouterentraineur.cpp \
    connexion.cpp \
    affichage_entraineur.cpp \
    affichage_joueur.cpp


HEADERS += \
        mainwindow.h \
    entraineurs.h \
    joueurs.h \
    gestion_entraineur_joueur.h \
    gestion_entraineur.h \
    gestion_joueur.h \
    ajouterjoueur.h \
    ajouterentraineur.h \
    connexion.h \
    affichage_entraineur.h \
    affichage_joueur.h


FORMS += \
        mainwindow.ui \
    gestion_entraineur_joueur.ui \
    gestion_entraineur.ui \
    gestion_joueur.ui \
    ajouterjoueur.ui \
    ajouterentraineur.ui \
    affichage_entraineur.ui \
    affichage_joueur.ui

RESOURCES += \
    images.qrc

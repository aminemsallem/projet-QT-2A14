#include "mainwindow.h"
#include <QApplication>
#include"gestion_entraineur_joueur.h"
#include"connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gestion_Entraineur_Joueur w;
    connexion c;
    bool test=c.ouvrirConnexion();

    w.show();

    return a.exec();
}

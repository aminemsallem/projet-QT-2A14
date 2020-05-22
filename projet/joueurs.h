#ifndef JOUEURS_H
#define JOUEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
#include "entraineurs.h"
#include "ajouterjoueur.h"
#include "ui_ajouterjoueur.h"


#include"affichage_joueur.h"
class joueurs
{
public:
    joueurs();
    joueurs(QString cin,QString nom,QString prenom,QString entraineur, QDate date_naissance,int age);
    QString getNom() ;
    void setNom( QString &value);
    QString getPrenom() ;
    void setPrenom( QString &value);

    int getAge();
    void setAge(int value);
    QString getEntraineur() ;
    void setEntraineur(QString &value);
    QDate getDate_naissance() ;
    void setDate_naissance( QDate &value);
    int getValide() ;
    void setValide();



    bool ajouter();
    void list_entraineurs(Ui::AFFICHAGE_JOUEUR *ui);
    void list_entraineurs2(Ui::AjouterJoueur *ui);
    void affichage(Ui::AFFICHAGE_JOUEUR *ui);
    bool Supprimer(Ui::AFFICHAGE_JOUEUR *ui);
    void Tri_AGE(Ui::AFFICHAGE_JOUEUR *ui) ;
    void Tri_NOM(Ui::AFFICHAGE_JOUEUR *ui);

    void Recherche(Ui::AFFICHAGE_JOUEUR *ui);
    QString getCin() ;
    void setCin(QString value);

    bool modifier(Ui::AFFICHAGE_JOUEUR *ui);
    void pdf(Ui::AFFICHAGE_JOUEUR *ui);
private:
    QString nom,prenom,entraineur;
    QDate date_naissance;
    QString cin;
    int age;
    int valide=0;
};

#endif // JOUEURS_H

#ifndef ENTRAINEURS_H
#define ENTRAINEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
#include "gestion_entraineur.h"

#include "affichage_entraineur.h"
class Entraineurs
{
public:
    Entraineurs();
    Entraineurs(QString cin,QString nom,QString prenom,QString specialite,int nombre_titres);

    QString getCin() ;
    void setCin( QString value);
    QString getNom() ;
    void setNom( QString value);
    QString getPrenom() ;
    void setPrenom( QString value);
    QString getSpecialite();
    void setSpecialite( QString value);
    int getNombre_titres() ;
    void setNombre_titres(int value);
    int getNombre_joueurs() ;
    void setNombre_joueurs(int value);
    int getValide();
    void setValide();

    bool ajouter();
void affichage(Ui::AFFICHAGE_ENTRAINEUR *ui);
bool Supprimer(Ui::AFFICHAGE_ENTRAINEUR *ui);
void Tri_TITRE(Ui::AFFICHAGE_ENTRAINEUR *ui) ;
 void Tri_NOM(Ui::AFFICHAGE_ENTRAINEUR *ui);

 void Recherche(Ui::AFFICHAGE_ENTRAINEUR *ui);
 bool modifier(Ui::AFFICHAGE_ENTRAINEUR *ui);
private:
    QString nom,prenom,specialite,cin;
    int nombre_titres,nombre_joueurs;
int valide=0;
};

#endif // ENTRAINEURS_H

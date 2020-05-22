#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include "gestionemploye.h"
#include <QDate>

class Employe
{
public:
    Employe();

    Employe(QString cin,QString nom,QString prenom,QString departement,QString mobile,QDate date_naissance,int age );
    QString getCin() ;
    void setCin( QString &value);

    QString getNom() ;
    void setNom( QString &value);

    QString getPrenom() ;
    void setPrenom( QString &value);

    QString getDepartement() ;
    void setDepartement( QString &value);

    QString getMobile() ;
    void setMobile( QString &value);

    QDate getDate_naissance() ;
    void setDate_naissance( QDate &value);

    int getAge() ;
    void setAge(int value);

    int getCheck() ;
    void setCheck();
    bool ajouter();
    void afficher(Ui::GestionEmploye *ui);
    bool Supprimer(Ui::GestionEmploye *ui);
    void departentss(Ui::GestionEmploye *ui);
    bool modifier(Ui::GestionEmploye *ui);
    void recherche(Ui::GestionEmploye *ui);

    void CREATION_PDF();
    void GRAPH(Ui::GestionEmploye *ui);
    int TOTAL_EMP();
    int TOTAL_DEP();
private:
    QString cin,nom,prenom,departement,mobile;
    QDate date_naissance;
    int check=0;
    int age;

};

#endif // EMPLOYE_H

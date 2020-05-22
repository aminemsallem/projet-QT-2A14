#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include "gestiondepartement.h"
#include <QDate>

class departement
{
public:
    departement();
    departement(QString nom, QString reference );
    QString getNom() ;
    void setNom( QString &value);

    QString getReference() ;
    void setReference( QString &value);

    int getNombre_employee() ;
    void setNombre_employee(int value);
    bool ajouter();
    void afficher(Ui::GestionDepartement *ui);
    bool Supprimer(Ui::GestionDepartement *ui);
    bool modifier(Ui::GestionDepartement *ui);
    void TRI1(Ui::GestionDepartement *ui);
    void TRI2(Ui::GestionDepartement *ui);
private :
    QString nom;
    QString reference ;
    int nombre_employee;
};

#endif // DEPARTEMENT_H

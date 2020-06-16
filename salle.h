#ifndef SALLE_H
#define SALLE_H
#include "gestionequipements.h"
#include "gestionsalles.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>

class salle
{
public:
    salle();

    salle(int numero,QString nom,QString type,QString etat,QString descreption);
    int get_numero();
    QString get_nom();
    QString get_type();
    QString get_etat();
    QString get_desc();
    QString getType();

    void setType( QString &value);
    int get_erreur();
    bool modifier(Ui::gestionSalles *ui);

    void set_erreur();
    void set_numero(int c);
    void load(Ui::gestionSalles *ui);

    bool ajouter();
    bool Supprimer(Ui::gestionSalles *ui);
    void tri1(Ui::gestionSalles *ui) ;
    void tri2(Ui::gestionSalles *ui);
    void load_combobox2(Ui::gestionSalles *ui);
private:
    QString nom,etat,descreption,type;
    int numero,erreur=0;

};

#endif // SALLE_H

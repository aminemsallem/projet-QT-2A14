#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include "gestionequipements.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
class equipements
{
public:
    equipements();


    equipements(QString code,QString nom,QString salle,QString type,QString etat);
    QString get_code();
    QString get_nom();
    QString get_salle();
    QString get_type();
    QString get_etat();
    int get_erreur();
    void set_erreur();
    bool modifier(Ui::GestionEquipements *ui);
    void load(Ui::GestionEquipements *ui);
    void load_combobox(Ui::GestionEquipements *ui);
    void load_combobox2(Ui::GestionEquipements *ui);
    bool ajouter();
    bool Supprimer(Ui::GestionEquipements *ui);
    void Recherche(Ui::GestionEquipements *ui);
void pdf(Ui::GestionEquipements *ui);
private:
    QString nom,code,salle,etat,type;
    int erreur=0;


};

#endif // EQUIPEMENTS_H

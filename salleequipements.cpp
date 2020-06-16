#include "salleequipements.h"
#include "ui_salleequipements.h"
#include "gestionequipements.h"
#include "gestionsalles.h"
#include "../menu.h"
SalleEquipements::SalleEquipements(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SalleEquipements)
{
    ui->setupUi(this);
        this->setWindowTitle("Gestion Salles et equipements");
}

SalleEquipements::~SalleEquipements()
{
    delete ui;
}

void SalleEquipements::on_salle_clicked()
{
    gestionSalles *w = new gestionSalles;
    hide();
    w->show();
}

void SalleEquipements::on_equipements_clicked()
{
    GestionEquipements *w = new GestionEquipements;
    hide();
    w->show();
}

void SalleEquipements::on_retour_clicked()
{
    MENU *w = new MENU;
    hide();
    w->show();
}

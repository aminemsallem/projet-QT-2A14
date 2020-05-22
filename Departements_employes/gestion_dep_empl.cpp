#include "gestion_dep_empl.h"
#include "ui_gestion_dep_empl.h"

#include "gestiondepartement.h"
#include "gestionemploye.h"
Gestion_Dep_Empl::Gestion_Dep_Empl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Dep_Empl)
{
    ui->setupUi(this);
}

Gestion_Dep_Empl::~Gestion_Dep_Empl()
{
    delete ui;
}

void Gestion_Dep_Empl::on_departements_clicked()
{
    GestionDepartement *w = new GestionDepartement;
    hide();
    w->show();
}

void Gestion_Dep_Empl::on_employe_clicked()
{
    GestionEmploye *w = new GestionEmploye;
    hide();
    w->show();
}

void Gestion_Dep_Empl::on_pushButton_clicked()
{

}

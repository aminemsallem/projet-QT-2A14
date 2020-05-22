#include "gestion_entraineur.h"
#include "ui_gestion_entraineur.h"
#include "ajouterentraineur.h"

#include "affichage_entraineur.h"
#include "gestion_entraineur_joueur.h"
Gestion_Entraineur::Gestion_Entraineur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Entraineur)
{
    ui->setupUi(this);
}

Gestion_Entraineur::~Gestion_Entraineur()
{
    delete ui;
}

void Gestion_Entraineur::on_entraineurs_clicked()
{
    AjouterEntraineur *w = new AjouterEntraineur;
    hide();
    w->show();
}

void Gestion_Entraineur::on_pushButton_clicked()
{
    Gestion_Entraineur_Joueur *w = new Gestion_Entraineur_Joueur;
    hide();
    w->show();
}

void Gestion_Entraineur::on_entraineurs_2_clicked()
{
    AFFICHAGE_ENTRAINEUR *w = new AFFICHAGE_ENTRAINEUR;
    hide();
    w->show();
}

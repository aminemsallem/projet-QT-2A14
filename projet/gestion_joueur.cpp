#include "gestion_joueur.h"
#include "ui_gestion_joueur.h"
#include "ajouterjoueur.h"
#include "affichage_joueur.h"
#include "gestion_entraineur_joueur.h"
Gestion_Joueur::Gestion_Joueur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Joueur)
{
    ui->setupUi(this);
}

Gestion_Joueur::~Gestion_Joueur()
{
    delete ui;
}

void Gestion_Joueur::on_entraineurs_clicked()
{
    AjouterJoueur *w = new AjouterJoueur;
    hide();
    w->show();
}

void Gestion_Joueur::on_pushButton_clicked()
{
    Gestion_Entraineur_Joueur *w = new Gestion_Entraineur_Joueur;
    hide();
    w->show();
}
void Gestion_Joueur::on_entraineurs_2_clicked()
{
    AFFICHAGE_JOUEUR *w = new AFFICHAGE_JOUEUR;
    hide();
    w->show();
}




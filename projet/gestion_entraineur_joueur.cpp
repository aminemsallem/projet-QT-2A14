#include "gestion_entraineur_joueur.h"
#include "ui_gestion_entraineur_joueur.h"
#include "gestion_joueur.h"
#include "gestion_entraineur.h"
Gestion_Entraineur_Joueur::Gestion_Entraineur_Joueur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Entraineur_Joueur)
{
    ui->setupUi(this);
}

Gestion_Entraineur_Joueur::~Gestion_Entraineur_Joueur()
{
    delete ui;
}

void Gestion_Entraineur_Joueur::on_entraineurs_clicked()
{

    Gestion_Entraineur *w = new Gestion_Entraineur;
    hide();
    w->show();
}



void Gestion_Entraineur_Joueur::on_joueurs_clicked()
{

    Gestion_Joueur *w = new Gestion_Joueur;
    hide();
    w->show();
}

void Gestion_Entraineur_Joueur::on_pushButton_clicked()
{


}

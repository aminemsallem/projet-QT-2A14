#include "affichage_entraineur.h"
#include "ui_affichage_entraineur.h"
#include "entraineurs.h"
#include "gestion_entraineur.h"

#include<QDebug>
#include <QMessageBox>
AFFICHAGE_ENTRAINEUR::AFFICHAGE_ENTRAINEUR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_ENTRAINEUR)
{
    ui->setupUi(this);
    Entraineurs e ;
    e.affichage(ui);
}

AFFICHAGE_ENTRAINEUR::~AFFICHAGE_ENTRAINEUR()
{
    delete ui;
}

void AFFICHAGE_ENTRAINEUR::on_annuler_clicked()
{
    Gestion_Entraineur *w = new Gestion_Entraineur;
    hide();
    w->show();
}

void AFFICHAGE_ENTRAINEUR::on_supprimer_clicked()
{
    Entraineurs e;
    e.Supprimer(ui);
    e.affichage(ui);
}

void AFFICHAGE_ENTRAINEUR::on_comboBox_currentIndexChanged(int index)
{
    Entraineurs e;
    if (index==0)
    { e.Tri_NOM(ui);

    }

    else
    {  e.Tri_TITRE(ui);

    }
}

void AFFICHAGE_ENTRAINEUR::on_search_clicked()
{
    Entraineurs e;
    e.Recherche(ui);
}

void AFFICHAGE_ENTRAINEUR::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->titres->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->reference->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->stackedWidget->setCurrentIndex(1);

}

void AFFICHAGE_ENTRAINEUR::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_ENTRAINEUR::on_Valider_clicked()
{
    Entraineurs e;

    if(e.modifier(ui))
    {
        QMessageBox ::information(this,"","entraineur modifié")  ;
        ui->stackedWidget->setCurrentIndex(0);
        e.affichage(ui);
    }
    else
    { QMessageBox ::critical(this,"","erreur de modification") ;}
}


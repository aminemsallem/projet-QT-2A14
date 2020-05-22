#include "gestiondepartement.h"
#include "ui_gestiondepartement.h"
#include"departement.h"
#include "connexion.h"
#include "gestion_dep_empl.h"
#include <QMessageBox>
GestionDepartement::GestionDepartement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionDepartement)
{
    ui->setupUi(this);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(2,false);
    departement d;
    d.afficher(ui);

}

GestionDepartement::~GestionDepartement()
{
    delete ui;
}

void GestionDepartement::on_pushButton_clicked()
{     Gestion_Dep_Empl *w = new Gestion_Dep_Empl;
      hide();
        w->show();
}



void GestionDepartement::on_modifier_clicked()
{ departement d;
    if(d.modifier(ui))
    {  QMessageBox ::information(this,"","Departement Modifié")  ;
        ui->tabWidget->setCurrentIndex(1);
        d.afficher(ui);
        ui->tabWidget->setTabEnabled(2,false);
    }
}

void GestionDepartement::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->tabWidget->setTabEnabled(2,true);
    ui->referenceUp->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->referenceUp->setEnabled(false);
    ui->nomUp->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->tabWidget->setCurrentIndex(2);
}

void GestionDepartement::on_tabWidget_currentChanged(int index)
{
    departement d;
    d.afficher(ui);

}

void GestionDepartement::on_ajouter_clicked()
{
    QString nom= ui->nom->text();
    QString reference= ui->reference->text();
    departement d (nom,reference);

    if(d.ajouter())
    {  QMessageBox ::information(this,"","Departement ajouté")  ;
        ui->tabWidget->setCurrentIndex(1);
        d.afficher(ui);
    }

}

void GestionDepartement::on_reset_clicked()
{
    ui->nomUp->clear();
    ui->referenceUp->clear();
    ui->tabWidget->setTabEnabled(2,false);
    ui->tabWidget->setCurrentIndex(1);
}

void GestionDepartement::on_supprimer_clicked()
{
    departement d;

    if(d.Supprimer(ui))
    {
        QMessageBox ::information(this,"","Departement Supprimé")  ;
        ui->tabWidget->setCurrentIndex(1);
        d.afficher(ui);
    }
}

void GestionDepartement::on_reset_2_clicked()
{
    ui->nom->clear();
    ui->reference->clear();
}

void GestionDepartement::on_radioButton_clicked()
{
    departement d;
    d.TRI2(ui);

}

void GestionDepartement::on_radioButton_2_clicked()
{
    departement d;
    d.TRI1(ui);
}

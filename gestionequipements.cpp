#include "gestionequipements.h"
#include "ui_gestionequipements.h"
#include "equipements.h"
#include "salleequipements.h"
#include "stat.h"
#include <QMessageBox>
GestionEquipements::GestionEquipements(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionEquipements)
{

    ui->setupUi(this);
    this->setWindowTitle("Gestion Equipements");
    equipements eq;

    eq.load(ui);

    eq.load_combobox(ui);
    eq.load_combobox2(ui);
    ui->modifier->hide();
    ui->reset->hide();
}

GestionEquipements::~GestionEquipements()
{
    delete ui;
}

void GestionEquipements::on_ajouter_clicked()
{

    QRegExp Exp1 ("[a-z]$");
    QRegExp Exp2 ("^[a-z]");
    QRegExp Nom = Exp1 ;
    QRegExp Nom2 = Exp2 ;
    QString msg_nom ="le nom est invalide";
    QString msg_etat ="l'etat est invalide";
    QString msg_type ="le type est invalide";
    QString msg_numero ="la numreo doit etre composé de 3 chiffres au minimum ";
    QString msg_vide="";

    QString nom= ui->nom->text();
    QString numero2= ui->Numero->text();
    QString type= ui->type->text();
    QString etat= ui->etat->currentText();
    QString salle= ui->salles->currentText();

    equipements eq(numero2,nom,salle,type,etat);

    if(numero2.size()>=3)
    {ui->Numero->setStyleSheet("QLineEdit { color: black;}");
        ui->numero_t->setText(msg_vide);}
    else {
        ui->Numero->setStyleSheet("QLineEdit { color: red;}");
        eq.set_erreur();
        ui->numero_t->setText(msg_numero);
        ui->numero_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }

    if ((!nom.contains(Nom))||(!nom.contains(Nom2)))
    {

        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->nom_t->setText(msg_nom);
        ui->nom_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        eq.set_erreur();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->nom_t->setText(msg_vide);

    }

    if ((!type.contains(Nom))||(!type.contains(Nom2)))
    {
        ui->type->setStyleSheet("QLineEdit { color: red;}");
        eq.set_erreur();
        ui->type_t->setText(msg_etat);
        ui->type_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->type->setStyleSheet("QLineEdit { color: black;}");
        ui->type_t->setText(msg_vide); }



    if (eq.get_erreur()==0)
    {
        if (eq.ajouter())
        {
            QMessageBox ::information(this,"","la salle est ajoutee")  ;
            ui->nom->clear();
            ui->Numero->clear();
            ui->type->clear();
            ui->etat->clear();

            eq.load(ui);
            eq.load_combobox(ui);
        }
        else
        {QMessageBox ::critical(this,"","numero de salle dupliquée") ;
            ui->Numero->setStyleSheet("QLineEdit { color: red;}");
        }
    }
    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;
    }





}

void GestionEquipements::on_annuler_clicked()
{
    SalleEquipements *w = new SalleEquipements;
    hide();
    w->show();
}

void GestionEquipements::on_pushButton_clicked()
{

}

void GestionEquipements::on_tableView_clicked(const QModelIndex &index)
{
    equipements eq;
    ui->Numero->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->Numero->setEnabled(false);
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->type->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());

    eq.load_combobox(ui);
    ui->salles->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    eq.load_combobox2(ui);
    ui->etat->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->ajouter->hide();
    ui->modifier->show();
    ui->reset->show();

}

void GestionEquipements::on_reset_clicked()
{   equipements eq;
    ui->ajouter->show();
    ui->modifier->hide();
    ui->reset->hide();
    ui->Numero->clear();
    ui->nom->clear();
    ui->type->clear();
    ui->etat->clear();
    eq.load_combobox(ui);
    eq.load_combobox2(ui);
    ui->Numero->setEnabled(true);
}

void GestionEquipements::on_search_clicked()
{
    equipements eq;
    eq.Recherche(ui);
}



void GestionEquipements::on_stats_clicked()
{
    Stat *w = new Stat;
    hide();
    w->show();
}

void GestionEquipements::on_modifier_clicked()
{
    equipements eq;
    if( eq.modifier(ui))
    {
        eq.load(ui);
        ui->ajouter->show();
        ui->modifier->hide();
        ui->reset->hide();
        ui->Numero->clear();
        ui->nom->clear();
        ui->type->clear();
        ui->etat->clear();
        eq.load_combobox(ui);
        eq.load_combobox2(ui);
        ui->Numero->setEnabled(true);
        QMessageBox ::information(this,"","equipement modifié")  ;
    }
    else
    { QMessageBox ::critical(this,"","erreur de modification") ;}
}

void GestionEquipements::on_supprimer_clicked()
{
    equipements eq;
        eq.Supprimer(ui);
         eq.load(ui);
}

void GestionEquipements::on_PDF_clicked()
{
    equipements eq;
        eq.pdf(ui);

}

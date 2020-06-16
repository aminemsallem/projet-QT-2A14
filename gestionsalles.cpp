#include "gestionsalles.h"
#include "ui_gestionsalles.h"
#include "salleequipements.h"
#include "salle.h"
#include <QMessageBox>
gestionSalles::gestionSalles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestionSalles)
{
    ui->setupUi(this);
        this->setWindowTitle("Gestion salles");
    salle s;
    ui->modifier->hide();
    ui->reset->hide();
    s.load_combobox2(ui);

    s.load(ui);
}

gestionSalles::~gestionSalles()
{
    delete ui;
}

void gestionSalles::on_ajouter_clicked()
{

    QRegExp Exp1 ("[a-z]$");
    QRegExp Exp2 ("^[a-z]");
    QRegExp Nom = Exp1 ;
    QRegExp Nom2 = Exp2 ;
    QString msg_nom ="le nom est invalide";
    QString msg_service ="le nom de service est invalide";
    QString msg_numero ="la numreo doit etre composé de 3 chiffres au minimum ";
    QString msg_vide="";


    QString nom= ui->nom->text();
    int numero= ui->Numero->text().toInt();
    QString numero2= ui->Numero->text();
    QString type= ui->type->text();
    QString etat= ui->etat->currentText();
    QString description= ui->description->toPlainText();

    salle s(numero,nom,type,etat,description);

    if(numero2.size()>=3)
    {ui->Numero->setStyleSheet("QLineEdit { color: black;}");
        ui->numero_t->setText(msg_vide);}
    else {
        ui->Numero->setStyleSheet("QLineEdit { color: red;}");
        s.set_erreur();
        ui->numero_t->setText(msg_numero);
        ui->numero_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }

    if ((!nom.contains(Nom))||(!nom.contains(Nom2)))
    {
        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->nom_t->setText(msg_nom);
        ui->nom_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        s.set_erreur();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->nom_t->setText(msg_vide);

    }

    if ((!type.contains(Nom))||(!type.contains(Nom2)))
    {

        ui->type->setStyleSheet("QLineEdit { color: red;}");
        s.set_erreur();
        ui->type_t->setText(msg_service);
        ui->type_t->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->type->setStyleSheet("QLineEdit { color: black;}");
        ui->type_t->setText(msg_vide); }



    if (s.get_erreur()==0)
    {
        if (s.ajouter())
        {
            QMessageBox ::information(this,"","la salle est ajoutee")  ;
            ui->nom->clear();
            ui->Numero->clear();
            ui->type->clear();
            ui->etat->clear();
            ui->description->clear();
            s.load(ui);
        }
        else
        {QMessageBox ::critical(this,"","numero ou nom de la salle est dupliquée") ;
            ui->Numero->setStyleSheet("QLineEdit { color: red;}");
            ui->nom->setStyleSheet("QLineEdit { color: red;}");
        }
    }
    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;
    }





}

void gestionSalles::on_annuler_clicked()
{
    SalleEquipements *w = new SalleEquipements;
    hide();
    w->show();
}

void gestionSalles::on_tableView_activated(const QModelIndex &index)
{

}

void gestionSalles::on_supprimer_clicked()
{    salle s;
     s.Supprimer(ui);
      s.load(ui);

}

void gestionSalles::on_comboBox_currentIndexChanged(int index)
{
    salle s;
    if (index==0)
    { s.tri2(ui);}

    else
    {  s.tri1(ui);

    }
}

void gestionSalles::on_reset_clicked()
{
    salle s;
    ui->ajouter->show();
    ui->modifier->hide();
    ui->reset->hide();
    ui->Numero->clear();
    ui->nom->clear();
    ui->type->clear();
    ui->etat->clear();
    ui->nom->setEnabled(true);

}

void gestionSalles::on_tableView_clicked(const QModelIndex &index)
{
    salle s;
    ui->Numero->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->nom->setEnabled(false);
    ui->type->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());

    s.load_combobox2(ui);
    ui->etat->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());

    ui->description->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->ajouter->hide();
    ui->modifier->show();
    ui->reset->show();

}

void gestionSalles::on_modifier_clicked()
{
    salle s;
    if( s.modifier(ui))
    {
        s.load(ui);
        ui->ajouter->show();
        ui->modifier->hide();
        ui->reset->hide();
        ui->Numero->clear();
        ui->nom->clear();
        ui->type->clear();
        ui->etat->clear();
        s.load_combobox2(ui);
        ui->nom->setEnabled(true);
        QMessageBox ::information(this,"","salle modifiée")  ;
    }
    else
    { QMessageBox ::critical(this,"","erreur de modification") ;}
}

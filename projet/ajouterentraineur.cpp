#include "ajouterentraineur.h"
#include "ui_ajouterentraineur.h"
#include "entraineurs.h"
#include "gestion_entraineur.h"
#include <QMessageBox>
AjouterEntraineur::AjouterEntraineur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterEntraineur)
{
    ui->setupUi(this);
}

AjouterEntraineur::~AjouterEntraineur()
{
    delete ui;
}

void AjouterEntraineur::on_Valider_clicked()
{

    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");

    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_specialite ="specialite invalide";
    QString msg_nbr="nombre de titres invalide";
    QString msg_vide="";

    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    int titres= ui->titres->text().toInt();
    QString specialite= ui->specialite->text();


    QString reference=nom.rightJustified(2, '.', true)+"_"+prenom.rightJustified(2, '.', true)+"_"+specialite;


    Entraineurs e(reference,nom,prenom,specialite,titres);


    if ((!nom.contains(regex1))||(!nom.contains(regex2)))
    {
        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->text_nom->setText(msg_nom);
        ui->text_nom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nom->setText(msg_vide);

    }

    if ((!prenom.contains(regex1))||(!prenom.contains(regex2)))
    {
        ui->prenom->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_prenom->setText(msg_prenom);
        ui->text_prenom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->prenom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_prenom->setText(msg_vide);
    }

    if ((!specialite.contains(regex1))||(!prenom.contains(regex2)))
    {
        ui->specialite->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_specialite->setText(msg_specialite);
        ui->text_specialite->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->specialite->setStyleSheet("QLineEdit { color: black;}");
        ui->text_specialite->setText(msg_vide);
    }






    if (e.getValide()==0)
    {
        if (e.ajouter())
        {

            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->prenom->setStyleSheet("QLineEdit { color: green;}");
            ui->specialite->setStyleSheet("QLineEdit { color: green;}");
            ui->titres->setStyleSheet("QLineEdit { color: green;}");
            {QMessageBox ::information(this,""," entraineur ajouté  ") ;}
        }

    }

    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;}

}

void AjouterEntraineur::on_Annuler_clicked()
{
    Gestion_Entraineur *w = new Gestion_Entraineur;
    hide();
    w->show();
}

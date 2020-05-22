#include "ajouterjoueur.h"
#include "ui_ajouterjoueur.h"
#include "gestion_joueur.h"
#include "joueurs.h"
#include <QMessageBox>
AjouterJoueur::AjouterJoueur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterJoueur)
{
    ui->setupUi(this);

    joueurs e;

    e.list_entraineurs2(ui);
}

AjouterJoueur::~AjouterJoueur()
{
    delete ui;
}

void AjouterJoueur::on_Annuler_clicked()
{
    Gestion_Joueur *w = new Gestion_Joueur;
    hide();
    w->show();
}

void AjouterJoueur::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_cin ="cin invalide";
    QString msg_nbr="nombre de titres invalide";
    QString msg_vide="";

    QString cin= ui->cin->text();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString entraineur= ui->entraineur->currentText();
    QDate date=ui->date->date();
    QDate date2=QDate::currentDate();

    int age=date2.year()-date.year();

    joueurs e;
    if(cin.size()==8)
    {ui->cin->setStyleSheet("QLineEdit { color: black;}");
        ui->text_cin->setText(msg_vide);}
    else {
        ui->cin->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_cin->setText(msg_cin);
        ui->text_cin->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }

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






    if (age<8 )
    {  e.setValide();
        ui->date_text->setText("age très petit");
        ui->date_text->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else if (age>40)
    {     ui->date_text->setText("age très grand");
        ui->date_text->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else
    { ui->date_text->setText(msg_vide);}



    if (e.getValide()==0)
    { joueurs jr(cin,nom,prenom,entraineur,date,age);
        if (jr.ajouter())
        {

            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->prenom->setStyleSheet("QLineEdit { color: green;}");
            ui->cin->setStyleSheet("QLineEdit { color: green;}");

            {QMessageBox ::information(this,""," joueur ajouté  ") ;}
        }
        else {
            {QMessageBox ::critical(this,"","erreur d'ajout \n cin dupliquée") ;
                ui->cin->setStyleSheet("QLineEdit { color: red;}");
            }
        }
    }

    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;}
}

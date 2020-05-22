#include "gestionemploye.h"
#include "ui_gestionemploye.h"
#include "employe.h"
#include "gestion_dep_empl.h"
#include <QMessageBox>
GestionEmploye::GestionEmploye(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionEmploye)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(2,false);
    Employe e;

    e.departentss(ui);
    e.afficher(ui);
    e.GRAPH(ui);
}

GestionEmploye::~GestionEmploye()
{
    delete ui;
}

void GestionEmploye::on_ajouter_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_cin ="cin invalide";
    QString msg_mobile ="mobile invalide";
    QString msg_vide="";
    QString cin= ui->cin->text();
    QString mobile= ui->mobile->text();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString departement= ui->departement->currentText();
    QDate date=ui->dateEdit->date();
    QDate date2=QDate::currentDate();
    int age=date2.year()-date.year();

    Employe e;
    if(cin.size()==8)
    {ui->cin->setStyleSheet("QLineEdit { color: black;}");
        ui->text_cin->setText(msg_vide);}
    else {
        ui->cin->setStyleSheet("QLineEdit { color: red;}");
        e.setCheck();
        ui->text_cin->setText(msg_cin);
        ui->text_cin->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    if(mobile.size()==8)
    {ui->mobile->setStyleSheet("QLineEdit { color: black;}");
        ui->text_mobile->setText(msg_vide);}
    else {
        ui->mobile->setStyleSheet("QLineEdit { color: red;}");
        e.setCheck();
        ui->text_mobile->setText(msg_mobile);
        ui->text_mobile->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    if ((!nom.contains(regex1))||(!nom.contains(regex2)))
    {
        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->text_nom->setText(msg_nom);
        ui->text_nom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setCheck();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nom->setText(msg_vide);

    }

    if ((!prenom.contains(regex1))||(!prenom.contains(regex2)))
    {
        ui->prenom->setStyleSheet("QLineEdit { color: red;}");
        e.setCheck();
        ui->text_prenom->setText(msg_prenom);
        ui->text_prenom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->prenom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_prenom->setText(msg_vide);
    }

    if (age<18 )
    {     e.setCheck();
        ui->text_date->setText("age très petit");
        ui->text_date->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else if (age>60)
    {     ui->text_date->setText("age très grand");
        ui->text_date->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else
    { ui->text_date->setText(msg_vide);}



    if (e.getCheck()==0)
    {
        Employe e(cin,nom,prenom,departement,mobile,date,age);
        if (e.ajouter())
        {

            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->prenom->setStyleSheet("QLineEdit { color: green;}");
            ui->cin->setStyleSheet("QLineEdit { color: green;}");

            {QMessageBox ::information(this,""," employe ajouté  ") ;}
            e.GRAPH(ui);
            e.afficher(ui);

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

void GestionEmploye::on_reset_2_clicked()
{
    ui->mobile->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->dateEdit->clear();
    ui->cin->clear();
}

void GestionEmploye::on_supprimer_clicked()
{
    Employe e;

    if(e.Supprimer(ui))
    {
        QMessageBox ::information(this,"","Employe Supprimé")  ;
        e.GRAPH(ui);
        e.afficher(ui);

    }
}

void GestionEmploye::on_pushButton_clicked()
{
    Gestion_Dep_Empl *w = new Gestion_Dep_Empl;
    hide();
    w->show();
}

void GestionEmploye::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->tabWidget->setTabEnabled(2,true);
    ui->cin_mod->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->nom_mod->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->prenom_mod->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->mobile_mod->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());
    ui->departement_mod->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());


    ui->tabWidget->setCurrentIndex(2);
}

void GestionEmploye::on_reset_clicked()
{
    ui->tabWidget->setTabEnabled(2,false);
    ui->tabWidget->setCurrentIndex(1);
}

void GestionEmploye::on_modifier_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_mobile ="mobile invalide";
    QString msg_vide="";

    QString mobile= ui->mobile_mod->text();
    QString nom= ui->nom_mod->text();
    QString prenom= ui->prenom_mod->text();
    QString departement= ui->departement_mod->currentText();



    Employe e;

    if(mobile.size()==8)
    {ui->mobile_mod->setStyleSheet("QLineEdit { color: black;}");
        ui->text_mobile_2->setText(msg_vide);}
    else {
        ui->mobile_mod->setStyleSheet("QLineEdit { color: red;}");
        e.setCheck();
        ui->text_mobile_2->setText(msg_mobile);
        ui->text_mobile_2->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    if ((!nom.contains(regex1))||(!nom.contains(regex2)))
    {
        ui->nom_mod->setStyleSheet("QLineEdit { color: red;}");
        ui->text_nom_2->setText(msg_nom);
        ui->text_nom_2->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setCheck();
    }
    else { ui->nom_mod->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nom_2->setText(msg_vide);

    }

    if ((!prenom.contains(regex1))||(!prenom.contains(regex2)))
    {
        ui->prenom_mod->setStyleSheet("QLineEdit { color: red;}");
        e.setCheck();
        ui->text_prenom_2->setText(msg_prenom);
        ui->text_prenom_2->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->prenom_mod->setStyleSheet("QLineEdit { color: black;}");
        ui->text_prenom_2->setText(msg_vide);
    }


    if (e.getCheck()==0)
    {

        if (e.modifier(ui))
        {
            QMessageBox ::information(this,""," employe modifié  ") ;
            ui->tabWidget->setTabEnabled(2,false);
            ui->tabWidget->setCurrentIndex(1);
            e.afficher(ui);
        }

    }

    else
    {QMessageBox ::information(this,"","erreur de modification  ") ;}
}

void GestionEmploye::on_rechercher_clicked()
{   Employe e;
    e.recherche(ui);
}

void GestionEmploye::on_pdf_clicked()
{
    Employe e;
    e.CREATION_PDF();
}

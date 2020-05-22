#include "affichage_joueur.h"
#include "ui_affichage_joueur.h"
#include "joueurs.h"
#include "gestion_joueur.h"
#include <QMessageBox>
AFFICHAGE_JOUEUR::AFFICHAGE_JOUEUR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_JOUEUR)
{
    ui->setupUi(this);
    joueurs j ;
    j.affichage(ui);

}

AFFICHAGE_JOUEUR::~AFFICHAGE_JOUEUR()
{
    delete ui;
}

void AFFICHAGE_JOUEUR::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_JOUEUR::on_supprimer_clicked()
{
    joueurs j;
    j.Supprimer(ui);
    j.affichage(ui);
}

void AFFICHAGE_JOUEUR::on_annuler_clicked()
{
    Gestion_Joueur *w = new Gestion_Joueur;
    hide();
    w->show();
}

void AFFICHAGE_JOUEUR::on_search_clicked()
{
    joueurs j;
    j.Recherche(ui);
}

void AFFICHAGE_JOUEUR::on_comboBox_currentIndexChanged(int index)
{
    joueurs j;
    if (index==0)
    { j.Tri_NOM(ui);

    }

    else
    {  j.Tri_AGE(ui);

    }
}

void AFFICHAGE_JOUEUR::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_vide="";
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString entraineur= ui->entraineur->currentText();
    int age=ui->age->text().toInt();

    joueurs e;

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
    else if (age>38)
    {     ui->date_text->setText("age très grand");
        ui->date_text->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else
    { ui->date_text->setText(msg_vide);}

    if (e.getValide()==0)
    {
        if (e.modifier(ui))
        {
            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->prenom->setStyleSheet("QLineEdit { color: green;}");
            ui->age->setStyleSheet("QLineEdit { color: green;}");
            {QMessageBox ::information(this,""," joueur modifier  ") ;}
            e.affichage(ui);
        }
        else {
            {QMessageBox ::critical(this,"","erreur de modification") ;

            }
        }
    }

    else
    {QMessageBox ::information(this,"","erreur de modification") ;}


}

void AFFICHAGE_JOUEUR::on_tableView_doubleClicked(const QModelIndex &index)
{
    joueurs j;
    j.list_entraineurs(ui);
    ui->entraineur->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->age->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());
    ui->prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->cin->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->cintex->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->cin->setEnabled(false);

    ui->stackedWidget->setCurrentIndex(1);
}

void AFFICHAGE_JOUEUR::on_PDF_clicked()
{
    joueurs j;
    j.pdf(ui);
}

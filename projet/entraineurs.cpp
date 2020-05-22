#include "entraineurs.h"

#include "affichage_entraineur.h"
#include "ui_affichage_entraineur.h"
Entraineurs::Entraineurs()
{

}

Entraineurs::Entraineurs(QString cin, QString nom, QString prenom, QString specialite, int nombre_titres)
{
    this->setCin(cin);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setNombre_titres(nombre_titres);
    this->setSpecialite(specialite);
}
QString Entraineurs::getCin()
{
    return cin;
}

void Entraineurs::setCin(QString value)
{
    cin = value;
}

QString Entraineurs::getNom()
{
    return nom;
}

void Entraineurs::setNom( QString value)
{
    nom = value;
}

QString Entraineurs::getPrenom()
{
    return prenom;
}

void Entraineurs::setPrenom(QString value)
{
    prenom = value;
}

QString Entraineurs::getSpecialite()
{
    return specialite;
}

void Entraineurs::setSpecialite( QString value)
{
    specialite = value;
}

int Entraineurs::getNombre_titres()
{
    return nombre_titres;
}

void Entraineurs::setNombre_titres(int value)
{
    nombre_titres = value;
}

int Entraineurs::getNombre_joueurs()
{
    return nombre_joueurs;
}

void Entraineurs::setNombre_joueurs(int value)
{
    nombre_joueurs = value;
}

int Entraineurs::getValide()
{
    return valide;
}

void Entraineurs::setValide()
{
    valide = 1;
}

bool Entraineurs::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO entraineurs (reference, NOM, PRENOM,NOMBRE_JOUEURS,NOMBRE_TITRES,SPECIALITE) "
                  "VALUES (:reference, :nom, :prenom,:nbre_joueurs,:nombre_titre,:specialite)");
    query.bindValue(":reference",getCin());
    query.bindValue(":nom", getNom());
    query.bindValue(":prenom",getPrenom());
    query.bindValue(":nbre_joueurs", 0);
    query.bindValue(":nombre_titre", getNombre_titres());
    query.bindValue(":specialite", getSpecialite());

    return    query.exec();
}

void Entraineurs::affichage(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from entraineurs");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

void Entraineurs::Tri_TITRE(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from entraineurs order by NOMBRE_TITRES");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void Entraineurs::Tri_NOM(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from entraineurs order by NOM");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void Entraineurs::Recherche(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from entraineurs where (reference LIKE '%"+reference+"%' or NOM LIKE '%"+reference+"%' or PRENOM LIKE '%"+reference+"%' )");

    if ( q.exec() )
    { modal->setQuery(q);
      ui->tableView->setModel(modal);}

}
bool Entraineurs::Supprimer(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM entraineurs WHERE reference ='"+id+"'");
    q.exec();


}

bool Entraineurs::modifier(Ui::AFFICHAGE_ENTRAINEUR *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE entraineurs set NOM=:NOM,PRENOM=:PRENOM,NOMBRE_TITRES=:NOMBRE_TITRES where reference='"+ref+"'") ;

    q.bindValue(":NOM",ui->nom->text());
    q.bindValue(":PRENOM",ui->prenom->text());
    q.bindValue(":NOMBRE_TITRES",ui->titres->text());

    q.exec();

}


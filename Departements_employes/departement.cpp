#include "departement.h"
#include "ui_gestiondepartement.h"
departement::departement()
{

}

departement::departement(QString nom, QString reference)
{
    this->setNom( nom);
    this->setReference(reference);
    this->setNombre_employee(0);

}

QString departement::getNom()
{
    return nom;
}

void departement::setNom( QString &value)
{
    nom = value;
}

QString departement::getReference()
{
    return reference;
}

void departement::setReference( QString &value)
{
    reference = value;
}

int departement::getNombre_employee()
{
    return nombre_employee;
}

void departement::setNombre_employee(int value)
{
    nombre_employee = value;
}

bool departement::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO DEPARTEMENTS (REFERENCE, NOM, NOMBRE_EMPLOYE) "
                  "VALUES (:reference, :nom, :NOMBRE_EMPLOYE)");
    query.bindValue(":reference",getReference());
    query.bindValue(":nom", getNom());
    query.bindValue(":NOMBRE_EMPLOYE",getNombre_employee() );

    return    query.exec();
}

void departement::afficher(Ui::GestionDepartement *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from departements");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

bool departement::modifier(Ui::GestionDepartement *ui)
{
    QSqlQuery q;

    QString ref=ui->referenceUp->text();


    q.prepare("UPDATE departements set NOM=:nom where reference ='"+ref+"'") ;

    q.bindValue(":nom",ui->nomUp->text());


    return q.exec();

}
bool departement::Supprimer(Ui::GestionDepartement *ui)
{
    QSqlQuery q;
    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("DELETE FROM DEPARTEMENTS WHERE reference ='"+ref+"'");
    return q.exec();

}
void departement::TRI1(Ui::GestionDepartement *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from DEPARTEMENTS order by NOMBRE_EMPLOYE");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void departement::TRI2(Ui::GestionDepartement *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from DEPARTEMENTS order by NOM");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

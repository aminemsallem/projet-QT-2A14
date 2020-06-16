#include "salle.h"
#include "gestionsalles.h"
#include "gestionsalles.h"
#include "ui_gestionsalles.h"
salle::salle()
{

}

salle::salle(int numero, QString nom, QString type, QString etat, QString descreption)
{
    this->numero=numero;
    this->nom=nom;
    this->etat=etat;
    this->type=type;
    this->descreption=descreption;

}

bool salle::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO salles (numero, NOM, type,etat,DESCRIPTION) "
                  "VALUES (:numero, :nom,:type,:etat,:description)");
    query.bindValue(":numero",numero);
    query.bindValue(":nom", nom);
    query.bindValue(":description", descreption);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    return    query.exec();
}

bool salle::modifier(Ui::gestionSalles *ui)
{
    QSqlQuery q;

    QString val=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();

    q.prepare("UPDATE salles set NUMERO=:NUMERO,description=:description,ETAT=:etat,TYPE=:type where nom='"+val+"'") ;


    q.bindValue(":NUMERO",ui->Numero->text());
    q.bindValue(":description",ui->description->toPlainText());
    q.bindValue(":etat",ui->etat->currentText());
    q.bindValue(":type",ui->type->text());

    if ( q.exec())
    {

        return true ;
    }
    else
    {

        return false;
    }
}

void salle::load_combobox2(Ui::gestionSalles *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select NOM from etat");
    q.exec();
    modal->setQuery(q);
    ui->etat->setModel(modal);
}

QString salle::getType()
{
    return type;
}

void salle::setType(QString &value)
{
    type = value;
}

int salle::get_erreur()
{
    return erreur;
}

void salle::set_erreur()
{
    this->erreur=1;
}

void salle::load(Ui::gestionSalles *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from salles");
    q.exec();
    modal->setQuery(q);

    ui->tableView->setModel(modal);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
bool salle::Supprimer(Ui::gestionSalles *ui)
{
    QSqlQuery q;

    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM equipement WHERE salle ='"+nom+"'");

    if(q.exec())
    {
        qWarning("ok");
        q.prepare("DELETE FROM salles WHERE numero ='"+id+"'");
        q.exec();
    }


}

void salle::tri1(Ui::gestionSalles *ui)
{

    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from salles order by numero");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void salle::tri2(Ui::gestionSalles *ui)
{

    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from salles order by nom");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


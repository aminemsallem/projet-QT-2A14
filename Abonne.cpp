#include "Abonne.h"
#include "QDebug"
Abonne::Abonne()
{

}

Abonne::Abonne(int id,QString nom,QString prenom, QDate date,QString numero)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->datenaissance=date;
    this->numerocarte=numero;

}
Abonne::Abonne(int id,QString nom,QString prenom,QString numero)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->numerocarte=numero;

}


bool Abonne::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO abonne (id,nom, prenom, datenaissance, numerocarte) "
                        "VALUES (:id, :nom, :prenom, :date, :Numero)");
    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date", datenaissance);
    query.bindValue(":Numero", numerocarte);

    return    query.exec();

}

QSqlQueryModel * Abonne::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonne");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));


    return model;
}

bool Abonne::supprimer(QString sup)
{
QSqlQuery query;
query.prepare("DELETE FROM Abonne WHERE id = :id");
query.bindValue(":id", sup);
return    query.exec();
}


 QSqlQueryModel * Abonne::chercher(QString rech)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from abonne where upper(nom) like upper('%"+rech+"%') or upper(prenom) like upper('%"+rech+"%') or upper(numerocarte) like upper('%"+rech+"%') ");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));


         return model;
 }

 void Abonne::getAbonne(QString id)
 {
     QSqlQuery query;
     if(query.exec("select id,nom,prenom,datenaissance,numerocarte from abonne where id ='"+id+"'"))
     {

         while(query.next())
         {

             this->setId(query.value(0).toInt());
             this->setNom(query.value(1).toString());
             this->setPrenom(query.value(2).toString());
             this->setDate(query.value(3).toDate());
             this->setNumero(query.value(4).toString());


         }
     }
 }




 void Abonne::setNom(QString x)
 {
     this->nom=x;
 }
 void Abonne::setPrenom(QString x)
 {
     this->prenom=x;
 }
 void Abonne::setDate(QDate x)
 {
     this->datenaissance=x;
 }
 void Abonne::setNumero(QString x)
 {
     this->numerocarte=x;
 }
 void Abonne::setId(int x)
 {
     this->id=x;
 }


 QString Abonne::getNom()
 {
     return this->nom;
 }
 QString Abonne::getPrenom()
 {
     return this->prenom;
 }
 QDate Abonne::getDate()
 {
     return this->datenaissance;
 }
 QString Abonne::getNumero()
 {
     return this->numerocarte;
 }
 int Abonne::getId()
 {
     return this->id;
 }

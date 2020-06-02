#include "Abonnement.h"
#include "QDebug"
Abonnement::Abonnement()
{

}

Abonnement::Abonnement(int id ,QString tarif,QString duree,QString type,QString numero ,QDate date)
{
    this->id=id;
    this->tarif=tarif;
    this->duree=duree;
    this->type=type;
    this->numero=numero;
    this->datecreation=date;

}



bool Abonnement::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO abonnement (id,tarif, duree, type, numero,datecreation) "
                        "VALUES (:id, :tarif, :duree, :type, :Numero,:date)");
    query.bindValue(":id",id);
    query.bindValue(":tarif", tarif);
    query.bindValue(":duree", duree);
    query.bindValue(":type", type);
    query.bindValue(":date", datecreation);
    query.bindValue(":Numero", numero);

    return    query.exec();

}

QSqlQueryModel * Abonnement::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnement");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tarif"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


    return model;
}

bool Abonnement::supprimer(QString sup)
{
QSqlQuery query;
query.prepare("DELETE FROM Abonnement WHERE id = :id");
query.bindValue(":id", sup);
return    query.exec();
}


 QSqlQueryModel * Abonnement::chercher(QString rech)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from abonnement where upper(numero) like upper('%"+rech+"%') or upper(duree) like upper('%"+rech+"%') or upper(type) like upper('%"+rech+"%')or upper(tarif) like upper('%"+rech+"%') ");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tarif"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


         return model;
 }

 void Abonnement::getAbonnement(QString id)
 {
     QSqlQuery query;
     if(query.exec("select id,tarif,duree,type,numero,datecreation from abonnement where id ='"+id+"'"))
     {

         while(query.next())
         {

             this->setId(query.value(0).toInt());
             this->setTarif(query.value(1).toString());
             this->setDuree(query.value(2).toString());
             this->setType(query.value(3).toString());
             this->setNumero(query.value(4).toString());
            this->setDate(query.value(5).toDate());


         }
     }
 }




 void Abonnement::setTarif(QString x)
 {
     this->tarif=x;
 }
 void Abonnement::setType(QString x)
 {
     this->type=x;
 }
 void Abonnement::setDuree(QString x)
 {
     this->duree=x;
 }
 void Abonnement::setDate(QDate x)
 {
     this->datecreation=x;
 }
 void Abonnement::setNumero(QString x)
 {
     this->numero=x;
 }
 void Abonnement::setId(int x)
 {
     this->id=x;
 }


 QString Abonnement::getTarif()
 {
     return this->tarif;
 }
 QString Abonnement::getType()
 {
     return this->type;
 }
 QString Abonnement::getDuree()
 {
     return this->duree;
 }
 QDate Abonnement::getDate()
 {
     return this->datecreation;
 }
 QString Abonnement::getNumero()
 {
     return this->numero;
 }
 int Abonnement::getId()
 {
     return this->id;
 }

 QSqlQueryModel * Abonnement::triDuree()
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from abonnement order by CAST(duree as INT) asc");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tarif"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


     return model;
 }
 QSqlQueryModel * Abonnement::triTarif()
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from abonnement order by CAST(tarif as INT) asc");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tarif"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


     return model;
 }

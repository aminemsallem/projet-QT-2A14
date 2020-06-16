#include "Evenement.h"
#include "QDebug"

Evenement::Evenement()
{

}

Evenement::Evenement(int id, QString nom,QString type,QString lieu,QDate date)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->lieu=lieu;
    this->dateEvent=date;

}

int Evenement::getId()
{
    return this->id;
}

void Evenement::setId(int id)
{
    this->id=id;
}


QString Evenement::getNom()
{
    return this->nom;
}

void Evenement::setNom(QString nom)
{
    this->nom=nom;
}


QString Evenement::getType()
{
    return this->type;
}

void Evenement::setType(QString type)
{
    this->type=type;
}


QString Evenement::getLieu()
{
    return this->lieu;
}

void Evenement::setLieu(QString lieu)
{
    this->lieu=lieu;
}


QDate Evenement::getDate()
{
    return this->dateEvent;
}

void Evenement::setDate(QDate date)
{
    this->dateEvent=date;
}


bool Evenement::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO evenement (id,nom, type, lieu, dateEvent) "
                        "VALUES (:id, :nom, :type, :lieu,:date)");
    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":lieu", lieu);
    query.bindValue(":date", dateEvent);

    return    query.exec();

}

QSqlQueryModel * Evenement::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenement");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


    return model;
}


bool Evenement::supprimer(QString sup)
{
QSqlQuery query;
query.prepare("DELETE FROM evenement WHERE id = :id");
query.bindValue(":id", sup);
return    query.exec();
}

QSqlQueryModel * Evenement::chercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from evenement where upper(nom) like upper('%"+rech+"%') or upper(lieu) like upper('%"+rech+"%') or upper(type) like upper('%"+rech+"%')");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


        return model;
}

void Evenement::getEvenement(QString id)
{
    QSqlQuery query;
    if(query.exec("select id,nom,type,lieu,dateevent from evenement where id ='"+id+"'"))
    {

        while(query.next())
        {

            this->setId(query.value(0).toInt());
            this->setNom(query.value(1).toString());
            this->setType(query.value(2).toString());
            this->setLieu(query.value(3).toString());
            this->setDate(query.value(4).toDate());


        }
    }
}

bool Evenement::update(QString x, QString cher,QString id)
{
    QSqlQuery query;
        if(x=="1")
        {
            query.prepare("UPDATE evenement SET nom=? where id= "+id+" ");
            query.addBindValue(cher);
            qDebug() << x << endl;

        }
        else if(x=="2")
        {
            query.prepare("UPDATE evenement SET type=? where id="+id+" ");
            query.addBindValue(cher);
        }
        else if(x=="3")
        {
            query.prepare("UPDATE evenement SET lieu=? where id="+id+"  ");
            query.addBindValue(cher);
        }
    return query.exec();
}


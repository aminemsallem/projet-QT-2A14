#include "Prix.h"
#include "QDebug"

Prix::Prix()
{

}

Prix::Prix(int id,QString prix,QString evenement,QString type,QString valeur,QString nombre)
{
    this->id=id;
    this->prix=prix;
    this->evenement=evenement;
    this->type=type;
    this->valeur=valeur;
    this->nombre=nombre;

}

int Prix::getId()
{
    return this->id;
}
void Prix::setId(int id)
{
    this->id=id;
}

QString Prix::getPrix()
{
    return this->prix;
}
void Prix::setPrix(QString prix)
{
    this->prix=prix;

}

QString Prix::getType()
{
    return this->type;
}
void Prix::setType(QString type)
{
    this->type=type;
}

QString Prix::getEvenement()
{
    return this->evenement;
}
void Prix::setEvenement(QString event)
{
    this->evenement=event;
}

QString Prix::getValeur()
{
    return this->valeur;
}
void Prix::setValeur(QString val)
{
    this->valeur=val;
}

QString Prix::getNombre()
{
    return this->nombre;
}
void Prix::setNombre(QString num)
{
    this->nombre=num;

}

bool Prix::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO prix (id,prix, evenement, type, valeur,nombre) "
                        "VALUES (:id, :prix, :evenement, :type,:valeur,:nombre)");
    query.bindValue(":id",id);
    query.bindValue(":prix", prix);
    query.bindValue(":evenement", evenement);
    query.bindValue(":type", type);
    query.bindValue(":valeur", valeur);
    query.bindValue(":nombre", nombre);
    return    query.exec();

}

QSqlQueryModel * Prix::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from prix");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Evenement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Valeur"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre"));


    return model;
}


bool Prix::supprimer(QString sup)
{
QSqlQuery query;
query.prepare("DELETE FROM prix WHERE id = :id");
query.bindValue(":id", sup);
return    query.exec();
}

QSqlQueryModel * Prix::chercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from prix where upper(prix) like upper('%"+rech+"%') or upper(evenement) like upper('%"+rech+"%')  or upper(type) like upper('%"+rech+"%') or upper(valeur) like upper('%"+rech+"%') or upper(nombre) like upper('%"+rech+"%')  ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Evenement"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Valeur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre"));


        return model;
}

void Prix::getPrix(QString id)
{
    QSqlQuery query;
    if(query.exec("select id,prix,evenement,type,valeur,nombre from prix where id ='"+id+"'"))
    {

        while(query.next())
        {

            this->setId(query.value(0).toInt());
            this->setPrix(query.value(1).toString());
            this->setEvenement(query.value(2).toString());
            this->setType(query.value(3).toString());
            this->setValeur(query.value(4).toString());
            this->setNombre(query.value(5).toString());


        }
    }
}

bool Prix::update(QString x, QString cher,QString id)
{
    QSqlQuery query;
        if(x=="1")
        {
            query.prepare("UPDATE prix SET prix=? where id= "+id+" ");
            query.addBindValue(cher);


        }
        else if(x=="2")
        {
            query.prepare("UPDATE prix SET evenement=? where id="+id+" ");
            query.addBindValue(cher);
        }
        else if(x=="3")
        {
            query.prepare("UPDATE prix SET type=? where id="+id+"  ");
            query.addBindValue(cher);
        }
        else if(x=="4")
        {
            query.prepare("UPDATE prix SET valeur=? where id="+id+" ");
            query.addBindValue(cher);
        }
        else if(x=="5")
        {
            query.prepare("UPDATE prix SET nombre=? where id="+id+"  ");
            query.addBindValue(cher);
        }
    return query.exec();
}

QSqlQueryModel * Prix::triNombre()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from prix order by CAST(nombre as INT) asc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Evenement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Valeur"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre"));


    return model;
}



QSqlQueryModel * Prix::triValeur()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from prix order by CAST(valeur as INT) asc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Evenement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Valeur"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre"));


    return model;
}


#include "connection.h"
#include "QSqlDatabase"
Connection::Connection()
{

}

bool Connection::ouvrirconnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetQT");
db.setUserName("prosit");//inserer nom de l'utilisateur
db.setPassword("12345");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}


void Connection::fermerconnexion()
{
    db.close();
}

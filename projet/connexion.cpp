#include "connexion.h"


bool connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");
db.setPassword("zarzis1.");
if (db.open())
    test=true;
return  test;
}
void connexion::fermerConnexion()
{db.close();}

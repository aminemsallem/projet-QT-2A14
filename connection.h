#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
    bool ouvrirconnexion();
    void fermerconnexion();

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H

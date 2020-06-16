#ifndef PRIX_H
#define PRIX_H
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDate>
class Prix
{
private:

    int id;
    QString prix;
    QString evenement;
    QString type;
    QString valeur;
    QString nombre;

public:

    Prix();
    Prix(int,QString,QString,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * triValeur();
    QSqlQueryModel * triNombre();
    bool supprimer(QString);
    QSqlQueryModel * chercher(QString);
    void getAbonne(QString);
    void getPrix(QString id);
    bool update(QString,QString,QString);


    int getId();
    void setId(int);

    QString getPrix();
    void setPrix(QString);

    QString getType();
    void setType(QString);

    QString getEvenement();
    void setEvenement(QString);

    QString getValeur();
    void setValeur(QString);

    QString getNombre();
    void setNombre(QString);












};
#endif // PRIX_H

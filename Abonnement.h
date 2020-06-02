#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDate>
class Abonnement
{
private:
    int id;
    QString duree;
    QString tarif;
    QString type;
    QString numero;
    QDate datecreation;

public:
    Abonnement();
    Abonnement(int,QString,QString,QString,QString,QDate);
    //Abonnement(int,QString,QString,QString);


    int getId();
    void setId(int);

    QString getDuree();
    void setDuree(QString);

    QString getTarif();
    void setTarif(QString);

    QString getType();
    void setType(QString);

    QString getNumero();
    void setNumero(QString);

    QDate getDate();
    void setDate(QDate);





    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * triTarif();
    QSqlQueryModel * triDuree();
    bool supprimer(QString);
    QSqlQueryModel * chercher(QString);
    void getAbonnement(QString);





};



#endif // ABONNEMENT_H

#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDate>
class Evenement
{
private:

    int id;
    QString nom;
    QString type;
    QString lieu;
    QDate dateEvent;

public:

    Evenement();
    Evenement(int,QString,QString,QString,QDate);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel * chercher(QString);
    void getAbonne(QString);
    void getEvenement(QString id);
    bool update(QString,QString,QString);


    int getId();
    void setId(int);

    QString getNom();
    void setNom(QString);

    QString getType();
    void setType(QString);

    QString getLieu();
    void setLieu(QString);

    QDate getDate();
    void setDate(QDate);












};
#endif // EVENEMENT_H

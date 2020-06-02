#ifndef ABONNE_H
#define ABONNE_H
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDate>
class Abonne
{
private:
    int id;
    QString nom;
    QString prenom;
    QDate datenaissance;
    QString numerocarte;


public:
    Abonne();
    Abonne(int,QString,QString,QDate,QString);
    Abonne(int,QString,QString,QString);


    int getId();
    void setId(int);

    QString getNom();
    void setNom(QString);

    QString getPrenom();
    void setPrenom(QString);

    QString getNumero();
    void setNumero(QString);

    QDate getDate();
    void setDate(QDate);





    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel * chercher(QString);
    void getAbonne(QString);





};






#endif // ABONNE_H

#include "joueurs.h"

#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include "ui_ajouterjoueur.h"
#include "affichage_joueur.h"
#include "ui_affichage_joueur.h"
joueurs::joueurs()
{

}

joueurs::joueurs(QString cin, QString nom, QString prenom, QString entraineur, QDate date_naissance, int age)
{
    this->setCin(cin);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setEntraineur(entraineur);
    this->setAge(age);
    this->setDate_naissance(date_naissance);
}

QString joueurs::getNom()
{
    return nom;
}

void joueurs::setNom( QString &value)
{
    nom = value;
}

QString joueurs::getPrenom()
{
    return prenom;
}

void joueurs::setPrenom( QString &value)
{
    prenom = value;
}




int joueurs::getAge()
{
    return age;
}

void joueurs::setAge(int value)
{
    age = value;
}

QString joueurs::getEntraineur()
{
    return entraineur;
}

void joueurs::setEntraineur(QString &value)
{
    entraineur = value;
}
QDate joueurs::getDate_naissance()
{
    return date_naissance;
}

void joueurs::setDate_naissance(QDate &value)
{
    date_naissance = value;
}

int joueurs::getValide()
{
    return valide;
}

void joueurs::setValide()
{
    valide = 1;
}
QString joueurs::getCin()
{
    return cin;
}

void joueurs::setCin(QString value)
{
    cin = value;
}
bool joueurs::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO joueurs (cin, NOM, PRENOM,DATE_NAISSANCE,entraineur,age) "
                  "VALUES (:cin, :nom, :prenom,:date,:entraineur,:age)");
    query.bindValue(":cin",getCin());
    query.bindValue(":nom", getNom());
    query.bindValue(":prenom",getPrenom());
    query.bindValue(":date", getDate_naissance());
    query.bindValue(":entraineur", getEntraineur());
    query.bindValue(":age", getAge());
    query.exec();

    query.prepare("UPDATE ENTRAINEURS set NOMBRE_JOUEURS=NOMBRE_JOUEURS +1 where REFERENCE='"+getEntraineur()+"'") ;
    return query.exec();


}

void joueurs::list_entraineurs(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select reference from entraineurs");
    q.exec();
    modal->setQuery(q);
    ui->entraineur->setModel(modal);
}

void joueurs::list_entraineurs2(Ui::AjouterJoueur *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select reference from entraineurs");
    q.exec();
    modal->setQuery(q);
    ui->entraineur->setModel(modal);
}

void joueurs::affichage(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from joueurs");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}
void joueurs::Tri_AGE(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from joueurs order by AGE");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void joueurs::Tri_NOM(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from joueurs order by NOM");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void joueurs::Recherche(Ui::AFFICHAGE_JOUEUR *ui)
{  QString num;
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from joueurs where (cin LIKE '%"+reference+"%' or NOM LIKE '%"+reference+"%' or ENTRAINEUR LIKE '%"+reference+"%' or PRENOM LIKE '%"+reference+"%' )");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView->setModel(modal);}


}
bool joueurs::Supprimer(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM joueurs WHERE cin ='"+id+"'");
    return q.exec();

}

bool joueurs::modifier(Ui::AFFICHAGE_JOUEUR *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE joueurs set NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE ,ENTRAINEUR=:ENTRAINEUR where cin='"+ref+"'") ;


    q.bindValue(":NOM",ui->nom->text());
    q.bindValue(":PRENOM",ui->prenom->text());
    q.bindValue(":AGE",ui->age->text());
    q.bindValue(":ENTRAINEUR",ui->entraineur->currentText());

    return q.exec();

}

void joueurs::pdf(Ui::AFFICHAGE_JOUEUR *ui)
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString CIN = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();
    QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString();
    QString age = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();
    QString date= ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString();
    QString entraineur = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString();
    doc.setHtml("<br> <h1>Information de joueur  " " " +nom+ " " +prenom+ " <br> <br> </h1>\n <h4 >Cin:" " " +CIN +" </h4> \n <h4> Nom et Prenom : " " "+ nom+ " " + prenom +" </h4> \n <h4>Date de naissance : " " "+date+" </h4> \n <h4>Age:" " "+age+" " "ans </h4> \n <h4> Reference Entraineur :" " "+entraineur+" </h4> ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}


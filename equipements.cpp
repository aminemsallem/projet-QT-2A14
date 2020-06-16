#include "equipements.h"
#include "gestionequipements.h"
#include "ui_gestionequipements.h"
#include<QMessageBox>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
equipements::equipements()
{

}

equipements::equipements(QString code, QString nom, QString salle, QString type, QString etat)
{    this->code=code;
     this->nom=nom;
     this->etat=etat;
     this->type=type;
     this->salle=salle;

}

int equipements::get_erreur()
{
    return this->erreur;
}

void equipements::set_erreur()
{
    this->erreur=1;
}

bool equipements::modifier(Ui::GestionEquipements *ui)
{
    QSqlQuery q;

    QString val=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE equipement set NOM=:nom,SALLE=:salle,ETAT=:etat,TYPE=:type where code='"+val+"'") ;


    q.bindValue(":nom",ui->nom->text());
    q.bindValue(":salle",ui->salles->currentText());
    q.bindValue(":etat",ui->etat->currentText());
    q.bindValue(":type",ui->type->text());

    if ( q.exec())
    {

        return true ;
    }
    else
    {

        return false;
    }
}

void equipements::load(Ui::GestionEquipements *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from equipement");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

void equipements::load_combobox(Ui::GestionEquipements *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select NOM from salles");
    q.exec();
    modal->setQuery(q);
    ui->salles->setModel(modal);
}
void equipements::load_combobox2(Ui::GestionEquipements *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select NOM from etat");
    q.exec();
    modal->setQuery(q);
    ui->etat->setModel(modal);
}
bool equipements::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO equipement (code, NOM, salle,etat,type) "
                  "VALUES (:code, :nom,:salle,:etat,:type)");
    query.bindValue(":code",code);
    query.bindValue(":nom", nom);
    query.bindValue(":salle", salle);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    return    query.exec();
}

bool equipements::Supprimer(Ui::GestionEquipements *ui)
{
    QSqlQuery q;
    bool e;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM equipement WHERE code ='"+id+"'");
    q.exec();
    if(q.first())
    {
        e=true;
    }
    else
    {
        e=false;
    }

}

void equipements::pdf(Ui::GestionEquipements *ui)
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString code = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();
    QString salle = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString();
    QString etat = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString();
    QString type= ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString();

    doc.setHtml("<br> <h1>Information de l'equipement  " " " +nom+ "  <br> <br> </h1>\n <h4 >Code:" " " +code +" </h4> \n <h4> Nom : " " "+ nom+ "  </h4> \n <h4> salle : " " "+salle+" </h4> \n <h4>Type:" " "+type+" " " </h4> \n <h4> Etat :" " "+etat+" </h4> ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
void equipements::Recherche(Ui::GestionEquipements *ui)
{

    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString value =ui->recherche_value->text();

    q.prepare("select * from equipement where (code LIKE '%"+value+"%' or NOM LIKE '%"+value+"%' or type LIKE '%"+value+"%' or SALLE LIKE '%"+value+"%')");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView->setModel(modal);}
    else
    {
        qWarning( "can't get value" ); }
}

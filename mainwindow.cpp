#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Abonne.h"
#include "Abonnement.h"
#include "Evenement.h"
#include "Prix.h"
#include "QDebug"
#include <QVector>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setStyleSheet("QMainWindow {background-color : #353535; }");
    x="0";
    //ui->tabWidget_3->setStyleSheet("QTabWidget {background-color : #353535; }");
    ui->setupUi(this);
    ui->MainStacked->setCurrentIndex(0);
    ui->AbonneStacked->setCurrentIndex(0);
    Abonne a;
    ui->afficherAbonne->setModel(a.afficher());
    ui->afficherAbonne->show();
    ui->oldIdAbonne->setVisible(false);
    ui->oldIdAbonnement->setVisible(false);
    ui->MainStacked->setCurrentIndex(0);
   // ui->idAbonne->setValidator( new QIntValidator(0, 10000000, this) );
    ui->numeroAbonne->setValidator( new QIntValidator(0, 10000000, this) );
    ui->updateIdAbonne->setValidator( new QIntValidator(0, 10000000, this) );
    ui->updateNumeroAbonne->setValidator( new QIntValidator(0, 10000000, this) );
    ui->tarifAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    ui->dureeAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    ui->numeroAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    ui->updateTarifAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    ui->updateDureeAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    ui->updateNumeroAbonnement->setValidator( new QIntValidator(0, 10000000, this) );
    //ui->valeurPrix->setValidator( new QIntValidator(0, 10000000, this) );
   // ui->nombrePrix->setValidator( new QIntValidator(0, 10000000, this) );




    notifyiconEv=new QSystemTrayIcon(this);
    notifyiconEv->setIcon(QIcon(":/img/img/Notification.jpg"));
    notifyiconEv->setVisible(true);
    notifyiconAb=new QSystemTrayIcon(this);
    notifyiconAb->setIcon(QIcon(":/img/img/Notification.jpg"));
    notifyiconAb->setVisible(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterAbonne_clicked()
{
    QSqlQuery query;
    QVector <int> tab;
    int i;
        int id=-1;
        if(query.exec("select id from abonne"))
            {
                while (query.next())
                {
                    tab.push_back(query.value(0).toInt());

                }

            }
            qSort(tab.begin(),tab.end());
            if(tab.size()==0)
            {
                id=1;
            }
            else if(tab[0]!=1)
            { id=1;}
            else if(tab.size()==1)
            {
                id=2;
            }

            else
            {for(i=1;i<tab.size();i++)
            {

                if (tab[i]-tab[i-1]>1)
                {
                    id=tab[i-1]+1;
                    break;
                }
            }
            }
            if (id==-1)
            {
                id=tab.size()+1;
            }


    Abonne a(id,ui->nomAbonne->text(),ui->prenomAbonne->text(),ui->dateAbonne->date(),ui->numeroAbonne->text());

    if(a.ajouter())
    {
    //ui->idAbonne->setText("");
    ui->nomAbonne->setText("");
    ui->prenomAbonne->setText("");
    ui->numeroAbonne->setText("");
     ui->afficherAbonne->setModel(a.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un abonné"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    notifyiconAb->show();
               notifyiconAb->showMessage("Success","Ajout d'abonne avec succes",QSystemTrayIcon::Critical,2000);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonné"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
}

void MainWindow::on_refresh_clicked()
{
    Abonne a;
    ui->afficherAbonne->setModel(a.afficher());
    ui->afficherAbonne->show();
}

void MainWindow::on_Supprimer_clicked()
{
QString val=ui->afficherAbonne->model()->data(ui->afficherAbonne->model()->index(ui->afficherAbonne->selectionModel()->currentIndex().row(),0)).toString();
Abonne a;
a.supprimer(val);
ui->afficherAbonne->setModel(a.afficher());

}

void MainWindow::on_chercherAbonne_textChanged(const QString &arg1)
{
Abonne a;
ui->afficherAbonne->setModel(a.chercher(ui->chercherAbonne->text()));
}

void MainWindow::on_ModifierAbonne_clicked()
{
QString val=ui->afficherAbonne->model()->data(ui->afficherAbonne->model()->index(ui->afficherAbonne->selectionModel()->currentIndex().row(),0)).toString();
Abonne a;
a.getAbonne(val);
qDebug()<<a.getId();
ui->oldIdAbonne->setText(QString::number(a.getId()));
ui->updateIdAbonne->setText(QString::number(a.getId()));
ui->updateNomAbonne->setText(a.getNom());
ui->updatePrenomAbonne->setText(a.getPrenom());
ui->updateNumeroAbonne->setText(a.getNumero());
ui->updateDateAbonne->setDate(a.getDate());
ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_ValiderUpdateAbonne_clicked()
{
    int x=0;
    if(ui->updateIdAbonne->text()=="")
    {
        ui->label_updateIdAbonne->setText("Ce champ ne peut pas être vide !");
        ui->label_updateIdAbonne->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateNomAbonne->text()=="")
    {
        ui->label_updateNomAbonne->setText("Ce champ ne peut pas être vide !");
        ui->label_updateNomAbonne->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updatePrenomAbonne->text()=="")
    {
        ui->label_updatePrenomAbonne->setText("Ce champ ne peut pas être vide !");
        ui->label_updatePrenomAbonne->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateNumeroAbonne->text()=="")
    {
        ui->label_updateNumeroAbonne->setText("Ce champ ne peut pas être vide !");
        ui->label_updateNumeroAbonne->setStyleSheet("QLabel {color : red; }");
        x=1;
    }

       if(x==0)
    {
   Abonne a(ui->updateIdAbonne->text().toInt(),ui->updateNomAbonne->text(),ui->updatePrenomAbonne->text(),ui->updateDateAbonne->date(),ui->updateNumeroAbonne->text());
    a.supprimer(ui->oldIdAbonne->text());

    if(a.ajouter())
    {
    ui->updateIdAbonne->setText("");
    ui->oldIdAbonne->setText("");
    ui->updateNomAbonne->setText("");
    ui->updatePrenomAbonne->setText("");
    ui->updateNumeroAbonne->setText("");

     ui->afficherAbonne->setModel(a.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un abonné"),
                       QObject::tr("Modification avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonné"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
     ui->afficherAbonne->setModel(a.afficher());

        ui->label_updateNumeroAbonne->setText("");
        ui->label_updatePrenomAbonne->setText("");
        ui->label_updateNomAbonne->setText("");
        ui->label_updateIdAbonne->setText("");
       }
}

void MainWindow::on_GestionAbonnes_clicked()
{
    ui->AbonneStacked->setCurrentIndex(0);

}

void MainWindow::on_GestionAbonnements_clicked()
{
     ui->AbonneStacked->setCurrentIndex(1);
}

void MainWindow::on_abonnesetabonnements_clicked()
{
    ui->MainStacked->setCurrentIndex(1);
    Abonne a;
    ui->afficherAbonne->setModel(a.afficher());
    Abonnement ab;
    ui->afficherAbonnement->setModel(ab.afficher());
}

void MainWindow::on_ajouterAbonnement_clicked()
{
    QSqlQuery query;
    QVector <int> tab;
    int i;
        int id=-1;
        if(query.exec("select id from abonnement"))
            {
                while (query.next())
                {
                    tab.push_back(query.value(0).toInt());

                }

            }
            qSort(tab.begin(),tab.end());
            if(tab.size()==0)
            {
                id=1;
            }
            else if(tab[0]!=1)
            { id=1;}
            else if(tab.size()==1)
            {
                id=2;
            }

            else
            {for(i=1;i<tab.size();i++)
            {

                if (tab[i]-tab[i-1]>1)
                {
                    id=tab[i-1]+1;
                    break;
                }
            }
            }
            if (id==-1)
            {
                id=tab.size()+1;
            }


    Abonnement ab(id,ui->tarifAbonnement->text(),ui->dureeAbonnement->text(),ui->typeAbonnement->text(),ui->numeroAbonnement->text(),ui->dateAbonnement->date());
    if(ab.ajouter())
    {
      //  ui->idAbonnement->setText("");
        ui->tarifAbonnement->setText("");
        ui->dureeAbonnement->setText("");
        ui->typeAbonnement->setText("");
        ui->numeroAbonnement->setText("");

       ui->afficherAbonnement->setModel(ab.afficher());
       QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnement"),
                          QObject::tr("Ajout avec succès !.\n"
                                      "Click Close to exit."), QMessageBox::Close);
       notifyiconAb->show();
                  notifyiconAb->showMessage("Success","Ajout d'abonnement avec succes",QSystemTrayIcon::Critical,2000);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnement"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }



}

void MainWindow::on_chercherAbonnement_textChanged(const QString &arg1)
{
    Abonnement ab;
    ui->afficherAbonnement->setModel(ab.chercher(ui->chercherAbonnement->text()));
}

void MainWindow::on_SupprimerAbonnement_clicked()
{
    QString val=ui->afficherAbonnement->model()->data(ui->afficherAbonnement->model()->index(ui->afficherAbonnement->selectionModel()->currentIndex().row(),0)).toString();
    Abonnement ab;
    ab.supprimer(val);
    ui->afficherAbonnement->setModel(ab.afficher());
}

void MainWindow::on_ModifierAbonnement_clicked()
{

    QString val=ui->afficherAbonnement->model()->data(ui->afficherAbonnement->model()->index(ui->afficherAbonnement->selectionModel()->currentIndex().row(),0)).toString();
    Abonnement ab;
    ab.getAbonnement(val);
    qDebug()<<ab.getId();
    ui->oldIdAbonnement->setText(QString::number(ab.getId()));
    ui->updateIdAbonnement->setText(QString::number(ab.getId()));
    ui->updateTypeAbonnement->setText(ab.getType());
    ui->updateTarifAbonnement->setText(ab.getTarif());
    ui->updateNumeroAbonnement->setText(ab.getNumero());
    ui->updateDureeAbonnement->setText(ab.getDuree());
    ui->updateDateAbonnement->setDate(ab.getDate());

    ui->tabWidget_2->setCurrentIndex(2);

}

void MainWindow::on_ValiderUpdate_clicked()
{
    int x=0;
    if(ui->updateIdAbonnement->text()=="")
    {
        ui->label_updateIdAbonnement->setText("Ce champ ne peut pas être vide !");
        ui->label_updateIdAbonnement->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateTarifAbonnement->text()=="")
    {
        ui->label_updateTarifAbonnement->setText("Ce champ ne peut pas être vide !");
        ui->label_updateTarifAbonnement->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateDureeAbonnement->text()=="")
    {
        ui->label_updateDureeAbonnement->setText("Ce champ ne peut pas être vide !");
        ui->label_updateDureeAbonnement->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateTypeAbonnement->text()=="")
    {
        ui->label_updateTypeAbonnement->setText("Ce champ ne peut pas être vide !");
        ui->label_updateTypeAbonnement->setStyleSheet("QLabel {color : red; }");
        x=1;
    }
    if(ui->updateNumeroAbonnement->text()=="")
    {
        ui->label_updateNumeroAbonnement->setText("Ce champ ne peut pas être vide !");
        ui->label_updateNumeroAbonnement->setStyleSheet("QLabel {color : red; }");
        x=1;
    }

       if(x==0)
    {
    Abonnement ab(ui->updateIdAbonnement->text().toInt(),ui->updateTarifAbonnement->text(),ui->updateDureeAbonnement->text(),ui->updateTypeAbonnement->text(),ui->updateNumeroAbonnement->text(),ui->updateDateAbonnement->date());
    ab.supprimer(ui->oldIdAbonnement->text());

    if(ab.ajouter())
    {
        ui->oldIdAbonnement->setText("");
        ui->updateIdAbonnement->setText("");
        ui->updateTypeAbonnement->setText("");
        ui->updateTarifAbonnement->setText("");
        ui->updateNumeroAbonnement->setText("");
        ui->updateDureeAbonnement->setText("");

         ui->label_updateIdAbonnement->setText("");
          ui->label_updateTarifAbonnement->setText("");
           ui->label_updateDureeAbonnement->setText("");
            ui->label_updateTypeAbonnement->setText("");
            ui->label_updateNumeroAbonnement->setText("");


     ui->afficherAbonnement->setModel(ab.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un abonnement"),
                       QObject::tr("Modification avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnement"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
     ui->afficherAbonnement->setModel(ab.afficher());
       }

}


void MainWindow::on_triTarif_clicked()
{
    Abonnement ab;
ui->afficherAbonnement->setModel(ab.triTarif());
}

void MainWindow::on_triDuree_clicked()
{
    Abonnement ab;
    ui->afficherAbonnement->setModel(ab.triDuree());

}


void MainWindow::on_Imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->afficherAbonne->model()->rowCount();
                const int columnCount =ui->afficherAbonne->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<img src=':/new/prefix1/icon/logo.webp' width='100' height='100'>\n"
                            "<h1>Liste des abonnes</h1>"



                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->afficherAbonne->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->afficherAbonne->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->afficherAbonne->isColumnHidden(column)) {
                                   QString data = ui->afficherAbonne->model()->data(ui->afficherAbonne->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                           document->print(&printer);}
}

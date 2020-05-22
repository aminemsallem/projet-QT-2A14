#include "employe.h"
#include "gestionemploye.h"
#include "ui_gestionemploye.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include "departement.h"
#include <QFont>
Employe::Employe()
{

}

Employe::Employe(QString cin, QString nom, QString prenom, QString departement, QString mobile, QDate date_naissance, int age)
{
    this->setCin(cin);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setDepartement(departement);
    this->setMobile(mobile);
    this->setDate_naissance(date_naissance);
    this->setAge(age);

}

QString Employe::getCin()
{
    return cin;
}

void Employe::setCin( QString &value)
{
    cin = value;
}

QString Employe::getNom()
{
    return nom;
}

void Employe::setNom( QString &value)
{
    nom = value;
}

QString Employe::getPrenom()
{
    return prenom;
}

void Employe::setPrenom( QString &value)
{
    prenom = value;
}

QString Employe::getDepartement()
{
    return departement;
}

void Employe::setDepartement( QString &value)
{
    departement = value;
}

QString Employe::getMobile()
{
    return mobile;
}

void Employe::setMobile( QString &value)
{
    mobile = value;
}

QDate Employe::getDate_naissance()
{
    return date_naissance;
}

void Employe::setDate_naissance( QDate &value)
{
    date_naissance = value;
}

int Employe::getAge()
{
    return age;
}

void Employe::setAge(int value)
{
    age = value;
}

int Employe::getCheck()
{
    return check;
}

void Employe::setCheck()
{
    check = 1;
}

bool Employe::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO employes (cin, NOM, PRENOM,DATE_NAISSANCE,departement,mobile,age) "
                  "VALUES (:cin, :nom, :prenom,:date,:departement,:mobile,:age)");
    query.bindValue(":cin",getCin());
    query.bindValue(":nom", getNom());
    query.bindValue(":prenom",getPrenom());
    query.bindValue(":date", getDate_naissance());
    query.bindValue(":departement", getDepartement());
    query.bindValue(":mobile", getMobile());
    query.bindValue(":age", getAge());
    query.exec();

    query.prepare("UPDATE departements set NOMBRE_EMPLOYE=NOMBRE_EMPLOYE +1 where REFERENCE='"+getDepartement()+"'") ;
    return query.exec();


}

void Employe::departentss(Ui::GestionEmploye *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select REFERENCE from departements");
    q.exec();
    modal->setQuery(q);
    ui->departement->setModel(modal);
    ui->departement_mod->setModel(modal);
}

void Employe::afficher(Ui::GestionEmploye *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from employes");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}
bool Employe::Supprimer(Ui::GestionEmploye *ui)
{
    QSqlQuery q;
    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    QString departementt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString();
    q.prepare("DELETE FROM EMPLOYES WHERE cin ='"+ref+"'");
    if(q.exec())
    {
        q.prepare("UPDATE departements set NOMBRE_EMPLOYE=NOMBRE_EMPLOYE -1 where REFERENCE='"+departementt+"'") ;
        return q.exec();
    } else return false;
}
bool Employe::modifier(Ui::GestionEmploye *ui)
{
    QSqlQuery q;

    QString cin=ui->cin_mod->text();


    q.prepare("UPDATE EMPLOYES set NOM=:nom ,prenom=:prenom,departement=:departement,mobile=:mobile where CIN ='"+cin+"'") ;

    q.bindValue(":nom",ui->nom_mod->text());
    q.bindValue(":prenom",ui->prenom_mod->text());
    q.bindValue(":departement",ui->departement_mod->currentText());
    q.bindValue(":mobile",ui->mobile_mod->text());

    return q.exec();

}
void Employe::recherche(Ui::GestionEmploye *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString mot =ui->recherche->text();
    q.prepare("select * from employes where (CIN LIKE '%"+mot+"%' or NOM LIKE '%"+mot+"%' or PRENOM LIKE '%"+mot+"%' )");

    q.exec() ;
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}


void Employe::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM EMPLOYES ");
    q.exec();
    QString pdf="<br> <h1  style='color:red'>LISTE DES EMPLOYES  <br></h1>\n <br> <table>  <tr>  <th>NOM ET PRENOM </th> <th>CIN </th> <th>DATE DE NAISSANCE </th> <th> AGE </th> <th>DEPARTEMENT </th> <th>MOBILE </th>    </tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(1).toString()+" " + q.value(2).toString() +"</td>   <td>" +q.value(0).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(6).toString()+" " "ans "  " " "</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

int Employe::TOTAL_EMP()
{  int nb;
    QSqlQuery q;

    q.prepare("SELECT COUNT(CIN) FROM EMPLOYES  ");
    q.exec();
    if ( q.first() )
        nb=q.value(0).toInt();
    else
    {
        qWarning( "can't get value" ); }
    return nb ;
}

int Employe::TOTAL_DEP()
{  int nb;
    QSqlQuery q;

    q.prepare("SELECT COUNT(REFERENCE) FROM DEPARTEMENTS ");
    q.exec();
    if ( q.first() )
        nb=q.value(0).toInt();
    else
    {
        qWarning( "can't get value" ); }
    return nb ;
}


void Employe::GRAPH(Ui::GestionEmploye *ui)
{

    int nombre_employe=TOTAL_EMP();
    int  nombre_departements= TOTAL_DEP();


    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->GRAPH->setBackground(QBrush(gradient));

    // create empty bar chart objects:

    QCPBars *EMPL = new QCPBars(ui->GRAPH->xAxis, ui->GRAPH->yAxis);
    QCPBars *DEPA = new QCPBars(ui->GRAPH->xAxis, ui->GRAPH->yAxis);

    EMPL->setAntialiased(false);
    DEPA->setAntialiased(false);

    EMPL->setStackingGap(1);
    DEPA->setStackingGap(1);

    // set names and colors:
    DEPA->setName("NOMBRE DES DEPARTEMENTS");
    DEPA->setPen(QPen(QColor(0, 125, 2).lighter(170)));
    DEPA->setBrush(QColor(0, 125, 2));
    EMPL->setName("NOMBRE DES EMPLOYES");
    EMPL->setPen(QPen(QColor(174, 0, 0).lighter(150)));
    EMPL->setBrush(QColor(174, 0, 0));




    // prepare x axis :
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->GRAPH->xAxis->setTicker(textTicker);
    ui->GRAPH->xAxis->setTickLabelRotation(60);
    ui->GRAPH->xAxis->setSubTicks(false);
    ui->GRAPH->xAxis->setTickLength(0, 4);
    ui->GRAPH->xAxis->setRange(0, 4);
    ui->GRAPH->xAxis->setBasePen(QPen(Qt::white));
    ui->GRAPH->xAxis->setTickPen(QPen(Qt::white));
    ui->GRAPH->xAxis->grid()->setVisible(true);
    ui->GRAPH->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->GRAPH->xAxis->setTickLabelColor(Qt::white);
    ui->GRAPH->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->GRAPH->yAxis->setRange(0, nombre_employe);
    ui->GRAPH->yAxis->setPadding(1);// a bit more space to the left border
    ui->GRAPH->yAxis->setBasePen(QPen(Qt::white));
    ui->GRAPH->yAxis->setTickPen(QPen(Qt::white));
    ui->GRAPH->yAxis->setSubTickPen(QPen(Qt::white));


    ui->GRAPH->yAxis->grid()->setSubGridVisible(true);
    ui->GRAPH->yAxis->setTickLabelColor(Qt::white);
    ui->GRAPH->yAxis->setLabelColor(Qt::white);
    ui->GRAPH->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->GRAPH->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> EMPDATA, DEPDATA;
    EMPDATA  << nombre_employe <<0 ;
    DEPDATA << 00 << nombre_departements;

    DEPA->setData(ticks, DEPDATA);
    EMPL->setData(ticks, EMPDATA);


    // setup legend:
    ui->GRAPH->legend->setVisible(true);
    ui->GRAPH->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->GRAPH->legend->setBrush(QColor(255, 255, 255, 100));
    ui->GRAPH->legend->setBorderPen(Qt::NoPen);

    ui->GRAPH->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

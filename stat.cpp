#include "stat.h"
#include "ui_stat.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <string>
#include "equipements.h"
QT_CHARTS_USE_NAMESPACE
using namespace QtCharts;
Stat::Stat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistiques");
    Stat::make(ui);

}

Stat::~Stat()
{
    delete ui;
}

void Stat::make(Ui::Stat *ui)
{
    int en_marche;
    int en_panne;
    int total;
    QString en_marche1;
    QString en_panne1;
    QSqlQuery q;

    q.prepare("SELECT COUNT(code) FROM EQUIPEMENT where ETAT='en marche' ");
    q.exec();
    q.first() ;
    en_marche=(q.value(0).toInt());

    q.prepare("SELECT COUNT(code) FROM EQUIPEMENT where ETAT='en panne' ");
    q.exec();
    q.first() ;
    en_panne=(q.value(0).toInt());
    q.prepare("SELECT COUNT(code) FROM EQUIPEMENT  ");
    q.exec();
    q.first() ;
    total=(q.value(0).toInt());

    en_marche=((double)en_marche/(double)total)*100;
    en_panne=((double)en_panne/(double)total)*100;

    en_marche1= QString::number(en_marche);
    en_panne1=QString::number(en_panne);
    QPieSeries *series = new QPieSeries();
    series->append("En marche"+en_marche1+"%",en_marche);
    series->append("En panne"+en_panne1+"%",en_panne);


    //
    // Add label to 1st slice
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkRed, 2));
    slice1->setBrush(Qt::red);



    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Statistiques sur les equipements ");
    chart->legend()->show();

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->stat->addWidget(chartView);

}

void Stat::on_pushButton_clicked()
{

    GestionEquipements *w = new GestionEquipements;
    hide();
    w->show();
}

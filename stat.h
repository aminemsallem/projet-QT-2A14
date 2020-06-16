#ifndef STAT_H
#define STAT_H
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

namespace Ui {
class Stat;
}

class Stat : public QWidget
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = 0);
    ~Stat();
  void make(Ui::Stat *ui);
private slots:
  void on_pushButton_clicked();

private:
    Ui::Stat *ui;
};

#endif // STAT_H

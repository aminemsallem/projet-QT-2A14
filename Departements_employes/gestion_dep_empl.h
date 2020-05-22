#ifndef GESTION_DEP_EMPL_H
#define GESTION_DEP_EMPL_H

#include <QWidget>

namespace Ui {
class Gestion_Dep_Empl;
}

class Gestion_Dep_Empl : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Dep_Empl(QWidget *parent = 0);
    ~Gestion_Dep_Empl();

private slots:
    void on_departements_clicked();

    void on_employe_clicked();

    void on_pushButton_clicked();

private:
    Ui::Gestion_Dep_Empl *ui;
};

#endif // GESTION_DEP_EMPL_H

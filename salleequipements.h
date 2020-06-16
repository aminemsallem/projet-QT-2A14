#ifndef SALLEEQUIPEMENTS_H
#define SALLEEQUIPEMENTS_H

#include <QMainWindow>

namespace Ui {
class SalleEquipements;
}

class SalleEquipements : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalleEquipements(QWidget *parent = 0);
    ~SalleEquipements();

private slots:
    void on_salle_clicked();

    void on_equipements_clicked();

    void on_retour_clicked();

private:
    Ui::SalleEquipements *ui;
};

#endif // SALLEEQUIPEMENTS_H

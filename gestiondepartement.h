#ifndef GESTIONDEPARTEMENT_H
#define GESTIONDEPARTEMENT_H
#include "connexion.h"
#include <QWidget>

namespace Ui {
class GestionDepartement;
}

class GestionDepartement : public QWidget
{
    Q_OBJECT

public:
    explicit GestionDepartement(QWidget *parent = 0);
    ~GestionDepartement();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_ajouter_clicked();

    void on_reset_clicked();

    void on_supprimer_clicked();

    void on_reset_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::GestionDepartement *ui;
};

#endif // GESTIONDEPARTEMENT_H

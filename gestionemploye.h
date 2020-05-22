#ifndef GESTIONEMPLOYE_H
#define GESTIONEMPLOYE_H

#include <QWidget>

namespace Ui {
class GestionEmploye;
}

class GestionEmploye : public QWidget
{
    Q_OBJECT

public:
    explicit GestionEmploye(QWidget *parent = 0);
    ~GestionEmploye();


private slots:
    void on_ajouter_clicked();

    void on_reset_2_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_reset_clicked();

    void on_modifier_clicked();

    void on_rechercher_clicked();

    void on_pdf_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::GestionEmploye *ui;
};

#endif // GESTIONEMPLOYE_H

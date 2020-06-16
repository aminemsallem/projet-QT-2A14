#ifndef GESTIONEQUIPEMENTS_H
#define GESTIONEQUIPEMENTS_H

#include <QWidget>
#include <QStyleOptionViewItem>
namespace Ui {
class GestionEquipements;
}

class GestionEquipements : public QWidget
{
    Q_OBJECT

public:
    explicit GestionEquipements(QWidget *parent = 0);
    ~GestionEquipements();

private slots:
    void on_ajouter_clicked();

    void on_annuler_clicked();

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_reset_clicked();

    void on_search_clicked();

    void on_stats_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_PDF_clicked();

private:
    Ui::GestionEquipements *ui;
};

#endif // GESTIONEQUIPEMENTS_H

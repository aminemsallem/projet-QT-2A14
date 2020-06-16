#ifndef GESTIONSALLES_H
#define GESTIONSALLES_H

#include <QWidget>

namespace Ui {
class gestionSalles;
}

class gestionSalles : public QWidget
{
    Q_OBJECT

public:
    explicit gestionSalles(QWidget *parent = 0);
    ~gestionSalles();

private slots:
    void on_ajouter_clicked();

    void on_annuler_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_supprimer_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_reset_clicked();



    void on_modifier_clicked();

    void on_tableView_clicked(const QModelIndex &index);
private:
    Ui::gestionSalles *ui;
};

#endif // GESTIONSALLES_H

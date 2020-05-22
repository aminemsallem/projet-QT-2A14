#ifndef AFFICHAGE_JOUEUR_H
#define AFFICHAGE_JOUEUR_H

#include <QWidget>

namespace Ui {
class AFFICHAGE_JOUEUR;
}

class AFFICHAGE_JOUEUR : public QWidget
{
    Q_OBJECT

public:
    explicit AFFICHAGE_JOUEUR(QWidget *parent = 0);
    ~AFFICHAGE_JOUEUR();

private slots:
    void on_Annuler_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();

    void on_search_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Valider_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_PDF_clicked();

private:
    Ui::AFFICHAGE_JOUEUR *ui;
};

#endif // AFFICHAGE_JOUEUR_H

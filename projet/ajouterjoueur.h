#ifndef AJOUTERJOUEUR_H
#define AJOUTERJOUEUR_H
#include "joueurs.h"
#include <QWidget>

namespace Ui {
class AjouterJoueur;
}

class AjouterJoueur : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterJoueur(QWidget *parent = 0);
    ~AjouterJoueur();

private slots:
    void on_Annuler_clicked();

    void on_Valider_clicked();

private:
    Ui::AjouterJoueur *ui;
};

#endif // AJOUTERJOUEUR_H

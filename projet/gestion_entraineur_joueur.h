#ifndef GESTION_ENTRAINEUR_JOUEUR_H
#define GESTION_ENTRAINEUR_JOUEUR_H

#include <QWidget>

namespace Ui {
class Gestion_Entraineur_Joueur;
}

class Gestion_Entraineur_Joueur : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Entraineur_Joueur(QWidget *parent = 0);
    ~Gestion_Entraineur_Joueur();

private slots:
    void on_entraineurs_clicked();

    void on_joueurs_clicked();

    void on_pushButton_clicked();

private:
    Ui::Gestion_Entraineur_Joueur *ui;
};

#endif // GESTION_ENTRAINEUR_JOUEUR_H

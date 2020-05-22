#ifndef GESTION_JOUEUR_H
#define GESTION_JOUEUR_H

#include <QWidget>

namespace Ui {
class Gestion_Joueur;
}

class Gestion_Joueur : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Joueur(QWidget *parent = 0);
    ~Gestion_Joueur();

private slots:
    void on_entraineurs_clicked();
    void on_entraineurs_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Joueur *ui;
};

#endif // GESTION_JOUEUR_H

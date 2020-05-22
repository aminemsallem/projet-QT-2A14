#ifndef AJOUTERENTRAINEUR_H
#define AJOUTERENTRAINEUR_H

#include <QWidget>

namespace Ui {
class AjouterEntraineur;
}

class AjouterEntraineur : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterEntraineur(QWidget *parent = 0);
    ~AjouterEntraineur();

private slots:
    void on_Valider_clicked();

    void on_Annuler_clicked();

private:
    Ui::AjouterEntraineur *ui;
};

#endif // AJOUTERENTRAINEUR_H

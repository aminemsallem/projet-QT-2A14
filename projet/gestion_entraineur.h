#ifndef GESTION_ENTRAINEUR_H
#define GESTION_ENTRAINEUR_H

#include <QWidget>

namespace Ui {
class Gestion_Entraineur;
}

class Gestion_Entraineur : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Entraineur(QWidget *parent = 0);
    ~Gestion_Entraineur();

private slots:
    void on_entraineurs_clicked();

    void on_pushButton_clicked();

    void on_entraineurs_2_clicked();

private:
    Ui::Gestion_Entraineur *ui;
};

#endif // GESTION_ENTRAINEUR_H

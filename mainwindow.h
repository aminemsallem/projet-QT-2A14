#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSystemTrayIcon"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterAbonne_clicked();

    void on_refresh_clicked();

    void on_Supprimer_clicked();

    void on_chercherAbonne_textChanged(const QString &arg1);

    void on_ModifierAbonne_clicked();

    void on_ValiderUpdateAbonne_clicked();

    void on_GestionAbonnes_clicked();

    void on_GestionAbonnements_clicked();

    void on_abonnesetabonnements_clicked();

    void on_ajouterAbonnement_clicked();

    void on_chercherAbonnement_textChanged(const QString &arg1);

    void on_SupprimerAbonnement_clicked();

    void on_ModifierAbonnement_clicked();

    void on_ValiderUpdate_clicked();

    void on_evennementsetprix_clicked();

    void on_Events_clicked();

    void on_Prix_clicked();

    void on_ajouterEvent_clicked();

    void on_chercherEvent_textChanged(const QString &arg1);

    void on_supprimerEvent_clicked();

    void on_updateEvent_clicked();

    void on_radioButton_nomEvet_clicked();

    void on_radioButton_typeEvent_clicked();

    void on_radioButton_lieuEvent_clicked();

    void on_ajoutPrix_clicked();

    void on_chercherPrix_textChanged(const QString &arg1);

    void on_suppPrix_clicked();

    void on_radioButton_prixPrix_clicked();

    void on_radioButton_eventPrix_clicked();

    void on_radioButton_typePrix_clicked();

    void on_radioButton_valeurPrix_clicked();

    void on_radioButton_nombrePrix_clicked();

    void on_updatePrix_clicked();

    void on_triTarif_clicked();

    void on_triDuree_clicked();

    void on_triValeur_clicked();

    void on_triNombre_clicked();

    void on_Imprimer_clicked();

private:
    Ui::MainWindow *ui;
    QString x;
    QString y;
    QSystemTrayIcon *notifyiconEv;
    QSystemTrayIcon *notifyiconAb;
};
#endif // MAINWINDOW_H

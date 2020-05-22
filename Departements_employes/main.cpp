#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include"departement.h"
#include "gestion_dep_empl.h"
#include "gestiondepartement.h"
#include "ui_gestiondepartement.h"
#include "DarkStyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new DarkStyle);

    Gestion_Dep_Empl w;
    Connexion c;
  if(c.ouvrirConnexion())
  {
    w.show();

     return a.exec();
}
  else { return 0; }

}


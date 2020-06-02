#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include "QDebug"
#include "Abonne.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Connection c;
      bool test=c.ouvrirconnexion();
         w.show();


    return a.exec();
}

#include "mainwindow.h"
#include "conexion.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTabWidget>

#include <QTranslator>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;

 MainWindow w;
    w.show();

    conexion  mybas;
    mybas.connection();
   return a.exec();


}

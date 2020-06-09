#ifndef TOURNOI_H
#define TOURNOI_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
class tournoi
{
private :
  QString id;
QString id_localisation;
QString type;
QString id_per;
public:
    tournoi();
     QSqlQueryModel* select();
    tournoi(QString,QString,QString,QString);
    void ajoutertournoi();
     QSqlQueryModel* affichertournoi();
     QSqlQueryModel* tri();
     QSqlQueryModel* recherche(QString id);
     void modifiertournoi(QString id);
     void supprimertournoi(QString id);

};

#endif // TOURNOI_H

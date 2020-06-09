#ifndef evenement_H
#define evenement_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
class evenement
{
private :
  QString id;
QString id_localisation;
QString type;
QString id_per;
QString depense;
public:
    evenement();
     QSqlQueryModel* select();
     QSqlQueryModel* select2(QString idper);
    evenement(QString,QString,QString,QString,QString);
    void ajouterevenement();
     QSqlQueryModel* afficherevenement();
     QSqlQueryModel* tri();
     QSqlQueryModel* countevenement();
     QSqlQueryModel* recherche(QString id);
     void modifierevenement(QString id);
     void supprimerevenement(QString id);

};

#endif // evenement_H

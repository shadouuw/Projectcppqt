#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDate>

class Personnel
{
private :
  QString id;
QString nom;
QString prenom;
QString adresse;
QString email;
QString id_dep;

public :
Personnel();
Personnel(QString,QString,QString,QString,QString,QString);
void ajouterpersonnel();
 QSqlQueryModel* afficherpersonnel();
 QSqlQueryModel* tri();
 QSqlQueryModel* recherche(QString id);
 void modifierpersonnel(QString id);
 void supprimerpersonnel(QString id);


};
#endif // PERSONNEL_H

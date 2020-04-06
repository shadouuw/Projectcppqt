#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDate>

class departement
{
private :
QString id;
QString nom;
QString type;
QString emplacement;
QString depense;
public:

    departement();
    departement(QString,QString,QString,QString,QString);
    void ajouterdepartement();
    QSqlQueryModel* countdepart();
     QSqlQueryModel* afficherdepartement();
};

#endif // DEPARTEMENT_H

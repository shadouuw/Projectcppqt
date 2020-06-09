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
     QSqlQueryModel* select();
    void supprimerdepartement(QString);
    QSqlQueryModel* recherche(QString id);
    void modifierdepartement (QString);

};

#endif // DEPARTEMENT_H

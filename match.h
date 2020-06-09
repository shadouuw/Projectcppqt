#ifndef MATCH_H
#define MATCH_H


#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDate>

class match
{
private :
QString id;
QString numero;
QString type;
QString localisation;
QString depense;
public:

    match();
    match(QString,QString,QString,QString,QString);
    void ajoutermatch();
    QSqlQueryModel* countdepart();
     QSqlQueryModel* affichermatch();
     QSqlQueryModel* select();
     QSqlQueryModel* tri();
    void supprimermatch(QString);
    QSqlQueryModel* recherche(QString id);
    void modifiermatch (QString);

};

#endif // MATCH_H

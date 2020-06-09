#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QSqlQueryModel>
class abonnement
{
private:
QString ID_AB;
QString ID_TOURNOI;
QDate DATE_AB;
QString DUREE_AB;
QString EMAIL;




public:
    abonnement();
    abonnement(QString,QString,QDate,QString,QString);
    void ajouterabonnement();
    QSqlQueryModel* afficherabonnement();
    QSqlQueryModel* tri();
    QSqlQueryModel* recherche(QString id);
    void supprimerabonnement(QString id);

};

#endif // ABONNEMENT_H

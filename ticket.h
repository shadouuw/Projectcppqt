#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDate>

class Ticket
{
private :
  QString id;
QString code;
QDate date_debut;
QDate date_fin;

public :
Ticket();
Ticket(QString,QString,QDate,QDate);
void ajouterticket();
QSqlQueryModel* afficherticket();
QSqlQueryModel* tri();
QSqlQueryModel* select();
QSqlQueryModel* verifier_id(QString id);
void qr_code(QString code,QString id);
QSqlQueryModel* recherche(QString id);
void modifierticket(QString id);
void supprimerticket(QString id);
QSqlQueryModel*  counttickets1(QString n);
QSqlQueryModel*  counttickets2();
QSqlQueryModel*  counttickets3();



};

#endif // TICKET_H

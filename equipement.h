#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H



#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDate>

class equipement
{
private :
QString id;
QString categorie;
QString type;
QString id_match;
QString depense;
public:

    equipement();
    equipement(QString,QString,QString,QString,QString);
    void ajouterequipement();
    QSqlQueryModel* countdepart();
     QSqlQueryModel* afficherequipement();
     QSqlQueryModel* select();
     QSqlQueryModel* tri();
    void supprimerequipement(QString);
    QSqlQueryModel* recherche(QString id);
    void modifierequipement (QString);

};
#endif // EQUIPEMENT_H

#ifndef JOUEUR_H
#define JOUEUR_H


#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>


class joueur
{
private:
    QString id;
    QString id_equipe;
    QString nom;
    QString prenom;
    QString longeur;
    QString poids;
    QString age;
    QString nationalite;


public:
    joueur();

    joueur( QString, QString, QString, QString, QString, QString, QString, QString );
    void ajouterjoueur();
    void modifierjoueur(QString);
    QSqlQueryModel* select2();
    void supprimerjoueur(QString);
    QSqlQueryModel* afficherjoueur();
    QSqlQueryModel* triIdequipe();
    QSqlQueryModel* trinom();
    QSqlQueryModel* selectstat1();
    QSqlQueryModel* selectstat2();
    QSqlQueryModel* trilongeur();
    QSqlQueryModel* tripoids();
    QSqlQueryModel* triage();
    QSqlQueryModel* triad();
    QSqlQueryModel* recherche2(QString);


};



#endif // JOUEUR_H

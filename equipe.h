#ifndef EQUIPE_H
#define EQUIPE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>

class equipe
{
private :
  QString id_equipe;
  QString id_tournoi;
  QString id_even;
  QString nom;
  QString region;

public :
 equipe();
 equipe(QString,QString,QString,QString,QString);
void ajouterequipe();
void modifierequipe(QString id_equipe);
void supprimerequipe(QString id_equipe);
QSqlQueryModel* afficherequipe();
QSqlQueryModel* tri();
QSqlQueryModel* select();
QSqlQueryModel* select3();
QSqlQueryModel* recherche(QString id_equipe);




};


#endif // EQUIPE_H

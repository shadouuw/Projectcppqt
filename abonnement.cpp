#include <QString>
#include<QVariant>
#include<QDebug>
#include<QSqlDatabase>
#include <iostream>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <qvariant.h>
#include <QTcpSocket>
#include "abonnement.h"

abonnement::abonnement()
{

}

abonnement::abonnement( QString ID_AB, QString ID_TOURNOI, QDate DATE_AB,QString DUREE_AB,QString EMAIL)
{

    this->ID_AB=ID_AB;
    this->ID_TOURNOI=ID_TOURNOI;

    this->DATE_AB= DATE_AB;
    this->DUREE_AB= DUREE_AB;
    this->EMAIL=EMAIL;

}

void abonnement::ajouterabonnement()
{
    QSqlQuery query;

      query.prepare("INSERT INTO ABONNEMENT (ID_AB,ID_TOURNOI,DATE_AB,DUREE_AB,EMAIL) VALUES (:ID_AB,:ID_TOURNOI,:DATE_AB,:DUREE_AB,:EMAIL)");

       query.bindValue(":ID_AB",ID_AB);
       query.bindValue(":ID_TOURNOI",ID_TOURNOI);
       query.bindValue(":DATE_AB",DATE_AB);
       query.bindValue(":DUREE_AB",DUREE_AB);
         query.bindValue(":EMAIL",EMAIL);

       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}

}

QSqlQueryModel* abonnement::afficherabonnement()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from ABONNEMENT");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* abonnement::tri()
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from ABONNEMENT order by DATE_AB");
    qry->exec();
    return modal;
}
QSqlQueryModel* abonnement::recherche(QString id)
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from ABONNEMENT where ID='"+id+"'");
    qry->exec();
    return modal;


}




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
#include "departement.h"

departement::departement()
{

}
departement::departement( QString id, QString nom, QString type,QString emplacement,QString depense)
{

    this->id=id;
    this->nom=nom;

    this->type=type;
    this->emplacement=emplacement;
    this->depense=depense;

}
void departement::ajouterdepartement()
{
    QSqlQuery query;

      query.prepare("INSERT INTO DEPARTEMENT (ID,NOM,TYPE,EMPLACEMENT_DEP,DEPENSE) VALUES (:ID,:NOM,:TYPE,:EMPLACEMENT_DEP,:DEPENSE)");

       query.bindValue(":ID",id);
       query.bindValue(":NOM",nom);
       query.bindValue(":TYPE",type);
       query.bindValue(":EMPLACEMENT_DEP",emplacement);
         query.bindValue(":DEPENSE",depense);

       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}

}




QSqlQueryModel* departement::afficherdepartement()
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from DEPARTEMENT");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* departement ::countdepart()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
     qry->prepare("select *from DEPARTEMENT ");


     qry->exec();
    modal->setQuery(*qry);

  return modal;
}

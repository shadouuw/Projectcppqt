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
QSqlQueryModel* departement ::select()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID from DEPARTEMENT");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

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

      query.prepare("INSERT INTO DEPARTEMENT (NOM,TYPE,EMPLACEMENT_DEP,DEPENSE) VALUES (:NOM,:TYPE,:EMPLACEMENT_DEP,:DEPENSE)");

       query.bindValue(":ID",id);
       query.bindValue(":NOM",nom);
       query.bindValue(":TYPE",type);
       query.bindValue(":EMPLACEMENT_DEP",emplacement);
         query.bindValue(":DEPENSE",depense);

       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}

}

void departement::modifierdepartement (QString id)
{
QSqlQuery query;
query.prepare("UPDATE DEPARTEMENT SET NOM=:NOM,TYPE=:TYPE,EMPLACEMENT_DEP=:EMPLACEMENT_DEP,DEPENSE=:DEPENSE where id ='"+id+"'");

query.bindValue(":NOM",nom);
 query.bindValue(":TYPE",type);
 query.bindValue(":EMPLACEMENT_DEP",emplacement);
 query.bindValue(":DEPENSE",depense);

query.exec();


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
void departement::supprimerdepartement(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM DEPARTEMENT WHERE ID='"+id+"'");
query.exec();
}
QSqlQueryModel* departement ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from DEPARTEMENT WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}



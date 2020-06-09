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
#include "match.h"

match::match()
{

}
QSqlQueryModel* match ::select()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID from match");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
match::match( QString id, QString numero, QString type,QString localisation,QString depense)
{

    this->id=id;
    this->numero=numero;

    this->type=type;
    this->localisation=localisation;
    this->depense=depense;

}
void match::ajoutermatch()
{
    QSqlQuery query;

      query.prepare("INSERT INTO match (NUMERO,LOCALISATION,TYPE) VALUES (:NOM,:TYPE,:EMPLACEMENT_DEP)");

       query.bindValue(":ID",id);
       query.bindValue(":NOM",numero);
       query.bindValue(":TYPE",type);
       query.bindValue(":EMPLACEMENT_DEP",localisation);
         query.bindValue(":DEPENSE",depense);

       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}

}

void match::modifiermatch (QString id)
{
QSqlQuery query;
query.prepare("UPDATE match SET NUMERO=:NOM,TYPE=:TYPE,LOCALISATION=:EMPLACEMENT_DEP where id ='"+id+"'");

query.bindValue(":NOM",numero);
 query.bindValue(":TYPE",type);
 query.bindValue(":EMPLACEMENT_DEP",localisation);
 query.bindValue(":DEPENSE",depense);

query.exec();


}


QSqlQueryModel* match::affichermatch()
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from match");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* match ::countdepart()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
     qry->prepare("select *from match ");


     qry->exec();
    modal->setQuery(*qry);

  return modal;
}
void match::supprimermatch(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM match WHERE ID='"+id+"'");
query.exec();
}
QSqlQueryModel* match ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from match WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* match ::tri()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from match order by ID");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


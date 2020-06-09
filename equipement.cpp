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
#include "equipement.h"

equipement::equipement()
{

}
QSqlQueryModel* equipement ::select()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID from equipement");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
equipement::equipement( QString id, QString categorie, QString type,QString id_match,QString depense)
{

    this->id=id;
    this->categorie=categorie;

    this->type=type;
    this->id_match=id_match;
    this->depense=depense;

}
void equipement::ajouterequipement()
{
    QSqlQuery query;

      query.prepare("INSERT INTO equipement (CATEGORIE,TYPE,ID_MATCH) VALUES (:NOM,:TYPE,:EMPLACEMENT_DEP)");

       query.bindValue(":ID",id);
       query.bindValue(":NOM",categorie);
       query.bindValue(":TYPE",type);
       query.bindValue(":EMPLACEMENT_DEP",id_match);
         query.bindValue(":DEPENSE",depense);

       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}

}

void equipement::modifierequipement (QString id)
{
QSqlQuery query;
query.prepare("UPDATE equipement SET CATEGORIE=:NOM,TYPE=:TYPE,ID_MATCH=:EMPLACEMENT_DEP where id ='"+id+"'");

query.bindValue(":NOM",categorie);
 query.bindValue(":TYPE",type);
 query.bindValue(":EMPLACEMENT_DEP",id_match);
 query.bindValue(":DEPENSE",depense);

query.exec();


}


QSqlQueryModel* equipement::afficherequipement()
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from equipement");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* equipement ::countdepart()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
     qry->prepare("select *from equipement ");


     qry->exec();
    modal->setQuery(*qry);

  return modal;
}
void equipement::supprimerequipement(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM equipement WHERE ID='"+id+"'");
query.exec();
}
QSqlQueryModel* equipement ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from equipement WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* equipement ::tri()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from equipement order by ID");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


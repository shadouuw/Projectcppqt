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
#include "evenement.h"

evenement::evenement()
{

    }

    evenement::evenement( QString id, QString id_localisation, QString type,QString id_per,QString depense)
    {

        this->id=id;
        this->id_localisation=id_localisation;
        this->type=type;
        this->depense=depense;
        this->id_per=id_per;

    }
    QSqlQueryModel* evenement ::countevenement()
    {

        QSqlQuery* qry = new QSqlQuery();
         QSqlQueryModel* modal=new QSqlQueryModel();
         qry->prepare("select *from evenement ");


         qry->exec();
        modal->setQuery(*qry);

      return modal;
    }

    QSqlQueryModel* evenement ::select()
    {

        QSqlQueryModel* modal=new QSqlQueryModel();
           QSqlQuery* qry = new QSqlQuery();
           qry->prepare("select ID from evenement");
           qry->exec();
           modal->setQuery(*qry);

           return modal;

    }
    QSqlQueryModel* evenement ::select2(QString idper)
    {

        QSqlQueryModel* modal=new QSqlQueryModel();
           QSqlQuery* qry = new QSqlQuery();
           qry->prepare("select * from evenement where id_personnel='"+idper+"'");
           qry->exec();
           modal->setQuery(*qry);

           return modal;

    }
void evenement::ajouterevenement()
{


  QSqlQuery query;

    query.prepare("INSERT INTO evenement (ID_LOC,TYPE_EVEN,ID_PERSONNEL,DEPENSE) VALUES (:ID_LOCALISATION,:TYPE,:ID_PER,:DEPENSE)");

     query.bindValue(":ID",id);
     query.bindValue(":ID_LOCALISATION",id_localisation);
     query.bindValue(":TYPE",type);
     query.bindValue(":ID_PER",id_per);
     query.bindValue(":DEPENSE",depense);


     if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}

}
void evenement::modifierevenement(QString id)
{
QSqlQuery query;
query.prepare("UPDATE evenement SET ID_LOC=:ID_LOCALISATION,TYPE_EVEN=:TYPE,ID_PERSONNEL=:ID_PER,DEPENSE=:DEPENSE WHERE ID='"+id+"'");

 query.bindValue(":ID_LOCALISATION",id_localisation);
 query.bindValue(":TYPE",type);
 query.bindValue(":ID_PER",id_per);
  query.bindValue(":DEPENSE",depense);
query.exec();

}

QSqlQueryModel* evenement ::afficherevenement()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from evenement");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* evenement ::tri()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from evenement order by ID");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* evenement ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from evenement WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


void evenement::supprimerevenement(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM evenement WHERE ID='"+id+"'");
query.exec();
}

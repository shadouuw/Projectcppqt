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
#include "tournoi.h"

tournoi::tournoi()
{

    }

    tournoi::tournoi( QString id, QString id_localisation, QString type,QString id_per)
    {

        this->id=id;
        this->id_localisation=id_localisation;
        this->type=type;
        this->id_per=id_per;

    }


    QSqlQueryModel* tournoi ::select()
    {

        QSqlQueryModel* modal=new QSqlQueryModel();
           QSqlQuery* qry = new QSqlQuery();
           qry->prepare("select ID_TOURNOI from TOURNOI");
           qry->exec();
           modal->setQuery(*qry);

           return modal;

    }

void tournoi::ajoutertournoi()
{


  QSqlQuery query;

    query.prepare("INSERT INTO tournoi (ID_TOURNOI,ID_LOCALISATION,TYPE,ID_PER) VALUES (:ID,:ID_LOCALISATION,:TYPE,:ID_PER)");

     query.bindValue(":ID",id);
     query.bindValue(":ID_LOCALISATION",id_localisation);
     query.bindValue(":TYPE",type);
     query.bindValue(":ID_PER",id_per);


     if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}

}
void tournoi::modifiertournoi(QString id)
{
QSqlQuery query;
query.prepare("UPDATE tournoi SET ID_LOCALISATION=:ID_LOCALISATION,TYPE=:TYPE,ID_PER=:ID_PER WHERE ID_TOURNOI='"+id+"'");

 query.bindValue(":ID_LOCALISATION",id_localisation);
 query.bindValue(":TYPE",type);
 query.bindValue(":ID_PER",id_per);
query.exec();

}

QSqlQueryModel* tournoi ::affichertournoi()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from tournoi");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* tournoi ::tri()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from tournoi order by ID_TOURNOI");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* tournoi ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from tournoi WHERE ID_TOURNOI='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


void tournoi::supprimertournoi(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM tournoi WHERE ID_TOURNOI='"+id+"'");
query.exec();
}

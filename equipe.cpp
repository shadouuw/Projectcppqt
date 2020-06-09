#include "equipe.h"
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

equipe::equipe()
{

}

QSqlQueryModel* equipe::select()
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select ID_EQUIPE from EQUIPE");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

 }
 equipe::equipe( QString id_equipe, QString id_tournoi, QString id_even, QString nom, QString region)
    {

        this->id_equipe=id_equipe;
        this->id_tournoi=id_tournoi;
        this->id_even=id_even;
        this->nom=nom;
        this->region= region;

    }

    void equipe::ajouterequipe()
{


  QSqlQuery query;


 query.prepare("INSERT INTO EQUIPE (ID_TOURNOI,ID_EVEN,NOM,REGION) VALUES (:ID_TOURNOI,:ID_EVEN,:NOM,:REGION)");

    query.bindValue(":ID_EQUIPE",id_equipe);
    query.bindValue(":ID_TOURNOI",id_tournoi);
    query.bindValue(":ID_EVEN",id_even);
    query.bindValue(":NOM",nom);
     query.bindValue(":REGION",region);

     if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}

}

void equipe::modifierequipe(QString id_equipe)
{

QSqlQuery query;
query.prepare("UPDATE EQUIPE SET ID_TOURNOI=:ID_TOURNOI,ID_EVEN=:ID_EVEN,NOM=:NOM,REGION=:REGION WHERE ID_EQUIPE='"+id_equipe+"'");

      query.bindValue(":ID_TOURNOI",id_tournoi);
      query.bindValue(":ID_EVEN",id_even);
      query.bindValue(":NOM",nom);
      query.bindValue(":REGION",region);

query.exec();


}

void equipe::supprimerequipe(QString id_equipe)
{
QSqlQuery query;
query.prepare("DELETE FROM EQUIPE WHERE ID_EQUIPE='"+id_equipe+"'");
query.exec();
}

QSqlQueryModel* equipe :: afficherequipe()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from EQUIPE");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* equipe ::tri()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from EQUIPE order by NOM");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* equipe ::recherche(QString id_equipe)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from EQUIPE where ID_EQUIPE='"+id_equipe+"' ");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* equipe ::select3()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID_EQUIPE from EQUIPE ");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

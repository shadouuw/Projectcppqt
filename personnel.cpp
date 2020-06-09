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
#include "personnel.h"

Personnel::Personnel()
{

    }

    Personnel::Personnel( QString id, QString nom, QString prenom,QString adresse,QString email,QString id_dep)
    {

        this->id=id;
        this->nom=nom;
        this->prenom= prenom;
        this-> adresse= adresse;
        this->email=email;
        this->id_dep=id_dep;

    }


void Personnel::ajouterpersonnel()
{


  QSqlQuery query;

    query.prepare("INSERT INTO PERSONNEL (NOM,PRENOM,ADRESSE,EMAIL,ID_DEP) VALUES (:NOM,:PRENOM,:ADRESSE,:EMAIL,:ID_DEP)");

     query.bindValue(":ID",id);
     query.bindValue(":NOM",nom);
     query.bindValue(":PRENOM",prenom);
     query.bindValue(":ADRESSE",adresse);
     query.bindValue(":EMAIL",email);
     query.bindValue(":ID_DEP",id_dep);


     if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}

}
void Personnel::modifierpersonnel(QString id)
{
QSqlQuery query;
query.prepare("UPDATE PERSONNEL SET NOM=:NOM,PRENOM=:PRENOM,ADRESSE=:ADRESSE,EMAIL=:EMAIL,ID_DEP=:ID_DEP WHERE ID='"+id+"'");

query.bindValue(":NOM",nom);
 query.bindValue(":PRENOM",prenom);
 query.bindValue(":ADRESSE",adresse);
 query.bindValue(":EMAIL",email);
  query.bindValue(":ID_DEP",id_dep);

query.exec();


}

QSqlQueryModel* Personnel ::afficherpersonnel()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from PERSONNEL");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* Personnel ::select()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID from PERSONNEL");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* Personnel ::tri()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from PERSONNEL order by ID");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* Personnel ::recherche(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from PERSONNEL WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* Personnel::select2(QString id)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from PERSONNEL WHERE ID='"+id+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

void Personnel::supprimerpersonnel(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM PERSONNEL WHERE ID='"+id+"'");
query.exec();
}

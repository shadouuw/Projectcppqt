


#include "joueur.h"

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


joueur::joueur()
{

    }

joueur::joueur( QString id, QString id_equipe, QString nom, QString prenom , QString longeur , QString poids , QString age, QString nationalite )
    {

        this->id=id;
        this->id_equipe=id_equipe;
        this->nom= nom;
        this->prenom= prenom;
        this->longeur= longeur;
        this->poids=poids;
        this->age=age;
        this->nationalite=nationalite;

    }

void joueur::ajouterjoueur()
{

    QSqlQuery query;

    query.prepare("INSERT INTO JOUEUR (ID_EQUIPE,NOM,PRENOM,LONGEUR,POIDS,AGE,NATIONALITE) VALUES (:ID_EQUIPE,:NOM,:PRENOM,:LONGEUR,:POIDS,:AGE,:NATIONALITE) " );

    query.bindValue(":ID",id);
    query.bindValue(":ID_EQUIPE",id_equipe);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":LONGEUR",longeur);
    query.bindValue(":POIDS",poids);
    query.bindValue(":AGE",age);
    query.bindValue(":NATIONALITE",nationalite);


      if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}



}


void joueur::modifierjoueur(QString id)
{
    QSqlQuery query;
query.prepare("UPDATE JOUEUR SET NOM=:NOM,ID_EQUIPE=:ID_EQUIPE,PRENOM=:PRENOM,LONGEUR=:LONGEUR,POIDS=:POIDS,AGE=:AGE,NATIONALITE=:NATIONALITE WHERE ID='"+id+"'");
    query.bindValue(":ID_EQUIPE",id_equipe);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":LONGEUR",longeur);
    query.bindValue(":POIDS",poids);
    query.bindValue(":AGE",age);
    query.bindValue(":NATIONALITE",nationalite);

query.exec();
}


void joueur::supprimerjoueur(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM JOUEUR WHERE ID='"+id+"'");
     query.exec();

}

QSqlQueryModel* joueur :: afficherjoueur()
{
       QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR");
    qry->exec();
    modal->setQuery(*qry);

  return modal;
}

QSqlQueryModel* joueur::triIdequipe()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by ID_EQUIPE ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* joueur::trinom()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by NOM ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* joueur::trilongeur()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by LONGEUR ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* joueur::tripoids()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by POIDS ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* joueur::triage()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by AGE ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* joueur::triad()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from JOUEUR order by ID ASC");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* joueur ::recherche2(QString nom)
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from JOUEUR WHERE ID='"+nom+"'");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}
QSqlQueryModel* joueur ::select2()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select ID from JOUEUR ");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


QSqlQueryModel* joueur ::selectstat1()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from JOUEUR where age > 30");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}

QSqlQueryModel* joueur ::selectstat2()
{

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select * from JOUEUR where age < 30");
       qry->exec();
       modal->setQuery(*qry);

       return modal;

}


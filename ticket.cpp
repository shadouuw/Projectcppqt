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
#include "ticket.h"

Ticket::Ticket()
{

    }

    Ticket::Ticket( QString id, QString code, QDate date_debut,QDate date_fin)
    {

        this->id=id;
        this->code=code;

        this-> date_debut= date_debut;
        this-> date_fin= date_fin;

    }


void Ticket::ajouterticket()
{


  QSqlQuery query;

    query.prepare("INSERT INTO TICKETS (ID,CODE,DATE_DEBUT,DATE_FIN) VALUES (:ID,:CODE,:DATE_DEBUT,:DATE_FIN)");

     query.bindValue(":ID",id);
     query.bindValue(":CODE",code);
     query.bindValue(":DATE_FIN",date_fin);
     query.bindValue(":DATE_DEBUT",date_debut);

     if(query.exec()){qDebug()<<"saved\n";}

        else{qDebug()<<"not saved!!!\n";}

}
void Ticket::modifierticket(QString id)
{
QSqlQuery query;
query.prepare("UPDATE TICKETS SET CODE=:CODE,DATE_FIN=:DATE_FIN,DATE_DEBUT=:DATE_DEBUT WHERE ID='"+id+"'");
 query.bindValue(":CODE",code);
 query.bindValue(":DATE_FIN",date_fin);
 query.bindValue(":DATE_DEBUT",date_debut);

query.exec();


}

void Ticket::qr_code(QString code,QString id)
{
QSqlQuery query;
query.prepare("UPDATE TICKETS SET QR_CODE=:CODE WHERE ID='"+id+"'");
query.bindValue(":CODE",code);
}
QSqlQueryModel* Ticket::verifier_id(QString id)
{
    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from TICKETS WHERE ID='"+id+"'");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

void Ticket::supprimerticket(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM TICKETS WHERE ID='"+id+"'");
query.exec();
}
QSqlQueryModel* Ticket :: afficherticket()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from TICKETS");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}
QSqlQueryModel* Ticket ::tri()
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from TICKETS order by DATE_DEBUT");
    qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* Ticket ::recherche(QString id)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
    qry->prepare("select *from TICKETS where ID='"+id+"' OR CODE='"+id+"'   ");



     qry->exec();
    modal->setQuery(*qry);

  return modal;

}

QSqlQueryModel* Ticket ::counttickets1(QString n)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* modal=new QSqlQueryModel();
     qry->prepare("select *from TICKETS where extract(MONTH from DATE_DEBUT )="+n+" ");


     qry->exec();
    modal->setQuery(*qry);

  return modal;

}







#include "donneur.h"
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


donneur::donneur()
{

    }

    donneur::donneur(QString civilite, QString nom , QString prenom, QString proffession, QString cin, QString adresse, QDate datenassaissance, QString email, QString tel, QString region, QString montant, QString nb)
    {

        this-> civilite=civilite;
        this->nom=nom;
        this-> prenom=prenom;
        this->proffession=proffession;
        this->cin=cin;
        this->adresse=adresse;
        this-> datenassaissance= datenassaissance;
        this->email=email;
        this->tel=tel;
        this->region=region;
        this->montant=montant;
        this->nb=nb;

    }

    void donneur:: ajoutDonneur()
    {
        QSqlQuery query;

       query.prepare("INSERT INTO DONNEURS (civilite, nom, prenom,proffession,cin,adresse,datenassaissance,email,tel,region,montant,nb)" "VALUES (:CIVILITE,:NOM,:PRENOM,:PROFFESSION,:CIN,:ADRESSE,:DATENASSAISSANCE,:EMAIL,:TEL,:REGION,:MONTANT,:NB)");
     // query.prepare("Insert into CLIENTS values('"+civilite+"','"+nom+"','"+prenom+"','"+proffession+"','"+cin+"','"+adresse+"','"+datenassaissance+"','"+email+"','"+tel+"','"+region+"','"+model+"','"+nb+"')");
      query.bindValue(":CIVILITE",civilite);
      query.bindValue(":NOM",nom);
      query.bindValue(":PRENOM",prenom);
      query.bindValue(":PROFFESSION",proffession);
      query.bindValue(":CIN",cin);
      query.bindValue(":ADRESSE",adresse);
       query.bindValue(":DATENASSAISSANCE",datenassaissance);
      query.bindValue(":EMAIL",email);
      query.bindValue(":TEL",tel);
      query.bindValue(":REGION",region);
      query.bindValue(":MONTANT",montant);
        query.bindValue(":NB",nb);




       if(query.exec()){qDebug()<<"saved\n";}

          else{qDebug()<<"not saved!!!\n";}


    }

    void donneur:: modifier()
    {
        QSqlQuery query ;
          // query.prepare("update DONNEURS set CIVILITE = '"+civilite+"', NOM = '"+nom+"', PRENOM='"+prenom+"',PROFFESSION='"+proffession+"',CIN='"+cin+"',ADRESSE='"+adresse+"',DATENASSAISSANCE='"+datenassaissance+"',TEL = '"+tel+"',EMAIL='"+email+"', MODEL='"+model+"',NB= '"+nb+"' where CIN= '"+cin+"'");
            query.prepare("update DONNEURS set  civilite=:CIVILITE, nom=:NOM, prenom=:PRENOM,proffession=:PROFFESSION,cin=:CIN,adresse=:ADRESSE,datenassaissance=:DATENASSAISSANCE,tel=:TEL ,email=:EMAIL,model=:MODEL,nb=:NB where(cin=:CIN)");
            query.bindValue(":CIVILITE",civilite);
            query.bindValue(":NOM",nom);
            query.bindValue(":PRENOM",prenom);
            query.bindValue(":PROFFESSION",proffession);
            query.bindValue(":CIN",cin);
            query.bindValue(":ADRESSE",adresse);
             query.bindValue(":DATENASSAISSANCE",datenassaissance);
            query.bindValue(":EMAIL",email);
            query.bindValue(":TEL",tel);
            query.bindValue(":REGION",region);
            query.bindValue(":MONTANT",montant);
              query.bindValue(":NB",nb);
           if(query.exec())
          {


           qDebug()<<" mis a jour effectuuer!!\n";
       }

        else{ qDebug()<<" echec de la mis a jour!!\n";}
    }


void donneur::supprimerDonneur()
{
    QSqlQuery query ;
       query.prepare("DELETE from DONNEURS where CIN = '"+cin+"'");
    if(query.exec())
       {

       qDebug()<<" supprimer!! \n";
   }
                     else{ qDebug()<<" echec de la suppression!! \n";}
   }



QSqlQueryModel *donneur:: rechercher(QString id)
{

    QSqlQueryModel *mqy=new::QSqlQueryModel;
               mqy->setQuery("select NOM,PRENOM,CIN,MODEL from DONNEURS where CIN like '%"+id+"%'");
               return mqy;

              }

 QSqlQueryModel *donneur::rechercher_nom(QString  name)
 {
     QSqlQueryModel *mqy=new::QSqlQueryModel;
                mqy->setQuery("select NOM,PRENOM,CIN,MODEL from DONNEURS where NOM like '%"+name+"%'");
                return mqy;


 }


QSqlQueryModel *donneur::afficher(QString id)
{

    QSqlQueryModel *mqy=new::QSqlQueryModel;
                mqy->setQuery("select *from DONNEURS where CIN like '%"+id+"%'");
                return mqy;
}


QSqlQueryModel *donneur::afficher_nom(QString name)
{

    QSqlQueryModel *mqy=new::QSqlQueryModel;
                mqy->setQuery("select *from DONNEURS where NOM like '%"+name+"%'");
                return mqy;
}


void donneur::notification(QString cin)
{
  QSystemTrayIcon *notif= new  QSystemTrayIcon;
  notif->show();
 // notif->setIcon(QIcon());
  notif->showMessage("service dons","un nouveau donneur a ete ajouter NUMERO CIN: "+cin+"",QSystemTrayIcon::Information,1000);
}

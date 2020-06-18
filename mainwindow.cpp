#include "mainwindow.h"
#include "smtp.h"
#include "ui_mainwindow.h"
#include "abonnement.h"
#include "conexion.h"
#include <QMovie>
#include <QIcon>
#include<QMessageBox>
#include<QDesktopServices>
#include<QDebug>
#include <QtWidgets>
#include <QLabel>
#include<QUrl>
#include<string>
#include<QFileDialog>
#include <QPixmap>
#include<QDateEdit>
#include<QDate>
#include <QTcpSocket>
#include <QTranslator>
#include "ticket.h"
#include "personnel.h"

#include "equipe.h"
#include "joueur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

 ui->pic_label->setAutoFillBackground(false);
 ui->pic_label->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
    QPixmap pix("C:/Users/User/Desktop/projrt/Nouveau dossier (4)/Section/welcome2.png"); //inserer une image
    ui->pic_label->setPixmap(pix);
    ui->pic_label_2->setAutoFillBackground(false);
    ui->pic_label_2->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   ui->pushButton_14->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix3("C:/Users/User/Desktop/projrt/Nouveau dossier (4)/Section/english.png"); //inserer une image
   QIcon ButtonIcon(pix3);
   ui->pushButton_14->setIcon(ButtonIcon);

   QMovie *movie=new QMovie("C:/Users/User/Desktop/projrt/Nouveau dossier (4)/Section/ezgif.com-resize.gif");
       ui->pic_label_2->setMovie(movie);
      movie->start();
      this->setFixedSize(1024,500);
      m_x=1024;
      m_y=768;
      qDebug() << QSslSocket::supportsSsl();qDebug() << QSslSocket::sslLibraryVersionString();

    Smtp* smtp=new Smtp("houss8976@gmail.com","Mouhamed123456","smtp.gmail.com");
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        smtp->sendMail("houss8976@gmail.com", "mohamedamine.messaoudi.1@esprit.tn" , "ahla w sahla","nchallah ta5tef xDD");


    ui->stackedWidget->setCurrentIndex(1);
      MainWindow::makeplot();

      if(t.load(":/english1.qm"))
          qDebug()<<"Loded successfully" << endl;
      else
          qDebug()<<"Could not load" << endl;
qApp->installTranslator(&t);

    QObject::connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(handle_Language_Change()));

     ui->combo_tri->addItem("par id");
     ui->combo_tri->addItem("par nom");

     ui->combo_tri->addItem("par id_equipe");

     ui->combo_tri->addItem("par longeur");
     ui->combo_tri->addItem("par poids");
     ui->combo_tri->addItem("par age");

      ui->combo_tri_equipe->addItem("par id_equipe");
      ui->combo_tri_equipe->addItem("par nom");


     ui->combo_tri_equipe->addItem("par id_tournoi");

     ui->combo_tri_equipe->addItem("par id_evenement");



}

 void MainWindow::makeplot()
{

  Ticket t;
}

 void connect()
 {
 QTcpSocket socket;
 socket.connectToHost("voidrealms.com",80);
 if(socket.waitForConnected(3000))
    {
 qDebug()<<"Connected!";
 }
 }



MainWindow::~MainWindow()
{
    delete ui;
}

 //ajouter
void MainWindow::on_pushButton_3_clicked()
{

           QString id=ui->id->text();
            QString code=ui->code->text();

             QDate date_debut=ui->date_debut->date();
             QDate date_fin=ui->date_fin->date();


            Ticket t(id,code,date_debut,date_fin);

             if(id.isEmpty() || code.isEmpty() )
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                t.ajouterticket();
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" Le ticket a été ajouter."),QMessageBox::Yes);
                 /*QSqlQueryModel* modal=new QSqlQueryModel();
                    QSqlQuery* qry = new QSqlQuery();
                    qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
                    qry->exec();
                    modal->setQuery(*qry);
                    ui->tableView->setModel(modal);*/



                 }


    }
void MainWindow::on_pushButton_7_clicked()
{

           QString id=ui->id_2->text();
            QString nom=ui->nom->text();

             QString prenom=ui->prenom->text();
             QString adresse=ui->adresse->text();
              QString email=ui->email->text();


            Personnel p(id,nom,prenom,adresse,email);

             if(id.isEmpty() || nom.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                p.ajouterpersonnel();
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" Le personnel a été modifier."),QMessageBox::Yes);




                 }


    }
void MainWindow::on_ajouter_abonnement_clicked()
{

           QString id=ui->id_6->text();
            QString id_tournoi=ui->id_7->text();

             QDate date_ab=ui->date_debut_2->date();
             QString duree_ab=ui->id_8->text();
              QString email=ui->id_9->text();


            abonnement a(id,id_tournoi,date_ab,duree_ab,email);

             if(id.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                a.ajouterabonnement();
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" L Abonnement a été ajouter avec succées."),QMessageBox::Yes);




                 }


    }
void MainWindow::on_modifier_personnel_clicked()
{

           QString id=ui->id_2->text();
            QString nom=ui->nom->text();

             QString prenom=ui->prenom->text();
             QString adresse=ui->adresse->text();
              QString email=ui->email->text();


            Personnel p(id,nom,prenom,adresse,email);

             if(id.isEmpty() || nom.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                p.modifierpersonnel(id);
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" Le personnel a été modifier."),QMessageBox::Yes);




                 }


    }

void MainWindow::on_pushButton_19_clicked()
{
    QString id=ui->id->text();
     QString code=ui->code->text();

      QDate date_debut=ui->date_debut->date();
      QDate date_fin=ui->date_fin->date();


     Ticket t(id,code,date_debut,date_fin);

      if(id.isEmpty() || code.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         t.modifierticket(id);
          QMessageBox::information(0,qApp->tr("erreur"),
                                qApp->tr(" Le ticket a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/



          }



}
void MainWindow::on_pushButton_5_clicked()
{
    Ticket t;
    QSqlQueryModel* modal=t.afficherticket();

    ui->tableView->setModel(modal);

       qDebug()<<(modal->rowCount());
}
void MainWindow::on_afficher_abonnement_clicked()
{
    abonnement a;
    QSqlQueryModel* modal=a.afficherabonnement();

    ui->tableView_6->setModel(modal);

       qDebug()<<(modal->rowCount());
}
void MainWindow::on_pushButton_8_clicked()
{
    Personnel p;
 QSqlQueryModel* modal=p.afficherpersonnel();
    ui->tableView_2->setModel(modal);

       qDebug()<<(modal->rowCount());
}


//// afficher
/*void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
       qry->exec();
       modal->setQuery(*qry);
    ui->tableView->setModel(modal);

       qDebug()<<(modal->rowCount());
}
//modifier
void MainWindow::on_pushButton_4_clicked()
{
    QString nom=ui->nom_p->text();
       QString prenom=ui->prenom_p->text();
        QString tel=ui->tel_p->text();
         QString adresse=ui->adresse_p->text();
           QString nb=ui->nb_p->text();
            QString cin=ui->cin_p->text();
            QString email=ui->email_p->text();
            QDate datenassaissance=ui->datenaissance_p->date();
            QString proffession =ui->proffession_p->text();
            QString region =ui->region_p->text();
             QString civilite =ui->civilite_p->text();


 donneur cp(civilite,nom,prenom,proffession,cin,adresse,datenassaissance,email,tel,region,nb);

 if(cin.isEmpty())
     {
         QMessageBox::critical(0,qApp->tr("erreur"),
                               qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
     }
 else{
     QMessageBox::critical(0,qApp->tr("erreur"),
                           qApp->tr("voulez vous modifier ce donneur."),QMessageBox::Yes,QMessageBox::No);
  cp.modifier();
  QSqlQueryModel* modal=new QSqlQueryModel();
     QSqlQuery* qry = new QSqlQuery();
     qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
     qry->exec();
     modal->setQuery(*qry);
   ui->tableView->setModel(modal);

     qDebug()<<(modal->rowCount());
 }
   ui->nom_p->clear();
     ui->prenom_p->clear();
       ui->adresse_p->clear();

           ui->nb_p->clear();
            ui->cin_p->clear();
            ui->civilite_p->clear();
            ui->region_p->clear();
            ui->proffession_p->clear();
            ui->datenaissance_p->clear();
            ui->email_p->clear();
            ui->tel_p->clear();
}
//reafficher les valeurs
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int r=index.row();
    ui->nom_p->setText(index.sibling(r,1).data().toString());
    ui->prenom_p->setText(index.sibling(r,2).data().toString());
    ui->adresse_p->setText(index.sibling(r,5).data().toString());
    // ui->datenaissance_p->setText(index.sibling(r,6).data().toString());
     ui->tel_p->setText(index.sibling(r,8).data().toString());
    ui->email_p->setText(index.sibling(r,7).data().toString());
    ui->region_p->setText(index.sibling(r,9).data().toString());
     //ui->nb_p->setText(index.sibling(r,10).data().toString());
    ui->proffession_p->setText(index.sibling(r,3).data().toString());
    ui->cin_p->setText(index.sibling(r,4).data().toString());
}

//supprimer
void MainWindow::on_pushButton_6_clicked()
{
    QString cin=ui->cin_p->text();
    QDate datenassaissance=ui->datenaissance_p->date();
     QString nom=ui->nom_p->text();
      QString adresse=ui->adresse_p->text();

    donneur cp("",nom,"","",cin,adresse,datenassaissance ,"","","","");

    if(nom.isEmpty() || adresse.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),
                                  qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
        }
    else{
        QMessageBox::critical(0,qApp->tr("erreur"),
                              qApp->tr("voulez vous suporimer ce donneur."),QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes){cp.supprimerdonneur();}

    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
       qry->exec();
       modal->setQuery(*qry);
       ui->tableView->setModel(modal);

       qDebug()<<(modal->rowCount());


    }

     ui->cin_p->clear();
     ui->nom_p->clear();
       ui->prenom_p->clear();
         ui->adresse_p->clear();

             ui->nb_p->clear();
              ui->cin_p->clear();
              ui->civilite_p->clear();
              ui->region_p->clear();
              ui->proffession_p->clear();
              //ui->datenaissance_p->clear();
              ui->email_p->clear();
              ui->tel_p->clear();
}




//rechercher





//imprimer la liste tableview2

//visitez la page fb
void MainWindow::on_commandLinkButton_clicked()
{
    QString link="https://www.facebook.com/Mercedes-Benz-Tunisie-1094449294019699/";
    QDesktopServices::openUrl(QUrl(link));
}

//visitez le site web
void MainWindow::on_commandLinkButton_2_clicked()
{
    QString link="https://www.automobile.tn";
    QDesktopServices::openUrl(QUrl(link));
}
//quitter
void MainWindow::on_pushButton_clicked()
{
    this->hide();
}
//page compte

//rechercher ok no ,id

//page email


*/




/*--------------------------------------------------------------------------------------------------------------------------------*/
//Authentification


void MainWindow::on_pushButton_11_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();

    equipe t1; //declaration
    QSqlQueryModel *modal1=t1.select(); //thez les id
    ui->comboBox->setModel(modal1);//t7othom fel combobox

  joueur j1;
QSqlQueryModel *modal2=j1.select2();
ui->comboBox_2->setModel(modal2);

  equipe e1;
QSqlQueryModel *modal3=e1.select3();
ui->com_modifier->setModel(modal3);

    if(username=="test" && password == "test")
       {
    QMessageBox::information(this,"Login","Username and password are Correct");
    ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
    QMessageBox::warning(this,"Login","Username and Password are Incorrect");
      }
}
void MainWindow::on_pushButton_12_clicked()
{
 ui->stackedWidget->setCurrentIndex(1);
   }

void MainWindow:: handle_Language_Change()
{
    if(t.load(":/english1.qm"))
        qDebug()<<"Loded successfully" << endl;  //change language to english
    else
        qDebug()<<"Could not load" << endl;
   if(qApp->installTranslator(&t))
{
       qDebug()<<"It worked"<<endl;

}
   ui->retranslateUi(this);
}

void MainWindow::on_pushButton_14_clicked()
{

}
void MainWindow::on_pushButton_13_clicked()
{
    Ticket t;
    QSqlQueryModel* modal=t.tri();

    ui->tableView->setModel(modal);

       qDebug()<<(modal->rowCount());

}
void MainWindow::on_pushButton_16_clicked()
{
    Ticket t;

    QString id=ui->recherche_label->text();

    QSqlQueryModel* modal=t.recherche(id);

    ui->tableView->setModel(modal);

       qDebug()<<(modal->rowCount());

}
void MainWindow::on_pushButton_17_clicked()
{
    Personnel p;

    QString id=ui->recherche_label_2->text();

    QSqlQueryModel* modal=p.recherche(id);

    ui->tableView_2->setModel(modal);

       qDebug()<<(modal->rowCount());

}
void MainWindow::on_pushButton_18_clicked()
{
    Personnel p;

    QString id=ui->recherche_label_2->text();

    QSqlQueryModel* modal=p.tri();

    ui->tableView_2->setModel(modal);

       qDebug()<<(modal->rowCount());

}
void MainWindow::on_delete_2_clicked()
{
    Ticket t;

    QString id=ui->recherche_label_3->text();

    t.supprimerticket(id);



}
void MainWindow::on_delete_personnel_clicked()
{
    Personnel p;

    QString id=ui->recherche_label_5->text();

    p.supprimerpersonnel(id);



}
void MainWindow::on_pushButton_15_clicked()
{
    if(t.load(":/japonais.qm"))
        qDebug()<<"Loded successfully" << endl;    //change language to japanese
    else
        qDebug()<<"Could not load" << endl;
   if(qApp->installTranslator(&t))
{
       qDebug()<<"It worked"<<endl;

}
   ui->retranslateUi(this);

}
void MainWindow::on_ajouter_equipe_clicked()
{

           QString id_equipe;
            QString id_tournoi=ui->id_tournoi->text();
             QString id_even=ui->id_even->text();
              QString nom=ui->nom_2->text();
               QString region=ui->region_2->text();





            equipe e(id_equipe,id_tournoi,id_even,nom,region);

             if(id_tournoi.isEmpty() || id_even.isEmpty() || nom.isEmpty() || region.isEmpty() )
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                e.ajouterequipe();
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" L'equipe a été ajouter a la liste."),QMessageBox::Yes);




                 }

             equipe t1; //declaration
             QSqlQueryModel *modal1=t1.select(); //thez les id
             ui->comboBox->setModel(modal1);//t7othom fel combobox

              equipe e1;
             QSqlQueryModel *modal3=e1.select3();
             ui->com_modifier->setModel(modal3);
    }

void MainWindow::on_ajouter_joueur_clicked()
{

           QString id;
            QString id_equipe=ui->comboBox->currentText();
             QString nom=ui->nom_3->text();
              QString prenom=ui->prenom_2->text();
               QString longeur=ui->longeur->text();
                QString poids=ui->poids->text();
                 QString age=ui->age->text();
                  QString nationalite=ui->nationalite->text();






            joueur j(id,id_equipe,nom,prenom,longeur,poids,age,nationalite);

             if( id_equipe.isEmpty() || nom.isEmpty() || prenom.isEmpty() || longeur.isEmpty() || poids.isEmpty() || age.isEmpty() || nationalite.isEmpty() )
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                j.ajouterjoueur();
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" Le joueur a été ajouter a la liste."),QMessageBox::Yes);




                 }

             joueur j1;
           QSqlQueryModel *modal2=j1.select2();
           ui->comboBox_2->setModel(modal2);

    }


void MainWindow::on_afficher_equipe_clicked()
{
    equipe e;
    QSqlQueryModel* modal=e.afficherequipe();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_afficher_joueur_clicked()
{
    joueur j;
    QSqlQueryModel* modal=j.afficherjoueur();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_modifier_equipe_clicked()
{

           QString id_equipe=ui->com_modifier->currentText();
            QString id_tournoi=ui->id_tournoi->text();

             QString id_even=ui->id_even->text();
             QString nom=ui->nom_2->text();
              QString region=ui->region_2->text();


              equipe e(id_equipe,id_tournoi,id_even,nom,region);

             if( id_tournoi.isEmpty() || id_even.isEmpty() || nom.isEmpty() || region.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                e.modifierequipe(id_equipe);
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" les information qui tu a changeé a été modifier."),QMessageBox::Yes);




                 }


    }

    void MainWindow::on_modifier_joueur_clicked()
{

           QString id=ui->comboBox_2->currentText();
            QString id_equipe=ui->comboBox->currentText();
             QString nom=ui->nom_3->text();
              QString prenom=ui->prenom_2->text();
               QString longeur=ui->longeur->text();
                QString poids=ui->poids->text();
                 QString age=ui->age->text();
                  QString nationalite=ui->nationalite->text();


              joueur j(id,id_equipe,nom,prenom,longeur,poids,age,nationalite);

              if( id_equipe.isEmpty() || nom.isEmpty() || prenom.isEmpty() || longeur.isEmpty() || poids.isEmpty() || age.isEmpty() || nationalite.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                j.modifierjoueur(id);
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" les information qui tu a changeé a été modifier."),QMessageBox::Yes);




                 }


    }

void MainWindow::on_supp_equipe_clicked()
{
    equipe e;

    QString id_equipe=ui->recherche_supp->text();

    e.supprimerequipe(id_equipe);

         equipe t1; //declaration
             QSqlQueryModel *modal1=t1.select(); //thez les id
             ui->comboBox->setModel(modal1);//t7othom fel combobox


   equipe e1;
   QSqlQueryModel *modal3=e1.select3();
   ui->com_modifier->setModel(modal3);

}

void MainWindow::on_supprimer_joueur_clicked()
{
    joueur j;

    QString id=ui->id_supp->text();

    j.supprimerjoueur(id);

    joueur j1;
    QSqlQueryModel *modal2=j1.select2();
    ui->comboBox_2->setModel(modal2);


}

void MainWindow::on_recherche_equipe_clicked()
{
    equipe e;

    QString id_equipe=ui->id_recherche->text();

    QSqlQueryModel* modal=e.recherche(id_equipe);

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());

}

void MainWindow::on_recherche_joueur_clicked()
{
    joueur j;

    QString id=ui->id_recherche2->text();

    QSqlQueryModel* modal=j.recherche2(id);

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());

}

void MainWindow::on_tri_equipe_clicked()
{
    equipe e;
    if(ui->combo_tri_equipe->currentText()=="par id_equipe")
    {
         QSqlQueryModel* modal=e.triIDequipe();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
    }

    if(ui->combo_tri_equipe->currentText()=="par id_tournoi")
    {
         QSqlQueryModel* modal=e.tritournoi();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
    }


    if(ui->combo_tri_equipe->currentText()=="par id_evenement")
    {
         QSqlQueryModel* modal=e.trieven();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
    }

 if(ui->combo_tri_equipe->currentText()=="par nom")
    {
         QSqlQueryModel* modal=e.trinom();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
    }



}

void MainWindow::on_tri_joueur_clicked()
{
    joueur j;

   if (ui->combo_tri->currentText()=="par id_equipe")
   {

        QSqlQueryModel* modal=j.triIdequipe();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }

     if (ui->combo_tri->currentText()=="par nom")
   {

        QSqlQueryModel* modal=j.trinom();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }
    if (ui->combo_tri->currentText()=="par poids")
   {

        QSqlQueryModel* modal=j.tripoids();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }
    if (ui->combo_tri->currentText()=="par longeur")
   {

        QSqlQueryModel* modal=j.trilongeur();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }
    if (ui->combo_tri->currentText()=="par age")
   {

        QSqlQueryModel* modal=j.triage();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }
    if (ui->combo_tri->currentText()=="par id")
   {

        QSqlQueryModel* modal=j.triad();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
   }



}
void MainWindow::on_exporter_clicked()
{
    QTableView *table;
    table = ui->table_joueur;

    QString filters("CSV files (.csv);;All files (.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                       filters, &defaultFilter);
    QFile file(fileName);

    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
        QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
    }

}

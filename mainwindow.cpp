#include "mainwindow.h"
#include <QSqlRecord>
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
#include <QBarSet>
#include <QLabel>
#include<QUrl>
#include<string>
#include<QFileDialog>
#include <QPixmap>
#include<QDateEdit>
#include <QDebug>
#include "generator/qrcode_generator.h"
#include<QDate>
#include <QTcpSocket>
#include <QTranslator>
#include <QtCharts>
#include "departement.h"
#include <QLineSeries>
#include <stats.h>
#include "ticket.h"
#include "personnel.h"
using namespace QtCharts;

static const QString SAVE_TO_PNG(QString("Save imagefile to\nQRCode.png"));
static const QString SAVE_TO_JPG(QString("Save imagefile to\nQRCode.jpg"));
static const QString SAVE_TO_BMP(QString("Save imagefile to\nQRCode.bmp"));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
#ifdef Q_OS_WINDOWS
    QRCodeGenerator::Initialize();
#endif
 ui->pic_label->setAutoFillBackground(false);
 ui->pic_label->setAttribute(Qt::WA_TranslucentBackground);
 ui->qrcodepixmapLabel->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
    QPixmap pix("C:/Users/besmelleh/Desktop/Nouveau dossier (4)/Section/welcome2.png"); //inserer une image
    ui->pic_label->setPixmap(pix);
    ui->pic_label_2->setAutoFillBackground(false);
    ui->pic_label_2->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   ui->pushButton_14->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix3("C:/Users/besmelleh/Desktop/Nouveau dossier (4)/Section/english.png"); //inserer une image
   QIcon ButtonIcon(pix3);
   ui->pushButton_14->setIcon(ButtonIcon);

   QMovie *movie=new QMovie("C:/Users/besmelleh/Desktop/Nouveau dossier (4)/Section/ezgif.com-resize.gif");
       ui->pic_label_2->setMovie(movie);
      movie->start();
      this->setFixedSize(1024,500);
      m_x=1024;
      m_y=768;
      qDebug() << QSslSocket::supportsSsl();qDebug() << QSslSocket::sslLibraryVersionString();



    ui->stackedWidget->setCurrentIndex(1);
      MainWindow::makeplot();

      if(t.load(":/english1.qm"))
          qDebug()<<"Loded successfully" << endl;
      else
          qDebug()<<"Could not load" << endl;
qApp->installTranslator(&t);

    QObject::connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(handle_Language_Change()));

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

void MainWindow::on_Qr_code_clicked()
{

        ui->stackedWidget->setCurrentIndex(3);

}






void MainWindow::on_ajouterdepartement_clicked()
{
    QString id=ui->id_5->text();
     QString nom=ui->id_11->text();

      QString type=ui->id_12->text();
      QString emplacement=ui->id_14->text();
      QString depense=ui->id_13->text();


     departement d(id,nom,type,emplacement,depense);

      if(id.isEmpty() || nom.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.ajouterdepartement();
          QMessageBox::information(0,qApp->tr("erreur"),
                                qApp->tr(" Le departement a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
}

void MainWindow :: on_afficherdepartement_clicked()
{
departement d;
    QSqlQueryModel* modal=d.afficherdepartement();

    ui->tableView_5->setModel(modal);

       qDebug()<<(modal->rowCount());
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
              QString id_dep=ui->id_10->text();

            Personnel p(id,nom,prenom,adresse,email,id_dep);

             if(id.isEmpty() || nom.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                p.ajouterpersonnel();
                Smtp* smtp=new Smtp("houss8976@gmail.com","Mouhamed123456","smtp.gmail.com");
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                    smtp->sendMail("houss8976@gmail.com", email , "Sportzen","Bienvenu "+nom+" "+prenom+" a notre association sportzen !");
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr(" Le personnel a été ajouter."),QMessageBox::Yes);




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
                 Smtp* smtp=new Smtp("houss8976@gmail.com","Mouhamed123456","smtp.gmail.com");
                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                     smtp->sendMail("houss8976@gmail.com", email , "Sportzen","Bienvenu  a notre association sportzen !");

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
              QString id_dep=ui->id_10->text();


            Personnel p(id,nom,prenom,adresse,email,id_dep);

             if(id.isEmpty() || nom.isEmpty() )
                 {
                     QMessageBox::information(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                p.modifierpersonnel(id);
                Smtp* smtp=new Smtp("houss8976@gmail.com","Mouhamed123456","smtp.gmail.com");
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                    smtp->sendMail("houss8976@gmail.com", email , "Sportzen","Bonjour "+nom+" "+prenom+" ,nous vous informons que vos informations ont été modifier !");
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
                                qApp->tr(" Le ticket a été modifier."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/



          }



}

void MainWindow::on_afficherstatdepart_clicked()
{
    QBarSet *set0=new QBarSet("Depenses");

    int n1=0;

     int depense[100];
     int j=0;
     for(j=0;j<100;j++)
       {
        depense[j]=0;
     }
    departement d;
    QString name[20];

     QSqlQueryModel*  modal1=d.countdepart();
    qDebug()<<(n1=modal1->rowCount());
    for (int i = 0; i <= modal1->rowCount(); i++) {

           depense[i] = modal1->record(i).value("depense").toInt();
             qDebug()<<depense[i];
           name[i] = modal1->record(i).value("nom").toString();
           qDebug()<<name[i];

       }

*set0<<depense[0]<<depense[1]<<depense[2]<<depense[3]<<depense[4]<<depense[5]<<depense[6];

    QBarSeries *series=new QBarSeries();
    series->append(set0);

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des depense anuelles des departement ");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories <<name[0]<<name[1]<<name[2]<<name[3]<<name[4];
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    QChartView *ChartView=new QChartView(chart);

     ChartView->setParent(ui->horizontalFrame);
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_stats_clicked()

{
QBarSet *set0=new QBarSet("Ticket vendus");

int n1=0;
int n2=0;
int n3=0;
int n4=0;
int n5=0;
int n6=0;
int n7=0;
int n8=0;
int n9=0;
int n10=0;
 int n11=0;
 int n12=0;
Ticket t;
 QSqlQueryModel*  modal1=t.counttickets1("1");
qDebug()<<(n1=modal1->rowCount());
 modal1=t.counttickets1("2");
qDebug()<<(n2=modal1->rowCount());
 modal1=t.counttickets1("3");
qDebug()<<(n3=modal1->rowCount());
modal1=t.counttickets1("4");
qDebug()<<(n4=modal1->rowCount());
modal1=t.counttickets1("5");
qDebug()<<(n5=modal1->rowCount());
modal1=t.counttickets1("6");
qDebug()<<(n6=modal1->rowCount());
modal1=t.counttickets1("7");
qDebug()<<(n7=modal1->rowCount());
modal1=t.counttickets1("8");
qDebug()<<(n8=modal1->rowCount());
modal1=t.counttickets1("9");
qDebug()<<(n9=modal1->rowCount());
modal1=t.counttickets1("10");
qDebug()<<(n10=modal1->rowCount());
modal1=t.counttickets1("11");
qDebug()<<(n11=modal1->rowCount());
modal1=t.counttickets1("12");
qDebug()<<(n12=modal1->rowCount());
*set0<<n1<<n2<<n3<<n4<<n5<<n6<<n7<<n8<<n9<<n10<<n11<<n12;

QBarSeries *series=new QBarSeries();
series->append(set0);

QChart *chart=new QChart();
chart->addSeries(series);
chart->setTitle("Statistique des tickets vendus ");
chart->setAnimationOptions(QChart::SeriesAnimations);
QStringList categories;
categories <<"Janvier"<<"Fevrier"<<"Mars"<<"Avril"<<"Mai"<<"Juin"<<"Juillet"<<"Aout"<<"Septembre"<<"Octobre"<<"Novmbre"<<"Décembre";
QBarCategoryAxis *axis=new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis,series);
QChartView *ChartView=new QChartView(chart);

 ChartView->setParent(ui->horizontalFrame);
ui->stackedWidget->setCurrentIndex(2);

}
void MainWindow::on_returnstat_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_retouuur_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
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


//qr coding
void MainWindow::on_generateButton_pressed()
{
    QString text = ui->lineEdit->text();

    if (text.isEmpty()) {
       return;
    }

    int qrcode_width = ui->qrcodepixmapLabel->width();
    int qrcode_height = ui->qrcodepixmapLabel->height();
    QPixmap qrcode_pixmap;
    bool result;
    result = QRCodeGenerator::GeneratePixmapFromText(text, qrcode_pixmap, qrcode_width, qrcode_height);
    if (true == result){
        ui->qrcodepixmapLabel->setPixmap(qrcode_pixmap);
    }
    else{
        QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCodeImage."));
        return;
    }

    if ((ui->qrcodepixmapLabel->pixmap() != Q_NULLPTR)
            && (ui->qrcodepixmapLabel->pixmap()->isNull() != true)){
        ui->saveFileButton->setEnabled(true);
    }
    else{
        ui->saveFileButton->setEnabled(false);
    }
}

void MainWindow::on_saveFileButton_pressed()
{
    if ((ui->qrcodepixmapLabel->pixmap() != Q_NULLPTR)
            && (ui->qrcodepixmapLabel->pixmap()->isNull() != true)){
        const QPixmap *QRCodePixmap = ui->qrcodepixmapLabel->pixmap();

        QString imageType = ui->comboBox->currentText();

        QString filetypeStr;
        if (imageType == QString("BMP")){
            filetypeStr = QString(".bmp");
        }
        else if (imageType == QString("JPG")){
            filetypeStr = QString(".jpg");
        }
        else if (imageType == QString("PNG")){
            filetypeStr = QString(".png");
        }
        else{
            filetypeStr = QString(".bmp");
        }

        bool saveResult;
        QString savefileName = QString("QRCode") + filetypeStr;
        saveResult = QRCodePixmap->save(savefileName);

        if (true == saveResult){
            QMessageBox::information(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" success"));
        }
        else{
            QMessageBox::warning(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" failure"));
        }
    }
    else{
        QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCode Image"));
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString savetofile_buttonStr;

    QString filetypeStr;
    if (arg1 == QString("BMP")){
        savetofile_buttonStr = SAVE_TO_BMP;
    }
    else if (arg1 == QString("JPG")){
        savetofile_buttonStr = SAVE_TO_JPG;
    }
    else if (arg1 == QString("PNG")){
        savetofile_buttonStr = SAVE_TO_PNG;
    }
    else{
        savetofile_buttonStr = SAVE_TO_PNG;
    }

    ui->saveFileButton->setText(savetofile_buttonStr);
}


void MainWindow::on_qr_button_pressed()
{
Ticket t;
 QString text = ui->lineEdit->text();
 QString text2=ui->qr_id->text();
QSqlQueryModel* modal=t.verifier_id(text2);
int n=modal->rowCount();
if(n!=0)
{
t.qr_code(text,text2);
}
else
{
    QMessageBox::critical(0,qApp->tr("erreur"),
                          qApp->tr("l'id n'existe pas dans la base."),QMessageBox::Cancel);
}



}

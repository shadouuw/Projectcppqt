#include "mainwindow.h"
#include <QSqlRecord>
#include "smtp.h"
#include "joueur.h"
#include "match.h"
#include "equipement.h"
#include "equipe.h"
#include "email.h"
#include "tournoi.h"
#include "ui_mainwindow.h"
#include "abonnement.h"
#include "don.h"
#include "donneur.h"
#include <QPainter>
#include <QInputMethodQueryEvent>
#include "evenement.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
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
    QPixmap pix("C:/Users/besmelleh/Desktop/Project/testing/Section/welcome2.png"); //inserer une image
    ui->pic_label->setPixmap(pix);
    ui->pic_label_2->setAutoFillBackground(false);
    ui->pic_label_2->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   ui->pushButton_14->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix3("C:/Users/besmelleh/Desktop/Project/testing/Section/english.png"); //inserer une image
   QIcon ButtonIcon(pix3);
   ui->pushButton_15->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix9("C:/Users/besmelleh/Desktop/Project/testing/Section/japon.png"); //inserer une image
   QIcon ButtonIcon8(pix9);
   this->setWindowTitle("Sportzen");
   setWindowIcon(QIcon("C:/Users/besmelleh/Desktop/Project/testing/Section/logo.png"));
   ui->pushButton_14->setIcon(ButtonIcon);
   ui->pushButton_47->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix5("C:/Users/besmelleh/Desktop/Project/testing/Section/france.png"); //inserer une image
   QIcon ButtonIcon3(pix5);

   ui->pushButton_48->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
   QPixmap pix6("C:/Users/besmelleh/Desktop/Project/testing/Section/arabe.png"); //inserer une image
   QIcon ButtonIcon4(pix6);
   ui->pushButton_47->setIcon(ButtonIcon3);
    ui->pushButton_48->setIcon(ButtonIcon4);
    ui->pushButton_15->setIcon(ButtonIcon8);
   QMovie *movie=new QMovie("C:/Users/besmelleh/Desktop/Project/testing/Section/ezgif.com-resize.gif");
       ui->pic_label_2->setMovie(movie);
      movie->start();
      this->setFixedSize(1024,500);
      m_x=1024;
      m_y=768;
      qDebug() << QSslSocket::supportsSsl();qDebug() << QSslSocket::sslLibraryVersionString();


      tournoi t1;
      QSqlQueryModel *modal1=t1.select();
      ui->comboBox_tournoi->setModel(modal1);
    ui->stackedWidget->setCurrentIndex(1);

      if(t.load(":/english1.qm"))
          qDebug()<<"Loded successfully" << endl;
      else
          qDebug()<<"Could not load" << endl;
qApp->installTranslator(&t);
ui->combo_tri->addItem("par nom");
ui->combo_tri->addItem("par id");
ui->combo_tri->addItem("par id_equipe");

ui->combo_tri->addItem("par longeur");
ui->combo_tri->addItem("par poids");
ui->combo_tri->addItem("par age");



    QObject::connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(handle_Language_Change()));

}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Qr_code_clicked()
{

Ticket t;
QSqlQueryModel *modal=t.select();

ui->comboBox_3->setModel(modal);
        ui->stackedWidget->setCurrentIndex(3);

}






void MainWindow::on_ajouterdepartement_clicked()
{
    QString id;
     QString nom=ui->id_11->text();

      QString type=ui->id_12->text();
      QString emplacement=ui->id_14->text();
      QString depense=ui->id_13->text();



     departement d(id,nom,type,emplacement,depense);
       departement d1;
QSqlQueryModel* modal=d1.recherche(id);
int n1=modal->rowCount();

      if(nom.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.ajouterdepartement();
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" Le departement a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
departement d2;
QSqlQueryModel* modald=d2.select();
ui->comboBox_11->setModel(modald);


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

           QString id;
            QString code=ui->code->text();

             QDate date_debut=QDate::currentDate();
             QDate date_fin=ui->date_fin->date();
             int n=date_debut.daysTo(date_fin);

            Ticket t(id,code,date_debut,date_fin);




if(n>0)
   {

             if(code.isEmpty() )
                 {
                     QMessageBox::critical(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                t.ajouterticket();
                 QMessageBox::information(0,qApp->tr("succes"),
                                       qApp->tr(" Le ticket a été ajouter."),QMessageBox::Yes);
                 /*QSqlQueryModel* modal=new QSqlQueryModel();
                    QSqlQuery* qry = new QSqlQuery();
                    qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
                    qry->exec();
                    modal->setQuery(*qry);
                    ui->tableView->setModel(modal);*/



                 }
}
else
   {
    QMessageBox::warning(0,qApp->tr("erreur"),
                          qApp->tr("Veuillez saisir une date valide."),QMessageBox::Yes);
}
Ticket t2;
QSqlQueryModel* modal3=t2.select();
ui->comboboxticket->setModel(modal3);


}



void MainWindow::on_pushButton_7_clicked()
{

    QString id;
     QString nom=ui->nom->text();

      QString prenom=ui->prenom->text();
      QString adresse=ui->adresse->text();
       QString email=ui->email->text();
       QString id_dep2=ui->comboBox_personnel_2->currentText();
       qDebug()<<"Le id de departement est"<<id_dep2;

     Personnel p(id,nom,prenom,adresse,email,id_dep2);
Personnel p1;
QSqlQueryModel* modal=p1.recherche(id);
int nb=modal->rowCount();





if( nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty())
{
              QMessageBox::warning(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
}


      else{
         p.ajouterpersonnel();
         Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

             smtp->sendMail("sportzen24@gmail.com", email , "Sportzen","Il nous fait grandement plaisir de te souhaiter la bienvenue chez Sportzen. Nous sommes heureux de ton arrivée chez nous et espérons que ton implication répondra àtes attentes.!");

          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" Le personnel a été ajouter."),QMessageBox::Yes);




          }

Personnel p2;
QSqlQueryModel *modalp=p2.select();
ui->comboBox_10->setModel(modalp);
}





void MainWindow::on_ajouter_abonnement_clicked()
{
        
           QString id;
            QString id_tournoi=ui->comboBox_tournoi->currentText();

             QDate date_ab=QDate::currentDate();
             QDate date_fin=ui->date_debut_2->date();
              QString email=ui->id_9->text();
             int n=date_ab.daysTo(date_fin);

            abonnement a(id,id_tournoi,date_ab,date_fin,email);

            abonnement a1;
            QSqlQueryModel* modalr=a1.recherche(id);




if(n>0)
{


             if( email.isEmpty()   )
                 {
                     QMessageBox::warning(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                 Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                     smtp->sendMail("Sportzen24@gmail.com", email , "Sportzen","Bienvenu  a notre association sportzen,On vous remercie de faire un abonnement et on espére votre satisfaction ");

                a.ajouterabonnement();
                 QMessageBox::information(0,qApp->tr("succées"),

                                       qApp->tr(" L Abonnement a été ajouter avec succées."),QMessageBox::Yes);




                 }
}
else
 {
    QMessageBox::warning(0,qApp->tr("erreur"),

                          qApp->tr(" Veuillez saisir une date valide."),QMessageBox::Yes);
}

abonnement a2;
QSqlQueryModel *modala=a2.select();
ui->comboBoxabonnement->setModel(modala);
    }
void MainWindow::on_modifier_personnel_clicked()
{

           QString id=ui->comboBox_10->currentText();
            QString nom=ui->nom->text();

             QString prenom=ui->prenom->text();
             QString adresse=ui->adresse->text();
              QString email=ui->email->text();
              QString id_dep=ui->comboBox_personnel_2->currentText();


            Personnel p(id,nom,prenom,adresse,email,id_dep);

             if(nom.isEmpty() )
                 {
                     QMessageBox::warning(0,qApp->tr("erreur"),
                                           qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                 }


             else{
                p.modifierpersonnel(id);
                Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                    smtp->sendMail("Sportzen24@gmail.com", email , "Sportzen","Bonjour "+nom+" "+prenom+" ,nous vous informons que vos informations ont été modifier !");
                 QMessageBox::information(0,qApp->tr("succés"),
                                       qApp->tr(" Le personnel a été modifier."),QMessageBox::Yes);




                 }

             Ticket t2;
             QSqlQueryModel* modal3=t2.select();
             ui->comboboxticket->setModel(modal3);

    }

void MainWindow::on_pushButton_19_clicked()
{
    QString id=ui->comboboxticket->currentText();
     QString code=ui->code->text();

     QDate date_debut=QDate::currentDate();
     QDate date_fin=ui->date_fin->date();
     int n=date_debut.daysTo(date_fin);


     Ticket t(id,code,date_debut,date_fin);



if(n>0)
   {
      if( code.isEmpty() )
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
else
{
    QMessageBox::warning(0,qApp->tr("erreur"),
                          qApp->tr("Veuillez saisir une date valide."),QMessageBox::Yes);
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







/*--------------------------------------------------------------------------------------------------------------------------------*/
//Authentification


void MainWindow::on_pushButton_11_clicked()
{
    match m2;
    QSqlQueryModel* modald=m2.select();
    ui->comboBox_16->setModel(modald);
    ui->comboBox_18->setModel(modald);


    evenement e1;
    QSqlQueryModel *modale=e1.select();
    ui->comboBox_6->setModel(modale);
    Personnel p;
   QSqlQueryModel *modalp=p.select();
   ui->comboBox_5->setModel(modalp);
   ui->comboBox_8->setModel(modalp);
   ui->comboBox_10->setModel(modalp);
    QString username=ui->username->text();
    QString password=ui->password->text();
    departement d1;
   QSqlQueryModel *modal=d1.select();
   ui->comboBox_personnel_2->setModel(modal);
   ui->comboBox_11->setModel(modal);
   ui->comboBox_4->setModel(modal);
   ui->comboBox_7->setModel(modal);
   tournoi t1;
   Ticket ti;
   abonnement a;
   QSqlQueryModel *modala=a.select();
   ui->comboBoxabonnement->setModel(modala);
   QSqlQueryModel *modalt=ti.select();

   ui->comboboxticket->setModel(modalt);

   ui->comboBox_15->setModel(modale);
   QSqlQueryModel *modal1=t1.select();
   ui->comboBox_tournoi->setModel(modal1);
   ui->comboBox_9->setModel(modal1);
 ui->comboBox_14->setModel(modal1);
   joueur j1;
 QSqlQueryModel *modalj=j1.select2();
 ui->comboBox_13->setModel(modalj);

 equipe eq1;
QSqlQueryModel *modal3=eq1.select3();
ui->com_modifier->setModel(modal3);
ui->comboBox_12->setModel(modal3);

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

    Ticket t2;
    QSqlQueryModel* modal3=t2.select();
    ui->comboboxticket->setModel(modal3);

}
void MainWindow::on_delete_personnel_clicked()
{
    Personnel p;

    QString id=ui->recherche_label_5->text();

    p.supprimerpersonnel(id);

    Personnel p2;
    QSqlQueryModel *modalp=p2.select();
    ui->comboBox_10->setModel(modalp);

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




void MainWindow::on_delete_4_clicked()
{
    abonnement a;

    QString id=ui->recherche_label_11->text();

    a.supprimerabonnement(id);
}




void MainWindow::on_pushButton_35_clicked()
{
 abonnement a;
 QString id=ui->recherche_label_12->text();
QSqlQueryModel* modal=a.recherche(id);
qDebug()<<"Le nombre est"<<modal->rowCount();
 ui->tableView_6->setModel(modal);

}

void MainWindow::on_pushButton_38_clicked()
{
    QString id;
     QString id_loc=ui->comboBox_7->currentText();

      QString type=ui->t3->text();
      QString id_per=ui->comboBox_8->currentText();



     tournoi t(id,id_loc,type,id_per);

      if( type.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         t.ajoutertournoi();
          QMessageBox::information(0,qApp->tr("erreur"),
                                qApp->tr(" Le tournoi a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
      tournoi t1;
      QSqlQueryModel *modal1=t1.select();
      ui->comboBox_tournoi->setModel(modal1);
}

void MainWindow::on_pushButton_40_clicked()
{
    tournoi t;
        QSqlQueryModel* modal=t.affichertournoi();

        ui->tableView_13->setModel(modal);

           qDebug()<<(modal->rowCount());
}



void MainWindow::on_delete_personnel_3_clicked()
{
    tournoi t;

    QString id=ui->t5->text();

    t.supprimertournoi(id);
    tournoi t1;
    QSqlQueryModel *modal1=t1.select();
    ui->comboBox_tournoi->setModel(modal1);
}




void MainWindow::on_pushButton_37_clicked()
{

    tournoi t;
     QString id=ui->t6->text();
    QSqlQueryModel* modal=t.recherche(id);
    qDebug()<<"Le nombre est"<<modal->rowCount();
     ui->tableView_13->setModel(modal);

}



void MainWindow::on_modifier_personnel_3_clicked()
{
    QString id=ui->comboBox_9->currentText();
     QString id_localisation=ui->comboBox_7->currentText();

      QString type=ui->t3->text();
      QString id_per=ui->comboBox_8->currentText();


     tournoi t(id,id_localisation,type,id_per);

      if(type.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         t.modifiertournoi(id);
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" Le tournoi a été modifier."),QMessageBox::Yes);




          }

}


void MainWindow::on_pushButton_39_clicked()
{
    tournoi t;
    QSqlQueryModel* modal=t.tri();

    ui->tableView_13->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_Qr_code_3_clicked()
{
   Ticket t;
    QString text = ui->comboboxticket->currentText();

    QSqlQueryModel *modal1=t.recherche(text);

         QString qr_code = modal1->record(0).value("qr_code").toString();
qDebug()<<"Le qr code est"<<qr_code;

    if (text.isEmpty()) {
       return;
    }

    int qrcode_width = ui->qrcodepixmapLabel_3->width();
    int qrcode_height = ui->qrcodepixmapLabel_3->height();
    QPixmap qrcode_pixmap;
    bool result;
    result = QRCodeGenerator::GeneratePixmapFromText(qr_code, qrcode_pixmap, qrcode_width, qrcode_height);
    if (true == result){
        ui->qrcodepixmapLabel_3->setPixmap(qrcode_pixmap);

    }
    else{
        QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCodeImage."));
        return;
    }

    if ((ui->qrcodepixmapLabel_3->pixmap() != Q_NULLPTR)
            && (ui->qrcodepixmapLabel_3->pixmap()->isNull() != true)){
        ui->saveFileButton->setEnabled(true);
    }
    else{
        ui->saveFileButton->setEnabled(false);
    }

}

void MainWindow::on_qr_button_clicked()
{
QString id=ui->comboBox_3->currentText();
QString code=ui->lineEdit->text();
Ticket t;
if(id.isEmpty() || code.isEmpty())
{
    QMessageBox::critical(0,qApp->tr("erreur"),
                          qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
}
else
{
t.qr_code(code,id);
QMessageBox::information(0,qApp->tr("succées"),
                      qApp->tr("Le code qr a été saisi avec succées"),QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_48_clicked()
{
    if(t.load(":/arabe.qm"))
        qDebug()<<"Loded successfully" << endl;
    else
        qDebug()<<"Could not load" << endl;
   if(qApp->installTranslator(&t))
{
       qDebug()<<"It worked"<<endl;

}
   ui->retranslateUi(this);
}

void MainWindow::on_pushButton_47_clicked()
{
    if(t.load(":/french.qm"))
        qDebug()<<"Loded successfully" << endl;
    else
        qDebug()<<"Could not load" << endl;
   if(qApp->installTranslator(&t))
{
       qDebug()<<"It worked"<<endl;

}
   ui->retranslateUi(this);
}

void MainWindow::on_button_sup_dep_2_clicked()
{
    departement d;

    QString id=ui->label_sup_dep_2->text();

    d.supprimerdepartement(id);
    departement d2;
    QSqlQueryModel* modald=d2.select();
    ui->comboBox_11->setModel(modald);
}

void MainWindow::on_button_rech_dep_2_clicked()
{
    departement d;
      QString id=ui->label_rech_dep_2->text();

      QSqlQueryModel* modal=d.recherche(id);

      ui->tableView_5->setModel(modal);

         qDebug()<<(modal->rowCount());
}

void MainWindow::on_pushButton_36_clicked()
{
    QString id=ui->comboBoxabonnement->currentText();
     QString id_tournoi=ui->comboBox_tournoi->currentText();

      QDate date_ab=QDate::currentDate();
      QDate date_fin=ui->date_debut_2->date();
       QString email=ui->id_9->text();
      int n=date_ab.daysTo(date_fin);

     abonnement a(id,id_tournoi,date_ab,date_fin,email);



if(n>0)
{


      if(  email.isEmpty()   )
          {
              QMessageBox::warning(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
          Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
         connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

              smtp->sendMail("Sportzen24@gmail.com", email , "Sportzen","Bienvenu  a notre association sportzen,On vous remercie de faire un abonnement et on espére votre satisfaction ");

         a.modifierabonnement(id);
          QMessageBox::information(0,qApp->tr("succées"),

                                qApp->tr(" L Abonnement a été ajouter avec succées."),QMessageBox::Yes);




          }
}
else
{
QMessageBox::warning(0,qApp->tr("erreur"),

                   qApp->tr(" Veuillez saisir une date valide."),QMessageBox::Yes);
}


}




void MainWindow::on_pushButton_49_clicked()
{
    abonnement a;
    QSqlQueryModel* modal=a.tri();

    ui->tableView_6->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_pushButton_50_clicked()
{
    Ticket t;

     QString text = ui->comboboxticket->currentText();
         QSqlQueryModel *modal3=t.recherche(text);
         ui->label_71->setAttribute(Qt::WA_TranslucentBackground);//background transparente ez
            QPixmap pix("C:/Users/besmelleh/Desktop/Project/testing/Section/Webp.net-resizeimage (2).png"); //inserer une image
            ui->label_71->setPixmap(pix);
   if(modal3->rowCount()!=0)
  {
 QDate date= modal3->record(0).value("date_debut").toDate();
 QString code=modal3->record(0).value("code").toString();
        ui->label->setText(code);
        ui->dateEdit->setDate(date);
        ui->label->setAttribute(Qt::WA_TranslucentBackground);
        ui->dateEdit->setAttribute(Qt::WA_TranslucentBackground);
ui->label_70->setAttribute(Qt::WA_TranslucentBackground);
ui->label_15->setAttribute(Qt::WA_TranslucentBackground);
ui->label_46->setAttribute(Qt::WA_TranslucentBackground);
     QSqlQueryModel *modal1=t.recherche(text);

          QString qr_code = modal1->record(0).value("qr_code").toString();
 qDebug()<<"Le qr code est"<<qr_code;

     if (text.isEmpty()) {
        return;
     }

     int qrcode_width = ui->qrcodepixmapLabel_4->width();
     int qrcode_height = ui->qrcodepixmapLabel_4->height();
     QPixmap qrcode_pixmap;
     bool result;
     result = QRCodeGenerator::GeneratePixmapFromText(qr_code, qrcode_pixmap, qrcode_width, qrcode_height);
     if (true == result){
         ui->qrcodepixmapLabel_4->setPixmap(qrcode_pixmap);

     }
     else{
         QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCodeImage."));
         return;
     }

     if ((ui->qrcodepixmapLabel_4->pixmap() != Q_NULLPTR)
             && (ui->qrcodepixmapLabel_4->pixmap()->isNull() != true)){
         ui->saveFileButton->setEnabled(true);
     }
     else{
         ui->saveFileButton->setEnabled(false);
     }

    QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("output.pdf");
        printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
        printer.setFullPage(false);

        QPainter painter(&printer);

        double xscale = printer.pageRect().width() / double(ui->Widget->width());
        double yscale = printer.pageRect().height() / double(ui->Widget->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer.paperRect().center());
        painter.scale(scale, scale);
        painter.translate(-ui->Widget->width()/2, -ui->Widget->height()/2);
        ui->Widget->render(&painter);




           QDesktopServices::openUrl(QUrl("C:/Users/besmelleh/Desktop/Project/testing/build-hamma-Desktop_Qt_5_14_0_MinGW_64_bit-Debug/output.pdf"));


   }
   else
   {
       QMessageBox::critical(0,qApp->tr("erreur"),
                             qApp->tr("veuillez saisir un identifiant pour pouvoir exporter le ticket en pdf."),QMessageBox::Cancel);
   }
}

void MainWindow::on_pushButton_10_clicked()
{

    QString civilite=ui->civilite_p->currentText();
        QString nom=ui->nom_p->text();
        QString prenom=ui->prenom_p->text();
        QString proffession= ui->proffession_p->text();
        QString cin=ui->cin_p->text();
         QString adresse=ui->adresse_p->text();
         QDate datenassaissance=ui->datenaissance_p->date();
         QString email= ui->email_p->text();
         QString tel= ui->tel_p->text();
         QString region= ui->region_p->text();
         QString montant= ui->montant_p->text();
         QString nb= ui->nb_p->text();


         donneur cp(civilite,nom,prenom, proffession,cin,adresse,datenassaissance,email,tel,region,montant,nb);

         if(nom.isEmpty() || adresse.isEmpty() || email.isEmpty())
             {
                 QMessageBox::critical(0,qApp->tr("erreur"),
                                       qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
             }

         else if(nom==adresse || nom==email || adresse==email)
            {
                QMessageBox::critical(0,qApp->tr("erreur"),
                                      qApp->tr("Des champs sont identiques."),QMessageBox::Cancel);
            }

         else{
             cp.ajoutDonneur();
             cp.notification(cin);
            ui->nom_p->clear();
            ui->prenom_p->clear();
           // ui->civilite_p->clear();
            ui->datenaissance_p->clear();
            ui->email_p->clear();
            ui->tel_p->clear();
            ui->cin_p->clear();
            ui->nb_p->clear();
            ui->region_p->clear();
            ui->montant_p->clear();
            ui->proffession_p->clear();
            ui->adresse_p->clear();

             }
         Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

             smtp->sendMail("sportzen24@gmail.com",email , "Sportzen","Bienvenu "+nom+"  a notre association sportzen !");

}




void MainWindow::on_pushButton_21_clicked()
{
    QString cin=ui->cin_p->text();
    QDate datenassaissance=ui->datenaissance_p->date();

    donneur cp("","","","",cin,"",datenassaissance ,"","","","","");
    cp.supprimerDonneur();
     ui->cin_p->clear();
     ui->nom_p->clear();
       ui->prenom_p->clear();
         ui->adresse_p->clear();
           ui->montant_p->clear();
             ui->nb_p->clear();
              ui->cin_p->clear();
              ui->civilite_p->clear();
              ui->region_p->clear();
              ui->proffession_p->clear();
              //ui->datenaissance_p->clear();
              ui->email_p->clear();
              ui->tel_p->clear();
}

void MainWindow::on_pushButton_20_clicked()
{
    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
       qry->exec();
       modal->setQuery(*qry);
       ui->tableView_7->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_pushButton_9_clicked()
{
    QString nom=ui->nom_p->text();
       QString prenom=ui->prenom_p->text();
        QString tel=ui->tel_p->text();
         QString adresse=ui->adresse_p->text();
          QString montant=ui->montant_p->text();
           QString nb=ui->nb_p->text();
            QString cin=ui->cin_p->text();
            QString email=ui->email_p->text();
            QDate datenassaissance=ui->datenaissance_p->date();
            QString proffession =ui->proffession_p->text();
            QString region =ui->region_p->text();
             QString civilite =ui->civilite_p->currentText();


 donneur cp(civilite,nom,prenom,proffession,cin,adresse,datenassaissance,email,tel,region,montant,nb);
 cp.modifier();
   ui->nom_p->clear();
     ui->prenom_p->clear();
       ui->adresse_p->clear();
         ui->montant_p->clear();
           ui->nb_p->clear();
            ui->cin_p->clear();
           // ui->civilite_p->clear();
            ui->region_p->clear();
            ui->proffession_p->clear();
            ui->datenaissance_p->clear();
            ui->email_p->clear();
            ui->tel_p->clear();
}

void MainWindow::on_pushButton_24_clicked()
{
    QString nom_e=ui->nom_e->text();
        QString num_e=ui->num_e->text();
        QString tel_e=ui->tel_e->text();
        QString email_e= ui->email_e->text();
        QDate date_e=ui->date_e->date();
         QString montant_e=ui->montant_e->text();
         QString nb_e=ui->nb_e->text();
         QString cin_e= ui->cin_e->text();
         QString adress_e= ui->adress_e->text();



         don cp(nom_e,num_e,tel_e,email_e,date_e,montant_e,nb_e,cin_e,adress_e);
         cp.ajoutDon();
         cp.notification_e(num_e);
         ui->cin_e->clear();
         ui->nom_e->clear();
           ui->num_e->clear();
             ui->adress_e->clear();
               ui->montant_e->clear();
                 ui->nb_e->clear();
                  ui->tel_e->clear();
                  ui->email_e->clear();
}




void MainWindow::on_affich_EN_clicked()
{
    QSqlQueryModel* modal=new QSqlQueryModel();
       QSqlQuery* qry = new QSqlQuery();
       qry->prepare("select  * from DONS ORDER by DATE_E DESC");
       qry->exec();
       modal->setQuery(*qry);
       ui->tableView_e->setModel(modal);

}

void MainWindow::on_pushButton_43_clicked()
{

    QString id;
     QString id_loc=ui->comboBox_4->currentText();
      QString depense=ui->t3_3->text();
      QString type=ui->t3_2->text();
      QString id_per=ui->comboBox_5->currentText();



     evenement t(id,id_loc,type,id_per,depense);

      if(type.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         t.ajouterevenement();
         Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        Personnel d;
QString email;
        QSqlQueryModel *modal1=d.select2(id_per);
         for (int i = 0; i < modal1->rowCount(); i++) {
qDebug()<<"looooooooooooooooooooooooooooooooool"<<email;
       email= modal1->record(i).value("email").toString();
         }
        qDebug()<<"looooooooooooooooooooooooooooooooool"<<email;
             smtp->sendMail("sportzen24@gmail.com", email , "Sportzen","Felicitation vous etes responsable de l'evenement qui aura lieu la semain prochaine.!");

          QMessageBox::information(0,qApp->tr("erreur"),
                                qApp->tr(" L'evenement a été ajouter."),QMessageBox::Yes);

}
      evenement t1;
      QSqlQueryModel *modal1=t1.select();
      ui->comboBox_6->setModel(modal1);
}

void MainWindow::on_pushButton_44_clicked()
{
    evenement t;
        QSqlQueryModel* modal=t.afficherevenement();

        ui->tableView_14->setModel(modal);

           qDebug()<<(modal->rowCount());
}



void MainWindow::on_pushButton_42_clicked()
{
    evenement t;
        QSqlQueryModel* modal=t.tri();

        ui->tableView_14->setModel(modal);

           qDebug()<<(modal->rowCount());
}



void MainWindow::on_delete_personnel_4_clicked()
{
    evenement t;

    QString id=ui->t5_2->text();

    t.supprimerevenement(id);
    tournoi t1;
    QSqlQueryModel *modal1=t1.select();
    ui->comboBox_6->setModel(modal1);
}


void MainWindow::on_modifier_personnel_4_clicked()
{
    QString id=ui->comboBox_6->currentText();
     QString id_loc=ui->comboBox_4->currentText();
   QString depense=ui->t3_3->text();
      QString type=ui->t3_2->text();
      QString id_per=ui->comboBox_5->currentText();



     evenement t(id,id_loc,type,id_per,depense);

      if(type.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         t.modifierevenement(id);
          QMessageBox::information(0,qApp->tr("succés"),
                                qApp->tr(" L'evenement a été modifier."),QMessageBox::Yes);

}
      evenement t1;
      QSqlQueryModel *modal1=t1.select();
      ui->comboBox_6->setModel(modal1);
}

void MainWindow::on_pushButton_41_clicked()
{
    evenement t;

    QString id=ui->t6_2->text();

    QSqlQueryModel* modal=t.recherche(id);

    ui->tableView_14->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_pushButton_25_clicked()
{
    QBarSet *set0=new QBarSet("Depenses");

    int n1=0;

     int depense[100];
     int j=0;
     for(j=0;j<100;j++)
       {
        depense[j]=0;
     }
    evenement d;
    QString name[20];
int f=0;
     QSqlQueryModel*  modal1=d.countevenement();
    qDebug()<<(n1=modal1->rowCount());
    for (int i = 0; i <= modal1->rowCount(); i++) {

           depense[i] = modal1->record(i).value("depense").toInt();
             qDebug()<<depense[i];
           name[i] = modal1->record(i).value("type_even").toString();
           qDebug()<<name[i];

       }





*set0<<depense[0]<<depense[1]<<depense[2]<<depense[3]<<depense[4]<<depense[5]<<depense[6];

    QBarSeries *series=new QBarSeries();
    series->append(set0);

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des depenses des evenement  ");
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
void MainWindow::on_imprimer_d_clicked()
{
    QPrinter printer;
    printer.setPrinterName("imprmer le nom");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog ::Rejected) return;
    ui->tableView_2->render(&printer);
}



void MainWindow::on_fichier_d_clicked()
{
    QString file=QFileDialog::getOpenFileName( this ,tr("open file"),"C://","All files(*.*);;Text file(*.txt);;Music File(*.mp3)");
    QMessageBox :: information(this,tr("File Name"),file);
}




void MainWindow::on_statistique2_clicked()

{
QBarSet *set0=new QBarSet("don");

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
don cp;
 QSqlQueryModel*  modal1=cp.countdon1("1");
qDebug()<<(n1=modal1->rowCount());
 modal1=cp.countdon1("2");
qDebug()<<(n2=modal1->rowCount());
 modal1=cp.countdon1("3");
qDebug()<<(n3=modal1->rowCount());
modal1=cp.countdon1("4");
qDebug()<<(n4=modal1->rowCount());
modal1=cp.countdon1("5");
qDebug()<<(n5=modal1->rowCount());
modal1=cp.countdon1("6");
qDebug()<<(n6=modal1->rowCount());
modal1=cp.countdon1("7");
qDebug()<<(n7=modal1->rowCount());
modal1=cp.countdon1("8");
qDebug()<<(n8=modal1->rowCount());
modal1=cp.countdon1("9");
qDebug()<<(n9=modal1->rowCount());
modal1=cp.countdon1("10");
qDebug()<<(n10=modal1->rowCount());
modal1=cp.countdon1("11");
qDebug()<<(n11=modal1->rowCount());
modal1=cp.countdon1("12");
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


    void MainWindow::on_pdf_d_clicked()
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "*.Pdf");
                if (!fileName.isEmpty())
                {
                  QPrinter printer;
                  printer.setFullPage(true);
                  printer.setPaperSize(QPrinter::A4);
                  printer.setOrientation(QPrinter::Portrait);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setOutputFileName(fileName);
                  ui->tableView_7->render(&printer);
                }
    }


void MainWindow::on_modifier_dep_2_clicked()
{
    QString id=ui->comboBox_11->currentText();
     QString nom=ui->id_11->text();

      QString type=ui->id_12->text();
      QString emplacement=ui->id_14->text();
      QString depense=ui->id_13->text();



     departement d(id,nom,type,emplacement,depense);


      if( nom.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.modifierdepartement(id);
          QMessageBox::information(0,qApp->tr("succés"),
                                qApp->tr(" Le departement a été Modifier."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}

}

void MainWindow::on_ajouter_joueur_clicked()
{

    QString id;
     QString id_equipe=ui->comboBox_12->currentText();
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
    ui->comboBox_13->setModel(modal2);
}

void MainWindow::on_afficher_joueur_clicked()
{
    joueur j;
    QSqlQueryModel* modal=j.afficherjoueur();

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
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

void MainWindow::on_recherche_joueur_clicked()
{
    joueur j;

    QString id=ui->id_recherche2->text();

    QSqlQueryModel* modal=j.recherche2(id);

    ui->table_joueur->setModel(modal);

       qDebug()<<(modal->rowCount());
}




void MainWindow::on_supprimer_joueur_clicked()
{
    joueur j;

    QString id=ui->id_supp->text();

    j.supprimerjoueur(id);

    joueur j1;
    QSqlQueryModel *modal2=j1.select2();
    ui->comboBox_13->setModel(modal2);

}

void MainWindow::on_modifier_joueur_clicked()
{

    QString id=ui->comboBox_13->currentText();
     QString id_equipe=ui->comboBox_12->currentText();
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

void MainWindow::on_ajouter_equipe_clicked()
{
    QString id_equipe;
     QString id_tournoi=ui->comboBox_14->currentText();
      QString id_even=ui->comboBox_15->currentText();
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
      ui->comboBox_12->setModel(modal1);//t7othom fel combobox

       equipe e1;
      QSqlQueryModel *modal3=e1.select3();
      ui->com_modifier->setModel(modal3);
}

void MainWindow::on_afficher_equipe_clicked()
{
    equipe e;
    QSqlQueryModel* modal=e.afficherequipe();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());
}

void MainWindow::on_tri_equipe_clicked()
{
    equipe e;
    QSqlQueryModel* modal=e.tri();

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());

}

void MainWindow::on_modifier_equipe_clicked()
{
    QString id_equipe=ui->com_modifier->currentText();
     QString id_tournoi=ui->comboBox_14->currentText();

      QString id_even=ui->comboBox_15->currentText();
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




void MainWindow::on_supp_equipe_clicked()
{
    equipe e;

    QString id_equipe=ui->recherche_supp->text();

    e.supprimerequipe(id_equipe);

         equipe t1; //declaration
             QSqlQueryModel *modal1=t1.select(); //thez les id
             ui->comboBox_12->setModel(modal1);//t7othom fel combobox


   equipe e1;
   QSqlQueryModel *modal3=e1.select3();
   ui->com_modifier->setModel(modal3);

}

void MainWindow::on_recherche_equipe_clicked()
{
    equipe e;

    QString id_equipe=ui->id_recherche->text();

    QSqlQueryModel* modal=e.recherche(id_equipe);

    ui->table_equipe->setModel(modal);

       qDebug()<<(modal->rowCount());

}

void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "*.Pdf");
            if (!fileName.isEmpty())
            {
              QPrinter printer;
              printer.setFullPage(true);
              printer.setPaperSize(QPrinter::A4);
              printer.setOrientation(QPrinter::Portrait);
              printer.setOutputFormat(QPrinter::PdfFormat);
              printer.setOutputFileName(fileName);
              ui->table_joueur->render(&printer);
            }
}

void MainWindow::on_afficher_equipe_2_clicked()
{

    QBarSet *set0=new QBarSet("joueurs");

    int n1=0;
    int n2=0;

    joueur j;
     QSqlQueryModel*  modal1=j.selectstat1();
    qDebug()<<(n1=modal1->rowCount());
     modal1=j.selectstat2();
    qDebug()<<(n2=modal1->rowCount());


    *set0<<n1<<n2;

    QBarSeries *series=new QBarSeries();
    series->append(set0);

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des ages des joueurs ");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories <<"Superieur a 30 "<<"inferieur a 30";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    QChartView *ChartView=new QChartView(chart);

     ChartView->setParent(ui->horizontalFrame);
     ui->stackedWidget->setCurrentIndex(2);


}

void MainWindow::on_ajouterdepartement_2_clicked()
{
    QString id;
     QString numero=ui->id_15->text();
     QString depense;
      QString type=ui->id_16->text();
      QString emplacement=ui->id_18->text();



     match d(id,numero,type,emplacement,depense);
       match d1;
QSqlQueryModel* modal=d1.recherche(id);
int n1=modal->rowCount();

      if(numero.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.ajoutermatch();
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" Le match a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
match d2;
QSqlQueryModel* modald=d2.select();
ui->comboBox_16->setModel(modald);
ui->comboBox_18->setModel(modald);
}




void MainWindow::on_afficherdepartement_2_clicked()
{
    match d;
        QSqlQueryModel* modal=d.affichermatch();

        ui->tableView_8->setModel(modal);

           qDebug()<<(modal->rowCount());
}

void MainWindow::on_modifier_dep_3_clicked()
{
    QString id=ui->comboBox_16->currentText();
     QString numero=ui->id_15->text();
     QString depense;
      QString type=ui->id_16->text();
      QString emplacement=ui->id_18->text();



     match d(id,numero,type,emplacement,depense);
       match d1;
QSqlQueryModel* modal=d1.recherche(id);
int n1=modal->rowCount();

      if(numero.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.modifiermatch(id);
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" Le match a été modifier."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
}

void MainWindow::on_button_sup_dep_3_clicked()
{
    match d;

    QString id=ui->label_sup_dep_3->text();

    d.supprimermatch(id);
    match d2;
    QSqlQueryModel* modald=d2.select();
    ui->comboBox_16->setModel(modald);
    ui->comboBox_18->setModel(modald);
}

void MainWindow::on_button_rech_dep_3_clicked()
{
    match d;
      QString id=ui->label_rech_dep_3->text();

      QSqlQueryModel* modal=d.recherche(id);

      ui->tableView_8->setModel(modal);

         qDebug()<<(modal->rowCount());
}

void MainWindow::on_afficherstatdepart_2_clicked()
{

    QString email=ui->id_19->text();

    Smtp* smtp=new Smtp("sportzen24@gmail.com","Ines123456","smtp.gmail.com");
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        smtp->sendMail("Sportzen24@gmail.com",email,"Sportzen","Bonjour,nous souhaitions vous invitez a un tournoi qui aura lieu prochainement");
}

void MainWindow::on_ajouterdepartement_4_clicked()
{
    match d;
        QSqlQueryModel* modal=d.tri();

        ui->tableView_8->setModel(modal);
}

void MainWindow::on_ajouterdepartement_5_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("output2.pdf");
        printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
        printer.setFullPage(false);

        QPainter painter(&printer);

        double xscale = printer.pageRect().width() / double(ui->tableView_8->width());
        double yscale = printer.pageRect().height() / double(ui->tableView_8->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer.paperRect().center());
        painter.scale(scale, scale);
        painter.translate(-ui->tableView_8->width()/2, -ui->tableView_8->height()/2);
        ui->tableView_8->render(&painter);




           QDesktopServices::openUrl(QUrl("C:/Users/besmelleh/Desktop/Project/testing/build-hamma-Desktop_Qt_5_14_0_MinGW_64_bit-Debug/output2.pdf"));
}
//match

void MainWindow::on_ajouterdepartement_3_clicked()
{
    QString id;
     QString categorie=ui->id_20->text();
     QString depense;
      QString type=ui->id_22->text();
      QString id_match=ui->comboBox_18->currentText();



     equipement d(id,categorie,type,id_match,depense);
       match d1;
QSqlQueryModel* modal=d1.recherche(id);
int n1=modal->rowCount();

      if(categorie.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.ajouterequipement();
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" L'equipement a été ajouter."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
equipement d2;
QSqlQueryModel* modald=d2.select();
ui->comboBox_17->setModel(modald);

}




void MainWindow::on_afficherdepartement_3_clicked()
{
    equipement d;
        QSqlQueryModel* modal=d.afficherequipement();

        ui->tableView_9->setModel(modal);

           qDebug()<<(modal->rowCount());
}

void MainWindow::on_modifier_dep_4_clicked()
{
    QString id=ui->comboBox_17->currentText();
    QString categorie=ui->id_20->text();
    QString depense;
     QString type=ui->id_22->text();
     QString id_match=ui->comboBox_18->currentText();



    equipement d(id,categorie,type,id_match,depense);




       equipement d1;
QSqlQueryModel* modal=d1.recherche(id);
int n1=modal->rowCount();

      if(categorie.isEmpty() )
          {
              QMessageBox::critical(0,qApp->tr("erreur"),
                                    qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
          }


      else{
         d.modifierequipement(id);
          QMessageBox::information(0,qApp->tr("succées"),
                                qApp->tr(" L'equipement a été modifier."),QMessageBox::Yes);
          /*QSqlQueryModel* modal=new QSqlQueryModel();
             QSqlQuery* qry = new QSqlQuery();
             qry->prepare("select *from DONNEURS ORDER by DATENASSAISSANCE DESC");
             qry->exec();
             modal->setQuery(*qry);
             ui->tableView->setModel(modal);*/
}
}

void MainWindow::on_button_sup_dep_4_clicked()
{
    equipement d;

    QString id=ui->label_sup_dep_4->text();

    d.supprimerequipement(id);
    match d2;
    QSqlQueryModel* modald=d2.select();
    ui->comboBox_17->setModel(modald);

}

void MainWindow::on_button_rech_dep_4_clicked()
{
    equipement d;
      QString id=ui->label_rech_dep_4->text();

      QSqlQueryModel* modal=d.recherche(id);

      ui->tableView_9->setModel(modal);

         qDebug()<<(modal->rowCount());
}



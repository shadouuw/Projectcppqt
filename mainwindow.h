#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "compte.h"
//#include "email.h"
#include <QMainWindow>
#include <QTranslator>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int language;

   QTranslator t;

private slots:
    void makeplot();
    void on_pushButton_15_clicked();
   void on_ajouterdepartement_clicked();
  void on_afficherdepartement_clicked();
  void on_generateButton_pressed();
  void on_saveFileButton_pressed();
  void on_retouuur_clicked();
  void on_comboBox_currentIndexChanged(const QString &arg1);
     void on_returnstat_clicked();
     void on_qr_button_pressed();
    void on_pushButton_3_clicked();//ajouter tickets
    void on_pushButton_5_clicked();//afficher tickets
    void on_pushButton_7_clicked();//ajouter personnel
    void on_pushButton_8_clicked();
    void on_Qr_code_clicked();
    void on_stats_clicked();

    /*void on_pushButton_4_clicked();//modifier donneur
     void on_pushButton_6_clicked();//supprimer donneur
     void on_pushButton_clicked();//quitter
     void on_commandLinkButton_2_clicked();
    void on_commandLinkButton_clicked();
     void on_tableView_doubleClicked(const QModelIndex &index);*/
      //void on_recher_e_textChanged(const QString &arg1);


    void on_pushButton_11_clicked();
     void on_pushButton_12_clicked();
         void on_pushButton_13_clicked();
     void on_pushButton_14_clicked();
     void on_pushButton_16_clicked();
     void on_pushButton_17_clicked();
     void on_pushButton_18_clicked();
      void on_pushButton_19_clicked();
      void on_delete_2_clicked();
      void on_delete_personnel_clicked();
      void on_delete_personnel_2_clicked();
      void on_modifier_personnel_clicked();
      void on_ajouter_abonnement_clicked();
      void on_afficher_abonnement_clicked();
      void on_afficherstatdepart_clicked();
     void handle_Language_Change();



private:
    Ui::MainWindow *ui;
    int m_x;

       int m_y;

};

#endif // MAINWINDOW_H

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

    void on_pushButton_15_clicked();
   void on_ajouterdepartement_clicked();
  void on_afficherdepartement_clicked();
  void on_generateButton_pressed();
  void on_saveFileButton_pressed();
  void on_retouuur_clicked();
  void on_comboBox_currentIndexChanged(const QString &arg1);
     void on_returnstat_clicked();
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
      void on_modifier_personnel_clicked();
      void on_ajouter_abonnement_clicked();
      void on_afficher_abonnement_clicked();
      void on_afficherstatdepart_clicked();
     void handle_Language_Change();



     void on_delete_4_clicked();

     void on_pushButton_35_clicked();

     void on_pushButton_38_clicked();

     void on_pushButton_40_clicked();

     void on_delete_personnel_3_clicked();

     void on_pushButton_37_clicked();

     void on_modifier_personnel_3_clicked();

     void on_pushButton_39_clicked();

     void on_Qr_code_3_clicked();

     void on_qr_button_clicked();

     void on_pushButton_48_clicked();

     void on_pushButton_47_clicked();

     void on_button_sup_dep_2_clicked();

     void on_button_rech_dep_2_clicked();

     void on_pushButton_36_clicked();

     void on_pushButton_49_clicked();

     void on_pushButton_50_clicked();

     void on_pushButton_10_clicked();

     void on_pushButton_21_clicked();

     void on_pushButton_20_clicked();

     void on_pushButton_9_clicked();

     void on_pushButton_24_clicked();

     void on_affich_EN_clicked();

     void on_pushButton_43_clicked();

     void on_pushButton_44_clicked();

     void on_pushButton_42_clicked();

     void on_delete_personnel_4_clicked();

     void on_modifier_personnel_4_clicked();

     void on_pushButton_41_clicked();

     void on_pushButton_25_clicked();

     void on_imprimer_d_clicked();

     void on_fichier_d_clicked();
     void on_statistique2_clicked();




     void on_pdf_d_clicked();

     void on_modifier_dep_2_clicked();

     void on_ajouter_joueur_clicked();

     void on_afficher_joueur_clicked();

     void on_tri_joueur_clicked();

     void on_recherche_joueur_clicked();

     void on_supprimer_joueur_clicked();

     void on_modifier_joueur_clicked();

     void on_ajouter_equipe_clicked();

     void on_afficher_equipe_clicked();

     void on_tri_equipe_clicked();

     void on_modifier_equipe_clicked();

     void on_supp_equipe_clicked();

     void on_recherche_equipe_clicked();

     void on_exporter_clicked();

     void on_afficher_equipe_2_clicked();

     void on_ajouterdepartement_2_clicked();

     void on_afficherdepartement_2_clicked();

     void on_modifier_dep_3_clicked();

     void on_button_sup_dep_3_clicked();

     void on_button_rech_dep_3_clicked();

     void on_afficherstatdepart_2_clicked();

     void on_ajouterdepartement_4_clicked();

     void on_ajouterdepartement_5_clicked();

     void on_button_sup_dep_4_clicked();

     void on_button_rech_dep_4_clicked();

     void on_modifier_dep_4_clicked();

     void on_ajouterdepartement_3_clicked();

     void on_afficherdepartement_3_clicked();

private:
    Ui::MainWindow *ui;
    int m_x;

       int m_y;

};

#endif // MAINWINDOW_H

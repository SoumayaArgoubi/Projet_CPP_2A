#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"etudiant.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_inserer_clicked()
{
    // récuperer les informations saisies dans l'interface
    int id = ui->lineEdit_ID->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_pren->text();

    Etudiant E (nom,prenom,id);
    bool test=E.ajouter();

    if(test)
    {
       ui->tableView->setModel(Etmp.afficher());// refresh
       QMessageBox::information(nullptr, QObject::tr("Ajot effectué"),
                    QObject::tr("OK.\n"
                                ""), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                    QObject::tr("KO.\n"
                                ""), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id =ui->lineEdit_IDS->text().toInt();

    bool test=Etmp.supprimer(id);

    if(test)
    {
       ui->tableView->setModel(Etmp.afficher());// refresh
       QMessageBox::information(nullptr, QObject::tr("suppression effectué"),
                    QObject::tr("OK.\n"
                                ""), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectué"),
                    QObject::tr("KO.\n"
                                ""), QMessageBox::Cancel);
}

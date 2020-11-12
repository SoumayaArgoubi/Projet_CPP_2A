#include "etudiant.h"

Etudiant::Etudiant(QString nom,QString prenom,int id)
{
    this->nom=nom;
    this->prenom=prenom;
    ID=id;
}

bool Etudiant::ajouter()
{
    //Implémentation de la méthode ajouter
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("INSERT INTO etudiant (id, nom,prenom) "
                  "VALUES (:id, :nom, :prenom)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();

}

QSqlQueryModel * Etudiant::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from etudiant");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID") );
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom") );
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom") );

    return  model;

}

bool Etudiant::supprimer(int id)
{
    QSqlQuery query;
  //  QString res=QString::number(id);

    query.prepare("Delete from etudiant where ID=:id");
    query.bindValue(":id",id);
    return  query.exec();
}

#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Etudiant
{
    QString nom, prenom;
    int ID;
public:
    Etudiant(){}
    Etudiant(QString,QString,int);

    QString getNom(){return nom;}
    QString getpreNom(){return prenom;}
    int getId(){return ID;}

    void setNom(QString nm){nom=nm;}
    void setprNom(QString pr){prenom=pr;}
    void setId(int id){ID=id;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);


};

#endif // ETUDIANT_H

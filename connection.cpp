#include "connection.h"

//Test Tutoriel Git

Connection::Connection()
{
     db = QSqlDatabase::addDatabase("QODBC");

}

bool Connection::createconnect()
{bool test=false;
db.setDatabaseName("projet2a");//inserer le nom de la source de données ODBC
db.setUserName("soumaya");//inserer nom de l'utilisateur
db.setPassword("projetcpp");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void Connection::closeConnection()
{db.close();}

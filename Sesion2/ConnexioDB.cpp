#include <iostream>
#include <string>
#include <fstream>
#include "ConnexioDB.hpp"

using namespace std;

// Constructor
ConnexioDB::ConnexioDB()
{
    driver = sql::mysql::get_mysql_driver_instance();
    string portHost, user, pasword;

    ifstream archivo("accesoDB.txt");
    if (archivo.is_open())
    {
        string linea;
        int i = 0;
        while (getline(archivo, linea))
        {
            if (i == 0)
            {
                portHost = linea;
            }
            else if (i == 1)
            {
                user = linea;
            }
            else if (i == 2)
            {
                pasword = linea;
            }
            i++;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

    con = driver->connect(portHost, user, pasword);
    con->setSchema(user);
    stmt = con->createStatement();
}

// Destructor
ConnexioDB::~ConnexioDB()
{}

// Metodos
void ConnexioDB::procesarRegistroUsuario(string sql)
{
    stmt->execute(sql);
    cout << "----------" << "\n"
    << "Usuari registrat correctament." << endl;
    cout << "----------" << endl;
}

void ConnexioDB::cosnultarUsuario(string sql)
{   //hacer que retorne en modo bool si existe o no 
    sql::ResultSet *res = stmt->executeQuery(sql);

    if (res->next())
    {
        cout << "----------" << "\n"
        << "Sobrenom: " << res->getString("sobrenom") << "\n"
        << "Nom: " << res->getString("nom") << "\n"
        << "Correu electronic: " << res->getString("correu_electronic") 
        << endl;
    }
    else
    {
        cout << "----------" << "\n"
        << "No s'ha trobat cap usuari amb aquest sobrenom." << endl;
    }
    cout << "----------" << endl;
}

void ConnexioDB::modificaUsuario(string sql)
{
    sql::ResultSet *res = stmt->executeQuery(sql);

    if (res->next())
    {
        cout << "----------" << "\n"
        << "El usuario actualmente tiene los siguientes datos: " << "\n"
        << "Sobrenom: " << res->getString("sobrenom") << "\n"
        << "Nom: " << res->getString("nom") << "\n"
        << "Correu electronic: " << res->getString("correu_electronic") 
        << endl;
        string sobrenom_usuari = res->getString("sobrenom");
        cout << "----------" << endl;
        cout << "Escriba el nuevo nom del usuario: ";
        string nom_usuari;
        cin.ignore();
        getline(cin, nom_usuari);
        cout << "Escriba el nuevo correu electronic del usuario: ";
        string correu_electronic_usuari;
        cin >> correu_electronic_usuari;

        sql = "UPDATE Usuari SET nom = '" + nom_usuari + "', correu_electronic = '" 
        + correu_electronic_usuari + "' WHERE sobrenom = '" + sobrenom_usuari + "'";
        stmt->execute(sql);
        cout << "----------" << "\n"
        << "Usuari modificat correctament." << endl;
        cout << "----------" << endl;
    }
    else
    {
        cout << "----------" << "\n"
        << "No s'ha trobat cap usuari amb aquest sobrenom." << endl;
    }
}

void ConnexioDB::eliminarUsuario(string sql)
{
    stmt->execute(sql);
    cout << "----------" << "\n"
    << "Usuari eliminat correctament." << endl;
    cout << "----------" << endl;
}

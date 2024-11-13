#include <iostream>
#include <string>
#include "ConnexioDB.hpp"

using namespace std;

// Constructor
ConnexioDB::ConnexioDB()
{
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep11", "gahKaek6choo2a"); //hay que hacer un gitignore con el archivo de configuracion
    con->setSchema("inep11");
    stmt = con->createStatement();
}

// Destructor
ConnexioDB::~ConnexioDB()
{
    delete stmt;
    delete con;
}

// Metodos
void ConnexioDB::procesarRegistroUsuario(string sql)
{
    stmt->execute(sql);
    cout << "----------" << "\n"
    << "Usuari registrat correctament." << endl;
    cout << "----------" << endl;
}

void ConnexioDB::cosnultarUsuario(string sql)
{
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

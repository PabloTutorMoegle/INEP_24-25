#include <iostream>
#include <string>
#include "ConnexioDB.hpp"

using namespace std;

// Constructor
ConnexioDB::ConnexioDB()
{
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep11", "gahKaek6choo2a");
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
void ConnexioDB::procesarRegistroUsuario()
{
    try
    {
        string sobrenom_usuari;
        string nom_usuari;
        string correu_electronic_usuari;

        cout << "Escriba el sobrenom del usuario: ";
        cin >> sobrenom_usuari;
        cout << "Escriba el nom del usuario: ";
        //el nombre del usuario puede tener espacios
        cin.ignore();
        getline(cin, nom_usuari);
        cout << "Escriba el correu electronic del usuario: ";
        cin >> correu_electronic_usuari;

        string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + sobrenom_usuari + "', '" + nom_usuari + "', '" + correu_electronic_usuari + "')";
        stmt->execute(sql);
        cout << "----------" << "\n"
        << "Usuari registrat correctament." << endl;
        cout << "----------" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQL Error: " << e.what() << endl;
        if(con != NULL) con->close();
    }
}

void ConnexioDB::cosnultarUsuario()
{
    try
    {
        string sobrenom_usuari;
        cout << "Escriba el sobrenom del usuario: ";
        cin >> sobrenom_usuari;

        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
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
    catch(const std::exception& e)
    {
        std::cerr << "SQL Error: " << e.what() << endl;
        if(con != NULL) con->close();
    }
}

void ConnexioDB::modificaUsuario()
{
    try
    {
        string sobrenom_usuari;
        cout << "Escriba el sobrenom del usuario: ";
        cin >> sobrenom_usuari;

        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        sql::ResultSet *res = stmt->executeQuery(sql);

        if (res->next())
        {
            cout << "----------" << "\n"
            << "El usuario actualmente tiene los siguientes datos: " << "\n"
            << "Sobrenom: " << res->getString("sobrenom") << "\n"
            << "Nom: " << res->getString("nom") << "\n"
            << "Correu electronic: " << res->getString("correu_electronic") 
            << endl;
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
    catch(const std::exception& e)
    {
        std::cerr << "SQL Error: " << e.what() << endl;
        if(con != NULL) con->close();
    }
}

void ConnexioDB::eliminarUsuario()
{
    try
    {
        string sobrenom_usuari;
        cout << "Escriba el sobrenom del usuario: ";
        cin >> sobrenom_usuari;

        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        sql::ResultSet *res = stmt->executeQuery(sql);

        sql = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        stmt->execute(sql);
        cout << "----------" << "\n"
        << "Usuari eliminat correctament." << endl;
        cout << "----------" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQL Error: " << e.what() << endl;
        if(con != NULL) con->close();
    }
}

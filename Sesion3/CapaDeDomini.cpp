#include <iostream>
#include "CapaDeDomini.hpp"

using namespace std;

CapaDeDomini* CapaDeDomini::instance = nullptr;

CapaDeDomini::CapaDeDomini()
{}

CapaDeDomini* CapaDeDomini::getInstance()
{
    if (instance == nullptr) {
        instance = new CapaDeDomini();
    }
    return instance;
}

void CapaDeDomini::registraUsuari(string nom_usuari, string sobrenom_usuari, string correu_electronic_usuari)
{
    ConnexioDB connexioDB;
    string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + sobrenom_usuari + 
    "', '" + nom_usuari + "', '" + correu_electronic_usuari + "')";
    try
    {
        connexioDB.procesarRegistroUsuario(sql);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    connexioDB.~ConnexioDB();
}

void CapaDeDomini::consultaUsuari(string sobrenom_usuari)
{
    ConnexioDB connexioDB;
    string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
    try
    {
        connexioDB.cosnultarUsuario(sql);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    connexioDB.~ConnexioDB();
}
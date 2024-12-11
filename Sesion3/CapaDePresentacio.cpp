//La capa de presentacion es un singleton
#include <iostream>
#include "CapaDePresentacio.hpp"

using namespace std;

CapaDePresentacio* CapaDePresentacio::instance = nullptr;

CapaDePresentacio::CapaDePresentacio()
{}

CapaDePresentacio* CapaDePresentacio::getInstance()
{
    if (instance == nullptr) {
        instance = new CapaDePresentacio();
    }
    return instance;
}

void CapaDePresentacio::registraUsuari()
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

    capaDeDomini->registraUsuari(nom_usuari, sobrenom_usuari, correu_electronic_usuari);

    return;
}
void CapaDePresentacio::consultaUsuari()
{
    string sobrenom_usuari;
    cout << "Escriba el sobrenom del usuario: ";
    cin >> sobrenom_usuari;

    capaDeDomini->consultaUsuari(sobrenom_usuari);

    return;
}
void CapaDePresentacio::modificaUsuari()
{
    ConnexioDB connexioDB;
    string sobrenom_usuari;
    cout << "Escriba el sobrenom del usuario: ";
    cin >> sobrenom_usuari;

    string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
    try
    {
        connexioDB.modificaUsuario(sql);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    connexioDB.~ConnexioDB();

    return;
}
void CapaDePresentacio::eliminarUsuari()
{
    ConnexioDB connexioDB;
    string sobrenom_usuari;
    cout << "Escriba el sobrenom del usuario: ";
    cin >> sobrenom_usuari;

    string sql = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

    try
    {
        connexioDB.eliminarUsuario(sql);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    connexioDB.~ConnexioDB();

    return;
}

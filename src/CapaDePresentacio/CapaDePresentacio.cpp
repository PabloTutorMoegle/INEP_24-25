#include <iostream>
#include "CapaDePresentacio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/IniciSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/TancaSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/RegistraUsuari.hpp"

using namespace std;

void inici_sessio()
{
    cout<< "** Inici de sessio **" << "\n"
        << "Sobrenom: ";
    string sobrenom;
    getline(cin, sobrenom);
    cout << "\n" << "Contrasenya: ";
    string contrasenya;
    getline(cin, contrasenya);
    cout << endl;
    TxIniciSessio iniciSessio("sobrenom", "contrasenya");
    try {
        iniciSessio.executar();
        cout << "Sessio iniciada correctament!" << endl;
    } catch (const char* error) {
        cout << "L'usuari no existeix o la contrasenya no és correcta." << endl;
    }
}

void tanca_sessio()
{
    cout<< "** Tancar sessio **" << "\n"
        << "Vols tancar la sessio? (S/N): ";
    string resposta;
    cin >> resposta;
    if (resposta == "S" || resposta == "s")
    {
        TxTancaSessio tancarSessio;
        tancarSessio.executa();
        cout << "Sessio tancada correctament!" << endl;
    }
    else
    {
        return;
    }
}

void registrar_usuari()
{
    cout << "** Registrar usuari **" << "\n"
        << "Nom complet: ";
    string nom;
    getline(cin, nom);
    cout << "Sobrenom: ";
    string sobrenom;
    getline(cin, sobrenom);
    cout << "\n" << "Contrasenya: ";
    string contrasenya;
    getline(cin, contrasenya);
    cout << "Correu electronic: ";
    string correu;
    getline(cin, correu);
    cout << "Data de naixement (DD/MM/AAAA): ";
    time_t data_naixement;
    cin >> data_naixement;
    cout << "Modalitats de subscripcio disponibles " << "\n"
        << "  > 1. Completa " << "\n"
        << "  > 2. Cinefil " << "\n"
        << "  > 3. Infantil " << "\n"
        << "Escull modalitat: ";
    int modalitat;
    cin >> modalitat;

    if(modalitat < 1 || modalitat > 3)
    {
        cout << "Modalitat no valida" << endl;
        return;
    }
    
    ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(modalitat);

    TxRegistraUsuari registraUsuari(
        nom,
        sobrenom,
        contrasenya,
        correu,
        data_naixement,
        modalitat_subscripcio
    );
    try
    {
        registraUsuari.executar();
        cout << "Nou usuari registrat correctament!" << endl;
    }
    catch(const exception& e)
    {
        cerr << "El sobrenom o el correu electronic ja existeixen." << endl;
    }
}

pair<DTOUsuari, pair<unsigned int, unsigned int>> consulta_usuari()
{
    return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
}

void modifica_usuari()
{

}

void esborra_usuari()
{

}

void properes_estrenes()
{

}

void ultimes_novetats()
{

}

void pelicules_mes_vistes()
{

}

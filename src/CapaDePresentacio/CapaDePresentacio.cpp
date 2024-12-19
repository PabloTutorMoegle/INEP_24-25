#include <iostream>
#include "CapaDePresentacio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/IniciSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/TancaSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/RegistraUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/ConsultaUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/DTOUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/ControlModificaUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/EsborraUsuari.hpp"

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
    TxConsultaUsuari consultaUsuari;

    consultaUsuari.executar();

    DTOUsuari usuari = consultaUsuari.obte_resultat();

    cout<<"** Consulta usuari **" << "\n"
        << "Nom: " << usuari.nom << "\n"
        << "Sobrenom: " << usuari.sobrenom << "\n"
        << "Correu electronic: " << usuari.correu_electronic << "\n"
        << "Data de naixement: " << usuari.data_naixement << "\n"
        << "Modalitat de subscripcio: " << usuari.modalitat_subscripcio << "\n"
        << "\n"
        << usuari.obte_pelis_vistes() << " pel·licules visualitzades "  << "\n"
        << usuari.obte_capitols_vists() << " capitols visualitzats " << endl;

    return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
}

void modifica_usuari()
{
    CtrlModificaUsuari controlModificaUsuari;
    DTOUsuari usuari = controlModificaUsuari.obte_usuari();

    cout<< "** Modifica usuari **" << "\n"
        << "Nom complet: " << usuari.nom << "\n"
        << "Sobrenom: " << usuari.sobrenom << "\n"
        << "Correu electronic: " << usuari.correu_electronic << "\n"
        << "Data de naixement (DD/MM/AAAA): " << usuari.data_naixement << "\n"
        << "Modalitat de subscripcio  " << usuari.modalitat_subscripcio << endl;

    cout << "Omplir la informacio que es vol modificar ..." << "\n"
         << "Nom complet: ";
    string nom = NULL;
    getline(cin, nom);
    cout << "\n" << "Sobrenom: ";
    string sobrenom = NULL;
    getline(cin, sobrenom);
    cout << "\n" << "Correu electronic: ";
    string correu = NULL;
    getline(cin, correu);
    cout << "\n" << "Data de naixement (DD/MM/AAAA): ";
    time_t data_naixement = NULL;
    cin >> data_naixement;
    cout << "\n" << "Modalitats de subscripcio disponibles " << "\n"
        << "  > 1. Completa " << "\n"
        << "  > 2. Cinefil " << "\n"
        << "  > 3. Infantil " << "\n"
        << "Escull modalitat: ";
    int modalitat = NULL;
    cin >> modalitat;

    if(modalitat < 1 || modalitat > 3)
    {
        cout << "Modalitat no valida" << endl;
        return;
    }

    ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(modalitat);

    try
    {
        controlModificaUsuari.modifica_usuari(
            nom,
            sobrenom,
            correu,
            data_naixement,
            modalitat_subscripcio
        );
    }
    catch(const std::exception& e)
    {
        std::cerr << "El correu electronic ja existeix." << '\n';
    }
    

    cout << "Usuari modificat correctament!" << endl;
}

void esborra_usuari()
{
    cout<< "** Esborra usuari **" << "\n"
        << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya..." << "\n";
        << "Contrasenya: ";
    string contrasenya;
    getline(cin, contrasenya);
    TxEsborraUsuari esborraUsuari(contrasenya);
    try
    {
        esborraUsuari.executar();
        cout << "Usuari esborrat correctament!" << endl;
    }
    catch(const char* error)
    {
        
    }
    
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

#include <iostream>
#include "CapaDePresentacio.hpp"



using namespace std;

void CapaDePresentacio::inici_sessio()
{
    string sobrenom, contrasenya;
    cout<< "** Inici de sessio **" << "\n"
        << "Sobrenom: ";
    cin >> sobrenom;

    cout << "Contrasenya: ";
    cin >> contrasenya;
    
    TxIniciSessio iniciSessio(sobrenom, contrasenya);
    try {
        iniciSessio.executar();
        cout << "Sessio iniciada correctament!" << endl;
    } catch (const char* error) {
        cout << "L'usuari no existeix o la contrasenya no és correcta." << endl;
    }
}

void CapaDePresentacio::tanca_sessio()
{
    string resposta;
    cout<< "** Tancar sessio **" << "\n"
        << "Vols tancar la sessio? (S/N): ";
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

void CapaDePresentacio::registrar_usuari()
{
    string nom, sobrenom, contrasenya, correu, data;
    int modalitat;

    cout << "** Registrar usuari **" << "\n"
        << "Nom complet: ";
    cin >> nom;
    
    cout << "Sobrenom: ";
    cin >> sobrenom;
    
    cout << "Contrasenya: ";
    cin >> contrasenya;
    
    cout << "Correu electronic: ";
    cin >> correu;
    
    cout << "Data de naixement (DD/MM/AAAA): ";
    cin >> data;
    
    cout << "Modalitats de subscripcio disponibles " << "\n"
        << "  > 1. Completa " << "\n"
        << "  > 2. Cinefil " << "\n"
        << "  > 3. Infantil " << "\n"
        << "Escull modalitat: ";
    cin >> modalitat;

    if(modalitat < 1 || modalitat > 3)
    {
        cout << "\n" << "Modalitat no valida" << endl;
        return;
    }

    //pasar data_naixement de string a time_t 
    tm tm = {};
    istringstream ss(data);
    ss >> get_time(&tm, "%d/%m/%Y");
    if (ss.fail()) {
        throw std::runtime_error("Error al convertir la cadena a tiempo");
    }
    time_t data_naixement = mktime(&tm);

    
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
    catch(const char* error)
    {
        cerr << error << endl;
    }
    catch(const exception& e)
    {
        cerr << "El sobrenom o el correu electronic ja existeixen." << endl;
    }
}

pair<DTOUsuari, pair<unsigned int, unsigned int>> CapaDePresentacio::consulta_usuari()
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
        << "\n";
        //HACER FUNCIONES 
        //<< usuari.obte_pelis_vistes() << " pel·licules visualitzades "  << "\n"
        //<< usuari.obte_capitols_vists() << " capitols visualitzats " << endl;

    return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
}

void CapaDePresentacio::modifica_usuari()
{
    CtrlModificaUsuari controlModificaUsuari;
    DTOUsuari usuari = controlModificaUsuari.obte_usuari();

    string nom, sobrenom, contrasenya, correu, data;
    int modalitat;

    cout<< "** Modifica usuari **" << "\n"
        << "Nom complet: " << usuari.nom << "\n"
        << "Sobrenom: " << usuari.sobrenom << "\n"
        << "Correu electronic: " << usuari.correu_electronic << "\n"
        << "Data de naixement (DD/MM/AAAA): " << usuari.data_naixement << "\n"
        << "Modalitat de subscripcio  " << usuari.modalitat_subscripcio << endl;

    cout << "Omplir la informacio que es vol modificar ..." << "\n"
         << "Nom complet: ";
    cin >> nom;

    cout << "Contrasenya: ";
    cin >> contrasenya;
    
    cout << "Sobrenom: ";
    cin >> sobrenom;
    
    cout << "Correu electronic: ";
    cin >> correu;
    
    cout << "Data de naixement (DD/MM/AAAA): ";
    cin >> data;
    
    cout << "Modalitats de subscripcio disponibles " << "\n"
        << "  > 1. Completa " << "\n"
        << "  > 2. Cinefil " << "\n"
        << "  > 3. Infantil " << "\n"
        << "Escull modalitat: ";

    if(modalitat < 1 || modalitat > 3)
    {
        cout << "Modalitat no valida" << endl;
        return;
    }

    //pasar data_naixement de string a time_t
    tm tm = {};
    istringstream ss(data);
    ss >> get_time(&tm, "%d/%m/%Y");
    if (ss.fail()) {
        throw std::runtime_error("Error al convertir la cadena a tiempo");
    }
    time_t data_naixement = mktime(&tm);

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
    
    usuari = controlModificaUsuari.obte_usuari();
    
    cout << "** Dades usuari modificades **" << "\n"
         << "Nom complet: " << usuari.nom << "\n"
         << "Sobrenom: " << usuari.sobrenom << "\n"
         << "Correu electronic: " << usuari.correu_electronic << "\n"
         << "Data de naixement: " << usuari.data_naixement << "\n"
         << "Modalitat de subscripcio: " << usuari.modalitat_subscripcio << endl;
}


void CapaDePresentacio::modifica_contrasenya()
{
    cout << "hello" << endl;
}

void CapaDePresentacio::esborra_usuari()
{
    string contrasenya;

    cout<< "** Esborra usuari **" << "\n"
        << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya..." << "\n"
        << "Contrasenya: ";
    cin >> contrasenya;

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

void CapaDePresentacio::properes_estrenes()
{
    auto usuari = PetitFlix::get_instance()->obte_usuari();

    if (usuari)
    {
        cout<< "** Properes estrenes **" << "\n"
            << "Modalitat: " << usuari->obte_modalitat_subscripcio() << "\n"
            << "\n" << endl;
        
        TxConsultaEstrenes consultaEstrenes(usuari->obte_modalitat_subscripcio());
        consultaEstrenes.executar();

        vector<DTOContingut> estrenes = consultaEstrenes.obte_resultat();

        for (int i = 0; i < estrenes.size(); i++)
        {
            DTOContingut estrena = estrenes[i];

            cout << i + 1 << ".- " << estrena.data_estrena
                << "[" << estrena.tipus << "]:"
                << estrena.titol << ";"
                << estrena.qualificacio << ";"
                << estrena.info << " min." << endl;
        }
    }
    else
    {
        int m = 0;

        cout << "Modalitats de subscripcio disponibles " << "\n"
            << "  > 1. Completa " << "\n"
            << "  > 2. Cinefil " << "\n"
            << "  > 3. Infantil " << "\n"
            << "Escull modalitat: ";
        cin >> m;

        if(m < 1 || m > 3)
        {
            cout << "Modalitat no valida" << endl;
            return;
        }

        ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(m); 

        cout<< "** Properes estrenes **" << "\n"
            << "Modalitat: " <<  modalitat_subscripcio << "\n"
            << "\n" << endl;
        
        TxConsultaEstrenes consultaEstrenes(modalitat_subscripcio);
        consultaEstrenes.executar();

        vector<DTOContingut> estrenes = consultaEstrenes.obte_resultat();

        for (int i = 0; i < estrenes.size(); i++)
        {
            DTOContingut estrena = estrenes[i];

            cout << i + 1 << ".- " << estrena.data_estrena
                << "[" << estrena.tipus << "]:"
                << estrena.titol << ";"
                << estrena.qualificacio << ";"
                << estrena.info << " min." << endl;
        }
    }
}


void CapaDePresentacio::ultimes_novetats()
{
    auto usuari = PetitFlix::get_instance()->obte_usuari();

    if (usuari)
    {
        cout<< "** Novetats **" << "\n" 
            << "Modalitat: " << usuari->obte_modalitat_subscripcio() << "\n"
            << "\n" << endl;

        TxConsultaNovetats txConsultaNovetats(usuari->obte_modalitat_subscripcio());
        txConsultaNovetats.executar();

        vector<DTOContingut> novetats = txConsultaNovetats.obte_resultat();

        for (int i = 0; i < novetats.size(); i++)
        {
            DTOContingut novetat = novetats[i];

            cout << i + 1 << ".- " << novetat.data_estrena
                << "[" << novetat.tipus << "]:"
                << novetat.titol << ";"
                << novetat.qualificacio << ";"
                << novetat.info << " min." << endl;
        }
    }
    else
    {
        int m = 0;

        cout << "Modalitats de subscripcio disponibles " << "\n"
            << "  > 1. Completa " << "\n"
            << "  > 2. Cinefil " << "\n"
            << "  > 3. Infantil " << "\n"
            << "Escull modalitat: ";

        cin >> m;

        if(m < 1 || m > 3)
        {
            cout << "Modalitat no valida" << endl;
            return;
        }

        ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(m); 

        TxConsultaNovetats txConsultaNovetats(modalitat_subscripcio);
        txConsultaNovetats.executar();

        vector<DTOContingut> novetats = txConsultaNovetats.obte_resultat();

        for (int i = 0; i < novetats.size(); i++)
        {
            DTOContingut novetat = novetats[i];

            cout << i + 1 << ".- " << novetat.data_estrena
                << "[" << novetat.tipus << "]:"
                << novetat.titol << ";"
                << novetat.qualificacio << ";"
                << novetat.info << " min." << endl;
        }
    }
}


void CapaDePresentacio::pelicules_mes_vistes()
{
    cout << "Hello World!" << endl;
}

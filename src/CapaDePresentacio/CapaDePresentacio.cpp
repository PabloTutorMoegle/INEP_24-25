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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nom);    
    
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

    //formatear la fecha    
    tm* tiempo_local = localtime(&usuari.data_naixement);
    char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
    strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
    string fecha_formateada(fecha);

    //poner la modalidad en string no en int
    string modalitat_subscripcio;
    switch (usuari.modalitat_subscripcio)
    {
    case 1:
        modalitat_subscripcio = "Completa";
        break;
    case 2:
        modalitat_subscripcio = "Cinefil";
        break;
    case 3:
        modalitat_subscripcio = "Infantil";
        break;
    default:
        break;
    }   

    cout <<"** Consulta usuari **" << "\n"
         << "Nom: " << usuari.nom << "\n"
         << "Sobrenom: " << usuari.sobrenom << "\n"
         << "Correu electronic: " << usuari.correu_electronic << "\n"
         << "Data de naixement: " << fecha_formateada << "\n"
         << "Modalitat de subscripcio: " << modalitat_subscripcio << "\n" << endl;

    try {
        TxVisualitzarPelicula txVisualitzarPelicula;

        txVisualitzarPelicula.buscar_visualitzacions(usuari.sobrenom);
        
        vector<DTOPelicula> visualitzacionsP = txVisualitzarPelicula.obte_resultats();
        
        TxConsultaVisualitzacions txConsultaVisualitzacions;
        
        txConsultaVisualitzacions.executar(usuari.sobrenom);
        
        vector<DTOCapitol> visualitzacionsC = txConsultaVisualitzacions.obte_tots_resultats();

        cout << visualitzacionsP.size() << " pelicules visualitzades" << "\n"
             << visualitzacionsC.size() << " capitols visualitzats" << endl;

    } catch (const char* error) {
        cerr << "Aquest usuari encara no ha vist cap pelicula ni serie."<< endl;
        return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
    }

    return pair<DTOUsuari, pair<unsigned int, unsigned int>>();
}

void CapaDePresentacio::modifica_usuari()
{
    CtrlModificaUsuari controlModificaUsuari;
    DTOUsuari usuariU = controlModificaUsuari.obte_usuari();

    PasarelaUsuari usuari = CercadoraUsuari::cercaUsuari(usuariU.sobrenom);

    string nom, sobrenom, contrasenya, correu, data;
    char modalitat;

    //formatear la fecha de nacimiento del usuario
    time_t date = usuari.obte_data_naixement();
    tm* tiempo_local = localtime(&date);
    char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
    strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
    string fecha_formateada(fecha);

    //poner la modalidad en string no en int
    string modalitat_subscripcio;
    switch (usuari.obte_modalitat_subscripcio())
    {
    case 1:
        modalitat_subscripcio = "Completa";
        break;
    case 2:
        modalitat_subscripcio = "Cinefil";
        break;
    case 3:
        modalitat_subscripcio = "Infantil";
        break;
    default:
        break;
    }

    cout<< "** Modifica usuari **" << "\n"
        << "Nom complet: " << usuari.obte_nom() << "\n"
        << "Sobrenom: " << usuari.obte_sobrenom() << "\n"
        << "Correu electronic: " << usuari.obte_correu_electronic() << "\n"
        << "Data de naixement (DD/MM/AAAA): " << fecha_formateada << "\n"
        << "Modalitat de subscripcio  " << modalitat_subscripcio << endl;

    cout << "Omplir la informacio que es vol modificar ..." << "\n"
         << "Nom complet: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nom);
    
    cout << "Correu electronic: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, correu);
    
    cout << "Data de naixement (DD/MM/AAAA): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, data);
    
    cout << "Modalitats de subscripcio disponibles " << "\n"
        << "  > 1. Completa " << "\n"
        << "  > 2. Cinefil " << "\n"
        << "  > 3. Infantil " << "\n"
        << "Escull modalitat: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(modalitat);

    time_t data_naixement = usuari.obte_data_naixement();

    if (data != "")
    {
        //pasar data_naixement de string a time_t
        tm tm = {};
        istringstream ss(data);
        ss >> get_time(&tm, "%d/%m/%Y");
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la cadena a tiempo");
        }
        data_naixement = mktime(&tm);
    }

    ModalitatSubscripcio modalitat_subs = usuari.obte_modalitat_subscripcio();

    if (modalitat != '\n')
    {
        //modalitat es un string, hay que convertirlo a int
        int mod = modalitat - 48;

        if (mod != 0 && mod >= 1 && mod <= 3)
        {
            modalitat_subs = static_cast<ModalitatSubscripcio>(mod);
        }
    }

    if (nom == "")
    {
        nom = usuari.obte_nom();
    }
    if(correu == "")
    {
        correu = usuari.obte_correu_electronic();
    }
    if(sobrenom == "")
    {
        sobrenom = usuari.obte_sobrenom();
    }

    try
    {
        controlModificaUsuari.modifica_usuari(
            nom,
            sobrenom,
            usuari.obte_contrasenya(),
            correu,
            data_naixement,
            modalitat_subs
        );
    }
    catch(const std::exception& e)
    {
        std::cerr << "El correu electronic ja existeix." << '\n';
        return;
    }
    
    usuari = CercadoraUsuari::cercaUsuari(sobrenom);
    
    cout << "** Dades usuari modificades **" << "\n"
         << "Nom complet: " << usuari.obte_nom() << "\n"
         << "Sobrenom: " << usuari.obte_sobrenom() << "\n"
         << "Correu electronic: " << usuari.obte_correu_electronic() << "\n"
         << "Data de naixement: " << time_t_to_datetime_string(usuari.obte_data_naixement()) << "\n"
         << "Modalitat de subscripcio: " << usuari.obte_modalitat_subscripcio() << endl;
}

void CapaDePresentacio::modifica_contrasenya()
{
    cout << "** Modifica contrasenya **" << "\n"
         << "Per confirmar el canvi de contrasenya, s'ha d'entrar la contrasenya actual..." << "\n"
         << "Contrasenya actual: ";
    string contrasenya;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, contrasenya);

    CtrlModificaUsuari controlModificaUsuari;
    DTOUsuari usuariU = controlModificaUsuari.obte_usuari();

    PasarelaUsuari usuari = CercadoraUsuari::cercaUsuari(usuariU.sobrenom);

    if (usuari.obte_contrasenya() != contrasenya)
    {
        cout << "Contrasenya incorrecta" << endl;
        return;
    }

    cout << "Escriu la nova contrasenya: ";
    string nova_contrasenya;
    cin >> nova_contrasenya;

    controlModificaUsuari.modifica_usuari(
        usuari.obte_nom(),
        usuari.obte_sobrenom(),
        nova_contrasenya,
        usuari.obte_correu_electronic(),
        usuari.obte_data_naixement(),
        usuari.obte_modalitat_subscripcio()
    );

    cout << "Contrasenya modificada correctament!" << endl;
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
        string modalitat_subscripcio;
        switch (usuari->obte_modalitat_subscripcio())
        {
            case 1:
                modalitat_subscripcio = "Completa";
                break;
            case 2:
                modalitat_subscripcio = "Cinefil";
                break;
            case 3:
                modalitat_subscripcio = "Infantil";
                break;
            default:
                break;
        }

        cout<< "** Properes estrenes **" << "\n"
            << "Modalitat: " << modalitat_subscripcio << "\n"
            << "\n" << endl;
        
        TxConsultaEstrenes consultaEstrenes(usuari->obte_modalitat_subscripcio());
        consultaEstrenes.executar();

        vector<DTOContingut> estrenes = consultaEstrenes.obte_resultat();

        if (estrenes.size() == 0)
        {
            cout << "No hi ha estrenes disponibles" << endl;
            return;
        }

        for (int i = 0; i < estrenes.size(); i++)
        {
            DTOContingut estrena = estrenes[i];

            cout << i + 1 << ".- " << estrena.data_estrena
                << " [" << estrena.tipus << "]: "
                << estrena.titol << "; "
                << estrena.qualificacio << "; "
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

        string modalitat;
        switch (m)
        {
        case 1:
            modalitat = "Completa";
            break;
        case 2:
            modalitat = "Cinefil";
            break;
        case 3:
            modalitat = "Infantil";
            break;
        default:
            break;
        }

        ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(m); 

        cout<< "** Properes estrenes **" << "\n"
            << "Modalitat: " <<  modalitat << "\n"
            << "\n" << endl;
        
        TxConsultaEstrenes consultaEstrenes(modalitat_subscripcio);
        consultaEstrenes.executar();

        vector<DTOContingut> estrenes = consultaEstrenes.obte_resultat();

        if (estrenes.size() == 0)
        {
            cout << "No hi ha estrenes disponibles" << endl;
            return;
        }

        for (int i = 0; i < estrenes.size(); i++)
        {
            DTOContingut estrena = estrenes[i];

            cout << i + 1 << ".- " << estrena.data_estrena
                << " [" << estrena.tipus << "]: "
                << estrena.titol << "; "
                << estrena.qualificacio << "; "
                << estrena.info << " min." << endl;
        }
    }
}


void CapaDePresentacio::ultimes_novetats()
{
    auto usuari = PetitFlix::get_instance()->obte_usuari();

    if (usuari)
    {
        string modalitat_subscripcio;
        switch (usuari->obte_modalitat_subscripcio())
        {
            case 1:
                modalitat_subscripcio = "Completa";
                break;
            case 2:
                modalitat_subscripcio = "Cinefil";
                break;
            case 3:
                modalitat_subscripcio = "Infantil";
                break;
            default:
                break;
        }

        cout<< "** Novetats **" << "\n" 
            << "Modalitat: " << modalitat_subscripcio << "\n"
            << "\n" << endl;

        TxConsultaNovetats txConsultaNovetats(usuari->obte_modalitat_subscripcio());
        txConsultaNovetats.executar();

        vector<DTOContingut> novetats = txConsultaNovetats.obte_resultat();

        for (int i = 0; i < novetats.size(); i++)
        {
            DTOContingut novetat = novetats[i];

            tm* tiempo_local = localtime(&novetat.data_estrena);

            // Crear una cadena para almacenar la fecha formateada
            char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"

            // Formatear la fecha en el formato deseado
            strftime(fecha, 11, "%d/%m/%Y", tiempo_local);

            // Convertir la cadena a un string de C++
            string fecha_formateada(fecha);

            cout << i + 1 << ".- " << fecha_formateada
                << " [" << novetat.tipus << "]: "
                << novetat.titol << "; "
                << novetat.qualificacio << "; "
                << novetat.info << "." << endl;
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

        string modalitat;
        switch (m)
        {
            case 1:
                modalitat = "Completa";
                break;
            case 2:
                modalitat = "Cinefil";
                break;
            case 3:
                modalitat = "Infantil";
                break;
            default:
                break;
        }

        ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(m); 

        cout<< "** Novetats **" << "\n" 
            << "Modalitat: " << modalitat << "\n"
            << "\n" << endl;

        TxConsultaNovetats txConsultaNovetats(modalitat_subscripcio);
        txConsultaNovetats.executar();

        vector<DTOContingut> novetats = txConsultaNovetats.obte_resultat();

        for (int i = 0; i < novetats.size(); i++)
        {
            DTOContingut novetat = novetats[i];

            tm* tiempo_local = localtime(&novetat.data_estrena);

            // Crear una cadena para almacenar la fecha formateada
            char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"

            // Formatear la fecha en el formato deseado
            strftime(fecha, 11, "%d/%m/%Y", tiempo_local);

            // Convertir la cadena a un string de C++
            string fecha_formateada(fecha);

            cout << i + 1 << ".- " << fecha_formateada
                << " [" << novetat.tipus << "]: "
                << novetat.titol << "; "
                << novetat.qualificacio << "; "
                << novetat.info << ". " << endl;
        }
    }
}


void CapaDePresentacio::pelicules_mes_vistes()
{
    auto usuari = PetitFlix::get_instance()->obte_usuari();

    if(usuari)
    {
        string modalitat_subscripcio;
        switch (usuari->obte_modalitat_subscripcio())
        {
            case 1:
                modalitat_subscripcio = "Completa";
                break;
            case 2:
                modalitat_subscripcio = "Cinefil";
                break;
            case 3:
                modalitat_subscripcio = "Infantil";
                break;
            default:
                break;
        }

        cout<< "** Pel·licules mes vistes **" << "\n"
            << "Modalitat: " << modalitat_subscripcio << "\n"
            << "\n" << endl;

        TxConsultaMesVistes txConsultaMesVistes(usuari->obte_modalitat_subscripcio());
        txConsultaMesVistes.executar();

        vector<DTOContingut> mesVistes = txConsultaMesVistes.obte_resultat();

        if(mesVistes.size() == 0)
        {
            cout << "No hi ha pel·licules visualitzades en aquesta modalitat." << endl;
            return;
        }

        for (int i = 0; i < mesVistes.size(); i++)
        {
            DTOContingut mesVista = mesVistes[i];

            cout << i + 1 << ".- " 
                << mesVista.titol << "; "
                << mesVista.qualificacio << "; "
                << mesVista.info << " " 
                << endl;
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

        string modalitat;
        switch (m)
        {
            case 1:
                modalitat = "Completa";
                break;
            case 2:
                modalitat = "Cinefil";
                break;
            case 3:
                modalitat = "Infantil";
                break;
            default:
                break;
        }

        ModalitatSubscripcio modalitat_subscripcio = static_cast<ModalitatSubscripcio>(m); 

        cout<< "** Pel·licules mes vistes **" << "\n"
            << "Modalitat: " << modalitat << "\n"
            << "\n" << endl;

        TxConsultaMesVistes txConsultaMesVistes(modalitat_subscripcio);
        
        txConsultaMesVistes.executar();

        vector<DTOContingut> mesVistes = txConsultaMesVistes.obte_resultat();

        if(mesVistes.size() == 0)
        {
            cout << "No hi ha pel·licules visualitzades en aquesta modalitat." << endl;
            return;
        }

        for (int i = 0; i < mesVistes.size(); i++)
        {
            DTOContingut mesVista = mesVistes[i];

            cout << i + 1 << ".- " 
                << mesVista.titol << "; "
                << mesVista.qualificacio << "; "
                << mesVista.info << " " 
                << endl;
        }
    }
}

void CapaDePresentacio::visualitzant_pelicula(string titol_pelicula)
{
    time_t hora_acual = time(0);

    //formatear la fecha
    tm* tiempo_local = localtime(&hora_acual);
    char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
    strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
    string fecha_formateada(fecha);

    cout << "Visualitacio registrada ... " << fecha_formateada << endl;
    TxVisualitzarPelicula txVisualitzarPelicula;
    txVisualitzarPelicula.executar(titol_pelicula);

    //pelicules relacionades
    cout << "Pelicules relacionades: " << endl;

    vector<DTOPelicula> pelicules_relacionades = txVisualitzarPelicula.pelicula_relacionada(titol_pelicula);

    for (int i = 0; i < pelicules_relacionades.size(); i++)
    {
        DTOPelicula pelicula_relacionada = pelicules_relacionades[i];

        cout << "- " << pelicula_relacionada.titol << "; "
             << pelicula_relacionada.descripcio << "; "
             << pelicula_relacionada.qualificacio << "; "
             << pelicula_relacionada.duracio << " min";

        //formatear fecha
        tm* tiempo_local = localtime(&pelicula_relacionada.data_estrena);
        char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
        strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
        string fecha_formateada(fecha);

        cout << fecha_formateada << "; " << endl;
    }
}

void CapaDePresentacio::visualitzar_pelicula()
{
    cout << "** Visualitzant pel·licula **" << "\n"
         << "Nom pel·licula: ";
    string nom_pelicula;
    //el titulo de la serie puede tener espacios y mas de una palabra
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nom_pelicula);
    
    TxVisualitzarPelicula txVisualitzarPelicula;
    try
    {
        txVisualitzarPelicula.buscar(nom_pelicula);
        DTOPelicula pelicula = txVisualitzarPelicula.obte_resultat();

        if(pelicula.titol == "")
        {
            cout << "La pel·licula no existeix." << endl;
            return;
        }

        cout << "Informacio pel·licula: " << "\n"
             << "Nom pel·licula: " << pelicula.titol << "\n"
             << "Descripcio: " << pelicula.descripcio << "\n"
             << "Qualificacio edat: " << pelicula.qualificacio << "\n";

        //formatear fecha
        tm* tiempo_local = localtime(&pelicula.data_estrena);
        char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
        strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
        string fecha_formateada(fecha);

        cout << "Data estrena: " << fecha_formateada << "\n"
             << "Duracio: " << pelicula.duracio << "\n"
             << "Vols continuar amb la visualitzacio? (S/N): ";
        string resposta;
        cin >> resposta;

        if (resposta == "S" || resposta == "s")
        {
            visualitzant_pelicula(pelicula.titol);
        }
        else
        {
            return;
        }
    }
    catch(const char* error)
    {
        cerr << "Error: " << error << endl;
    }
    catch(const std::exception& e)
    {
        cerr << "La pel·licula no existeix." << endl;
    }
}

void CapaDePresentacio::visualitzar_capitol()
{
    cout << "** Visualitzant capitol **" << "\n"
         << "Nom de la serie: ";
    string nom_serie;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nom_serie);

    TxVisualitzarCapitol txVisualitzarCapitol;
    int num_temporades = 0;

    try {
        txVisualitzarCapitol.buscar_temporades(nom_serie);

        num_temporades = txVisualitzarCapitol.obte_num_temporades();

    } catch (const char* error) {
        cerr << "La serie no existeix" << endl;
        return;
    }

    if (num_temporades == 0)
    {
        cout << "La serie no existeix." << endl;
        return;
    }

    cout << "La serie te " << num_temporades << " temporades. " << "\n"
         << "Escull la temporada: ";
    int num_temporada;
    cin >> num_temporada;

    if (num_temporada < 1 || num_temporada > num_temporades)
    {
        cout << "Aquesta temporada no existeix." << endl;
        return;
    }

    vector<DTOCapitol> capitols;

    try
    {
        txVisualitzarCapitol.buscar(nom_serie, num_temporada);
        capitols = txVisualitzarCapitol.obte_resultats();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    cout << "Llista de capitols: " << "\n";

    for (int i = 0; i < capitols.size(); i++)
    {
        DTOCapitol capitol = capitols[i];

        //falta mirar si el capitol ja ha estat visualitzat
        txVisualitzarCapitol.buscar_visualitzacions(PetitFlix::get_instance()->obte_usuari()->obte_sobrenom());
        vector<DTOCapitol> visualitzacions = txVisualitzarCapitol.obte_resultats(); 

        int num_visualitzacions = 0;

        for (int j = 0; j < visualitzacions.size(); j++)
        {
            DTOCapitol visualitzacio = visualitzacions[j];

            if (visualitzacio.titol == capitol.titol && visualitzacio.num_temporada == capitol.num_temporada && visualitzacio.num_capitol == capitol.num_capitol)
            {
                num_visualitzacions = visualitzacio.num_visualitzacions;
                break;
            }
        }

        cout << i + 1 << ".- " << capitol.titol << "; "
             << time_t_to_datetime_string(capitol.data) << "; "
             << "Capitol visualitzat " << num_visualitzacions << " vegades." << endl;
    }
    
    cout << "Numero de capitol a visualitzar: ";
    int num_capitol;
    cin >> num_capitol;

    if (num_capitol < 1 || num_capitol > capitols.size())
    {
        cout << "Aquest capitol no existeix." << endl;
        return;
    }

    cout << "Vols continuar amb la visualitzacio? (S/N): ";
    string resposta;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, resposta);
    
    //fecha actual
    time_t hora_acual = time(0);

    if (resposta == "S" || resposta == "s")
    {

        TxVisualitzarCapitol txVisualitzarCapitol;
        txVisualitzarCapitol.executar(nom_serie, num_temporada, num_capitol, hora_acual);
    }
    else
    {
        return;
    }

    //formatear la fecha
    tm* tiempo_local = localtime(&hora_acual);
    char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
    strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
    string fecha_formateada(fecha);

    cout << "Visualitzacio registrada ... " << fecha_formateada << endl;
}

void CapaDePresentacio::consulta_visualitzacions()
{
    PetitFlix::get_instance()->obte_usuari();
    string sobrenom_usuari = PetitFlix::get_instance()->obte_usuari()->obte_sobrenom();

    cout << "** Consulta visualitzacions **" << "\n" << endl;

    TxVisualitzarPelicula txVisualitzarPelicula;

    txVisualitzarPelicula.buscar_visualitzacions(sobrenom_usuari);
    
    vector<DTOPelicula> visualitzacionsP = txVisualitzarPelicula.obte_resultats();
    
    TxConsultaVisualitzacions txConsultaVisualitzacions;
    
    txConsultaVisualitzacions.executar(sobrenom_usuari);
    
    vector<DTOCapitol> visualitzacionsC = txConsultaVisualitzacions.obte_tots_resultats();
    
    if(visualitzacionsP.size() == 0 && visualitzacionsC.size() == 0)
    {
        cout << "No hi ha visualitzacions" << endl;
        return;
    }

    cout << "** Visualitzacions pel·licules **" << endl;
    cout << "****************************" << endl;

    for (int i = 0; i < visualitzacionsP.size(); i++)
    {
        DTOPelicula visualitzacio = visualitzacionsP[i];
        
        //formatear fecha
        tm* tiempo_local = localtime(&visualitzacio.data_estrena);
        char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
        strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
        string fecha_formateada(fecha);

        cout << "- " << fecha_formateada << "; "
             << visualitzacio.titol << "; "
             << visualitzacio.descripcio << "; "
             << visualitzacio.qualificacio << "; "
             << visualitzacio.duracio << " min; "
             << "nombre de visualitzacions " << visualitzacio.nb_visualitzacions << endl;
    }

    cout << "** Visualitzacions series **" << endl;
    cout << "****************************" << endl;

    for (int i = 0; i < visualitzacionsC.size(); i++)
    {
        DTOCapitol visualitzacio = visualitzacionsC[i];
        
        //formatear fecha
        tm* tiempo_local = localtime(&visualitzacio.data);
        char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
        strftime(fecha, 11, "%d/%m/%Y", tiempo_local);
        string fecha_formateada(fecha);

        cout << "- " << fecha_formateada << "; "
             << visualitzacio.titol << "; "
             << visualitzacio.qualificacio << "; "
             << "Temporada " << visualitzacio.num_temporada << ", capitol "
             << visualitzacio.num_capitol << "; "
             << "nombre de visualitzacions " << visualitzacio.num_visualitzacions << endl;
    }
}

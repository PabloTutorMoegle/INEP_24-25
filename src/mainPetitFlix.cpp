#include <iostream>
#include <string>
#include "./CapaDePresentacio/CapaDePresentacio.hpp"
#include "./CapaDeDomini/GestioUsuaris/PetitFlix.hpp"

using namespace std;

CapaDePresentacio cdp;

void consultes()
{
    cout<< "******************" << "\n"
        << "    Consultes     " << "\n"
        << "******************" << "\n"
        << "1. Properes estrenes" << "\n"
        << "2. Ultimes novetats" << "\n"
        << "3. Pel·licules mes vistes" << "\n"
        << "4. Tornar" << "\n"
        << "Escriu opcio: ";

    int opcio;
    cin >> opcio;
    while(cin >> opcio && opcio != 4)
    {
        switch (opcio)
        {
            case 1:
                CapaDePresentacio::properes_estrenes();
                break;
            case 2:
                cdp.ultimes_novetats();
                break;
            case 3:
                cdp.pelicules_mes_vistes();
                break;
            case 4:
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
}

void gestioUsuaris()
{
    cout<< "******************" << "\n"
        << "  Gestio Usuaris  " << "\n"
        << "******************" << "\n"
        << "1. Consulta usuari" << "\n"
        << "2. Modifica usuari" << "\n"
        << "3. Modifica contraenya" << "\n"
        << "4. Esborra usuari" << "\n"
        << "5. Tornar" << "\n"
        << "Escriu opcio: ";

    int opcio;
    cin >> opcio;
    while(cin >> opcio && opcio != 5)
    {
        switch (opcio)
        {
            case 1:
                cdp.consulta_usuari();
                break;
            case 2:
                cdp.modifica_usuari();
                break;
            case 3:
                cdp.modifica_contrasenya();
                break;
            case 4:
                cdp.esborra_usuari();
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
}

void visualitzacions()
{
    cout<< "******************" << "\n"
        << "   Visualitzar    " << "\n"
        << "******************" << "\n"
        << "1. Visualitzar pel·licula" << "\n"
        << "2. Visualitzar capitol" << "\n"
        << "3. Consulta visualitzacions" << "\n"
        << "4. Tornar" << "\n"
        << "Escriu opcio: ";

    int opcio;
    cin >> opcio;
    while(cin >> opcio && opcio != 3)
    {
        switch (opcio)
        {
            case 1:
                cout << "Visualitzant serie" << endl;
                break;
            case 2:
                cout << "Visualitzant pelicula" << endl;
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
}

int main() 
{
    PetitFlix* petitFlix = PetitFlix::get_instance();
    bool bucle = true;
    
    while (bucle)
    {
        auto usuari = petitFlix->obte_usuari();

        if(usuari)
        {
            cout<< "******************" << "\n"
                << "  Menu Principal  " << "\n"
                << "******************" << "\n"
                << "1. Gestio usuaris" << "\n"
                << "2. Visualitzar" << "\n"
                << "3. Consultes" << "\n"
                << "4. Tancar sessio" << "\n"
                << "5. Sortir: " << "\n"
                << "Escriu opcio: ";

            int opcio;
            cin >> opcio;
            switch (opcio)
            {
                case 1:
                    gestioUsuaris();
                    break;
                case 2:
                    visualitzacions();
                    break;
                case 3:
                    consultes();
                    break;
                case 4:
                    cdp.tanca_sessio();
                    break;
                case 5:
                    bucle = false;
                    break;
                default:
                    cout << "Opcio no valida" << endl;
                    break;
            }
        }
        else
        {
            cout<< "******************" << "\n"
                << "  Menu Principal  " << "\n"
                << "******************" << "\n"
                << "1. Iniciar sessio" << "\n"
                << "2. Registrar usuari" << "\n"
                << "3. Consultes" << "\n"
                << "4. Sortir" << "\n"
                << "Escriu opcio: ";

            int opcio;
            cin >> opcio;
            switch (opcio)
            {
                case 1:
                    cdp.inici_sessio();
                    break;
                case 2:
                    cdp.registrar_usuari();
                    break;
                case 3:
                    consultes();
                    return 0;;
                case 4:
                    bucle = false;
                    break;
                default:
                    cout << "Opcio no valida" << endl;
                    break;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include "./CapaDePresentacio/CapaDePresentacio.hpp"
#include "./CapaDeDomini/GestioUsuaris/PetitFlix.hpp"

using namespace std;

CapaDePresentacio cdp;

void consultes()
{
    bool bucleC = true;
    while(bucleC)
    {
        int opcio;

        cout<< "******************" << "\n"
            << "    Consultes     " << "\n"
            << "******************" << "\n"
            << "1. Properes estrenes" << "\n"
            << "2. Ultimes novetats" << "\n"
            << "3. Pel·licules mes vistes" << "\n"
            << "4. Tornar" << "\n"
            << "Escriu opcio: ";
        cin >> opcio;

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
                bucleC = false;
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
    return;
}

void gestioUsuaris()
{
    bool bucleG = true;
    while(bucleG)
    {
        int opcio;

        cout<< "******************" << "\n"
            << "  Gestio Usuaris  " << "\n"
            << "******************" << "\n"
            << "1. Consulta usuari" << "\n"
            << "2. Modifica usuari" << "\n"
            << "3. Modifica contrasenya" << "\n"
            << "4. Esborra usuari" << "\n"
            << "5. Tornar" << "\n"
            << "Escriu opcio: ";
        cin >> opcio;

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
                bucleG = false;
                break;
            case 5:
                bucleG = false;
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
    return;
}

void visualitzacions()
{
    bool bucleV = true;
    while(bucleV)
    {
        int opcio;

        cout<< "******************" << "\n"
            << "   Visualitzar    " << "\n"
            << "******************" << "\n"
            << "1. Visualitzar pel·licula" << "\n"
            << "2. Visualitzar capitol" << "\n"
            << "3. Consulta visualitzacions" << "\n"
            << "4. Tornar" << "\n"
            << "Escriu opcio: ";
        cin >> opcio;

        switch (opcio)
        {
            case 1:
                cdp.visualitzar_pelicula();
                break;
            case 2:
                cout << "Visualitzant serie" << endl;
                break;
            case 3:
                cdp.consulta_visualitzacions();
                break;
            case 4:
                bucleV = false;
                break;
            default:
                cout << "Opcio no valida" << endl;
                break;
        }
    }
    return;
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
            int opcio;

            cout<< "******************" << "\n"
                << "  Menu Principal  " << "\n"
                << "******************" << "\n"
                << "1. Gestio usuaris" << "\n"
                << "2. Visualitzar" << "\n"
                << "3. Consultes" << "\n"
                << "4. Tancar sessio" << "\n"
                << "5. Sortir: " << "\n"
                << "Escriu opcio: ";
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
            int opcio;

            cout<< "******************" << "\n"
                << "  Menu Principal  " << "\n"
                << "******************" << "\n"
                << "1. Iniciar sessio" << "\n"
                << "2. Registrar usuari" << "\n"
                << "3. Consultes" << "\n"
                << "4. Sortir" << "\n"
                << "Escriu opcio: ";
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
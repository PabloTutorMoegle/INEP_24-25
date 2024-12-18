#include <iostream>
#include <string>
#include "./CapaDePresentacio/CapaDePresentacio.hpp"
#include "./CapaDeDomini/GestioUsuaris/PetitFlix.hpp"

using namespace std;

int main() 
{
    CapaDePresentacio capaDePresentacio;
    PetitFlix* petitFlix = PetitFlix::get_instance();
    
    while (true)
    {
        auto usuari = petitFlix->obte_usuari();
        if(usuari)
        {
            cout << "Usuari autenticat" << endl;
        }
        else
        {
            cout << "Usuari no autenticat" << endl;
        }
    }

    return 0;
}
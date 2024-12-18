#ifndef DADES_PASARELA_USUARI_HPP
#define DADES_PASARELA_USUARI_HPP

#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaUsuari {
    private:
        string _sobrenom;
        string _nom;
        string _contrasenya;
        string _correu_electronic;
        time_t _data_naixement;
        ModalitatSubscripcio _modalitat_subscripcio;
        
    public:
        PasarelaUsuari(
            string sobrenom, 
            string nom, 
            string contrasenya, 
            string correu_electronic, 
            time_t data_naixement, 
            ModalitatSubscripcio modalitat_subscripcio
        );
        ~PasarelaUsuari();

        void insereix() const;
        void modifica() const;
        void esborra() const;

        string obte_sobrenom() const;
        string obte_nom() const;
        string obte_contrasenya() const;
        string obte_correu_electronic() const;
        time_t obte_data_naixement() const;
        ModalitatSubscripcio obte_modalitat_subscripcio() const;

        void posa_nom(string nom);
        void posa_contrasenya(string contrasenya);
        void posa_correu_electronic(string correu_electronic);
        void posa_data_naixement(time_t data_naixement);
        void posa_modalitat_subscripcio(ModalitatSubscripcio modalitat_subscripcio);
};

#endif

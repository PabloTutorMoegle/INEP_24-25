#ifndef DADES_VISUALITZAR_SERIE_PASARELA_HPP
#define DADES_VISUALITZAR_SERIE_PASARELA_HPP

#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaVisualitzarSerie {
    private:
        string _sobrenom;
        string _titol_serie;
        int _num_visualitzacions;
        int _num_temporada;
        int _num_capitol;
        time_t _data;
        ModalitatSubscripcio _modalitat_subscripcio;

    public:
        PasarelaVisualitzarSerie(
            string sobrenom, 
            string titolSerie, 
            int numVicialitzacions, 
            int numTemporada, 
            int numCapitol, 
            time_t data,
            ModalitatSubscripcio modalitat_subscripcio
        );
        void insereix();
        void modifica();
        void esborra();

        string obte_sobrenom();
        string obte_titol_serie();
        int obte_num_visualitzacions();
        int obte_num_temporada();
        int obte_num_capitol();
        time_t obte_data();
        ModalitatSubscripcio obte_modalitat_subscripcio();
};

#endif

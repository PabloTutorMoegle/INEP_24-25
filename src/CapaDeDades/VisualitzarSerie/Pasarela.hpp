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
        string _qualificacio;
        int _nb_visualitzacions;
        int _num_temporada;
        int _num_capitol;
        time_t _data;

    public:
        PasarelaVisualitzarSerie(
            string sobrenom, 
            string titol_serie, 
            string qualificacio,
            int nb_visualitzacions,
            int num_temporada, 
            int num_capitol, 
            time_t data
        );
        ~PasarelaVisualitzarSerie();

        void insereix();
        void modifica();
        void esborra();

        string obte_sobrenom();
        string obte_titol_serie();
        string obte_qualificacio();
        int obte_nb_visualitzacions();
        int obte_num_temporada();
        int obte_num_capitol();
        time_t obte_data();
};

#endif

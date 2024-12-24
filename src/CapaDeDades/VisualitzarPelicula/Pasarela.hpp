#ifndef DADES_VISUALITZAR_PELICULA_PASARELA_HPP
#define DADES_VISUALITZAR_PELICULA_PASARELA_HPP

#include <string>
using std::string;

#include <time.h>

#include <cppconn/prepared_statement.h>

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"

class PasarelaVisualitzarPelicula {
    private: 
        string _sobrenom;
        string _titol_pelicula;
        int _nb_visualitzacions;
        time_t _data;

    public:
        PasarelaVisualitzarPelicula(
            string sobrenom,
            string titol_pelicula,
            int nb_visualitzacions,
            time_t data
        );
        ~PasarelaVisualitzarPelicula();
        
        void insereix();
        void modifica();
        void esborra();

        unsigned int obte_num_visualitzacions();
        string obte_sobrenom() const;
        string obte_titol_pelicula() const;
        time_t obte_data() const;
};

#endif

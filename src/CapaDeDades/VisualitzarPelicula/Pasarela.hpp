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
        string _titol_pelicula;
        string _descripcio;
        string _qualificacio;
        string _tipus;
        time_t _data_estrena;
        int _duracio;

        string _sobrenom;
        time_t _data;
        int _nb_visualitzacions;


    public:
        PasarelaVisualitzarPelicula(
            string _titol_pelicula,
            string _descripcio,
            string _qualificacio,
            time_t _data_estrena,
            int _duracio
        );
        ~PasarelaVisualitzarPelicula();
        
        void insereix();
        void modifica();
        void esborra();

        void modifica_data(time_t data);

        unsigned int obte_num_visualitzacions();
        string obte_sobrenom() const;
        string obte_titol_pelicula() const;
        string obte_descripcio() const;
        string obte_qualificacio() const;
        time_t obte_data() const;
        int obte_duracio() const;
};

#endif

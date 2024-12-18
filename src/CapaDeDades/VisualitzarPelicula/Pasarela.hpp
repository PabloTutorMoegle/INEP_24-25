#ifndef DADES_VISUALITZAR_PELICULA_PASARELA_HPP
#define DADES_VISUALITZAR_PELICULA_PASARELA_HPP

#include <string>
using std::string;

#include <time.h>

class PasarelaVisualitzarPelicula {
    private: 
        string _sobrenom;
        string _titolPelicula;
        int _numVisualitzacions;
        time_t data;

    public: 
        void insereix();
        void modifica();
        void esborra();

        unsigned int obte_num_visualitzacions();
};

#endif

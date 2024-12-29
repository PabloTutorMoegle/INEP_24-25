#ifndef DADES_VISUALITZAR_PELICULA_CERCADORA_HPP
#define DADES_VISUALITZAR_PELICULA_CERCADORA_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;

#include "Pasarela.hpp"

class CercadoraVisualitzarPelicula {
    public:
        static vector<PasarelaVisualitzarPelicula> cerca_per_sobrenom(string sobrenom_usuari);
        static PasarelaVisualitzarPelicula obte_dades_pelicula(string titol_pelicula);
        static vector<string> cerca_relacionades(string titol_pelicula);
        static vector<PasarelaVisualitzarPelicula> obte_visualitzacions(string sobrenom_usuari);
};

#endif

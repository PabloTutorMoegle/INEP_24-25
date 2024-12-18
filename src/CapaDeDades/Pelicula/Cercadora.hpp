#ifndef DADES_CERCADORA_PELICULA_HPP
#define DADES_CERCADORA_PELICULA_HPP

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <vector>
using std::vector;

#include <ctime>

#include "Pasarela.hpp"
#include "../ConnexioBDD.hpp"
#include "../../definitions.hpp"

class CercadoraPelicula {
    public: 
        static vector<PasarelaPelicula> cerca_novetats();
        static vector<PasarelaPelicula> cerca_estrenes();
        static vector<PasarelaPelicula> cerca_mes_vistes();
};

#endif

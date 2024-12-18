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

class CercadoraConsulta {
    public: 
        static vector<PasarelaConsulta> cerca_novetats();
        static vector<PasarelaConsulta> cerca_estrenes();
        static vector<PasarelaConsulta> cerca_mes_vistes();
};

#endif

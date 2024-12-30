#ifndef DADES_VISUALITZAR_SERIE_CERCADORA_HPP
#define DADES_VISUALITZAR_SERIE_CERCADORA_HPP

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <vector>
using std::vector;

#include "Pasarela.hpp"
#include "../ConnexioBDD.hpp"
#include "../../definitions.hpp"

class CercadoraVisualitzarSerie {
    public:
        static vector<PasarelaVisualitzarSerie> cerca_per_sobrenom(string sobrenom_usuari);
        static PasarelaVisualitzarSerie obte_dades_capitol(string titol_serie, int num_temporada, int num_capitol);
        static int obte_num_temporades(string titol_serie);
        static vector<PasarelaVisualitzarSerie> obte_capitols(string titol_serie, int num_temporada);
};

#endif

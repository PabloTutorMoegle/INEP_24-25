#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Pasarela.hpp"

class CercadoraVisualitzarPelicula {
    public:
        static vector<PasarelaVisualitzarPelicula> cerca_per_sobrenom(string sobrenom_usuari);
};


#include <utility>
using std::pair;

#include "../PetitFlix.hpp"
#include "../../CapaDeDades/VisualitzarSerie/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarPelicula/Cercadora.hpp"

class TxInfoVisualitzacions {
    private:
        unsigned int _visualitzacions_pelicula;
        unsigned int _visualitzacions_serie;

    public:
        TxInfoVisualitzacions();
        
        void executar();
        pair<unsigned int, unsigned int> obte_resultat();
};

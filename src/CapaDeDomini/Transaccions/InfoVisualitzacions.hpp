#ifndef DOMINI_TRANSACCIO_INFO_VISUALITZACIONS_HPP
#define DOMINI_TRANSACCIO_INFO_VISUALITZACIONS_HPP

#include <utility>
using std::pair;

#include "../PetitFlix.hpp"
#include "../../CapaDeDades/VisualitzarSerie/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarSerie/Pasarela.hpp"
#include "../../CapaDeDades/VisualitzarPelicula/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarPelicula/Pasarela.hpp"

class TxInfoVisualitzacions {
    private:
        unsigned int _visualitzacions_pelicula;
        unsigned int _visualitzacions_serie;

    public:
        TxInfoVisualitzacions();
        ~TxInfoVisualitzacions();
        
        void executar();
        pair<unsigned int, unsigned int> obte_resultat() const;
};

#endif

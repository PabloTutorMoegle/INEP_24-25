#ifndef TXVISUALITZARPELICULA_HPP
#define TXVISUALITZARPELICULA_HPP

#include <optional>
using std::optional;

#include "../../CapaDeDades/VisualitzarPelicula/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarPelicula/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOPelicula.hpp"

class TxVisualitzarPelicula {
    private:
        optional<DTOPelicula> _resultat;

    public:
        TxVisualitzarPelicula();
        ~TxVisualitzarPelicula();

        void executar(string titol_pelicula);
        DTOPelicula obte_resultat() const;
};

#endif
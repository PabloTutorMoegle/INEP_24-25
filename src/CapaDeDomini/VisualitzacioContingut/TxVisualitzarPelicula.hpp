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
        vector<DTOPelicula> _resultats;

    public:
        TxVisualitzarPelicula();
        ~TxVisualitzarPelicula();
        
        void buscar(string titol_pelicula);
        void executar(string titol_pelicula);
        void buscar_visualitzacions(string sobrenom_usuari);
        DTOPelicula obte_resultat() const;
        vector<DTOPelicula> obte_resultats() const;

        vector<DTOPelicula> pelicula_relacionada(string titol_pelicula);
};

#endif
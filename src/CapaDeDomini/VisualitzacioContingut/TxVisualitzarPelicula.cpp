#include "TxVisualitzarPelicula.hpp"

TxVisualitzarPelicula::TxVisualitzarPelicula() {
    _resultat = std::nullopt;
}

TxVisualitzarPelicula::~TxVisualitzarPelicula() {}

void TxVisualitzarPelicula::executar(string titol_pelicula) 
{
    PasarelaVisualitzarPelicula visualitzacio = CercadoraVisualitzarPelicula::obte_dades_pelicula(titol_pelicula);

    _resultat = DTOPelicula(
        visualitzacio.obte_titol_pelicula(),
        visualitzacio.obte_sobrenom(),
        visualitzacio.obte_num_visualitzacions(),
        visualitzacio.obte_data()
    );
}

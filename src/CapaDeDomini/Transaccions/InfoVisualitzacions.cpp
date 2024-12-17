#include "InfoVisualitzacions.hpp"

TxInfoVisualitzacions::TxInfoVisualitzacions() {
    _visualitzacions_serie = 0;
    _visualitzacions_pelicula = 0;
};

void TxInfoVisualitzacions::executar() {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    PasarelaUsuari usuari = petit_flix->obte_usuari();
    string sobrenom_usuari = usuari.obte_sobrenom();

    vector<PasarelaVisualitzarSerie> visualitzacions_serie =  CercadoraVisualitzarSerie::cerca_per_sobrenom(sobrenom_usuari);
    vector<PasarelaVisualitzarPelicula> visualitzacions_pelicula =  CercadoraVisualitzarPelicula::cerca_per_sobrenom(sobrenom_usuari);

    for (auto visualitzacio : visualitzacions_serie) {
        _visualitzacions_serie += visualitzacio.obte_num_visualitzacions();
    }

    for (auto visualitzacio : visualitzacions_pelicula) {
        _visualitzacions_pelicula += visualitzacio.obte_num_visualitzacions();
    }
}

// Retorna (visualitzacions_pelicula, visualitzacions_serie)
pair<unsigned int, unsigned int> TxInfoVisualitzacions::obte_resultat() {
    return pair<unsigned int, unsigned int>(_visualitzacions_pelicula, _visualitzacions_serie);
}

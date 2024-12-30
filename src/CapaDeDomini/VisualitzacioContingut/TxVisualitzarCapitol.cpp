#include "TxVisualitzarCapitol.hpp"

TxVisualitzarCapitol::TxVisualitzarCapitol() {
    _resultat = std::nullopt;
    _num_temporades = 0;
    _resultats = vector<DTOCapitol>();
}

TxVisualitzarCapitol::~TxVisualitzarCapitol() {}

void TxVisualitzarCapitol::buscar_temporades(string titol_serie) 
{
    _num_temporades = CercadoraVisualitzarSerie::obte_num_temporades(titol_serie);
}

void TxVisualitzarCapitol::buscar(string titol_serie, int num_temporada) 
{
    vector<PasarelaVisualitzarSerie> visualitzacions = CercadoraVisualitzarSerie::obte_capitols(titol_serie, num_temporada);
    for (auto visualitzacio : visualitzacions) {
        _resultats.push_back(
            DTOCapitol {
                .titol = visualitzacio.obte_titol_serie(),
                .qualificacio = visualitzacio.obte_qualificacio(),
                .num_temporada = visualitzacio.obte_num_temporada(),
                .num_capitol = visualitzacio.obte_num_capitol(),
                .num_visualitzacions = visualitzacio.obte_nb_visualitzacions(),
                .data = visualitzacio.obte_data()
            }
        );
    }
}

void TxVisualitzarCapitol::executar(string titol_serie, int num_temporada, int num_capitol, time_t data) 
{
    PasarelaVisualitzarSerie visualitzacio = CercadoraVisualitzarSerie::obte_dades_capitol(titol_serie, num_temporada, num_capitol);

    //modificar la data de visualitzacio
    time_t date = time(0);
    visualitzacio.modifica_data(date);
    visualitzacio.set_sobrenom(PetitFlix::get_instance()->obte_usuari()->obte_sobrenom());

    visualitzacio.insereix();

    _resultat = DTOCapitol {
        .titol = visualitzacio.obte_titol_serie(),
        .qualificacio = visualitzacio.obte_qualificacio(),
        .num_temporada = visualitzacio.obte_num_temporada(),
        .num_capitol = visualitzacio.obte_num_capitol(),
        .num_visualitzacions = visualitzacio.obte_nb_visualitzacions(),
        .data = visualitzacio.obte_data()
    };

    return;
}   

void TxVisualitzarCapitol::buscar_visualitzacions(string sobrenom_usuari) 
{
    vector<DTOCapitol> results;
    vector<PasarelaVisualitzarSerie> visualitzacions = CercadoraVisualitzarSerie::cerca_per_sobrenom(sobrenom_usuari);
    for (auto visualitzacio : visualitzacions) {
        _resultats.push_back(
            DTOCapitol {
                .titol = visualitzacio.obte_titol_serie(),
                .qualificacio = visualitzacio.obte_qualificacio(),
                .num_temporada = visualitzacio.obte_num_temporada(),
                .num_capitol = visualitzacio.obte_num_capitol(),
                .num_visualitzacions = visualitzacio.obte_nb_visualitzacions(),
                .data = visualitzacio.obte_data()
            }
        );
    }
}

DTOCapitol TxVisualitzarCapitol::obte_resultat() const {
    return _resultat.value();
}

vector<DTOCapitol> TxVisualitzarCapitol::obte_resultats() const {
    return _resultats;
}

int TxVisualitzarCapitol::obte_num_temporades() const {
    return _num_temporades;
}
#include "TxConsultaVisualitzacions.hpp"

TxConsultaVisualitzacions::TxConsultaVisualitzacions() {
    _resultat = std::nullopt;
}

TxConsultaVisualitzacions::~TxConsultaVisualitzacions() {}

void TxConsultaVisualitzacions::executar(string sobrenom_usuari) 
{
    vector<PasarelaVisualitzarSerie> visualitzacions = CercadoraVisualitzarSerie::cerca_per_sobrenom(sobrenom_usuari);

    vector<DTOCapitol> resultats;

    for (PasarelaVisualitzarSerie visualitzacio : visualitzacions) {
        resultats.push_back(DTOCapitol {
            .titol = visualitzacio.obte_titol_serie(),
            .qualificacio = visualitzacio.obte_qualificacio(),
            .num_temporada = visualitzacio.obte_num_temporada(),
            .num_capitol = visualitzacio.obte_num_capitol(),
            .num_visualitzacions = visualitzacio.obte_nb_visualitzacions(),
            .data = visualitzacio.obte_data()
        });
    }

    _resultat = resultats;
}

DTOCapitol TxConsultaVisualitzacions::obte_resultat() const {
    return _resultat.value();
}

vector<DTOCapitol> TxConsultaVisualitzacions::obte_tots_resultats() const {
    return _resultat;
}
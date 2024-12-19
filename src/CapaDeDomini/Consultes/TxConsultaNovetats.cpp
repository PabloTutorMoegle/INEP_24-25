#include "TxConsultaNovetats.hpp"

TxConsultaNovetats::TxConsultaNovetats(ModalitatSubscripcio modalitat) {
    _resultat = std::nullopt;
    _modalitat = modalitat;
}

TxConsultaNovetats::~TxConsultaNovetats() {}

void TxConsultaNovetats::executar() {
    vector<PasarelaConsulta> pasareles_consulta;
    switch (_modalitat) {
        case Completa:
            pasareles_consulta = CercadoraConsulta::cerca_novetats_completa();
            break;
        case Cinefil:
            pasareles_consulta = CercadoraConsulta::cerca_novetats_cinefil();
            break;
        case Infantil:
            pasareles_consulta = CercadoraConsulta::cerca_novetats_infantil();
            break;
    }

    vector<DTOContingut> continguts;
    for (auto pasarela : pasareles_consulta) {
        continguts.push_back(DTOContingut{
            .data_estrena = pasarela.obte_data_estrena(),
            .tipus = pasarela.obte_tipus(),
            .titol = pasarela.obte_titol(),
            .qualificacio = pasarela.obte_qualificacio(),
            .info = pasarela.obte_info()
        });
    }

    _resultat = continguts;
}

vector<DTOContingut> TxConsultaNovetats::obte_resultat() const {
    if (!_resultat) {
        throw "No s'ha executat la transacció!";
    }
    return *_resultat;
};

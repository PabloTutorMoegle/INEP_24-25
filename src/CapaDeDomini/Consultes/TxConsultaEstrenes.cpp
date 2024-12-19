#include "TxConsultaEstrenes.hpp"

TxConsultaEstrenes::TxConsultaEstrenes(ModalitatSubscripcio modalitat) {
    _resultat = std::nullopt;
    _modalitat = modalitat;
}

TxConsultaEstrenes::~TxConsultaEstrenes() {}

void TxConsultaEstrenes::executar() {
    vector<PasarelaConsulta> pasareles_consulta;
    switch (_modalitat) {
        case Completa:
            pasareles_consulta = CercadoraConsulta::cerca_estrenes_completa();
            break;
        case Cinefil:
            pasareles_consulta = CercadoraConsulta::cerca_estrenes_cinefil();
            break;
        case Infantil:
            pasareles_consulta = CercadoraConsulta::cerca_estrenes_infantil();
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

vector<DTOContingut> TxConsultaEstrenes::obte_resultat() const {
    if (!_resultat) {
        throw "No s'ha executat la transacció!";
    }
    return *_resultat;
};

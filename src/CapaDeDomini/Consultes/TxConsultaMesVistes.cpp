#include "TxConsultaMesVistes.hpp"

TxConsultaMesVistes::TxConsultaMesVistes(ModalitatSubscripcio modalitat) {
    _modalitat = modalitat;
    _resultat = std::nullopt;
}

TxConsultaMesVistes::~TxConsultaMesVistes() {}

void TxConsultaMesVistes::executar() {
    vector<PasarelaConsulta> pasareles_consulta = CercadoraConsulta::cerca_mes_vistes(_modalitat);

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

vector<DTOContingut> TxConsultaMesVistes::obte_resultat() const {
    if (!_resultat) {
        throw "No s'ha executat la transacció!";
    }
    return *_resultat;
};

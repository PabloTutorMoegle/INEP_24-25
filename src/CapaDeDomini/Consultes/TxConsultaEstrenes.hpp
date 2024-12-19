#ifndef DOMINI_CONSULTA_ESTRENA_HPP
#define DOMINI_CONSULTA_ESTRENA_HPP

#include <optional>
using std::optional;

#include "../../CapaDeDades/Consulta/Cercadora.hpp"
#include "../../CapaDeDades/Consulta/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOContingut.hpp"

class TxConsultaEstrenes {
    private:
        optional<vector<DTOContingut>> _resultat;
        ModalitatSubscripcio _modalitat;

    public:
        TxConsultaEstrenes(ModalitatSubscripcio modalitat);
        ~TxConsultaEstrenes();

        void executar();
        vector<DTOContingut> obte_resultat() const;
};

#endif

#ifndef DOMINI_CONSULTA_NOVETAT_HPP
#define DOMINI_CONSULTA_NOVETAT_HPP

#include <optional>
using std::optional;

#include "../../CapaDeDades/Consulta/Cercadora.hpp"
#include "../../CapaDeDades/Consulta/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOContingut.hpp"

class TxConsultaNovetats {
    private:
        optional<vector<DTOContingut>> _resultat;
        ModalitatSubscripcio _modalitat;

    public:
        TxConsultaNovetats(ModalitatSubscripcio modalitat);
        ~TxConsultaNovetats();

        void executar();
        vector<DTOContingut> obte_resultat() const;
};

#endif

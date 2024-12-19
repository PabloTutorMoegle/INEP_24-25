#ifndef DOMINI_CONSULTA_MES_VISTES_HPP
#define DOMINI_CONSULTA_MES_VISTES_HPP

#include <optional>
using std::optional;

#include "../../CapaDeDades/Consulta/Cercadora.hpp"
#include "../../CapaDeDades/Consulta/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOContingut.hpp"

class TxConsultaMesVistes {
    private:
        optional<vector<DTOContingut>> _resultat;

    public:
        TxConsultaMesVistes();
        ~TxConsultaMesVistes();

        void executar();
        vector<DTOContingut> obte_resultat() const;
};

#endif

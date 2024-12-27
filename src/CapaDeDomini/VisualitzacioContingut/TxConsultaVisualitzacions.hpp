#ifndef TXCONSULTAVISUALITZACIONS_HPP
#define TXCONSULTAVISUALITZACIONS_HPP

#include <optional>
using std::optional;
#include <string>
#include <vector>
using namespace std;

#include "../../CapaDeDades/VisualitzarSerie/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarSerie/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOCapitol.hpp"

class TxConsultaVisualitzacions {
    private:
        optional<DTOCapitol> _resultat;

    public:
        TxConsultaVisualitzacions();
        ~TxConsultaVisualitzacions();
        
        //void buscar(string titol_serie);
        void executar(string sobrenom_usuari);
        DTOCapitol obte_resultat() const;
        vector<DTOCapitol> obte_tots_resultats() const;
};

#endif
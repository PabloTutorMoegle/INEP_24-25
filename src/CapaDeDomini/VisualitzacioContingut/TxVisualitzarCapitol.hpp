#ifndef TXVISULITZARCAPITOL_HPP
#define TXVISULITZARCAPITOL_HPP

#include <optional>
using std::optional;

#include "../../CapaDeDades/VisualitzarSerie/Cercadora.hpp"
#include "../../CapaDeDades/VisualitzarSerie/Pasarela.hpp"
#include "../../definitions.hpp"
#include "DTOCapitol.hpp"
#include "../../CapaDeDomini/GestioUsuaris/PetitFlix.hpp"

class TxVisualitzarCapitol {
    private:
        optional<DTOCapitol> _resultat;
        vector<DTOCapitol> _resultats;
        int _num_temporades;

    public:
        TxVisualitzarCapitol();
        ~TxVisualitzarCapitol();

        void buscar_temporades(string titol_serie);
        void buscar(string titol_serie, int num_temporada);
        void executar(string titol_serie, int num_temporada, int num_capitol, time_t data);
        void buscar_visualitzacions(string sobrenom_usuari);
        DTOCapitol obte_resultat() const;
        vector<DTOCapitol> obte_resultats() const;
        int obte_num_temporades() const;};

#endif
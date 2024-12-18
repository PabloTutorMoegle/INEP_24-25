#ifndef DOMINI_CONTROL_MODIFICA_USUARI_HPP
#define DOMINI_CONTROL_MODIFICA_USUARI_HPP

#include <string>
using std::string;

#include "Transaccions/ConsultaUsuari.hpp"

class CtrlModificaUsuari {
    private:
        optional<PasarelaUsuari> _usuari;

    public:
        CtrlModificaUsuari();
        ~CtrlModificaUsuari();

        DTOUsuari obte_usuari();
        void modifica_usuari(
            optional<string> nom_usuari,
            optional<string> contrasenya_usuari,
            optional<string> correu_electronic_usuari,
            optional<time_t> data_naixement_usuari,
            optional<ModalitatSubscripcio> modalitat_subscripcio_usuari
        );
};

#endif

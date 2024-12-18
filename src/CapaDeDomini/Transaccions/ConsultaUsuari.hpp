#ifndef DOMINI_TRANSACCIO_CONSULTA_USUARI_HPP
#define DOMINI_TRANSACCIO_CONSULTA_USUARI_HPP

#include "../DTOUsuari.hpp"
#include "../PetitFlix.hpp"

class TxConsultaUsuari {
    private:
        optional<DTOUsuari> _resultat;

    public:
        TxConsultaUsuari();
        ~TxConsultaUsuari();

        void executar();
        DTOUsuari obte_resultat() const;
        PasarelaUsuari obte_usuari() const;
};

#endif

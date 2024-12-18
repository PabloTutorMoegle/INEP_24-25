#ifndef DOMINI_TRANSACCIO_TANCA_SESSIO_HPP
#define DOMINI_TRANSACCIO_TANCA_SESSIO_HPP

#include "../PetitFlix.hpp"

class TxTancaSessio {
    public:
        TxTancaSessio();
        ~TxTancaSessio();

        void executa() const;
};

#endif

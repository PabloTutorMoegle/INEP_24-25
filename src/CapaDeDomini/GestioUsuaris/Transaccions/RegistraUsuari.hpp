#ifndef DOMINI_TRANSACCIO_REGISTRA_USUARI_HPP
#define DOMINI_TRANSACCIO_REGISTRA_USUARI_HPP

#include <string>
using std::string;

#include <time.h>

#include "../../../definitions.hpp"
#include "../../../CapaDeDades/Usuari/Pasarela.hpp"

class TxRegistraUsuari {
    private:
        string _nom_usuari;
        string _sobrenom_usuari;
        string _contrasenya_usuari;
        string _correu_electronic_usuari;
        time_t _data_naixement_usuari;
        ModalitatSubscripcio _modalitat_subscripcio;

    public:
        TxRegistraUsuari(
            string nom_usuari, 
            string sobrenom_usuari,
            string contrasenya_usuari, 
            string correu_electronic_usuari,
            time_t data_naixement_usuari, 
            ModalitatSubscripcio modalitat_subscripcio
        );

        ~TxRegistraUsuari();

        void executar() const;
};

#endif

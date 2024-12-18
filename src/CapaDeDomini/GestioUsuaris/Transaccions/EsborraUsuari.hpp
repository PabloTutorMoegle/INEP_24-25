#ifndef DOMINI_TRANSACCIO_ESBORRA_USUARI_HPP
#define DOMINI_TRANSACCIO_ESBORRA_USUARI_HPP

#include <string>
using std::string;

#include "../PetitFlix.hpp"
#include "../../../CapaDeDades/VisualitzarSerie/Pasarela.hpp"
#include "../../../CapaDeDades/VisualitzarSerie/Cercadora.hpp"

class TxEsborraUsuari {
    private:
        string _contrasenya_usuari;

    public:
        TxEsborraUsuari(string contrasenya_usuari);
        ~TxEsborraUsuari();

        void executar() const;
};

#endif

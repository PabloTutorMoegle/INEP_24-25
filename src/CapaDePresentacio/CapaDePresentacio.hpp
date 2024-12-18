#ifndef PRESENTACIO_HPP
#define PRESENTACIO_HPP

#include <utility>
using std::pair;

#include "../CapaDeDomini/GestioUsuaris/DTOUsuari.hpp"

// Això no fa falta que s'implementi com un singleton ja que tot els mètodes poden ser estàtics
class CapaDePresentacio {
    public:
        static void inici_sessio();
        static void tanca_sessio();
        static void registrar_usuari();
        static pair<DTOUsuari, pair<unsigned int, unsigned int>> consulta_usuari();
        static void modifica_usuari();
        static void esborra_usuari();
};

#endif

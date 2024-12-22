#include "RegistraUsuari.hpp"
#include <iostream>

TxRegistraUsuari::TxRegistraUsuari(
    string nom_usuari, 
    string sobrenom_usuari,
    string contrasenya_usuari, 
    string correu_electronic_usuari,
    time_t data_naixement_usuari,
    ModalitatSubscripcio modalitat_subscripcio
) {
    _nom_usuari = nom_usuari;
    _sobrenom_usuari = sobrenom_usuari;
    _contrasenya_usuari = contrasenya_usuari;
    _correu_electronic_usuari = correu_electronic_usuari;
    _data_naixement_usuari = data_naixement_usuari;
    _modalitat_subscripcio = modalitat_subscripcio;
}

TxRegistraUsuari::~TxRegistraUsuari() {}

void TxRegistraUsuari::executar() const {
    const PasarelaUsuari nou_usuari(
        _sobrenom_usuari,
        _nom_usuari,
        _contrasenya_usuari,
        _correu_electronic_usuari,
        _data_naixement_usuari,
        _modalitat_subscripcio
    );
    std::cout << "entra" << std::endl;
    nou_usuari.insereix();
    std::cout << "surt" << std::endl;
}

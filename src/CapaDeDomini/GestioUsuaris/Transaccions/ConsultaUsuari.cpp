#include "ConsultaUsuari.hpp"

TxConsultaUsuari::TxConsultaUsuari() {
    _resultat = std::nullopt;
}

TxConsultaUsuari::~TxConsultaUsuari() {}

void TxConsultaUsuari::executar() {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    const PasarelaUsuari usuari = petit_flix->obte_usuari();

    const string sobrenom = usuari.obte_sobrenom();
    const string nom = usuari.obte_nom();
    const string correu_electronic = usuari.obte_correu_electronic();
    const time_t data_naixement = usuari.obte_data_naixement();
    const ModalitatSubscripcio modalitat_subscripcio = usuari.obte_modalitat_subscripcio();

    _resultat = DTOUsuari {
        .sobrenom = sobrenom,
        .nom = nom,
        .correu_electronic = correu_electronic,
        .data_naixement = data_naixement,
        .modalitat_subscripcio = modalitat_subscripcio,
    };
}

DTOUsuari TxConsultaUsuari::obte_resultat() const {
    if (_resultat) {
        return *_resultat;
    } else {
        throw "No s'ha executat la transacció!";
    }
}

PasarelaUsuari TxConsultaUsuari::obte_usuari() const {
    const PetitFlix* petit_flix = PetitFlix::get_instance();   
    return petit_flix->obte_usuari();
}

#include "ConsultaUsuari.hpp"

TxConsultaUsuari::TxConsultaUsuari() {
    _resultat = std::nullopt;
}

void TxConsultaUsuari::executar() {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    PasarelaUsuari usuari = petit_flix->obte_usuari();

    string sobrenom = usuari.obte_sobrenom();
    string nom = usuari.obte_nom();
    string correu_electronic = usuari.obte_correu_electronic();
    time_t data_naixement = usuari.obte_data_naixement();
    ModalitatSubscripcio modalitat_subscripcio = usuari.obte_modalitat_subscripcio();

    _resultat = DTOUsuari {
        .sobrenom = sobrenom,
        .nom = nom,
        .correu_electronic = correu_electronic,
        .data_naixement = data_naixement,
        .modalitat_subscripcio = modalitat_subscripcio,
    };
}

DTOUsuari TxConsultaUsuari::obte_resultat() {
    if (_resultat) {
        return *_resultat;
    } else {
        throw "No s'ha executat la transacció!";
    }
}

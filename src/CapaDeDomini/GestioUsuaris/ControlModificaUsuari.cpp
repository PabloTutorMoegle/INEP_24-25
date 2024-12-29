#include "ControlModificaUsuari.hpp"

CtrlModificaUsuari::CtrlModificaUsuari(): _usuari(std::nullopt) {}
CtrlModificaUsuari::~CtrlModificaUsuari() {}

DTOUsuari CtrlModificaUsuari::obte_usuari() {
    TxConsultaUsuari tx_consulta_usuari;
    tx_consulta_usuari.executar();
    const DTOUsuari resultat = tx_consulta_usuari.obte_resultat();
    _usuari = tx_consulta_usuari.obte_usuari();

    return resultat;
}

void CtrlModificaUsuari::modifica_usuari(
    optional<string> nom_usuari,
    optional<string> sobrenom_usuari,
    optional<string> correu_electronic_usuari,
    optional<time_t> data_naixement_usuari,
    optional<ModalitatSubscripcio> modalitat_subscripcio_usuari
) {
    if (!_usuari) {
        return;
    }

    if (
        !nom_usuari &&
        !sobrenom_usuari &&
        !correu_electronic_usuari &&
        !data_naixement_usuari &&
        !modalitat_subscripcio_usuari
    ) return;
    
    if (nom_usuari) {
        _usuari->posa_nom(*nom_usuari);
    }

    if (sobrenom_usuari) {
        _usuari->posa_contrasenya(*sobrenom_usuari);
    }

    if (correu_electronic_usuari) {
        _usuari->posa_correu_electronic(*correu_electronic_usuari);
    }

    if (data_naixement_usuari) {
        _usuari->posa_data_naixement(*data_naixement_usuari);
    }

    if (modalitat_subscripcio_usuari) {
        _usuari->posa_modalitat_subscripcio(*modalitat_subscripcio_usuari);
    }

    _usuari->modifica();

}

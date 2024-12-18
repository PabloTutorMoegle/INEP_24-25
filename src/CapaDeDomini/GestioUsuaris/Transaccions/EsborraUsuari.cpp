#include "EsborraUsuari.hpp"

TxEsborraUsuari::TxEsborraUsuari(string contrasenya_usuari) {
    _contrasenya_usuari = contrasenya_usuari;
}

TxEsborraUsuari::~TxEsborraUsuari() {}

void TxEsborraUsuari::executar() const {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    const PasarelaUsuari usuari = petit_flix->obte_usuari();
    const string contrasenya_usuari = usuari.obte_contrasenya();

    if (contrasenya_usuari != _contrasenya_usuari) {
        throw "La contrasenya no és correcta, l'usuari no s'ha esborrat";
        return;
    }
    
    usuari.esborra();

    petit_flix->tanca_sessio();
}

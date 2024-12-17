#include "EsborraUsuari.hpp"

TxEsborraUsuari::TxEsborraUsuari(string contrasenya_usuari) {
    _contrasenya_usuari = contrasenya_usuari;
}

void TxEsborraUsuari::executar() {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    PasarelaUsuari usuari = petit_flix->obte_usuari();
    string contrasenya_usuari = usuari.obte_contrasenya();

    if (contrasenya_usuari != _contrasenya_usuari) {
        throw "La contrasenya no és correcta, l'usuari no s'ha esborrat";
        return;
    }
    
    usuari.esborra();

    // TODO: Tancar sessió? He preguntat a la Lídia
}

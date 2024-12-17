#include "IniciSessio.hpp"

TxIniciSessio::TxIniciSessio(string sobrenom_usuari, string contrasenya_usuari) {
    _sobrenom_usuari = sobrenom_usuari;
    _contrasenya_usuari = contrasenya_usuari;
}

void TxIniciSessio::executar() {
    PasarelaUsuari pasarela_usuari = CercadoraUsuari::cercaUsuari(_sobrenom_usuari);
    string contrasenya_pasarela = pasarela_usuari.obte_contrasenya();

    if (_contrasenya_usuari != contrasenya_pasarela) {
        throw "Hi ha hagut un error amb el sobrenom o la contrasenya";
        return;
    }


    PetitFlix* petit_flix = PetitFlix::get_instance();   
    petit_flix->inicia_sessio(pasarela_usuari);
}

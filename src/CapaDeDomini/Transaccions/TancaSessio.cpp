#include "TancaSessio.hpp"

TxTancaSessio::TxTancaSessio() {};

void TxTancaSessio::executa() {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    petit_flix->tanca_sessio();
}

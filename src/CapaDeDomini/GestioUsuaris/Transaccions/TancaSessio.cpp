#include "TancaSessio.hpp"

TxTancaSessio::TxTancaSessio() {};
TxTancaSessio::~TxTancaSessio() {};

void TxTancaSessio::executa() const {
    PetitFlix* petit_flix = PetitFlix::get_instance();   
    petit_flix->tanca_sessio();
}

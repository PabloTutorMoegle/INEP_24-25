#include "PetitFlix.hpp"

PetitFlix* PetitFlix::_instance = nullptr;

PetitFlix* PetitFlix::get_instance() {
    if (_instance == nullptr) {
        _instance = new PetitFlix();
    }
    return _instance;
}

PetitFlix::PetitFlix() {
    _usuari = std::nullopt;
}

PasarelaUsuari PetitFlix::obte_usuari() {
    if (_usuari) {
        return *_usuari;
    } else {
        throw "No hi ha cap sessió iniciada";
    }
}

// Pre: l'usuari ha estat autenticat previament
// I sure do hope no one runs this function ouside of it's indended context
void PetitFlix::inicia_sessio(PasarelaUsuari usuari) {
    _usuari = usuari;
}

void PetitFlix::tanca_sessio() {
    _usuari = std::nullopt;
}

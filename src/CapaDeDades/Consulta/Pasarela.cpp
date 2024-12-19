#include "Pasarela.hpp"

PasarelaConsulta::PasarelaConsulta(time_t data_estrena, string tipus, string titol, string qualificacio, string info) {
    _data_estrena = data_estrena;
    _tipus = tipus;
    _titol = titol;
    _qualificacio = qualificacio;
    _info = info;
}

PasarelaConsulta::~PasarelaConsulta() {}

time_t PasarelaConsulta::obte_data_estrena() const {
    return _data_estrena;
}

string PasarelaConsulta::obte_tipus() const {
    return _tipus;
}

string PasarelaConsulta::obte_titol() const {
    return _titol;
}

string PasarelaConsulta::obte_qualificacio() const {
    return _qualificacio;
}

string PasarelaConsulta::obte_info() const {
    return _info;
}

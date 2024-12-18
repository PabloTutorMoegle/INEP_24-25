#include "Pasarela.hpp"

PasarelaConsulta::PasarelaConsulta(time_t data_estrena, string tipus, string titol, string qualificacio, string info) {
    _data_estrena = data_estrena;
    _tipus = tipus;
    _titol = titol;
    _qualificacio = qualificacio;
    _info = info;
}

PasarelaConsulta::~PasarelaConsulta() {}

#ifndef DADES_PASARELA_PELICULA_HPP
#define DADES_PASARELA_PELICULA_HPP

#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaConsulta {
    private:
        time_t _data_estrena;
        string _tipus;
        string _titol;
        string _qualificacio;
        string _info;

    public:
        PasarelaConsulta(time_t data, string _tipus, string titol, string _qualificacio, string _info);
        ~PasarelaConsulta();

        time_t obte_data_estrena() const;
        string obte_tipus() const;
        string obte_titol() const;
        string obte_qualificacio() const;
        string obte_info() const;
};

#endif

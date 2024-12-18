#ifndef DADES_PASARELA_PELICULA_HPP
#define DADES_PASARELA_PELICULA_HPP

#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaPelicula {
    private:
        string _titol;
        time_t _data_estrena;
        int _duracio;

    public:
        PasarelaPelicula(string titol, time_t data, int duracio);
        ~PasarelaPelicula();

        void insereix() const;
        void modifica() const;
        void esborra() const;
};

#endif

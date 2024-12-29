#ifndef DTOCAPITOL_HPP
#define DTOCAPITOL_HPP

#include <string>
#include <ctime>

#include "../../definitions.hpp"

struct DTOCapitol {
    std::string titol;
    std::string qualificacio;
    int num_temporada;
    int num_capitol;
    int num_visualitzacions;
    time_t data;
};

#endif
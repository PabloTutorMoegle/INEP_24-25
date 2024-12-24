#ifndef DTOPELICULA_HPP
#define DTOPELICULA_HPP

#include <string>
#include <chrono>

#include "../../definitions.hpp"

struct DTOPelicula {
    std::string titol;
    std::string info;
    std::string qualificacio;
    std::time_t data_estrena;
};

#endif
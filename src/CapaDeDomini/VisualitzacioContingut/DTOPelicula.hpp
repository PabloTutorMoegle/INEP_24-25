#ifndef DTOPELICULA_HPP
#define DTOPELICULA_HPP

#include <string>
#include <ctime> 

#include "../../definitions.hpp"

struct DTOPelicula {
    std::string titol;
    std::string descripcio;
    std::string qualificacio;
    time_t data_estrena;
    int duracio;
};

#endif // DTOPELICULA_HPP
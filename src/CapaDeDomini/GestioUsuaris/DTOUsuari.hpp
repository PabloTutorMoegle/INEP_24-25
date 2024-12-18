#include <string>
#include <chrono>

#include "../../definitions.hpp"

struct DTOUsuari {
    std::string sobrenom;
    std::string nom;
    std::string correu_electronic;
    std::time_t data_naixement;
    ModalitatSubscripcio modalitat_subscripcio;
};

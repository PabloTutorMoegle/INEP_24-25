#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MODALITAT_COMPLETA "completa"
#define MODALITAT_CINEFIL "cinefil"
#define MODALITAT_INFANTIL "infantil"
enum ModalitatSubscripcio {
    Completa,
    Cinefil,
    Infantil,
};

#include <chrono>
#include <string>
#include <iomanip>
time_t time_t_from_string(std::string datetime);

std::string time_t_to_datetime_string(time_t datetime);

ModalitatSubscripcio modalitat_subscripcio_from_string(std::string modalitat);

std::string modalitat_subscripcio_to_string(ModalitatSubscripcio modalitat);

#endif

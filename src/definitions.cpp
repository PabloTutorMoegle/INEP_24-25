#include "definitions.hpp"

time_t time_t_from_string(std::string datetime) {
    tm tm = {};
    std::istringstream ss(datetime);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    
    if (ss.fail()) {
        throw "No s'ha pogut convertir usu_data_naixement a una data";
    } else {
        return mktime(&tm);
    }
}

std::string time_t_to_datetime_string(time_t datetime) {
    std::tm tm_info;
    
    // C++ sucks so mutch it doesn't have safe definitions for all platforms it supports
    #ifdef _WIN32
    localtime_s(&tm_info, &datetime); 
    #else
    localtime_r(&datetime, &tm_info);
    #endif

    std::ostringstream oss;
    oss << std::put_time(&tm_info, "%Y-%m-%d %H:%M:%S");
    
    return oss.str();
}

ModalitatSubscripcio modalitat_subscripcio_from_string(std::string modalitat) {
    std::string cleaned;
    for (char c : modalitat) {
        if (std::isalpha(c)) {
            cleaned += std::tolower(c);
        }
    }

    if (cleaned == MODALITAT_COMPLETA) {
        return ModalitatSubscripcio::Completa;
    } else if (cleaned == MODALITAT_CINEFIL) {
        return ModalitatSubscripcio::Cinefil;
    } else if (cleaned == MODALITAT_INFANTIL) {
        return ModalitatSubscripcio::Infantil;
    } else {
        throw "No s'ha pogut convertir la modalitat de subscripcó a un tipus vàlid";
    }
}

std::string modalitat_subscripcio_to_string(ModalitatSubscripcio modalitat) {
    switch (modalitat) {
        case ModalitatSubscripcio::Completa:
            return MODALITAT_COMPLETA;
        case ModalitatSubscripcio::Cinefil:
            return MODALITAT_CINEFIL;
        case ModalitatSubscripcio::Infantil:
            return MODALITAT_INFANTIL;
    }
    return ""; // Unreachable
}

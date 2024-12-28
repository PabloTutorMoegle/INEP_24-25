#include "TxVisualitzarPelicula.hpp"

TxVisualitzarPelicula::TxVisualitzarPelicula() {
    _resultat = std::nullopt;
}

TxVisualitzarPelicula::~TxVisualitzarPelicula() {}

void TxVisualitzarPelicula::buscar(string titol_pelicula) 
{
    PasarelaVisualitzarPelicula visualitzacio = CercadoraVisualitzarPelicula::obte_dades_pelicula(titol_pelicula);

    _resultat = DTOPelicula {
        .titol = visualitzacio.obte_titol_pelicula(),
        .descripcio = visualitzacio.obte_descripcio(),
        .qualificacio = visualitzacio.obte_qualificacio(),
        .data_estrena = visualitzacio.obte_data(),
        .duracio = visualitzacio.obte_duracio()
    };

    return;
}

void TxVisualitzarPelicula::executar(string titol_pelicula) 
{
    PasarelaVisualitzarPelicula visualitzacio = CercadoraVisualitzarPelicula::obte_dades_pelicula(titol_pelicula);
    
    //modificar la data de visualitzacio
    time_t data = time(0);
    visualitzacio.modifica_data(data);
    
    visualitzacio.insereix();

    _resultat = DTOPelicula {
        .titol = visualitzacio.obte_titol_pelicula(),
        .descripcio = visualitzacio.obte_descripcio(),
        .qualificacio = visualitzacio.obte_qualificacio(),
        .data_estrena = visualitzacio.obte_data(),
        .duracio = visualitzacio.obte_duracio()
    };

    return;
}

void TxVisualitzarPelicula::buscar_visualitzacions(string sobrenom_usuari) 
{
    vector<PasarelaVisualitzarPelicula> visualitzacions = CercadoraVisualitzarPelicula::obte_visualitzacions(sobrenom_usuari);
    for (auto visualitzacio : visualitzacions) {
        _resultat = DTOPelicula {
            .titol = visualitzacio.obte_titol_pelicula(),
            .descripcio = visualitzacio.obte_descripcio(),
            .qualificacio = visualitzacio.obte_qualificacio(),
            .data_estrena = visualitzacio.obte_data(),
            .duracio = visualitzacio.obte_duracio(),
            .nb_visualitzacions = visualitzacio.obte_num_visualitzacions()
        };
    }

    return;
}

DTOPelicula TxVisualitzarPelicula::obte_resultat() const 
{
    if (_resultat) {
        return *_resultat;
    } else {
        throw "No s'ha executat la transacció!";
    }
}

vector<DTOPelicula> TxVisualitzarPelicula::obte_resultats() const 
{
    vector<DTOPelicula> resultats;

    if (_resultat) {
        resultats.push_back(*_resultat);
    } else {
        throw "No s'ha executat la transacció!";
    }

    return resultats;
}

vector<DTOPelicula> TxVisualitzarPelicula::pelicula_relacionada(string titol_pelicula) 
{
    vector<DTOPelicula> resultats;

    //buscar pelicules relacionades
    vector<string> relacionades = CercadoraVisualitzarPelicula::cerca_relacionades(titol_pelicula);
    
    for (auto relacionada : relacionades) {
        PasarelaVisualitzarPelicula visualitzacio = CercadoraVisualitzarPelicula::obte_dades_pelicula(relacionada);

        resultats.push_back(DTOPelicula {
            .titol = visualitzacio.obte_titol_pelicula(),
            .descripcio = visualitzacio.obte_descripcio(),
            .qualificacio = visualitzacio.obte_qualificacio(),
            .data_estrena = visualitzacio.obte_data(),
            .duracio = visualitzacio.obte_duracio()
        });
    }
    
    return resultats;
}
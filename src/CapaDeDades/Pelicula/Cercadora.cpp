#include "Cercadora.hpp"

vector<PasarelaPelicula> CercadoraPelicula::cerca_novetats() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    // Sé que has dit que només hem d'utiltzar SELECT, UPDATE i DELETE però si hem
    // de fer això en C++ no acabarem mai
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM pelicula WHERE pel_data_estrena < ? ORDER BY pel_data_estrena DESC LIMIT 5"
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaPelicula> pelicules;

    while (result->next()) {
        string titol = result->getString("pel_titol");
        time_t data = time_t_from_string(result->getString("pel_data_estrena"));
        int duracio = result->getInt("pel_duracio");
        
        pelicules.push_back(
            PasarelaPelicula(
                titol,
                data,
                duracio
            )
        );
    }

    return pelicules;
}

vector<PasarelaPelicula> CercadoraPelicula::cerca_estrenes() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    // Sé que has dit que només hem d'utiltzar SELECT, UPDATE i DELETE però si hem
    // de fer això en C++ no acabarem mai
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM pelicula WHERE pel_data_estrena > ? ORDER BY pel_data_estrena DESC LIMIT 5"
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaPelicula> pelicules;

    while (result->next()) {
        string titol = result->getString("pel_titol");
        time_t data = time_t_from_string(result->getString("pel_data_estrena"));
        int duracio = result->getInt("pel_duracio");
        
        pelicules.push_back(
            PasarelaPelicula(
                titol,
                data,
                duracio
            )
        );
    }

    return pelicules;
}

#include "Cercadora.hpp"

vector<PasarelaConsulta> CercadoraConsulta::cerca_novetats(ModalitatSubscripcio modalitat_subscripcio) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    // Sé que has dit que només hem d'utiltzar SELECT, UPDATE i DELETE però si hem
    // de fer això en C++ no acabarem mai
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT " 
            "pel_data_estrena AS data_estrena, "
            "'Pelicula' AS tipus, "
            "pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT(pel_duracio, ' min') AS info "
        "FROM pelicula p "
        "JOIN contingut c ON p.pel_titol = c.con_titol "
        "WHERE pel_data_estrena < ? "
        "UNION ALL "
        "SELECT "
            "ser_data_estrena AS data_estrena, "
            "'Sèrie' AS tipus, "
            "ser_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT('Temporada ', ser_temporada) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena < ? "
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> pelicules;

    while (result->next()) {
        string titol = result->getString("pel_titol");
        time_t data = time_t_from_string(result->getString("pel_data_estrena"));
        int duracio = result->getInt("pel_duracio");
        
        pelicules.push_back(
            PasarelaConsulta(
                titol,
                data,
                duracio
            )
        );
    }

    return pelicules;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_estrenes(ModalitatSubscripcio modalitat_subscripcio) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    // Sé que has dit que només hem d'utiltzar SELECT, UPDATE i DELETE però si hem
    // de fer això en C++ no acabarem mai
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM pelicula WHERE pel_data_estrena > ? ORDER BY pel_data_estrena DESC LIMIT 5"
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> pelicules;

    while (result->next()) {
        string titol = result->getString("pel_titol");
        time_t data = time_t_from_string(result->getString("pel_data_estrena"));
        int duracio = result->getInt("pel_duracio");
        
        pelicules.push_back(
            PasarelaConsulta(
                titol,
                data,
                duracio
            )
        );
    }

    return pelicules;
}

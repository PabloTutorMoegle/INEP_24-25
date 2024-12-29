#include "Cercadora.hpp"

vector<PasarelaConsulta> CercadoraConsulta::cerca_novetats_completa() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
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
            "CONCAT('Temporada ', tem_numero) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena < ? "
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));
    pstmt->setString(2, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> continguts;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        continguts.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return continguts;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_novetats_cinefil() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
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
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> continguts;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        continguts.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return continguts;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_novetats_infantil() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT " 
            "pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT(pel_duracio, ' min') AS info "
        "FROM pelicula p "
        "JOIN contingut c ON p.pel_titol = c.con_titol "
        "WHERE pel_data_estrena < ? AND c.con_qualificacio = 'TP'"
        "UNION ALL "
        "SELECT "
            "ser_data_estrena AS data_estrena, "
            "'Sèrie' AS tipus, "
            "ser_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT('Temporada ', tem_numero) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena < ? AND c.con_qualificacio = 'TP'"
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));
    pstmt->setString(2, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> pelicules;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        pelicules.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return pelicules;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_estrenes_completa() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT " 
            "pel_data_estrena AS data_estrena, "
            "'Pelicula' AS tipus, "
            "pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT(pel_duracio, ' min') AS info "
        "FROM pelicula p "
        "JOIN contingut c ON p.pel_titol = c.con_titol "
        "WHERE pel_data_estrena > ? "
        "UNION ALL "
        "SELECT "
            "ser_data_estrena AS data_estrena, "
            "'Sèrie' AS tipus, "
            "ser_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT('Temporada ', tem_numero) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena > ? "
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));
    pstmt->setString(2, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> continguts;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        continguts.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return continguts;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_estrenes_cinefil() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT " 
            "pel_data_estrena AS data_estrena, "
            "'Pelicula' AS tipus, "
            "pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT(pel_duracio, ' min') AS info "
        "FROM pelicula p "
        "JOIN contingut c ON p.pel_titol = c.con_titol "
        "WHERE pel_data_estrena > ? "
        "UNION ALL "
        "SELECT "
            "ser_data_estrena AS data_estrena, "
            "'Sèrie' AS tipus, "
            "ser_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT('Temporada ', tem_numero) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena > ? "
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));
    pstmt->setString(2, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> continguts;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        continguts.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return continguts;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_estrenes_infantil() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    time_t current_time = time(nullptr);
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT " 
            "pel_data_estrena AS data_estrena, "
            "'Pelicula' AS tipus, "
            "pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT(pel_duracio, ' min') AS info "
        "FROM pelicula p "
        "JOIN contingut c ON p.pel_titol = c.con_titol "
        "WHERE pel_data_estrena > ? AND c.con_qualificacio = 'TP'"
        "UNION ALL "
        "SELECT "
            "ser_data_estrena AS data_estrena, "
            "'Sèrie' AS tipus, "
            "ser_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "CONCAT('Temporada ', ser_temporada) AS info "
        "FROM serie s "
        "JOIN contingut c ON s.ser_titol = c.con_titol "
        "WHERE ser_data_estrena > ? AND c.con_qualificacio = 'TP'"
        "ORDER BY data_estrena DESC " 
        "LIMIT 5 "
    );

    pstmt->setString(1, time_t_to_datetime_string(current_time));
    pstmt->setString(2, time_t_to_datetime_string(current_time));

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> pelicules;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string tipus = result->getString("tipus");
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        string info = result->getString("info");
        
        pelicules.push_back(
            PasarelaConsulta(
                data,
                tipus,
                titol,
                qualificacio,
                info
            )
        );
    }

    return pelicules;
}

vector<PasarelaConsulta> CercadoraConsulta::cerca_mes_vistes() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT "
            "pel.pel_data_estrena AS data_estrena, "
            "pel.pel_titol AS titol, "
            "c.con_qualificacio AS qualificacio, "
            "SUM(vip.vip_nb_visualitzacions) AS visualitzacions, "
            "pel_duracio AS duracio "
        "FROM "
            "pelicula pel "
        "JOIN "
            "contingut c ON pel.pel_titol = c.con_titol "
        "JOIN "
            "visualitzacio_pelicula vip ON pel.pel_titol = vip.vip_titol_pelicula "
        "GROUP BY "
            "pel.pel_titol "
        "ORDER BY "
            "visualitzacions DESC "
        "LIMIT 5"
    );

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaConsulta> continguts;

    while (result->next()) {
        time_t data = time_t_from_string(result->getString("data_estrena"));
        string titol = result->getString("titol");
        string qualificacio = result->getString("qualificacio");
        int visualitzacions_totals = result->getInt("visualitzacions");
        int duracio = result->getInt("duracio");
        
        string info = std::to_string(duracio) + " min.; Visualitzacions: " + std::to_string(visualitzacions_totals);
        
        continguts.push_back(
            PasarelaConsulta(
                data,
                "",
                titol,
                qualificacio,
                info
            )
        );
    }

    return continguts;
}

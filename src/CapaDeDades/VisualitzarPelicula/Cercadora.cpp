#include "Cercadora.hpp"

vector<PasarelaVisualitzarPelicula> CercadoraVisualitzarPelicula::cerca_per_sobrenom(string sobrenom_usuari) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM visualitzacio_capitol WHERE vic_sobrenom_usuari = ?"
    );
    pstmt->setString(1, sobrenom_usuari);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaVisualitzarPelicula> visualitzacions_pelicula;

    /*while (result->next()) {
        string sobrenom = result->getString("vip_sobrenom_usuari");
        string titol_pelicula = result->getString("vip_titol_pelicula");
        time_t data = time_t_from_string(result->getString("vip_data"));
        int nb_visualitzacions = result->getInt("vip_nb_visualitzacions");
        
        visualitzacions_pelicula.push_back(
            PasarelaVisualitzarPelicula(
                sobrenom, 
                titol_pelicula, 
                nb_visualitzacions,
                data
            )
        );
    }*/

    return visualitzacions_pelicula;
}

PasarelaVisualitzarPelicula CercadoraVisualitzarPelicula::obte_dades_pelicula(string titol_pelicula) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    PetitFlix* petitFlix = PetitFlix::get_instance();
    string sobrenom_usuari = petitFlix->obte_usuari()->obte_sobrenom();
    
    unique_ptr<PreparedStatement> pstmt1 = connexio_bdd->get_prepared_statement(
        "SELECT * FROM contingut WHERE con_titol = ? AND con_tipus = 'Pelicula'"
    );
    pstmt1->setString(1, titol_pelicula);

    unique_ptr<ResultSet> result1(pstmt1->executeQuery());

    string titol, descripcio, qualificacio;

    if(result1->next()) {
        titol = result1->getString("con_titol");
        descripcio = result1->getString("con_descripcio");
        qualificacio = result1->getString("con_qualificacio");
    }

    unique_ptr<PreparedStatement> pstmt2 = connexio_bdd->get_prepared_statement(
        "SELECT * FROM pelicula WHERE pel_titol = ?"
    );
    pstmt2->setString(1, titol_pelicula);

    unique_ptr<ResultSet> result2(pstmt2->executeQuery());

    time_t data;
    int duracio;

    if(result2->next())
    {
        data = time_t_from_string(result2->getString("pel_data_estrena"));
        duracio = result2->getInt("pel_duracio");
    }
    
    return PasarelaVisualitzarPelicula(titol, descripcio, qualificacio, data, duracio, sobrenom_usuari, 0);
}

vector<string> CercadoraVisualitzarPelicula::cerca_relacionades(string titol_pelicula) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT p.pel_titol FROM pelicula p "
        "JOIN relacionat r ON p.pel_titol = r.rel_titol_y "
        "WHERE r.rel_titol_x = ? "
        "UNION "
        "SELECT p.pel_titol FROM pelicula p "
        "JOIN relacionat r ON p.pel_titol = r.rel_titol_x "
        "WHERE r.rel_titol_y = ?"
    );

    pstmt->setString(1, titol_pelicula);
    pstmt->setString(2, titol_pelicula);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<string> titols_relacionats;

    while (result->next()) {
        string titol = result->getString("pel_titol");
        titols_relacionats.push_back(titol);
    }

    return titols_relacionats;
}

vector<PasarelaVisualitzarPelicula> CercadoraVisualitzarPelicula::obte_visualitzacions(string sobrenom_usuari) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM visualitzacio_pelicula WHERE vip_sobrenom_usuari = ?"
    );
    pstmt->setString(1, sobrenom_usuari);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    unique_ptr<PreparedStatement> pstmt2 = connexio_bdd->get_prepared_statement(
        "SELECT * FROM contingut WHERE con_titol = ?"
    );

    unique_ptr<PreparedStatement> pstmt3 = connexio_bdd->get_prepared_statement(
        "SELECT * FROM pelicula WHERE pel_titol = ?"
    );

    vector<PasarelaVisualitzarPelicula> visualitzacions_pelicula;

    while (result->next()) {
        string titol_pelicula = result->getString("vip_titol_pelicula");

        pstmt2->setString(1, titol_pelicula);
        unique_ptr<ResultSet> result2(pstmt2->executeQuery());

        pstmt3->setString(1, titol_pelicula);
        unique_ptr<ResultSet> result3(pstmt3->executeQuery());

        if (!result2->next() || !result3->next()) {
            continue;
        }

        string sobrenom = result->getString("vip_sobrenom_usuari");
        time_t data = time_t_from_string(result->getString("vip_data"));
        int nb_visualitzacions = result->getInt("vip_nb_visualitzacions");
        string descripcio = result2->getString("con_descripcio");
        string qualificacio = result2->getString("con_qualificacio");
        int duracio = result3->getInt("pel_duracio");
        
        visualitzacions_pelicula.push_back(
            PasarelaVisualitzarPelicula(
                titol_pelicula,
                descripcio,
                qualificacio,
                data,
                duracio,
                sobrenom,
                nb_visualitzacions
            )
        );
    }

    return visualitzacions_pelicula;
}

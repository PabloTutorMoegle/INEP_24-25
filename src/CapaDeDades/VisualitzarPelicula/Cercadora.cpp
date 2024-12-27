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
    
    return PasarelaVisualitzarPelicula(titol, descripcio, qualificacio, data, duracio);
}

vector<PasarelaVisualitzarPelicula> CercadoraVisualitzarPelicula::cerca_relacionades(string titol_pelicula) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT rel_titol_x FROM relacionat WHERE rel_titol_y = ? UNION SELECT rel_titol_y FROM relacionat WHERE rel_titol_x = ?"
    );
    pstmt->setString(1, titol_pelicula);
    pstmt->setString(2, titol_pelicula);
    pstmt->setString(1, titol_pelicula);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<string> titols_relacionats;

    while (result->next()) {
        titols_relacionats.push_back(result->getString("rel_titol_y"));
    }

    vector<PasarelaVisualitzarPelicula> pelicules_relacionades;

    for (const string& titol_relacionat : titols_relacionats) {
        unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
            "SELECT * FROM pelicula WHERE pel_titol = ?"
        );
        pstmt->setString(1, titol_relacionat);

        unique_ptr<ResultSet> result(pstmt->executeQuery());

        if (result->next()) {
            string titol = result->getString("pel_titol");
            string descripcio = result->getString("pel_info");
            string qualificacio = result->getString("pel_qualificacio");
            time_t data = time_t_from_string(result->getString("pel_data_estrena"));
            int duracio = result->getInt("pel_duracio");

            pelicules_relacionades.push_back(
                PasarelaVisualitzarPelicula(
                    titol, 
                    descripcio, 
                    qualificacio,
                    data,
                    duracio
                )
            );
        }
    }

    return pelicules_relacionades;
}
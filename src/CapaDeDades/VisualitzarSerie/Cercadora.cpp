#include "Cercadora.hpp"

vector<PasarelaVisualitzarSerie> CercadoraVisualitzarSerie::cerca_per_sobrenom(string sobrenom_usuari) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM visualitzacio_capitol WHERE vic_sobrenom_usuari = ?"
    );
    pstmt->setString(1, sobrenom_usuari);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM capitol WHERE cap_titol_serie = ? AND cap_numero_temporada = ? AND cap_numero = ?"
    );

    vector<PasarelaVisualitzarSerie> visualitzacions_serie;

    while (result->next()) {

        pstmt->setString(1, result->getString("vic_titol_serie"));
        pstmt->setInt(2, result->getInt("vic_num_temporada"));
        pstmt->setInt(3, result->getInt("vic_num_capitol"));

        unique_ptr<ResultSet> result2(pstmt->executeQuery());

        if (!result2->next()) {
            continue;
        }

        string sobrenom = result->getString("vic_sobrenom_usuari");
        string titol_serie = result->getString("vic_titol_serie");
        string qualificacio = result2->getString("cap_qualificacio");
        int num_temporada = result->getInt("vic_num_temporada");
        int num_capitol = result->getInt("vic_num_capitol");
        time_t data = time_t_from_string(result->getString("vic_data"));
        int nb_visualitzacions = result->getInt("vic_nb_visualitzacions");
        
        visualitzacions_serie.push_back(
            PasarelaVisualitzarSerie(
                sobrenom, 
                titol_serie, 
                qualificacio,
                nb_visualitzacions, 
                num_temporada, 
                num_capitol, 
                data
            )
        );
    }

    return visualitzacions_serie;
}

PasarelaVisualitzarSerie CercadoraVisualitzarSerie::obte_dades_capitol(string titol_serie, int num_temporada, int num_capitol) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM capitol WHERE cap_titol_serie = ? AND cap_numero_temporada = ? AND cap_numero = ?"
    );
    pstmt->setString(1, titol_serie);
    pstmt->setInt(2, num_temporada);
    pstmt->setInt(3, num_capitol);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    if (!result->next()) {
        throw "Capitol no trobat";
    }

    string qualificacio = result->getString("cap_qualificacio");

    return PasarelaVisualitzarSerie(
        "", 
        titol_serie, 
        qualificacio,
        0, 
        num_temporada, 
        num_capitol, 
        time(0)
    );
}

int CercadoraVisualitzarSerie::obte_num_temporades(string titol_serie) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT MAX(cap_numero_temporada) FROM capitol WHERE cap_titol_serie = ?"
    );
    pstmt->setString(1, titol_serie);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    if (!result->next()) {
        throw "Serie no trobada";
    }

    return result->getInt(1);
}

vector<PasarelaVisualitzarSerie> CercadoraVisualitzarSerie::obte_capitols(string titol_serie, int num_temporada) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM capitol WHERE cap_titol_serie = ? AND cap_numero_temporada = ?"
    );
    pstmt->setString(1, titol_serie);
    pstmt->setInt(2, num_temporada);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaVisualitzarSerie> capitols;

    while (result->next()) {
        string qualificacio = result->getString("cap_qualificacio");
        int num_capitol = result->getInt("cap_numero");
        time_t data = time_t_from_string(result->getString("cap_data_estrena"));

        capitols.push_back(
            PasarelaVisualitzarSerie(
                "", 
                titol_serie, 
                qualificacio,
                0, 
                num_temporada, 
                num_capitol, 
                data
            )
        );
    }

    return capitols;
}
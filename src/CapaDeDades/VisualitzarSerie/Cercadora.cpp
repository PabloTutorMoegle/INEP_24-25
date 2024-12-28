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
                num_temporada, 
                num_temporada, 
                num_capitol, 
                data
            )
        );
    }

    return visualitzacions_serie;
}

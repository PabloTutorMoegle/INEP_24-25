#include "Cercadora.hpp"

vector<PasarelaVisualitzarPelicula> CercadoraVisualitzarPelicula::cerca_per_sobrenom(string sobrenom_usuari) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM visualitzacio_capitol WHERE vic_sobrenom_usuari = ?"
    );
    pstmt->setString(1, sobrenom_usuari);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    vector<PasarelaVisualitzarPelicula> visualitzacions_pelicula;

    while (result->next()) {
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
    }

    return visualitzacions_pelicula;
}

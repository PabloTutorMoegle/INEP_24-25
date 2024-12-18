#include "Cercadora.hpp"

PasarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenom) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    unique_ptr<PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "SELECT * FROM usuari WHERE usu_sobrenom = ?"
    );
    pstmt->setString(1, sobrenom);

    unique_ptr<ResultSet> result(pstmt->executeQuery());

    if (result->next()) {
        string sobrenom = result->getString("usu_sobrenom");
        string nom = result->getString("usu_nom");
        string contrasenya = result->getString("usu_contrasenya");
        string correu_electronic = result->getString("usu_correu_electronic");
        time_t data_naixement = time_t_from_string(result->getString("usu_data_naixement"));
        ModalitatSubscripcio modalitat_subscripcio = modalitat_subscripcio_from_string(result->getString("usu_modalitat_subscripcio"));
        
        return PasarelaUsuari(sobrenom, nom, contrasenya, correu_electronic, data_naixement, modalitat_subscripcio);
    } else {
        throw "No existeix l'usuari";
    }
}

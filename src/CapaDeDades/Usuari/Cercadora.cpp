#include "Cercadora.hpp"

PasarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenom) {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    string query = "SELECT * FROM usuari WHERE usu_sobrenom = '" + sobrenom + "'";

    unique_ptr<ResultSet> result = connexio_bdd->execute_query(query);

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

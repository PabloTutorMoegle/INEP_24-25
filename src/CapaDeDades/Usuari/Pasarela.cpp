#include "Pasarela.hpp"

PasarelaUsuari::PasarelaUsuari(
    string sobrenom, 
    string nom, 
    string contrasenya, 
    string correu_electronic, 
    time_t data_naixement, 
    ModalitatSubscripcio modalitat_subscripcio
) {
    _sobrenom = sobrenom;
    _nom = nom;
    _contrasenya = contrasenya;
    _correu_electronic = correu_electronic;
    _data_naixement = data_naixement;
    _modalitat_subscripcio = modalitat_subscripcio;
}

void PasarelaUsuari::insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO usuari ("
            "usu_sobrenom,"
            "usu_nom," 
            "usu_contrasenya," 
            "usu_correu_electronic," 
            "usu_data_naixement," 
            "usu_modalitat_subscripcio"
        ") VALUES (?, ?, ?, ?, ?, ?)"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _nom);
    pstmt->setString(3, _contrasenya);
    pstmt->setString(4, _correu_electronic);
    pstmt->setString(5, time_t_to_datetime_string(_data_naixement));
    pstmt->setString(6, modalitat_subscripcio_to_string(_modalitat_subscripcio));

    pstmt->executeUpdate();
}

void PasarelaUsuari::modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE usuari SET "
        "usu_nom = ?, "
        "usu_contrasenya = ?, "
        "usu_correu_electronic = ?, "
        "usu_data_naixement = ?, "
        "usu_modalitat_subscripcio = ? "
        "WHERE usu_sobrenom = ?");

    pstmt->setString(1, _nom);
    pstmt->setString(2, _contrasenya);
    pstmt->setString(3, _correu_electronic);
    pstmt->setString(4, time_t_to_datetime_string(_data_naixement));
    pstmt->setString(5, modalitat_subscripcio_to_string(_modalitat_subscripcio));
    pstmt->setString(6, _sobrenom);

    pstmt->executeUpdate();
}

void PasarelaUsuari::esborra() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM usuari WHERE usu_sobrenom = ?"
    );

    pstmt->setString(1, _sobrenom);

    pstmt->executeUpdate();
}

string PasarelaUsuari::obte_sobrenom() {
    return _sobrenom;
}

string PasarelaUsuari::obte_nom() {
    return _nom;
}

string PasarelaUsuari::obte_contrasenya() {
    return _contrasenya;
}

string PasarelaUsuari::obte_correu_electronic() {
    return _correu_electronic;
}

time_t PasarelaUsuari::obte_data_naixement() {
    return _data_naixement;
}

ModalitatSubscripcio PasarelaUsuari::obte_modalitat_subscripcio() {
    return _modalitat_subscripcio;
}

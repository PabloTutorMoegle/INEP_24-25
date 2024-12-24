#include "Pasarela.hpp"

PasarelaVisualitzarPelicula::PasarelaVisualitzarPelicula(
    string sobrenom,
    string titol_pelicula,
    int nb_visualitzacions,
    time_t data
) {
    _sobrenom = sobrenom;
    _titol_pelicula = titol_pelicula;
    _nb_visualitzacions = nb_visualitzacions;
    _data = data;
}

PasarelaVisualitzarPelicula::~PasarelaVisualitzarPelicula() {}

void PasarelaVisualitzarPelicula::insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO visualitzacio_pelicula ("
            "vip_sobrenom_usuari,"
            "vip_titol_pelicula,"
            "vip_data,"
            "vip_nb_vicialitzacions,"
        ") VALUES (?, ?, ?, ?)"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _titol_pelicula);
    pstmt->setString(3, time_t_to_datetime_string(_data));
    pstmt->setInt(4, _nb_visualitzacions);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarPelicula::modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE visualitzacio_pelicula SET "
        "vip_titol_pelicula = ?, "
        "vip_data = ?, "
        "vip_nb_vicialitzacions = ?, "
        "WHERE vip_sobrenom_usuari = ?"
    );

    pstmt->setString(1, _titol_pelicula);
    pstmt->setString(4, time_t_to_datetime_string(_data));
    pstmt->setInt(5, _nb_visualitzacions);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarPelicula::esborra() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM visualitzacio_pelicula WHERE vic_sobrenom = ? AND vip_titol_pelicula = ?"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _titol_pelicula);

    pstmt->executeUpdate();
}

unsigned int PasarelaVisualitzarPelicula::obte_num_visualitzacions() {
    return _nb_visualitzacions;
}

string PasarelaVisualitzarPelicula::obte_sobrenom() const {
    return _sobrenom;
}

string PasarelaVisualitzarPelicula::obte_titol_pelicula() const {
    return _titol_pelicula;
}

time_t PasarelaVisualitzarPelicula::obte_data() const {
    return _data;
}


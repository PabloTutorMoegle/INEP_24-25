#include "Pasarela.hpp"

PasarelaVisualitzarSerie::PasarelaVisualitzarSerie(
    string sobrenom,
    string titol_serie,
    string qualificacio,
    int nb_visualitzacions,
    int num_temporada,
    int num_capitol,
    time_t data
) {
    _sobrenom = sobrenom;
    _titol_serie = titol_serie;
    _qualificacio = qualificacio;
    _nb_visualitzacions = nb_visualitzacions;
    _num_temporada = num_temporada;
    _num_capitol = num_capitol;
    _data = data;
}

PasarelaVisualitzarSerie::~PasarelaVisualitzarSerie() {}

void PasarelaVisualitzarSerie::insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO visualitzacio_capitol ("
            "vic_sobrenom_usuari,"
            "vic_titol_serie,"
            "vic_num_temporada,"
            "vic_num_capitol,"
            "vic_data,"
            "vic_nb_vicialitzacions,"
        ") VALUES (?, ?, ?, ?, ?, ?)"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _titol_serie);
    pstmt->setInt(3, _num_temporada);
    pstmt->setInt(4, _num_capitol);
    pstmt->setString(5, time_t_to_datetime_string(_data));
    pstmt->setInt(6, _nb_visualitzacions);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE visualitzacio_capitol SET "
        "vic_titol_serie = ?, "
        "vic_num_temporada = ?, "
        "vic_num_capitol = ?, "
        "vic_data = ?, "
        "vic_nb_vicialitzacions = ?, "
        "WHERE vic_sobrenom_usuari = ?"
    );

    pstmt->setString(1, _titol_serie);
    pstmt->setInt(1, _num_temporada);
    pstmt->setInt(2, _num_capitol);
    pstmt->setString(4, time_t_to_datetime_string(_data));
    pstmt->setInt(5, _nb_visualitzacions);
    pstmt->setString(6, _sobrenom);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::esborra() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM visualitzacio_capitol WHERE vic_sobrenom = ? AND vic_titol_serie = ? AND vic_num_temporada = ? AND vic_num_capitol = ?"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _titol_serie);
    pstmt->setInt(3, _num_temporada);
    pstmt->setInt(4, _num_capitol);

    pstmt->executeUpdate();
}

string PasarelaVisualitzarSerie::obte_sobrenom() {
    return _sobrenom;
}

string PasarelaVisualitzarSerie::obte_titol_serie() {
    return _titol_serie;
}

string PasarelaVisualitzarSerie::obte_qualificacio() {
    return _qualificacio;
}

int PasarelaVisualitzarSerie::obte_nb_visualitzacions() {
    return _nb_visualitzacions;
}

int PasarelaVisualitzarSerie::obte_num_temporada() {
    return _num_temporada;
}   

int PasarelaVisualitzarSerie::obte_num_capitol() {
    return _num_capitol;
}

time_t PasarelaVisualitzarSerie::obte_data() {
    return _data;
}

#include "Pasarela.hpp"

PasarelaVisualitzarSerie::PasarelaVisualitzarSerie(
    string sobrenom,
    string titolSerie,
    int numVicialitzacions,
    int numTemporada,
    int numCapitol,
    time_t data,
    ModalitatSubscripcio modalitat_subscripcio
) {
    _sobrenom = sobrenom;
    _titol_serie = titolSerie;
    _num_visualitzacions = numVicialitzacions;
    _num_temporada = numTemporada;
    _num_capitol = numCapitol;
    _data = data;
    _modalitat_subscripcio = modalitat_subscripcio;
}

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
    pstmt->setInt(6, _num_visualitzacions);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE visualitzacio_capitol SET "
        "vis_titol_serie = ?, "
        "vis_num_vicialitzacions = ?, "
        "vis_num_temporada = ?, "
        "vis_num_capitol = ?, "
        "vis_data = ?, "
        "WHERE vis_sobrenom = ?" // TODO: Arreglar ordre i noms
    );

    pstmt->setString(1, _titol_serie);
    pstmt->setInt(2, _num_visualitzacions);
    pstmt->setInt(3, _num_temporada);
    pstmt->setInt(4, _num_capitol);
    pstmt->setString(5, time_t_to_datetime_string(_data));
    pstmt->setString(6, modalitat_subscripcio_to_string(_modalitat_subscripcio));
    pstmt->setString(7, _sobrenom); // TODO arreglar setStrings i ordre

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::esborra() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM visualitzacio_capitol WHERE vic_sobrenom = ?"
    );

    pstmt->setString(1, _sobrenom);

    pstmt->executeUpdate();
}

string PasarelaVisualitzarSerie::obte_sobrenom() {
    return _sobrenom;
}

string PasarelaVisualitzarSerie::obte_titol_serie() {
    return _titol_serie;
}

int PasarelaVisualitzarSerie::obte_num_visualitzacions() {
    return _num_visualitzacions;
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

ModalitatSubscripcio PasarelaVisualitzarSerie::obte_modalitat_subscripcio() {
    return _modalitat_subscripcio;
}

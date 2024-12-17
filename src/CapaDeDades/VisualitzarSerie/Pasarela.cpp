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
    _titolSerie = titolSerie;
    _numVicialitzacions = numVicialitzacions;
    _numTemporada = numTemporada;
    _numCapitol = numCapitol;
    _data = data;
    _modalitat_subscripcio = modalitat_subscripcio;
}

void PasarelaVisualitzarSerie::Insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO visualitzar_serie ("
            "vis_sobrenom,"
            "vis_titol_serie,"
            "vis_num_vicialitzacions,"
            "vis_num_temporada,"
            "vis_num_capitol,"
            "vis_data,"
            "vis_modalitat_subscripcio"
        ") VALUES (?, ?, ?, ?, ?, ?, ?)"
    );

    pstmt->setString(1, _sobrenom);
    pstmt->setString(2, _titolSerie);
    pstmt->setInt(3, _numVicialitzacions);
    pstmt->setInt(4, _numTemporada);
    pstmt->setInt(5, _numCapitol);
    pstmt->setString(6, time_t_to_datetime_string(_data));
    pstmt->setString(7, modalitat_subscripcio_to_string(_modalitat_subscripcio));

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::Modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE visualitzar_serie SET "
        "vis_titol_serie = ?, "
        "vis_num_vicialitzacions = ?, "
        "vis_num_temporada = ?, "
        "vis_num_capitol = ?, "
        "vis_data = ?, "
        "vis_modalitat_subscripcio = ? "
        "WHERE vis_sobrenom = ?"
    );

    pstmt->setString(1, _titolSerie);
    pstmt->setInt(2, _numVicialitzacions);
    pstmt->setInt(3, _numTemporada);
    pstmt->setInt(4, _numCapitol);
    pstmt->setString(5, time_t_to_datetime_string(_data));
    pstmt->setString(6, modalitat_subscripcio_to_string(_modalitat_subscripcio));
    pstmt->setString(7, _sobrenom);

    pstmt->executeUpdate();
}

void PasarelaVisualitzarSerie::Esborra() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM visualitzar_serie WHERE vis_sobrenom = ?"
    );

    pstmt->setString(1, _sobrenom);

    pstmt->executeUpdate();
}

string PasarelaVisualitzarSerie::ObteSobrenom() {
    return _sobrenom;
}

string PasarelaVisualitzarSerie::ObteTitolSerie() {
    return _titolSerie;
}

int PasarelaVisualitzarSerie::ObteNumVicialitzacions() {
    return _numVicialitzacions;
}

int PasarelaVisualitzarSerie::ObteNumTemporada() {
    return _numTemporada;
}   

int PasarelaVisualitzarSerie::ObteNumCapitol() {
    return _numCapitol;
}

time_t PasarelaVisualitzarSerie::ObteData() {
    return _data;
}

ModalitatSubscripcio PasarelaVisualitzarSerie::ObteModalitatSubscripcio() {
    return _modalitat_subscripcio;
}
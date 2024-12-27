#include "Pasarela.hpp"

PasarelaVisualitzarPelicula::PasarelaVisualitzarPelicula(
    string titol_pelicula,
    string descripcio,
    string qualificacio,
    time_t data,
    int duracio,
    string sobrenom
) {
    _sobrenom = sobrenom;
    _titol_pelicula = titol_pelicula;
    _descripcio = descripcio;
    _qualificacio = qualificacio;
    _data_estrena = data;
    _duracio = duracio;
    _nb_visualitzacions = 1;
}

PasarelaVisualitzarPelicula::~PasarelaVisualitzarPelicula() {}

void PasarelaVisualitzarPelicula::insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    // Obtener la fecha actual
    time_t now = time(0);
    tm* tiempo_local = localtime(&now);
    char fecha[11]; 
    strftime(fecha, 11, "%Y-%m-%d", tiempo_local);
    string fecha_formateada(fecha);

    // Consulta INSERT ... ON DUPLICATE KEY UPDATE
    std::unique_ptr<sql::PreparedStatement> stmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO visualitzacio_pelicula ("
            "vip_sobrenom_usuari,"
            "vip_titol_pelicula,"
            "vip_data,"
            "vip_nb_visualitzacions"
        ") VALUES (?, ?, ?, ?) "
        "ON DUPLICATE KEY UPDATE "
            "vip_nb_visualitzacions = vip_nb_visualitzacions + 1"
    );

    stmt->setString(1, _sobrenom);
    stmt->setString(2, _titol_pelicula);
    stmt->setString(3, fecha_formateada);
    stmt->setInt(4, 1); // Inicialitzar en 1
        
    stmt->executeUpdate();
}

void PasarelaVisualitzarPelicula::modifica() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE visualitzacio_pelicula SET "
        "vip_titol_pelicula = ?, "
        "vip_data = ?, "
        "vip_nb_visualitzacions = ?, "
        "WHERE vip_sobrenom_usuari = ?"
    );

    pstmt->setString(1, _titol_pelicula);
    pstmt->setString(2, time_t_to_datetime_string(_data));
    pstmt->setInt(3, _nb_visualitzacions);

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

void PasarelaVisualitzarPelicula::modifica_data(time_t data) {
    _data = data;
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

string PasarelaVisualitzarPelicula::obte_descripcio() const {
    return _descripcio;
}

string PasarelaVisualitzarPelicula::obte_qualificacio() const {
    return _qualificacio;
}

time_t PasarelaVisualitzarPelicula::obte_data() const {
    return _data_estrena;
}

int PasarelaVisualitzarPelicula::obte_duracio() const {
    return _duracio;
}


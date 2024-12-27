#include "Pasarela.hpp"

PasarelaVisualitzarPelicula::PasarelaVisualitzarPelicula(
    string titol_pelicula,
    string descripcio,
    string qualificacio,
    time_t data,
    int duracio
) {
    _titol_pelicula = titol_pelicula;
    _descripcio = descripcio;
    _qualificacio = qualificacio;
    _data_estrena = data;
    _duracio = duracio;
    _nb_visualitzacions = 0;
}

PasarelaVisualitzarPelicula::~PasarelaVisualitzarPelicula() {}

void PasarelaVisualitzarPelicula::insereix() {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    // Formatear fecha
    tm* tiempo_local = localtime(&_data_estrena);
    char fecha[11]; // Espacio suficiente para "DD/MM/YYYY"
    strftime(fecha, 11, "%Y-%m-%d", tiempo_local);
    string fecha_formateada(fecha);

    // Check if the record already exists
    std::unique_ptr<sql::PreparedStatement> check_stmt = connexio_bdd->get_prepared_statement(
        "SELECT vip_nb_visualitzacions FROM visualitzacio_pelicula WHERE vip_sobrenom_usuari = ? AND vip_titol_pelicula = ?"
    );
    check_stmt->setString(1, _sobrenom);
    check_stmt->setString(2, _titol_pelicula);
    std::unique_ptr<sql::ResultSet> res(check_stmt->executeQuery());

    if (res->next()) {
        // Record exists, update the visualizations count
        int current_visualitzacions = res->getInt("vip_nb_vicialitzacions");
        std::unique_ptr<sql::PreparedStatement> update_stmt = connexio_bdd->get_prepared_statement(
            "UPDATE visualitzacio_pelicula SET vip_nb_visualitzacions = ? WHERE vip_sobrenom_usuari = ? AND vip_titol_pelicula = ?"
        );
        update_stmt->setInt(1, current_visualitzacions + 1);
        update_stmt->setString(2, _sobrenom);
        update_stmt->setString(3, _titol_pelicula);
        update_stmt->executeUpdate();
    } else {
        // Record does not exist, insert a new one
        std::unique_ptr<sql::PreparedStatement> insert_stmt = connexio_bdd->get_prepared_statement(
            "INSERT INTO visualitzacio_pelicula ("
                "vip_sobrenom_usuari,"
                "vip_titol_pelicula,"
                "vip_data,"
                "vip_nb_visualitzacions"
            ") VALUES (?, ?, ?, ?)"
        );
        insert_stmt->setString(1, _sobrenom);
        insert_stmt->setString(2, _titol_pelicula);
        insert_stmt->setString(3, fecha_formateada);
        insert_stmt->setInt(4, _nb_visualitzacions);
        insert_stmt->executeUpdate();
    }
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


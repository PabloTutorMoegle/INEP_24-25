#include "Pasarela.hpp"

PasarelaPelicula::PasarelaPelicula(string titol, time_t data, int duracio) {
    _titol = titol;
    _data_estrena = data;
    _duracio = duracio;
}

PasarelaPelicula::~PasarelaPelicula() {}

void PasarelaPelicula::insereix() const {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "INSERT INTO pelicula ("
            "pel_titol,"
            "pel_data_estrena," 
            "pel_duracio," 
        ") VALUES (?, ?, ?)"
    );

    pstmt->setString(1, _titol);
    pstmt->setString(2, time_t_to_datetime_string(_data_estrena));
    pstmt->setInt(3, _duracio);

    pstmt->executeUpdate();
}

void PasarelaPelicula::modifica() const {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();

    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "UPDATE pelicula SET "
        "pel_data_estrena = ?, "
        "pel_duracio = ?, "
        "WHERE pel_titol = ?");

    pstmt->setString(1, _titol);
    pstmt->setInt(2, _duracio);
    pstmt->setString(3, time_t_to_datetime_string(_data_estrena));

    pstmt->executeUpdate();
}

void PasarelaPelicula::esborra() const {
    ConnexioBDD* connexio_bdd = ConnexioBDD::getInstance();
    
    std::unique_ptr<sql::PreparedStatement> pstmt = connexio_bdd->get_prepared_statement(
        "DELETE FROM pelicula WHERE pel_titol = ?"
    );

    pstmt->setString(1, _titol);

    pstmt->executeUpdate();
}

#include "ConnexioBDD.hpp"

ConnexioBDD* ConnexioBDD::_instance = nullptr;

ConnexioBDD* ConnexioBDD::getInstance() {
    if (_instance == nullptr) {
        _instance = new ConnexioBDD();
    }
    return _instance;
}

void ConnexioBDD::execute(std::string query) {
    _statement->execute(query);
}

std::unique_ptr<ResultSet> ConnexioBDD::execute_query(std::string query) {
    std::unique_ptr<ResultSet> result(_statement->executeQuery(query));
    return result;
}

std::unique_ptr<PreparedStatement> ConnexioBDD::get_prepared_statement(std::string statement) {
    std::unique_ptr<PreparedStatement> pstmt(_connection->prepareStatement(statement));
    return pstmt;
}

ConnexioBDD::ConnexioBDD() {
    std::ifstream env_file(".env");
    std::string line;

    if (!env_file.is_open()) {
        throw "Could not open the .env file.";
        return;
    }
    
    std::string host = "";
    std::string user = "";
    std::string password = "";

    while (getline(env_file, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);

            key.erase(key.find_last_not_of(" \n\r\t") + 1);
            value.erase(0, value.find_first_not_of(" \n\r\t"));

            if (key == "HOST") {
                host = value;
            } else if (key == "USER") {
                user = value;
            } else if (key == "PASSWORD") {
                password = value;
            }
        }
    }

    env_file.close();

    if (host == "" || user == "" || password == "") {
        throw "No s'ha trobat els credencials al fitxer .env";
    }

    _driver = get_mysql_driver_instance();
    _connection = _driver->connect(host, user, password);
    _connection->setSchema(user);
    _statement = _connection->createStatement();

}

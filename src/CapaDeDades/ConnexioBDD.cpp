#include "ConnexioBDD.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

// Define the static member
singleton *singleton::instance = nullptr;

singleton *singleton::getInstance() {
    if (instance == nullptr) {
        instance = new singleton();
    }
    return instance;
}

singleton::singleton() {
    ifstream envFile(".env");
    string line;

    if (!envFile.is_open()) {
        cerr << "Could not open the .env file." << endl;
        return;
    }

    while (getline(envFile, line)) {
        // Ignore comments and empty lines
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Split the line into key and value
        size_t delimiterPos = line.find('=');
        if (delimiterPos != string::npos) {
            string key = line.substr(0, delimiterPos);
            string value = line.substr(delimiterPos + 1);

            // Trim whitespace
            key.erase(key.find_last_not_of(" \n\r\t") + 1);
            value.erase(0, value.find_first_not_of(" \n\r\t"));

            // Set the values based on keys
            if (key == "HOST") {
                _host = value;
            } else if (key == "USER") {
                _user = value;
            } else if (key == "PASSWORD") {
                _password = value;
            }
        }
    }

    envFile.close();
}

std::string singleton::getHost() { return _host; }

std::string singleton::getUser() { return _user; }

std::string singleton::getPassword() { return _password; }

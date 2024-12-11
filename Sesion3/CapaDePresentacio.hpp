#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP

#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include "ConnexioDB.hpp"
#include "CapaDeDomini.hpp"

using namespace std;

class CapaDePresentacio {

public:
    static CapaDePresentacio* getInstance();

    void registraUsuari();
    void consultaUsuari();
    void modificaUsuari();
    void eliminarUsuari();

private:
    CapaDePresentacio();
    static CapaDePresentacio* instance;
    CapaDeDomini *capaDeDomini = CapaDeDomini::getInstance();
};

#endif

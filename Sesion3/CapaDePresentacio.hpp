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

using namespace std;

class CapaDePresentacio {
private:
    //ConnexioDB connexioDB;

public:
    static CapaDePresentacio& getInstance()
    {
        static CapaDePresentacio instance;
        return instance;
    }

    void registraUsuari();
    void consultaUsuari();
    void modificaUsuari();
    void eliminarUsuari();

};

#endif
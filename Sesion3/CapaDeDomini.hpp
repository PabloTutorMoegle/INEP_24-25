#ifndef CAPADEDOMINI_HPP
#define CAPADEDOMINI_HPP

#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include "ConnexioDB.hpp"

using namespace std;

class CapaDeDomini {

    public:
        static CapaDeDomini* getInstance();

        void registraUsuari(string nom_usuari, string sobrenom_usuari, string correu_electronic_usuari);
        void consultaUsuari(string sobrenom_usuari);
        
    private:
        CapaDeDomini();
        static CapaDeDomini* instance;
};

#endif
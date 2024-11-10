#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

class ConnexioDB
{
    private:
        sql::mysql::MySQL_Driver *driver = NULL;
        sql::Connection *con = NULL;
        sql::Statement *stmt = NULL;

    public:
        // Constructor
        ConnexioDB();
        // Destructor
        ~ConnexioDB();
        // Metodos
        void procesarRegistroUsuario(string sql);
        void cosnultarUsuario(string sql);
        void modificaUsuario(string sql);
        void eliminarUsuario(string sql);
};

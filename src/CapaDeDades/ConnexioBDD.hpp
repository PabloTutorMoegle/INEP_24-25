#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using sql::Connection;
using sql::Statement;
using sql::ResultSet;
using sql::mysql::get_mysql_driver_instance;
using sql::mysql::MySQL_Driver;

using namespace std;

class ConnexioBDD {
    public:
        static ConnexioBDD *getInstance();

        void execute(string query);
        ResultSet* execute_query(string query);

    private:
        static ConnexioBDD *_instance;

        MySQL_Driver *_driver = nullptr;
        Connection *_connection = nullptr;
        Statement *_statement = nullptr;

        ConnexioBDD();
};

#endif

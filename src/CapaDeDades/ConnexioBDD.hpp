#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using sql::Connection;
using sql::ResultSet;
using sql::Statement;
using sql::mysql::get_mysql_driver_instance;
using sql::mysql::MySQL_Driver;
using sql::PreparedStatement;

class ConnexioBDD {
    public:
        static ConnexioBDD *getInstance();

        void execute(std::string query);
        std::unique_ptr<ResultSet> execute_query(std::string query);
        std::unique_ptr<PreparedStatement> get_prepared_statement(std::string statement);

    private:
        static ConnexioBDD *_instance;

        MySQL_Driver *_driver = nullptr;
        Connection *_connection = nullptr;
        Statement *_statement = nullptr;

        ConnexioBDD();
};

#endif

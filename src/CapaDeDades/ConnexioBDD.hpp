#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include <string>

using namespace std;

class singleton {
    public:
        static singleton *getInstance();
        string getHost();
        string getUser();
        string getPassword();

    private:
        singleton();
        static singleton *instance;
        string _host;
        string _user;
        string _password;
};

#endif

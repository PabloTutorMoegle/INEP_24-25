#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP

#include <iostream>
#include <string>

using namespace std;

class CapaDePresentacio {
public:
    static CapaDePresentacio* getInstance();
    void registraUsuari();
    void consultaUsuari();
    void modificaUsuari();
    void eliminarUsuari();

private:
    CapaDePresentacio() {}
    static CapaDePresentacio* instance;
};

#endif
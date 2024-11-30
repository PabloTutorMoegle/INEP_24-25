//La capa de presentacion es un singleton

#include "CapaDePresentacio.hpp"

using namespace std;

CapaDePresentacio* CapaDePresentacio::instance = nullptr;


CapaDePresentacio* CapaDePresentacio::getInstance() {
    if (instance == nullptr) {
        instance = new CapaDePresentacio();
    }
    return instance;
}

CapaDePresentacio::CapaDePresentacio() {
    // Initialize with default values or read from a config file
}

void registraUsuari()
{

}
void consultaUsuari()
{

}
void modificaUsuari()
{

}
void eliminarUsuari()
{

}

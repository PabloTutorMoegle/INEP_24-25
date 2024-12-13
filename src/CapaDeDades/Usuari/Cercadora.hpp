#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include "Pasarela.hpp"
#include "../ConnexioBDD.hpp"
#include "../../definitions.hpp"

class CercadoraUsuari {
    public: 
        static PasarelaUsuari cercaUsuari(string sobrenom);
};

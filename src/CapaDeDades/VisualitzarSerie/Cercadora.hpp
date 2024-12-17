#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include "Pasarela.hpp"
#include "../ConnexioBDD.hpp"
#include "../../definitions.hpp"

class Cercadora {
    public:
        PasarelaVisualitzarSerie CercaVisualitzarSeriePerSobrenom(std::string sobreNom);
};

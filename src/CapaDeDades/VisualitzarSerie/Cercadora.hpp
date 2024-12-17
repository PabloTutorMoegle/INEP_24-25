#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <vector>
using std::vector;

#include "Pasarela.hpp"
#include "../ConnexioBDD.hpp"
#include "../../definitions.hpp"

class CercadoraVisualitzarSerie {
    public:
        static vector<PasarelaVisualitzarSerie> cerca_per_sobrenom(string sobreNom);
};

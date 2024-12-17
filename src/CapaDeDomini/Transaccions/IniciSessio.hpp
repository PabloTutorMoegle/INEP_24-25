#include <string>
using std::string;

#include "../PetitFlix.hpp"
#include "../../CapaDeDades/Usuari/Cercadora.hpp"

class TxIniciSessio {
    private:
        string _sobrenom_usuari;
        string _contrasenya_usuari;

    public:
        TxIniciSessio(string sobrenom_usuari, string contrasenya_usuari);

        void executar();
};

#include <string>
using std::string;

#include "../PetitFlix.hpp"

class TxEsborraUsuari {
    private:
        string _contrasenya_usuari;

    public:
        TxEsborraUsuari(string contrasenya_usuari);

        void executar();
};

#include <string>
#include <time.h>
using std::string;

#include "../../definitions.h"

class PasarelaUsuari {
    private:
        string _sobrenom;
        string _nom;
        string _contrasenya;
        string _correu_electronic;
        time_t _data_naixement;
        ModalitatSubscripcio _modalitat_subscripcio;
        
    public:
        void insereix();
        void modifica();
        void esborra();
};

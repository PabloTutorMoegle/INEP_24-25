#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaUsuari {
    private:
        string _sobrenom;
        string _nom;
        string _contrasenya;
        string _correu_electronic;
        time_t _data_naixement;
        ModalitatSubscripcio _modalitat_subscripcio;
        
    public:
        PasarelaUsuari(
            string sobrenom, 
            string nom, 
            string contrasenya, 
            string correu_electronic, 
            time_t data_naixement, 
            ModalitatSubscripcio modalitat_subscripcio
        );
        void insereix();
        void modifica();
        void esborra();
};

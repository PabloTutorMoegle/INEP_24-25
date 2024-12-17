#include <string>
#include <time.h>
using std::string;

#include "../../definitions.hpp"
#include "../ConnexioBDD.hpp"
#include <cppconn/prepared_statement.h>

class PasarelaVisualitzarSerie {
    private:
        string _sobrenom;
        string _titolSerie;
        int _numVicialitzacions;
        int _numTemporada;
        int _numCapitol;
        time_t _data;
        ModalitatSubscripcio _modalitat_subscripcio;

    public:
        PasarelaVisualitzarSerie(
            string sobrenom, 
            string titolSerie, 
            int numVicialitzacions, 
            int numTemporada, 
            int numCapitol, 
            time_t data,
            ModalitatSubscripcio modalitat_subscripcio
        );
        void Insereix();
        void Modifica();
        void Esborra();

        string ObteSobrenom();
        string ObteTitolSerie();
        int ObteNumVicialitzacions();
        int ObteNumTemporada();
        int ObteNumCapitol();
        time_t ObteData();
        ModalitatSubscripcio ObteModalitatSubscripcio();
};

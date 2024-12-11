#include <string>
#include <time.h>

using namespace std;

class Pasarela {
    private:
        string _sobrenom;
        string _titolSerie;
        int _numVicialitzacions;
        int _numTemporada;
        int _numCapitol;
        time_t _data;

    public:
        void Insereix();
        void Modifica();
        void Esborra();
};
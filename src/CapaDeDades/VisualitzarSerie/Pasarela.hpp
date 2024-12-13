#include <string>
#include <time.h>

class PasarelaVisualitzarSerie {
    private:
        std::string _sobrenom;
        std::string _titolSerie;
        int _numVicialitzacions;
        int _numTemporada;
        int _numCapitol;
        time_t _data;

    public:
        PasarelaVisualitzarSerie();
        void Insereix();
        void Modifica();
        void Esborra();
};

#include <optional>
using std::optional;

#include "../CapaDeDades/Usuari/Pasarela.hpp"

class PetitFlix {
    private:
        static PetitFlix* _instance;

        optional<PasarelaUsuari> _usuari;

        PetitFlix();
    
    public:
        static PetitFlix* get_instance();

        PasarelaUsuari obte_usuari();
        void inicia_sessio(PasarelaUsuari usuari);
        void tanca_sessio();

};

#include "../DTOUsuari.hpp"
#include "../PetitFlix.hpp"

class TxConsultaUsuari {
    private:
        optional<DTOUsuari> _resultat;

    public:
        TxConsultaUsuari();
        ~TxConsultaUsuari();

        void executar();
        DTOUsuari obte_resultat();
};

#ifndef PRESENTACIO_HPP
#define PRESENTACIO_HPP

#include <utility>
using std::pair;

#include "../CapaDeDomini/GestioUsuaris/DTOUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/PetitFlix.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/IniciSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/TancaSessio.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/RegistraUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/ConsultaUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/ControlModificaUsuari.hpp"
#include "../CapaDeDomini/GestioUsuaris/Transaccions/EsborraUsuari.hpp"

#include "../CapaDeDomini/Consultes/TxConsultaEstrenes.hpp"
#include "../CapaDeDomini/Consultes/TxConsultaMesVistes.hpp"
#include "../CapaDeDomini/Consultes/TxConsultaNovetats.hpp"

#include "../CapaDeDomini/VisualitzacioContingut/TxVisualitzarPelicula.hpp"
#include "../CapaDeDomini/VisualitzacioContingut/TxVisualitzarCapitol.hpp"
#include "../CapaDeDomini/VisualitzacioContingut/TxConsultaVisualitzacions.hpp"

// Això no fa falta que s'implementi com un singleton ja que tot els mètodes poden ser estàtics
class CapaDePresentacio {
    public:
        static void inici_sessio();
        static void registrar_usuari();

        static pair<DTOUsuari, pair<unsigned int, unsigned int>> consulta_usuari();
        static void modifica_usuari();
        static void modifica_contrasenya();
        static void esborra_usuari();
        static void tanca_sessio();
        
        static void properes_estrenes();
        static void ultimes_novetats();
        static void pelicules_mes_vistes();

        static void visualitzant_pelicula(string titol_pelicula);
        static void visualitzar_pelicula();
        static void visualitzar_capitol();
        static void consulta_visualitzacions();
};

#endif

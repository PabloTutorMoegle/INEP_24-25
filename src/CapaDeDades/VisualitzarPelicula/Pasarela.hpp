#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class PasarelaVisualitzaPelicula {
    private: 
        string _sobrenom;
        string _titolPelicula;
        int _numVisualitzacions;
        time_t data;

    public: 
        void insereix();
        void modifica();
        void esborra();
};

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "civilizacion.h"

using namespace std;

class Videojuego{
    private:
        string usuario;
        vector<Civilizacion> civs;
    
    public:
        Videojuego();
        Videojuego(const string&);

        void setUsuario(const string&);
        string getUsuario();

        void agregarCiv(const Civilizacion&);
        void insertarCiv(const Civilizacion&, size_t);
        void inicializa(const Civilizacion&, size_t);

        Civilizacion getPrimerCiv();
        Civilizacion getUltimaCiv();

    
        void ordenarNombre();
        void ordenarX();
        void ordenarY();
        void ordenarPuntuacion();

        void eliminaCiv(size_t);

        Civilizacion* buscarCiv(const Civilizacion&);

        void respaldarCivs();
        void recuperaCivs();

        size_t total();

        void mostrar();

        friend Videojuego& operator << (Videojuego &v, const Civilizacion &c){
            v.agregarCiv(c);
            return v;
        }
};

#endif
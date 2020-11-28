#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include "aldeano.h"

using namespace std;

class Civilizacion{
    private:
        string nombre;
        int x;
        int y;
        float puntuacion;

        list<Aldeano> aldeanos;
    public:
        Civilizacion();
        Civilizacion(const string&, const int&, const int&, const float&);

        void setNombre(const string&);
        void setX(const int&);
        void setY(const int&);
        void setPuntuacion(const float&);

        string getNombre();
        int getX();
        int getY();
        float getPuntuacion();

        //Aldeanos--------------------------
        void agregarFinal(const Aldeano&);
        void agregarInicio(const Aldeano&);

        void eliminarNombre(const string&);
        void eliminarEdad(); //eliminar >= 60
        void eliminarSalud(const float&);

        void ordenarNombre();
        void ordenarEdad();
        void ordenarSalud();

        Aldeano* buscar(const Aldeano&);

        bool vacia();

        void print();

        friend ostream& operator<<(ostream &out, const Civilizacion &c){
            out << left;
            out << setw(20) << c.nombre;
            out << setw(5) <<  c.x;
            out << setw(5) <<  c.y;
            out << setw(10) <<  c.puntuacion;
            out << endl;
            return out;
        }

        friend istream& operator>>(istream &in, Civilizacion &c){
            cout << "Nombre de la Civ: ";
            getline(cin, c.nombre);
            //cin.ignore();

            cout << "Posicion en X: ";
            cin >>c.x;
            //cin.ignore();
            cout << "Posicion en Y: ";
            cin >> c.y;
            //cin.ignore();
            cout << "Puntuacion: ";
            cin >> c.puntuacion;

            return in;
        }

        bool operator == (const Civilizacion& c){
            return nombre == c.nombre;
        }

        bool operator == (const Civilizacion& c) const{
            return nombre == c.nombre;
        }
/*
        bool operator > (const Civilizacion& c){
            return nombre > c.nombre;
        }
        bool operator<(const Civilizacion& c) const{
            return nombre < c.nombre;
        }*/
};

#endif
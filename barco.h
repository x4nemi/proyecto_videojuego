#ifndef BARCO_H
#define BARCO_H

#include <stack>

#include "guerrero.h"

using namespace std;

class Barco{
    private:
        string id;
        float combustible;
        int velocidad;
        float armadura;

        stack<Guerrero> pilaGuerreros;

    public:
        Barco();
        Barco(const string&, const float&);

        void setID(const string&);
        void setCombustible(const float&);
        void setVelocidad(const int&);
        void setArmadura(const float&);

        string getID();
        float getCombustible() const;
        int getVelocidad();
        float getArmadura();

        //Guerrero
        void pushGuerrero(const Guerrero&);
        void popGuerrero();
        Guerrero& getTopeGuerrero();
        void menuBarco();
        void capturarGuerrero();
        void mostrarGuerreros();

        friend ostream& operator << (ostream &out, const Barco& b){
            out << left;
            out << setw(10) << b.id;
            out << setw(15) << b.combustible;
            out << setw(15) << b.velocidad;
            out << setw(15) << b.armadura;

            return out;
        }

        /*friend istream& operator>>(istream &in, Barco &b){
            cout << "ID: ";
            getline(cin, b.id);
            cout << "Edad: ";
            cin >> a.edad; cin.ignore();
            cout << "Genero: ";
            getline(cin, a.genero);
            cout << "Salud: ";
            cin >> a.salud;

            return in;
        }*/
        bool operator == (Barco* b){
            return id == b->id;
        }

        bool operator == (Barco* b) const{
            return id == b->id;
        }


};

#endif
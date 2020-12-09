#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Guerrero{
    private:
        string id;
        int salud;
        float fuerza;
        float defensa;
        string tipoGuerrero;

    public:
        Guerrero();
        Guerrero(const string&);

        void setID(const string&);
        void setSalud(const int&);
        void setFuerza(const float&);
        void setDefensa(const float&);
        void setTipo(const string&);

        string getID();
        int getSalud();
        float getFuerza();
        float getDefensa();
        string getTipo();

        friend ostream& operator << (ostream &out, const Guerrero& g){
            out << left;
            out << setw(10) << g.id;
            out << setw(10) << g.salud;
            out << setw(10) << g.fuerza;
            out << setw(10) << g.defensa;
            out << setw(18) << g.tipoGuerrero;

            return out;
        }

        /*friend istream& operator >> (istream &in, const Guerrero& g){
            cout << "ID: ";
            getline(cin, g.id);
            cout << "Salud: ";
            cin >> g.salud; cin.ignore();
            cout << "Fuerza: ";
            cin >> g.fuerza; cin.ignore();
            cout << "Defensa: ";
            cin >> g.defensa; cin.ignore();

            return in;
        }*/
};

#endif 
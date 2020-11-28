#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <string>
#include <iomanip>

class Aldeano{
    private:
        std::string nombre;
        size_t edad;
        std::string genero;
        float salud;
    public:
        Aldeano() {}
        Aldeano(const std::string&, size_t, const std::string&, const float&);

        void setNombre(const std::string&);
        void setEdad(size_t);
        void setGenero(const std::string&);
        void setSalud(const float&);

        std::string getNombre();
        size_t getEdad();
        std::string getGenero();
        float getSalud();

        friend ostream& operator << (ostream &out, const Aldeano& a){
            out << left;
            out << setw(15) << a.nombre;
            out << setw(10) << a.edad;
            out << setw(15) << a.genero;
            out << setw(10) << a.salud;

            return out;
        }

        friend istream& operator>>(istream &in, Aldeano &a){
            cout << "Nombre: ";
            getline(cin, a.nombre);
            cout << "Edad: ";
            cin >> a.edad;
            cout << "Genero: ";
            getline(cin, a.genero);
            cout << "Salud: ";
            cin >> a.salud;

            return in;
        }

        bool operator == (const Aldeano& a){
            return nombre == a.nombre;
        }

        bool operator == (const Aldeano& a) const{
            return nombre == a.nombre;
        }

        bool operator < (Aldeano& a){
            return nombre < a.getNombre();
        }
};

#endif
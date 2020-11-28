#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){ }

Civilizacion::Civilizacion(const std::string& n, const int& x, const int& y, const float& p){
    this->nombre = n;
    this->x = x;
    this->y = y;
    this->puntuacion = p;
}

void Civilizacion::setNombre(const std::string& n){
    nombre = n;
}

void Civilizacion::setX(const int& x){
    this->x = x;
}

void Civilizacion::setY(const int& y){
    this->y = y;
}

void Civilizacion::setPuntuacion(const float& p){
    puntuacion = p;
}

string Civilizacion::getNombre(){
    return nombre;
}

int Civilizacion::getX(){
    return x;
}

int Civilizacion::getY(){
    return y;
}

float Civilizacion::getPuntuacion(){
    return puntuacion;
}

//Aldeanos
void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
}

void Civilizacion::print(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string& n){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(n == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparaEdad(Aldeano& a){
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparaEdad);
}

void Civilizacion::eliminarSalud(const float& x){
    aldeanos.remove_if([x](Aldeano &a){ return a.getSalud() >= x;});
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort();
}

bool comparaEdadSort(Aldeano &a, Aldeano &b){
    return a.getEdad() > b.getEdad();
}

void Civilizacion::ordenarEdad(){
    aldeanos.sort(comparaEdadSort);
}

void Civilizacion::ordenarSalud(){
    aldeanos.sort([](Aldeano &a, Aldeano &b){return a.getSalud() > b.getSalud();});
}

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

void Civilizacion::setPuntuacion(const int& p){
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
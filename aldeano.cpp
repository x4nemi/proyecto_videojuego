#include "aldeano.h"

using namespace std;

Aldeano::Aldeano(const string& n, const size_t e, const string& g, const float& s){
    nombre = n;
    edad = e;
    genero = g;
    salud = s;
}

void Aldeano::setNombre(const string& n){
    nombre = n;
}

void Aldeano::setEdad(size_t e){
    edad = e;
}

void Aldeano::setGenero(const string& g){
    genero = g;
}

void Aldeano::setSalud(const float& s){
    salud = s;
}

string Aldeano::getNombre(){
    return nombre;
}

size_t Aldeano::getEdad(){
    return edad;
}

string Aldeano::getGenero(){
    return genero;
}

float Aldeano::getSalud(){
    return salud;
}
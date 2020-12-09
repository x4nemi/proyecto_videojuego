#include "guerrero.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Guerrero::Guerrero() { } //float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));

Guerrero::Guerrero(const string& id){
    this->id = id;
    srand (time(NULL));
    salud =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100.0));
    //srand (time(NULL));
    fuerza = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 60.0));
    //srand (time(NULL));
    defensa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 30.0));
    string tipos[] = {"Lancero", "Arquero", "Paladin", "Mago"};
    //srand (time(NULL));
    tipoGuerrero = tipos[rand() % 4];
}

void Guerrero::setID(const string& id){
    this->id = id;
}

void Guerrero::setSalud(const int& salud){
    this->salud = salud;
}

void Guerrero::setFuerza(const float& fuerza){
    this->fuerza = fuerza;
}

void Guerrero::setDefensa(const float& defensa){
    this->defensa = defensa;
}

void Guerrero::setTipo(const string& tipo){
    tipoGuerrero = tipo;
}

string Guerrero::getID(){
    return id;
}

int Guerrero::getSalud(){
    return salud;
}

float Guerrero::getFuerza(){
    return fuerza;
}

float Guerrero::getDefensa(){
    return defensa;
}

string Guerrero::getTipo(){
    return tipoGuerrero;
}
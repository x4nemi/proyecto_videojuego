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
    this->nombre = n;
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

int Civilizacion::getX() {
    return x;
}

int Civilizacion::getY(){
    return y;
}

float Civilizacion::getPuntuacion() const{
    return puntuacion;
}

//Aldeanos
void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
    setPuntuacion(puntuacion + 100.0);
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
    setPuntuacion(puntuacion + 100.0);
}

void Civilizacion::print(){
    cout << left << "\t";
    cout << setw(15) << "Nombre";
    cout << setw(10) << "Edad";
    cout << setw(15) << "Genero";
    cout << setw(10) << "Salud";
    cout << endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << "\t" << *it << endl;
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
    aldeanos.remove_if([x](Aldeano &a){ return a.getSalud() <= x;});
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


Aldeano* Civilizacion::buscar(const Aldeano& a){
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    if(it == aldeanos.end()){
        return nullptr;
    }
    else return &(*it);
}

bool Civilizacion::vacia(){
    return aldeanos.empty();
}

void Civilizacion::respaldarAldeanos()
{
    ofstream archivo(getNombre() + ".txt", ios::out);//Se crea el objeto archivo con el nombre de la civilizacion
    if (archivo.is_open()) {
        for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {//Se recorre toda la lista de aldeanos
            Aldeano& aldeano = *it;
            archivo << aldeano.getNombre() << endl;
            archivo << aldeano.getEdad() << endl;
            archivo << aldeano.getGenero() << endl;
            archivo << aldeano.getSalud() << endl;
        }
        archivo.close();//Se cierra el arcivo
    }
    else {
        cout << "No se pudo abrir el archivo, Respaldar_aldeanos" << endl;
    }
}

void Civilizacion::recuperaAldeanos(){
    ifstream archivo(getNombre() + ".txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo, recuperar aldeanos" << endl;
        return;
    }
    else {
        Aldeano* aux = nullptr;
        string auxstr;
        while (!archivo.eof()) {
            aux = new Aldeano();
            getline(archivo, auxstr);
            aux->setNombre(auxstr);
            getline(archivo, auxstr);
            aux->setEdad(atoi(auxstr.c_str()));
            getline(archivo, auxstr);
            aux->setGenero(auxstr.c_str());
            getline(archivo, auxstr);
            aux->setSalud(atof(auxstr.c_str()));
            agregarFinal(*aux);
        }
        aldeanos.pop_back();
        archivo.close();
    }
}
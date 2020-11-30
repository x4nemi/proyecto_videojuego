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
    puntuacion += 100;
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
    puntuacion += 100;
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

void Civilizacion::respaldarAldeanos(){
    //crea un archivo txt llamado como la civilización 
    //y guarda a los aldeanos con sus datos
    ofstream aldeanoss(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanoss << aldeano.getNombre() << endl;
        aldeanoss << aldeano.getEdad()   << endl;
        aldeanoss << aldeano.getGenero() << endl;
        aldeanoss << aldeano.getSalud()  << endl;

    }
    aldeanoss.close();
}

void Civilizacion::recuperaAldeanos(){
    ifstream archivo(getNombre() + ".txt");

    if(archivo.is_open()){
        string aux;
        size_t edad;
        float salud;
        Aldeano a;

        while(true){
            getline(archivo, aux);
            if(archivo.eof()) break;

            a.setNombre(aux);

            getline(archivo, aux);
            edad = stoi(aux);
            a.setEdad(edad);

            getline(archivo, aux);
            a.setGenero(aux);

            getline(archivo, aux);
            cout << aux;
            salud = stof(aux);
            a.setSalud(salud);

            agregarFinal(a);
        }
    }
}
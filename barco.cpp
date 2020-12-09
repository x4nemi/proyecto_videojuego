#include "barco.h"

using namespace std;

Barco::Barco() { }

Barco::Barco(const string& id, const float& c){
    this->id = id;
    combustible = c;
    velocidad = 0;
    armadura = 100.0;
}

void Barco::setID(const string& i){
    id = i;
}

void Barco::setCombustible(const float& c){
    combustible = c;
}

void Barco::setVelocidad(const int& v){
    velocidad = v;
}

void Barco::setArmadura(const float& a){
    armadura = a;
}

string Barco::getID(){
    return id;
}

float Barco::getCombustible() const{
    return combustible;
}

int Barco::getVelocidad(){
    return velocidad;
}

float Barco::getArmadura(){
    return armadura;
}

void Barco::pushGuerrero(const Guerrero& g){
    pilaGuerreros.push(g);
}

void Barco::popGuerrero(){
    pilaGuerreros.pop();
}

Guerrero& Barco::getTopeGuerrero(){
    return pilaGuerreros.top();
}

void Barco::menuBarco(){
    int opc;

    while(true){
        cout << "1. Agregar Guerrero" << endl;
        cout << "2. Eliminar Guerrero" << endl;
        cout << "3. Tope" << endl;
        cout << "4. Mostrar Guerreros" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc; cin.ignore();

        if(!opc) break;

        cout << endl;

        if((opc >= 2 and opc <= 4) and pilaGuerreros.empty()){
            cout << "Pila vacia" << endl << endl;
            continue;
        }

        switch (opc){
        case 1:
            capturarGuerrero();
            cout << "Guerrero agregado...";
            break;
        case 2:
        {
            string opcion;
            cout << "Se eliminara el siguiente Guerrero:" << endl;
            cout << left;
            cout << setw(10) << "ID";
            cout << setw(10) << "Salud";
            cout << setw(10) << "Fuerza";
            cout << setw(10) << "Defensa";
            cout << setw(18) << "Tipo de Guerrero" << endl;
            cout << getTopeGuerrero() << endl;
            cout << "Seguro? (s/n): ";
            getline(cin, opcion);

            if(opcion == "s"){
                popGuerrero();
                cout << "Eliminado...";
            }
        }
            break;
        case 3:
            cout << left;
            cout << setw(10) << "ID";
            cout << setw(10) << "Salud";
            cout << setw(10) << "Fuerza";
            cout << setw(10) << "Defensa";
            cout << setw(18) << "Tipo de Guerrero" << endl;
            cout << getTopeGuerrero();
            break;
        case 4:
        {
            mostrarGuerreros();
        }
            break;
        default:
            cout << "Opcion incorrecta";
            break;
        }
        cout << endl << endl;
    }
}

void Barco::capturarGuerrero(){
    string id;
    cout << "ID: ";
    getline(cin, id);

    Guerrero g(id);

    pushGuerrero(g);
}

void Barco::mostrarGuerreros(){
    stack<Guerrero> copia = pilaGuerreros;

    cout << left;
    cout << setw(10) << "ID";
    cout << setw(10) << "Salud";
    cout << setw(10) << "Fuerza";
    cout << setw(10) << "Defensa";
    cout << setw(18) << "Tipo de Guerrero" << endl;

    while(!copia.empty()){
        cout << copia.top() << endl;
        copia.pop();
    }
}
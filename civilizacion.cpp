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


void Civilizacion::agregarBarco(Barco* b){
    puerto.push_back(b); //al final
}

void Civilizacion::menuCiv(){
    int opc;

    while(true){
        cout << "1. Agregar Barco" << endl;
        cout << "2. Mostrar todos los Barcos" << endl;
        cout << "3. Buscar barco" << endl;
        cout << "4. Eliminar" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc; cin.ignore();

        if(!opc) break;

        cout << endl << endl;

        if(opc >= 2 and opc <= 4 and !puerto.size()){
            cout << "Aun no hay barcos capturados" << endl << endl;
            continue;
        }

        switch (opc){
        case 1:
            capturarBarco();
            cout << "Barco agregado...";
            break;
        case 2:
            mostrarBarcos();
            break;
        case 3:
        {
            string id;
            cout << "ID: ";
            getline(cin, id);

            Barco *barco = buscarBarco(id);
            if(barco == nullptr){
                cout << "Barco no encontrado";
            }
            else{
                cout << "Barco encontrado:" << endl;
                cout << left;
                cout << setw(10) << "ID";
                cout << setw(15) << "Combustible";
                cout << setw(15) << "Velocidad";
                cout << setw(15) << "Armadura" << endl;
                cout << *barco;

                Barco &b = *barco;
                cout << endl;
                b.menuBarco();
            }
        }
            break;
        case 4:
        {
            string op;
            cout << "a. Por ID" << endl;
            cout << "b. Por combustible menor a 'x' cantidad" << endl;
            cout << "Opcion: ";
            getline(cin, op);

            if(op == "a"){
                string id;
                cout << "ID: ";
                getline(cin, id);
                eliminarID(id);

                cout << "Eliminado(s)...";
            }
            else if(op == "b"){
                float c;
                cout << "Valor de X: ";
                cin >> c; cin.ignore();

                eliminarCombX(c);
                cout << "Eliminado(s)...";
            }else{
                cout << "Opcion incorrecta";
            }
        }
            break;
        default:
            cout << "Opcion incorrecta";
            break;
        }
        cout << endl << endl;
    }
}

void Civilizacion::capturarBarco(){
    string id;
    float combustible; 
    
    cout << "Id: ";
    getline(cin, id);
    
    cout << "Combustible: ";
    cin >> combustible; cin.ignore();

    Barco *b = new Barco(id, combustible);

    agregarBarco(b);
}

void Civilizacion::mostrarBarcos(){
    cout << left;
    cout << setw(10) << "ID";
    cout << setw(15) << "Combustible";
    cout << setw(15) << "Velocidad";
    cout << setw(15) << "Armadura" << endl;
    for(auto const &b : puerto){
        cout << *b << endl;
    }
}

Barco* Civilizacion::buscarBarco(const string& id){
    for(auto it = puerto.begin(); it != puerto.end(); it++){
        Barco *b = *it;

        if(id == b->getID()){
            return *it;
        }
    }
    return nullptr;

}

void Civilizacion::eliminarID(const string& id){
    for(auto it = puerto.begin(); it != puerto.end(); it++){
        Barco *b = *it;

        if(id == b->getID()){
            puerto.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarCombX(const float& x){
    puerto.remove_if([x](Barco *b){ return b->getCombustible() < x;});
}

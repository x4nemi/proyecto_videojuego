#include "videojuego.h"

using namespace std;

Videojuego::Videojuego(){ }

Videojuego::Videojuego(const string& u){
    usuario = u;
}

void Videojuego::setUsuario(const string& u){
    usuario = u;
}

string Videojuego::getUsuario(){
    return usuario;
}

void Videojuego::agregarCiv(const Civilizacion c){
    civs.push_back(c);
}

void Videojuego::mostrar(){
    cout << left;
    cout << setw(20) << "Nombre de la Civ";
    cout << setw(5) << "X";
    cout << setw(5) << "Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;

    for (size_t i = 0; i < civs.size(); i++) {
        Civilizacion &c = civs[i];
        cout << c;
    }
}

/*void Videojuego::respaldar_tabla(){
    ofstream archivo("civs_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(10) << "Nombre";
        archivo << setw(10) << "Tipo";
        archivo << setw(8) << "Fuerza";
        archivo << setw(6) << "Salud";
        archivo << endl;
        for (size_t i = 0; i < civs.size(); i++) {
            Civilizacion &c = civs[i];
            archivo << p;
        }
    }
    archivo.close();
}

void Videojuego::respaldar()
{
    ofstream archivo("civs.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < civs.size(); i++) {
            Civilizacion &c = civs[i];
            archivo << p.getNombre() << endl;
            archivo << p.getTipo() << endl;
            archivo << p.getFuerza() << endl;
            archivo << p.getSalud() << endl;
        }
    }
    archivo.close();
}

void Videojuego::recuperar()
{
    ifstream archivo("civs.txt");
    if (archivo.is_open()) {
        string temp;
        float fuerza;
        int salud;
        Civilizacion p;

        while (true)
        {
            getline(archivo, temp); // nombre
            if (archivo.eof()) {
                break;
            }
            p.setNombre(temp);

            getline(archivo, temp); // tipo
            p.setTipo(temp);

            getline(archivo, temp); // fuerza
            fuerza = stof(temp);  // string-to-float
            p.setFuerza(fuerza);

            getline(archivo, temp);
            salud = stoi(temp); // // string-to-int
            p.setSalud(salud);

            agregarCiv(c);            
        }
        
    }
    archivo.close();
}*/

void Videojuego::insertarCiv(const Civilizacion c, size_t pos){
    civs.insert(civs.begin() + pos, c);
}

size_t Videojuego::total(){
    return civs.size();
}

void Videojuego::inicializa(const Civilizacion &c, size_t n){
    civs = vector<Civilizacion>(n, c);
}

void Videojuego::eliminaCiv(size_t pos){
    civs.erase(civs.begin() + pos);
}

Civilizacion Videojuego::getPrimerCiv(){
    return civs.front();
}

Civilizacion Videojuego::getUltimaCiv(){
    return civs.back();
}

void Videojuego::ordenarNombre(){
    sort(civs.begin(), civs.end(), [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

void Videojuego::ordenarX(){
    sort(civs.begin(), civs.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}
void Videojuego::ordenarY(){
    sort(civs.begin(), civs.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getY() < c2.getY();});
}

void Videojuego::ordenarPuntuacion(){
    sort(civs.begin(), civs.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}

Civilizacion* Videojuego::buscarCiv(const Civilizacion &c){
    // vector<Civilizacion>::iterator
    auto it = find(civs.begin(), civs.end(), c);

    if (it == civs.end()){
        return nullptr;
    }

    else{
        return &(*it);
    }
}

void Videojuego::respaldarCivs(){
    ofstream archivo("civilizaciones.txt", ios::out); //Se crea y abre el archivo
    if (archivo.is_open()) {
        for (int i = 0; i < total(); ++i) {
            if (i == total() - 1) {
                archivo << civs[i].getNombre() << endl;
                archivo << civs[i].getX() << endl;
                archivo << civs[i].getY() << endl;
                archivo << civs[i].getPuntuacion();
                civs[i].respaldarAldeanos();
                break;
            }
            archivo << civs[i].getNombre() << endl;
            archivo << civs[i].getX() << endl;
            archivo << civs[i].getY() << endl;
            archivo << civs[i].getPuntuacion() << endl;
            civs[i].respaldarAldeanos();
        }
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo, respaldar Civilizaciones" << endl;
    }

}

void Videojuego::recuperaCivs() {
    ifstream archivo("civilizaciones.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo, recuperar civilizaciones" << endl;
        return;
    }
    else {
        Civilizacion* aux;
        string auxstr;
        while (!archivo.eof()) {
            aux = new Civilizacion();
            getline(archivo, auxstr);
            aux->setNombre(auxstr);
            getline(archivo, auxstr);
            aux->setX(atoi(auxstr.c_str()));
            getline(archivo, auxstr);
            aux->setY(atoi(auxstr.c_str()));
            getline(archivo, auxstr);
            aux->recuperaAldeanos();
            aux->setPuntuacion(atof(auxstr.c_str()));
            agregarCiv(*aux);
        }
        archivo.close();
    }
}
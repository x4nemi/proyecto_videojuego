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

void Videojuego::agregarCiv(const Civilizacion &c){
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

void Videojuego::insertarCiv(const Civilizacion &c, size_t pos){
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
    //se va a crear un archivo txt con los nombres de las civs
    //y cada que se agregue una civ, se respaldarán sus aldeanos
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civs.size(); ++i) {
        Civilizacion &c = civs[i];
        archivo << c.getNombre() << endl;
        archivo << c.getX() << endl;
        archivo << c.getY() << endl;
        archivo << c.getPuntuacion() << endl;
        c.respaldarAldeanos();
    }
    archivo.close();
}

void Videojuego::recuperaCivs(){
    ifstream archivo("civilizaciones.txt");

    if(archivo.is_open()){
        string aux;
        int xy;
        float p;
        Civilizacion c;

        while(true){
            getline(archivo, aux);
            if(archivo.eof()) break;
            c.setNombre(aux);

            getline(archivo, aux);
            xy = stoi(aux);
            c.setX(xy);

            getline(archivo, aux);
            xy = stoi(aux);
            c.setY(xy);

            getline(archivo, aux);
            p = stof(aux);
            c.setPuntuacion(p);

            c.recuperaAldeanos();

            agregarCiv(c);
        }
    }

    archivo.close();
}
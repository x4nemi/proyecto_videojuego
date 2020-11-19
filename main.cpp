#include "videojuego.h"

using namespace std;

int main(){
    int op;
    string nombre;

    cout << "Nombre del nombre: ";
    getline(cin, nombre);

    Videojuego vj(nombre);   

    while(1){
        cout << "\n\n1. Cambiar nombre del usuario" << "\t";
        cout << "2. Agregar Civ" << "\t";
        cout << "3. Insertar" << "\t";
        cout << "4. Inicializar" << endl;
        cout << "5. Primera Civ" << endl;
        cout << "6. Ultima Civ";
        cout << "7. Ordenar" << "\t";
        cout << "8. Eliminar" << "\t";
        cout << "9. Buscar" << endl;
        cout << "3. Respaldad" << endl;
        cout << "4. Recuperar" << "\t";
        
        
        
        
        
        cout << "0. Salir" << endl << "Opcion: ";
        cin >> op; cin.ignore();

        if(!op) break;
        cout << endl;
        
        switch(op){
            case 1:
                cout << "Nombre: ";
                getline(cin, nombre);
                vj.setUsuario(nombre);
                cout << "...Modificado";

            case 2:
            {
                Civilizacion c;
                cin >> c; 
                vj.agregarCiv(c);
                cin.ignore();
            }
                break;
            case 2:
                vj.mostrar();
                break;
            case 3:
                //vj.respaldar();
                cout << "Respaldado";
                break;
            case 4:
                //vj.recuperar();
                cout << "Recuperado";
                break;
            case 5:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();

                if(vj.total() <= pos){
                    cout << "Posicion invalida";
                    break;
                }
                Civilizacion c;
                cin >> c; 
                vj.insertarCiv(c, pos);
                
            }
                break;
            case 6:
            {
                size_t tam;
                cout << "Tamanio: ";
                cin >> tam; cin.ignore();

                Civilizacion c;
                cin >> c;
                vj.inicializa(c, tam);
            }
                break;
            case 7:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; //cin.ignore();

                if(vj.total() <= pos){
                    cout << "Posicion invalida";
                    break;
                }

                vj.eliminaCiv(pos);
            }
                break;
            case 8:
                if(vj.total() == -1){
                    cout << "No hay computadoras registradas";
                    break;
                }
                vj.ordenarNombre();
                cout << "Ordenado";
                break;
            case 9:
            {
                Civilizacion c;
                cin >> c;

                Civilizacion* ptr = vj.buscarCiv(c);
                if(ptr == nullptr){
                    cout << "No encontrado" << endl;
                    break;
                }

                else{
                    cout << *ptr;
                }
            }

        }
    }
    return 0;
}
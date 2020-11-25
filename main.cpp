#include "videojuego.h"

using namespace std;

int main(){
    int op;
    string nombre;

    cout << "Nombre del usuario: ";
    getline(cin, nombre);

    Videojuego vj(nombre);   

    while(1){
        cout << "=============================================" << endl;
        cout << "Bienvenid@, " << nombre << "!" << endl;
        cout << "1. Cambiar nombre del usuario" << "\t";
        cout << "2. Agregar Civilizacion" << endl;
        cout << "3. Insertar" << "\t";
        cout << "4. Inicializar" << "\t";
        cout << "5. Primera Civ" << endl;
        cout << "6. Ultima Civ" << "\t";
        cout << "7. Ordenar" << "\t";
        cout << "8. Eliminar" << endl;
        cout << "9. Buscar" << "\t";
        cout << "10. Modificar" << "\t";
        cout << "11. Resumen" << endl;   
        cout << "0. Salir" << endl << "Opcion: ";
        cin >> op; cin.ignore();

        if(!op) break;
        cout << endl << endl;

        if(op >= 5 and op <= 11 and vj.total() <= 0){
            cout << "Aun no hay elementos";
            continue;
        }

        if(op == 8 or op == 3){
            cout << "Hay " << vj.total() << " civilizaciones" << endl;
        }
        
        switch(op){
            case 1:
                cout << "Nombre: ";
                getline(cin, nombre);
                vj.setUsuario(nombre);
                cout << "...Modificado";
                break;
            case 2:
            {
                Civilizacion c;
                cin >> c; 
                vj.agregarCiv(c);
                cin.ignore();
                cout << "Agregado...";
            }
                break;
            case 3:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();

                if(vj.total() < pos){
                    cout << "Posicion invalida";
                    break;
                }
                Civilizacion c;
                cin >> c; 
                vj.insertarCiv(c, pos - 1);
                cout << "Civilizacion insertada...";
            }
                break;
            case 4:
            {
                size_t tam;
                cout << "Tamanio: ";
                cin >> tam; cin.ignore();

                Civilizacion c;
                cin >> c;
                vj.inicializa(c, tam);
                cout << "Inicializada...";
            }
                break;
            case 5:
                cout << "Primera Civilizacion: " << endl;
                cout << vj.getPrimerCiv();
                break;
            case 6:
                cout << "Ultima Civilizacion: " << endl;
                cout << vj.getUltimaCiv();
                break;
            case 7:
                cout << "1. Ordenar por Nombre" << endl;
                cout << "2. Ordenar por la posicion en X" << endl;
                cout << "3. Ordenar por la posicion enY" << endl;
                cout << "4. Ordenar por Puntuacion" << endl;
                cin >> op;

                if(op == 1){
                    vj.ordenarNombre();
                }
                else if(op == 2){
                    vj.ordenarX();
                }
                else if(op == 3){
                    vj.ordenarY();
                }
                else if(op == 4){
                    vj.ordenarPuntuacion();
                }
                else{
                    cout << "Opcion incorrecta";
                    break;
                }
                cout << "Ordenada...";
                break;
            case 8:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; //cin.ignore();

                if(vj.total() < pos){
                    cout << "Posicion invalida";
                    break;
                }

                vj.eliminaCiv(pos + 1);
                cout << "Eliminado...";
            }
                break;
            case 9:
            {
                string cadena;
                Civilizacion c;
                cout << "Nombre de la Civilizacion: ";
                getline(cin, cadena);
                c.setNombre(cadena);

                Civilizacion* ptr = vj.buscarCiv(c);
                if(ptr == nullptr){
                    cout << "No encontrado" << endl;
                    break;
                }

                else{
                    cout << "Primera civilizacion encontrada:" << endl;
                    cout << left;
                    cout << setw(20) << "Nombre de la Civ";
                    cout << setw(5) << "X";
                    cout << setw(5) << "Y";
                    cout << setw(10) << "Puntuacion";
                    cout << endl;
                    cout << *ptr;
                }
            }
                break;
            case 10:
            {
                string cadena;
                Civilizacion c;
                cout << "Nombre de la Civilizacion a modificar: ";
                getline(cin, cadena);
                c.setNombre(cadena);

                Civilizacion* ptr = vj.buscarCiv(c);
                if(ptr == nullptr){
                    cout << "No encontrado" << endl;
                    break;
                }

                else{
                    string cadena;
                    int pos;
                    float punt;
                    cout << "Civilizacion a modificar:" << endl;
                    cout << left;
                    cout << setw(20) << "Nombre de la Civ";
                    cout << setw(5) << "X";
                    cout << setw(5) << "Y";
                    cout << setw(10) << "Puntuacion";
                    cout << endl;
                    cout << *ptr;

                    cout << "1. Modificar Nombre" << endl;
                    cout << "2. Modificar X" << endl;
                    cout << "3. Modificar Y" << endl;
                    cout << "4. Modificar Puntuacion" << endl;
                    cout << "Opcion: ";
                    cin >> op;

                    if(op == 1){
                        cout << "Nombre: ";
                        getline(cin, cadena);
                        ptr->setNombre(cadena);
                    }
                    else if(op == 2){
                        cout << "X: ";
                        cin >> pos;
                        ptr->setX(pos);
                    }
                    else if(op == 3){
                        cout << "Y: ";
                        cin >> pos;
                        ptr->setY(pos);
                    }
                    else if(op == 4){
                        cout << "Puntuacion: ";
                        cin >> punt;
                        ptr->setPuntuacion(punt);
                    }
                    else{
                        cout << "Opcion incorrecta";
                    }
                }
            }
                break;
            case 11:
                cout << "**Resumen**" << endl;
                vj.mostrar();
                break;
            default:
                cout << "Opcion incorrecta";
        }
        cout << endl << endl;

    }
    return 0;
}
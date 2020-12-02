#include "videojuego.h"

void subMenu(Civilizacion &c){
    int op;

    while(1){
        cout << "1. Agregar aldeano" << endl;
        cout << "2. Eliminar aldeano" << endl;
        cout << "3. Clasificar aldeanos" << endl;
        cout << "4. Buscar aldeano" << endl;
        cout << "5. Modificar aldeano" << endl;
        cout << "6. Mostrar aldeanos" << endl;
        cout << "0. Salir" << endl << "Opcion: ";
        cin >> op; 
        cin.ignore();

        if(!op){
            break;
        }

        if(op >= 2 and op <= 6 and c.vacia()){
            cout << "Aun no hay aldeanos capturados" << endl;
            continue;
        }

        cout << endl;

        switch (op){
        case 1:
        {
            string opc;
            Aldeano a;
            cout << "a. Agregar al final" << endl;
            cout << "b. Agregar al inicio" << endl;
            cout << "Opcion: ";
            getline(cin, opc);

            cout << endl;

            if(opc == "a" or opc == "b"){
                cin >> a;
            }

            if(opc == "a"){
                c.agregarInicio(a);
                cout << "Aldeano agregado...";
            }
            else if(opc == "b"){
                c.agregarFinal(a);
                cout << "Aldeano agregado...";
            }
            else{
                cout << "Opcion incorrecta";
            }
        }
            break;
        case 2:
        {
            string opc;
            cout << "a. Eliminar por nombre" << endl;
            cout << "b. Eliminar aldeanos donde su salud sea menor a x" << endl;
            cout << "c. Eliminar aldeanos donde su edad sea mayor igual a 60";
            cout << "Opcion: ";
            getline(cin, opc);
            cout << endl;

            if(opc == "a"){
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);

                c.eliminarNombre(nombre);
            }

            if(opc == "b"){
                float x;
                cout << "Valor de x: ";
                cin >> x;
                c.eliminarSalud(x);
            }

            if(opc == "c"){
                c.eliminarEdad();
            }

            if(opc >= "a" and opc <= "c"){
                cout << "Eliminado(s)...";
            }

            else{
                cout << "Opcion incorrecta";
            }
        }
            break;
        case 3:
        {
            string opc;
            cout << "a. Por nombre" << endl;
            cout << "b. Por edad" << endl;
            cout << "c. Por salud" << endl;
            cout << "Opcion:";
            getline(cin, opc);
            cout << endl;

            if(opc == "a"){
                c.ordenarNombre();
            }
            if(opc == "b"){
                c.ordenarEdad();
            }
            if(opc == "c"){
                c.ordenarSalud();
            }
            if(opc >= "a" and opc <= "c"){
                cout << "Clasificado...";
            }
            else{
                cout << "Opcion incorrecta";
            }
        }
            break;
        case 4:
        {
            string nombre;
            Aldeano aux;
            cout << "Nombre del aldeano a buscar: ";
            getline(cin, nombre);
            aux.setNombre(nombre);

            Aldeano *ptr = c.buscar(aux);
            if(ptr == nullptr){
                cout << "No encontrado";
                break;
            }
            else{
                cout << "Aldeano encontrado:" << endl;
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(10) << "Edad";
                cout << setw(15) << "Genero";
                cout << setw(10) << "Salud";
                cout << endl;
                cout << *ptr;
            }            
        }
            break;
        case 5:
        {
            string nombre;
            Aldeano aux;
            cout << "Nombre del aldeano a buscar: ";
            getline(cin, nombre);
            aux.setNombre(nombre);

            Aldeano *ptr = c.buscar(aux);
            if(ptr == nullptr){
                cout << "No encontrado";
                break;
            }
            else{
                string opc;
                string aux;

                cout << "Aldeano a modificar:" << endl;
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(10) << "Edad";
                cout << setw(15) << "Genero";
                cout << setw(10) << "Salud";
                cout << endl;
                cout << *ptr << endl << endl;

                cout << "a. Modificar nombre" << endl;
                cout << "b. Modificar edad" << endl;
                cout << "c. Modificar genero" << endl;
                cout << "d. Modificar Salud" << endl;
                cout << "Opcion: ";
                getline(cin, opc);

                cout << endl;

                if(opc == "a"){
                    cout << "Nombre: ";
                    getline(cin, aux);
                    ptr->setNombre(aux);
                }
                if(opc == "b"){
                    size_t edad;
                    cout << "Edad: ";
                    cin >> edad;
                    ptr->setEdad(edad);
                }
                if(opc == "c"){
                    cout << "Genero: ";
                    getline(cin, aux);
                    ptr->setGenero(aux);
                }
                if(opc == "d"){
                    float salud;
                    cout << "Salud: ";
                    cin >> salud;
                    ptr->setSalud(salud);
                }
                if(opc >= "a" and opc <= "d"){
                    cout << "Modificado...";
                }
                else{
                    cout << "Opcion incorrecta";
                }
            }     
        }
            break;
        case 6:
            c.print();
            break;
        default:
            cout << "Opcion incorrecta";
            break;
        }
        cout << endl << endl;
    }
}
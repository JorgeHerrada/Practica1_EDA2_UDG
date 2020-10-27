/*

215465492 Saul Ezequiel García Ramos
219293548 Abel Alejandro villa Gonzalez
211721923 Jorge Luis Herrada Serrano 

Materia: Estructura de datos 2
Seccion: D12
Profesor: Graciela Lara Lopez

*/

#include "bolso.h"
#include <iostream>
// #include <cwchar>
// #include <clocale>
#include<stdlib.h>

using namespace std;

//Funcion que despliega el menú de opciones y retorna
//en entero la opcion del usuario
int opcMenu();

//funcion para confirmar opcion elegida
bool confirmacion(int);


//Funciones para validar entrada de datos
int tomarInt();
bool tipoIntValido(string numero);

int main() {

    //Cambiando color de consola
    system("color F1");

    Bolso bolso;

    //setlocale(LC_ALL,"");

    int opc;

    do {
        opc = opcMenu();

        switch(opc) {
        case 1: {
            bolso.insertarBolso();
        }
        break;
        case 2: {
            string claveBolso;

            do {
                cout << "Ingrese la clave a consultar: ";
                getline(cin, claveBolso);
                break;
                if(claveBolso.size() != 6) {
                    cout << "Error, la clave son solo 6 caracteres de la forma: (AAA-00)" << endl;
                } else {
                    break;
                }
            } while(true);

            bolso.consultaBolso(claveBolso);
        }
        break;
        case 3: {
            string claveBolso;

            do {
                cout << "Ingrese la clave del producto a eliminar: ";
                getline(cin, claveBolso);
                if(claveBolso.size() != 6) {
                    cout << "Error, la clave son solo 6 caracteres de la forma (AAA-00)" << endl;
                } else {
                    break;
                }
            } while(true);

            bolso.eliminarBolso(claveBolso);
        }
        break;
        case 4: {
            cout<<"Fin del programa"<<endl<<endl;
        }
        break;

        default:
            break;
        }
        system("pause");

    } while(opc!=4);

    return 0;
}

int opcMenu() {
    int opcion;

    do {
        system("cls");
        cout<<"********************";
        cout<<"Base de datos TITA MADRID";
        cout<<"********************"<<endl<<endl<<endl;
        cout<<"Captura el digito de la operacion a realizar: "<<endl<<endl;
        cout<<"1.-Insertar nuevo registro."<<endl;
        cout<<"2.-Mostrar registro por su codigo."<<endl;
        cout<<"3.-Eliminar registro de manera LOGICA."<<endl;
        cout<<"4.-SALIR"<<endl;

        opcion = tomarInt();

        switch(opcion) {
        case 1: {
            if(confirmacion(opcion) == true) {
                return opcion;
            }
        }
        break;
        case 2: {
            if(confirmacion(opcion) == true) {
                return opcion;
            }
        }
        break;
        case 3: {
            if(confirmacion(opcion) == true) {
                return opcion;
            }
        }
        break;
        case 4: {
            if(confirmacion(opcion) == true) {
                return opcion;
            }
        }
        break;
        default: {
            cout<<"Opcion invalida, intenta de nuevo con un entero entre 1 y 4."<<endl;
        }
        break;
        }
        system("pause");

    } while (opcion != 4);

    return opcion;
}

bool confirmacion(int opcion) {
    string nombreDeOpcion;
    switch (opcion) {
    case 1:
        nombreDeOpcion = "Insertar nuevo Registro";
        break;
    case 2:
        nombreDeOpcion = "Mostrar registro por su codigo";
        break;
    case 3:
        nombreDeOpcion = "Eliminar registro de manera LoGICA";
        break;
    case 4:
        nombreDeOpcion = "SALIR";
        break;
    default:
        break;
    }

    cout<<"Elegiste la opcion "<<opcion<<".-"<<nombreDeOpcion<<" "<<endl;
    cout<<"Presiona 1 para confirmar o 0 para regresar el menu de opciones."<<endl<<endl;

    int opc1 = tomarInt();
    cout<<endl<<endl;

    if(opc1 == 1) {
        return true;
    } else if(opc1 == 0) {
        return false;
    } else {
        cout<<"Opcion invalida, volveras al mena inicial"<<endl;
        return false;
    }
}

int tomarInt() {
    string numero;
    bool esValido = false;

    while(! esValido) {
        try {
            //cout<<"Ingrese un entero entre 0 y 9: ";
            getline(cin,numero);
            esValido = tipoIntValido(numero);

            if(! esValido) {
                throw numero;
            }
        } catch(string e) {
            cout<<"\n\nEl entero: "<<e<<" no es valido."<<endl;
        }
    }
    return atoi(numero.c_str());
}

bool tipoIntValido(string numero) {
    int inicio=0;
    if (numero.length()==0)
        return 0; //false
    if(numero[0] == '+' || numero[0] == '-') {
        inicio = 1;
        if (numero.length() == 1)
            return 0;
    }
    for (int i=inicio; i<numero.length(); i++) {
        if(! isdigit(numero[i]))
            return 0;
    }
    return 1;
}


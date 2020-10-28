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
#include<stdlib.h>

using namespace std;

//Función que despliega el menú de opciones y retorna
//en entero la opción del usuario
int opcMenu();

//función para confirmar opción elegida
bool confirmacion(int);

//Funciones para validar entrada de datos
int tomarInt();
bool tipoIntValido(string numero);

int main() {

    system("color F1");//Cambiando color de consola

    //SE CREA UN OBJETO DE LA CLASE BOLSO
    Bolso bolso;

    int opc;

    do {
        opc = opcMenu();// DESPLIEGA EL MENÚ DE OPCIONES Y RETORNA
                        // UN INT CON LA OPCIÓN DEL USUARIO

        switch(opc) {
        case 1: 
        {
            bolso.insertarBolso();//SE MANDA LLAMAR LA FUNCION DE INSERTAR BOLSO
        }
        break;

        case 2: 
        {
            string claveBolso;

            do 
            {
                cout << "Ingrese la clave a consultar: ";
                getline(cin, claveBolso);//MANDAMOS COMO PARAMETRO LA CLAVE
                //break;
                if(claveBolso.size() != 6) //CONFIRMAMOS QUE LOS DATOS CUMPLAN CON LA FORMA DE CAMPO CLAVE
                {
                    cout << "Error, la clave son solo 6 caracteres de la forma: (AAA-00)" << endl;
                } 
                else 
                {
                    break;
                }
            } while(true);

            //MANDA LA CLAVE DEL BOLSO COMO PARAMETRO PARA REALIZAR LA BUSQUEDA Y DESPLEGAR INFORMACIÓN
            bolso.consultaBolso(claveBolso);
        }
        break;

        case 3: 
        {
            string claveBolso;

            do 
            {
                cout << "Ingrese la clave del producto a eliminar: ";
                getline(cin, claveBolso);
                if(claveBolso.size() != 6) //CONFIRMAMOS QUE LOS DATOS CUMPLAN CON LA FORMA DE CAMPO CLAVE
                {
                    cout << "Error, la clave son solo 6 caracteres de la forma (AAA-00)" << endl;
                } 
                else 
                {
                    break;
                }
            } while(true);

            //MANDA LA CLAVE DEL BOLSO COMO PARAMETRO PARA REALIZAR LA BUSQUEDA, ELIMINAR Y DESPLEGAR INFORMACIÓN
            bolso.eliminarBolso(claveBolso);
        }
        break;

        case 4: 
        {
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


//Función que despliega el menú de opciones y retorna
//en entero la opción del usuario
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

        opcion = tomarInt();//PEDIMOS AL USUARIO INGRESAR SU OPCION COMO ENTERO Y VALIDAMOS LA ENTRADA

        //ENTRAMOS AL CASO CORRESPONDIENTE SEGUN EL VALOR DE OPCION INGRESADO POR USUARIO
        switch(opcion) {
        case 1: 
        {
            if(confirmacion(opcion) == true) //CONFIRMA LA OPCION ELEGIDA
            {
                return opcion;//RETORNA EL INT DE LA OPCION 
            }
        }
        break;

        case 2: 
        {
            if(confirmacion(opcion) == true) //CONFIRMA LA OPCION ELEGIDA
            {
                return opcion;//RETORNA EL INT DE LA OPCION 
            }
        }
        break;

        case 3: 
        {
            if(confirmacion(opcion) == true) //CONFIRMA LA OPCION ELEGIDA
            {
                return opcion;//RETORNA EL INT DE LA OPCION 
            }
        }
        break;

        case 4: 
        {
            if(confirmacion(opcion) == true) //CONFIRMA LA OPCION ELEGIDA
            {
                return opcion;//RETORNA EL INT DE LA OPCION 
            }
        }
        break;

        default: 
        {
            cout<<"Opcion invalida, intenta de nuevo con un entero entre 1 y 4."<<endl;
        }
        break;

        }
        system("pause");

    } while (opcion != 4);

    return opcion;
}

//FUNCION PARA QUE USUARIO CONFIRME LA OPCION ELEGIDA, TRUE PARA CONFIRMAR O FALSE PARA VOLVER AL MENÚ
bool confirmacion(int opcion) {
    string nombreDeOpcion;

    //ENTRAMOS AL CASO CORRESPONDIENTE SEGUN EL VALOR DE OPCION INGRESADO POR USUARIO
    switch (opcion) {
    case 1:
        nombreDeOpcion = "Insertar nuevo Registro";
        break;
    case 2:
        nombreDeOpcion = "Mostrar registro por su codigo";
        break;
    case 3:
        nombreDeOpcion = "Eliminar registro de manera LOGICA";
        break;
    case 4:
        nombreDeOpcion = "SALIR";
        break;
    default:
        break;
    }

    //DESPLEGAMOS LA OPCION ELEGIDA PARA QUE USUARIO CONFIRME
    cout<<"\nElegiste la opcion "<<opcion<<".-"<<nombreDeOpcion<<" "<<endl;
    cout<<"Presiona 1 para confirmar o 0 para regresar el menu de opciones."<<endl<<endl;

    int opc1 = tomarInt();
    cout<<endl;

    if(opc1 == 1) //SI CONFIRMA CON 1 SE RETORNA TRUE
    { 
        return true;
    } 
    else if(opc1 == 0) //SI CANCELA CON 0, RETORNA FALSE
    {
        return false;
    } 
    else //CUALQUIER OPCION INVALIDA RETORNA FALSE
    {
        cout<<"Opcion invalida, volveras al menu inicial"<<endl;
        return false;
    }
}

//FUNCION PARA VALIDAR LA ENTRADA DE ENTEROS 
//TOMA UNA CADENA, LA ANALISA Y SI ES VALIDA LA CONVIERTE A ENTERO
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

//FUNCION PARA VALIDAR ENTRADA DE ENTEROS
//RECIBE LA CADENA QUE INGRESA EL USUARIO Y ANALISA QUE
//CONTENGA SOLO NUMEROS VALIDOS, RETORNA TRUE SI ES VALIDO
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


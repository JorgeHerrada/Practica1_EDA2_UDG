#include "bolso.h"
using namespace std;


void Bolso::insertarBolso() {
    // SE ABRE EL ARCHIVO EN MODO ESCRITURA APP (ESCRIBE AL FINAL SI HAY CONTENIDO, SINO LO CREA)
    ofstream archivo("archivo.txt", ios::app);

    // SI EL ARCHIVO NO SE PUDO ABRIR = ERROR
    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    // SINO CONTINUA
    else {

        string tempString;
        int tam1, tam2, tam3;

        cout << "Ingrese el nombre: ";
        getline(cin, nombre);

        cout << "Ingrese la descripcion: ";
        getline(cin, descripcion);

        clave = generarClave(nombre);

        // SE OBTIENE LA LONGITUD DE LOS CAMPOS
        tam1 = clave.size();
        tam2 = nombre.size();
        tam3 = descripcion.size();

        // SE CONVIERTE LA LONGITUD DE CLAVE A CHAR[]
        tempString = to_string(tam1);
        char tempLenClave[sizeof(int)];
        strcpy(tempLenClave, tempString.c_str());

        // SE CONVIERTE LA CLAVE A CHAR[]
        char tempClave[tam1];
        strcpy(tempClave, clave.c_str());

        // SE CONVIERTE LA LONGITUD DE NOMBRE A CHAR[]
        tempString = to_string(tam2);
        char tempLenNombre[sizeof(int)];
        strcpy(tempLenNombre, tempString.c_str());

        // SE CONVIERTE NOMBRE A CHAR[]
        char tempNombre[tam2];
        strcpy(tempNombre, nombre.c_str());

        // SE CONVIERTE LA LONGITUD DE DESCRIPCION A CHAR[]
        tempString = to_string(tam3);
        char tempLenDescripcion[sizeof(int)];
        strcpy(tempLenDescripcion, tempString.c_str());

        // SE CONVIERTE DESCRIPCION A CHAR[]
        char tempDescripcion[tam3];
        strcpy(tempDescripcion, descripcion.c_str());

        // SE ESCRIBE EN EL ARCHIVO LOS CAMPOS DEL REGISTRO
        // SE ESCRIBE SU LONGITUD Y DESPUES SU VALOR
        archivo.write(tempLenClave, sizeof(int));
        archivo.write(tempClave, tam1);

        archivo.write(tempLenNombre, sizeof(int));
        archivo.write(tempNombre, tam2);

        archivo.write(tempLenDescripcion, sizeof(int));
        archivo.write(tempDescripcion, tam3);

        cout << endl << "Se ingreso el siguiente registro:" << endl
             << "Clave: " << clave << endl
             << "Nombre: " << nombre << endl
             << "Descripcion: " << descripcion << endl << endl;
    }

    // CERRAMOS EL ARCHIVO
    archivo.close();
}

void Bolso::consultaBolso(string claveBolso) {
    // SE ABRE EL ARCHIVO EN MODO LECTURA
    ifstream archivo("archivo.txt");

    // SI NO SE PUDO ABRIR = ERROR
    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    // SI NO CONTINUA
    else {
        int tam1, tam2, tam3; // VARIABLES PARA LONGITUD VARIABLE DE LOS CAMPOS
        string limpiar("\0"); // CADENA PARA LIMPIAR ARREGLOS DE CARACTERES
        char tempLen[sizeof(int)]; // ARREGO TEMPORAL PARA ALMACENAR LA LONGITUD DE LOS CAMPOS
        bool encontrado(false); // BANDERA PARA INDICAR SI EL REGISTRO SE ENCONTRO

        // SI NO LLEGA AL FINAL DEL ARCHIVO CONTINUA
        while(!archivo.eof()) {
            archivo.read(tempLen, sizeof(int)); // SE LEE LA LONGITUDO DEL CAMPO CLAVE
            tam1 = atoi(tempLen); // SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempClave[tam1]; // SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempClave, tam1); // SE LEE EL CAMPO CLAVE
            tempClave[tam1] = '\0'; // ASIGNAMOS EL CARACTER NULO MANUALMENTE
            clave = tempClave; // LO PASAMOS AL ATRIBUTO DE LA CLASE

            strcpy(tempLen, limpiar.c_str()); // SE LIMPIA EL ARREGLO DE CARACTERES

            archivo.read(tempLen, sizeof(int));
            tam2 = atoi(tempLen);
            char tempNombre[tam2];
            archivo.read(tempNombre, tam2);
            tempNombre[tam2] = '\0';
            nombre = tempNombre;

            strcpy(tempLen, limpiar.c_str());

            archivo.read(tempLen, sizeof(int));
            tam3 = atoi(tempLen);
            char tempDescripcion[tam3];
            archivo.read(tempDescripcion, tam3);
            tempDescripcion[tam3] = '\0';
            descripcion = tempDescripcion;

            strcpy(tempLen, limpiar.c_str());

            // SI LA CLAVE QUE BUSCA ES IGUAL A LA CLAVE LEIDA EN EL REGISTRO ENTONCES SE IMPRIME, SE ACTIVA LA BANDERA Y TERMINA LA BUSQUEDA
            if(claveBolso == clave) {
                cout << endl << "Se encontro:" << endl
                     << "Clave: " << clave << endl
                     << "Nombre: " << nombre << endl
                     << "Descripcion: " << descripcion << endl;

                encontrado = true;
                break;
            }
        }
        // SI NO SE ACTIVO LA BANDERA, NO SE ENCONTRO
        if(!encontrado) {
            cout << endl << "No se encontro" << endl;
        }
    }

    // SE CIERRA EL ARCHIVO
    archivo.close();
}

void Bolso::eliminarBolso(string claveBolso) {
   // SE ABRE EL ARCHIVO EN MODO LECTURA
    ifstream archivo("archivo.txt");
    //SE ABRE EL ARCHIVO TEMPORAL EN ESCRITURA
    ofstream archivot("archivot.txt", ios::app);

    // SI NO SE PUDO ABRIR = ERROR
    if(!archivo.is_open() || !archivot.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    // SI NO CONTINUA
    else {
        int tam1, tam2, tam3; // VARIABLES PARA LONGITUD VARIABLE DE LOS CAMPOS
        string limpiar("\0"); // CADENA PARA LIMPIAR ARREGLOS DE CARACTERES
        char tempLen1[sizeof(int)],tempLen2[sizeof(int)],tempLen3[sizeof(int)]; // ARREGLO PARA ALMACENAR LA LONGITUD DE LOS CAMPOS
		bool encontrado(false); // BANDERA PARA INDICAR SI EL REGISTRO SE ENCONTRO

        // SI NO LLEGA AL FINAL DEL ARCHIVO CONTINUA
        while(!archivo.eof()) {
            archivo.read(tempLen1, sizeof(int)); // SE LEE LA LONGITUDO DEL CAMPO CLAVE
            tam1 = atoi(tempLen1); // SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempClave[tam1]; // SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempClave, tam1); // SE LEE EL CAMPO CLAVE
            tempClave[tam1] = '\0'; // ASIGNAMOS EL CARACTER NULO MANUALMENTE
            clave = tempClave; // LO PASAMOS AL ATRIBUTO DE LA CLASE

            //PRUEBA PARA CONTROLAR DUPLICACION 
            if(archivo.eof()){
                break;
            }

            archivo.read(tempLen2, sizeof(int));
            tam2 = atoi(tempLen2);
            char tempNombre[tam2];
            archivo.read(tempNombre, tam2);
            tempNombre[tam2] = '\0';
            nombre = tempNombre;


            archivo.read(tempLen3, sizeof(int));
            tam3 = atoi(tempLen3);
            char tempDescripcion[tam3];
            archivo.read(tempDescripcion, tam3);
            tempDescripcion[tam3] = '\0';
            descripcion = tempDescripcion;


            // SI LA CLAVE QUE BUSCA ES IGUAL A LA CLAVE LEIDA EN EL REGISTRO ENTONCES SE AGREGA EL ASTERISCO AL INICIO DE LA CLAVE
			//SE ACTIVA LA BANDERA DE BUSQUEDA
            if(claveBolso == clave) {
            	//AMPLIAMOS LA LONGITUD DE LA CLAVE PARA AGREGAR EL *
            	string tempString;
            	int LongD=tam1+1;
            	tempString = to_string(LongD);
        		strcpy(tempLen1, tempString.c_str());
        		//AGREGAMOS EL ASTERISCO AL INICIO DE LA CADENA DE LA CLAVE Y LA REGRESAMOS A CHAR PAR APODER ALMACENARLA
        		
            	tempString = "*"+claveBolso;
            	char auxClave[LongD];
        		strcpy(auxClave, tempString.c_str());
        		
        		
            	// ESCRIBIMOS EN EL ARCHIVO CON LA NUEVA MODIFICACION 
            	archivot.write(tempLen1, sizeof(int));
		        archivot.write(auxClave, LongD);
		
		        archivot.write(tempLen2, sizeof(int));
		        archivot.write(tempNombre, tam2);
		
		        archivot.write(tempLen3, sizeof(int));
		        archivot.write(tempDescripcion, tam3);
		        //MOSTRAMOS EN PANTALLA EL REGISTRO ELIMINADO
                cout << endl << "Registro eliminado:" << endl
                     << "Clave: " << tempString << endl
                     << "Nombre: " << nombre << endl
                     << "Descripcion: " << descripcion << endl;
				
                encontrado = true;
            }
            //PASAMOS EL REGISTRO IGUAL A COMO SE ENCUENTRA
            else {
            	archivot.write(tempLen1, sizeof(int));
		        archivot.write(tempClave, tam1);
		
		        archivot.write(tempLen2, sizeof(int));
		        archivot.write(tempNombre, tam2);
		
		        archivot.write(tempLen3, sizeof(int));
		        archivot.write(tempDescripcion, tam3);
			}
        }
        // SI NO SE ACTIVO LA BANDERA, NO SE ENCONTRO
        if(!encontrado) {
            cout << endl << "No se encontro" << endl;
        }
    }

    // SE CIERRA EL ARCHIVO
    archivo.close();
    archivot.close();
    //ELIMINAMOS EL ORIGINAL Y SOBREESCRIBIMOS EL NOMBRE DEL TEMPORAL POR EL DE EL ORIGINAL
    remove("archivo.txt");
    rename("archivot.txt", "archivo.txt");
}




// GENERA UNA CLAVE PARA EL BOLSO
string Bolso::generarClave(string nombreBolso) {
    // SEMILLA PARA GENERAR NUMEROS ALEATORIOS
    srand(time(NULL));

    string claveFinal;
    int num1, num2, inicio = 0, fin = 9;

    // AGREGAMOS LAS TRES PRIMERAS LETRAS DEL NOMBRE EN MAYUSCULA
    for(int i = 0; i < 3; i++) {
        claveFinal += toupper(nombreBolso[i]);
    }

    // AGREGAR EL GUION
    claveFinal += '-';

    // GENERAR LOS NUMEROS ALEATORIOS DESDE 0 AL 9
    num1 = rand()%(fin-inicio+1)+inicio;
    num2 = rand()%(fin-inicio+1)+inicio;

    // AGREGAR LOS NUMEROS ALEATORIOS
    claveFinal += to_string(num1);
    claveFinal += to_string(num2);


    return claveFinal;
}


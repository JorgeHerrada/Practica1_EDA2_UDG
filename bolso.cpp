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

        string tempString;// VARIABLE PARA ALMACENAR EL TAMAÑO DE LOS CAMPOS EN STRING
        int tam1, tam2, tam3;// VARIABLE PARA ALMACENAR EL TAMAÑO DE LOS CAMPOS EN STRING

        cout << "Ingrese el nombre: ";//CAPTURAS DE NOMBRE
        getline(cin, nombre);

        cout << "Ingrese la descripcion: ";//CAPTURAS DE DESCRIPCION
        getline(cin, descripcion);

        clave = generarClave(nombre);//SE MANDA LLAMAR LA FUNCION GENERAR CLAVE QUE DEVUELVE UNA CLAVE PARA LA CLAVE, RECIBE EL NOMBRE PARA FORMARLA

        // SE OBTIENE LA LONGITUD DE LOS CAMPOS
        tam1 = clave.size();
        tam2 = nombre.size();
        tam3 = descripcion.size();

        // SE CONVIERTE LA LONGITUD DE CLAVE A CHAR[]
        tempString = to_string(tam1); //CONVERTIMOS EL TAMA�O 1 A STRING
        char tempLenClave[sizeof(int)];//CREAMOS LA VARIABLE DE CADENA DE CARACTERES, DE ACUERDO AL TAMA�O
        strcpy(tempLenClave, tempString.c_str());//COPIAMOS EL STRING A LA CADENA DE CARACTERES

        // SE CONVIERTE LA CLAVE A CHAR[]
        char tempClave[tam1];//SE CREA LA VARIABLE CHAR
        strcpy(tempClave, clave.c_str());//LE PASAS A TEMCLAVE LO QUE TENGA LA CLAVE


        // SE CONVIERTE LA LONGITUD DE NOMBRE A CHAR[]
        tempString = to_string(tam2);//CONVERTIMOS EL TAMA�O 2 A STRING
        char tempLenNombre[sizeof(int)];//CREAMOS LA VARIABLE DE CADENA DE CARACTERES, DE ACUERDO AL TAMA�O
        strcpy(tempLenNombre, tempString.c_str());//COPIAMOS EL STRING A LA CADENA DE CARACTERES

        // SE CONVIERTE NOMBRE A CHAR[]
        char tempNombre[tam2];//SE CREA LA VARIABLE CHAR
        strcpy(tempNombre, nombre.c_str());//LE PASAS A TEMPNOMBRE LO QUE TENGA LA CLAVE

        // SE CONVIERTE LA LONGITUD DE DESCRIPCION A CHAR[]
        tempString = to_string(tam3);
        char tempLenDescripcion[sizeof(int)];
        strcpy(tempLenDescripcion, tempString.c_str());

        // SE CONVIERTE DESCRIPCION A CHAR[]
        char tempDescripcion[tam3];
        strcpy(tempDescripcion, descripcion.c_str());

        // SE ESCRIBE EN EL ARCHIVO LOS CAMPOS DEL REGISTRO
        // SE ESCRIBE SU LONGITUD Y DESPUES SU VALOR
        archivo.write(tempLenClave, sizeof(int));//SE ESCRIBE LA LONGITUD DEL ATRIBUTO CLAVE
        archivo.write(tempClave, tam1);//SE ESCRIBE LA CLAVE

        archivo.write(tempLenNombre, sizeof(int));//SE ESCRIBE LA LONGITUD DEL NOMBRE
        archivo.write(tempNombre, tam2);// SE ESCRIBE LA CLAVE


        archivo.write(tempLenDescripcion, sizeof(int));
        archivo.write(tempDescripcion, tam3);

        // SE IMPRIME EN PANTALLA LO QUE SE ESCRIBIO
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

            archivo.read(tempLen, sizeof(int));// SE LEE LA LONGITUDO DEL NOMBRE
            tam2 = atoi(tempLen);// SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempNombre[tam2];// SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempNombre, tam2);//SE LEE EL CAMPO NOMBRE
            tempNombre[tam2] = '\0';// ASIGNAMOS EL CARACTER NULO MANUALMENTE
            nombre = tempNombre;// LO PASAMOS AL ATRIBUTO DE LA CLASE

            strcpy(tempLen, limpiar.c_str());// SE LIMPIA EL ARREGLO DE CARACTERES

            archivo.read(tempLen, sizeof(int));// SE LEE LA LONGITUD DE LA DESCRIPCION
            tam3 = atoi(tempLen);// SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempDescripcion[tam3];// SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempDescripcion, tam3);//SE LEE EL CAMPO NOMBRE
            tempDescripcion[tam3] = '\0';// ASIGNAMOS EL CARACTER NULO MANUALMENTE
            descripcion = tempDescripcion;// LO PASAMOS AL ATRIBUTO DE LA CLASE

            strcpy(tempLen, limpiar.c_str());// SE LIMPIA EL ARREGLO DE CARACTERES

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

            archivo.read(tempLen2, sizeof(int));// SE LEE LA LONGITUDO DEL CAMPO NOMBRE
            tam2 = atoi(tempLen2);// SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempNombre[tam2];// SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempNombre, tam2);// SE LEE EL CAMPO NOMBRE
            tempNombre[tam2] = '\0';// ASIGNAMOS EL CARACTER NULO MANUALMENTE
            nombre = tempNombre;// LO PASAMOS AL ATRIBUTO DE LA CLASE


            archivo.read(tempLen3, sizeof(int));// SE LEE LA LONGITUDO DEL CAMPO DESCRIPCION
            tam3 = atoi(tempLen3);// SE CONVIERTE EL ARREGLO TEMPORAL A ENTERO
            char tempDescripcion[tam3];// SE CREA EL ARREGLO DE CARACTERES PARA LA LECTURA DEL CAMPO
            archivo.read(tempDescripcion, tam3);// SE LEE EL CAMPO DESCRIPCION
            tempDescripcion[tam3] = '\0';// ASIGNAMOS EL CARACTER NULO MANUALMENTE
            descripcion = tempDescripcion;// LO PASAMOS AL ATRIBUTO DE LA CLASE


            // SI LA CLAVE QUE BUSCA ES IGUAL A LA CLAVE LEIDA EN EL REGISTRO ENTONCES SE AGREGA EL ASTERISCO AL INICIO DE LA CLAVE
			//SE ACTIVA LA BANDERA DE BUSQUEDA
            if(claveBolso == clave) 
            {
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
		
                // ESCRIBIMOS EN EL ARCHIVO CON LA NUEVA MODIFICACION 
		        archivot.write(tempLen2, sizeof(int));
		        archivot.write(tempNombre, tam2);
		
                // ESCRIBIMOS EN EL ARCHIVO CON LA NUEVA MODIFICACION 
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
            else 
            {
            	archivot.write(tempLen1, sizeof(int));
		        archivot.write(tempClave, tam1);
		
		        archivot.write(tempLen2, sizeof(int));
		        archivot.write(tempNombre, tam2);
		
		        archivot.write(tempLen3, sizeof(int));
		        archivot.write(tempDescripcion, tam3);
			}
        }
        // SI NO SE ACTIVO LA BANDERA, NO SE ENCONTRO
        if(!encontrado) 
        {
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


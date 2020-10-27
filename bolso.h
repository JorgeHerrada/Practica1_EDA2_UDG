#ifndef BOLSO_H
#define BOLSO_H

#include <iostream>
#include <fstream> // LIBRERIA DE ARCHIVOS
#include <ctime> // LIBRERIA PARA GENERAR NUMEROS ALEATORIOS
#include <string> // CONVERTIR INT A STRINGS
#include <cstring> // CONVERTIR STRING A CHAR[]

class  Bolso {
private:
    std::string clave;
    std::string nombre;
    std::string descripcion;

public:
    void insertarBolso();
    void consultaBolso(std::string);
    void eliminarBolso(std::string);
    std::string generarClave(std::string);
};

#endif // BOLSO_H


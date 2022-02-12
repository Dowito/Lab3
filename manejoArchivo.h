#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H
#include <iostream>
#include <fstream>
#include <Auxiliar.h>

using namespace std;

unsigned long long tamArchivo(char *direccion);
/*
name->Direccion del archivo a abrir.
retorna el tamaño del archivo.
*/

char *rArchivo(char *cad);
/*
cad->Cadena con el directorio y nombre de archivo a abrir. Ej: "../Lab3/Data_base/natural.txt"
lee un archivo.txt(texo natural) y returna una cadena de caracteres que contiene todos los
caracteres del texto leido
*/

void writeArchivo(char *name, char *cad);
/*
name->Cadena de caracteres. Es el nombre del archivo a escribir
cad->Cadena de caracteres que se escribiran en el texto.
Escribe una cadena de caracteres en un texto.
*/

char *bits2Byte(bool *arrBits, unsigned long long tamArrBits);
/*
arrBits->arreglo bits.
tamBits->tamaño de arrBits
Agrupa 8 bits para formar 1 byte del mas al menos significativo por cada bloque.
Retorna una cadena de caracteres formado por los bytes resultantes.
*/

bool *codificacionMetodo1(unsigned long long n, bool *arrBits, unsigned long long tamArrBits);
/*
n->Semilla para la codificacion
arrBits->Arreglo de booleanos(bits)
tamArrBits->Tamaño de arrBits
Codifica a arrBits.
Retorna cadena booleana (bits) encriptada
*/

bool *decodificacionMetodo2(unsigned long long n, bool *arrEncript, unsigned long long tamArrEncript);
/*
n->Semilla
arrEncript->Arreglo de booleanos(bits)
tamArrEncript->Tamaño de arrEncript
Decodifica a arrEncript
retorna cadena booleana (bits) desencriptados
*/

#endif // MANEJOARCHIVO_H

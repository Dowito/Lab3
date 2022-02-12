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

char *writeArchivo(char *name, char *cad);
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

bool *CodificacionMet1(unsigned long long n, bool *arrBits, unsigned long long tamArrBits);
/*
n->Semilla. segunda la semilla se codificara los datos de manera diferente
arrBits->Arreglo de booleanos, representan una cadena de bits
se encripta arrBits.
Retorna dicha cadena de bits encriptada
*/
#endif // MANEJOARCHIVO_H

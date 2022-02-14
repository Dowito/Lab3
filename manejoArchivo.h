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

char *readArchivo(char *name);
/*
cad->Cadena con la ruta/nombre de archivo a abrir. Ej: "../Lab3/Data_base/natural.txt"
Lee un archivo. (Lo abre en binario)
Retorna una cadena de caracteres con toda la informacion que hay en el texto.
*/

void writeArchivo(char *name, char *cad);
/*
name->Cadena de caracteres. Es el nombre del archivo a escribir
cad->Cadena de caracteres que se escribiran en el texto.
Escribe una cadena de caracteres en un texto.
El texto se abre en modo binario.
*/

bool archivosIguales(char *name1, char *name2); //Hice esta funcion para hacer pruebas.
/*
name1 y name2 ruta/nombre de los archivos a comprar
retorna true si son iguales, de lo contrario retorna false
*/

bool *getBits(char *cad);
/*
*cad->Recibe una cadena de caracteres
Guarda cada uno de los bits totales de cad de manera individual en un arreglo
de booleanos
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

bool *decodificacionMetodo1(unsigned long long n, bool *arrEncript, unsigned long long tamArrEncript);
/*
n->Semilla
arrEncript->Arreglo de booleanos(bits)
tamArrEncript->Tamaño de arrEncript
Decodifica a arrEncript
retorna cadena booleana (bits) desencriptados
*/

void metodo1C(unsigned long long semilla, char *inName, char *outName);
/*
semilla->Numero entero necesario para la codificacion.
inName->Ruta/nombre del archivo que se codificara.
outName->Ruta/nombre del archivo donde se guardara la informacion encriptada.
Lee un archivo, lo codifica y guarda la informacion encriptada en otro archivo.
*/

void metodo1D(unsigned long long semilla, char *inName, char *outName);
/*
semilla->Numero entero
inName->Ruta/nombre del archivo que se decodificara
outName->Ruta/nombre del archivo donde se guardara la informacion decodificada
lee un archivo, lo decodifica y guarda la informacion en otro archivo
*/

bool *codificacionMetodo2(unsigned long long n, bool *arrBits, unsigned long long tamArrBits);
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

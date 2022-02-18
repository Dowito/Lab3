#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H
#include <iostream>
#include <fstream>
#include <Auxiliar.h>

using namespace std;

unsigned long long tamArchivo(char *name);
/*
name->Direccion del archivo a abrir.
retorna el tamaño del archivo.
*/

unsigned long long tamArchivo(string name);
/*
name->Direccion del archivo a abrir.
retorna el tamaño del archivo.
*/

char *readArchivo(char *name);
/*
name->Cadena con la ruta/nombre de archivo a abrir. Ej: "../Lab3/Data_base/natural.txt"
Lee un archivo. (Lo abre en binario)
Retorna una cadena de caracteres con toda la informacion que hay en el texto.
*/

string readArchivo(string name);
/*
name->String con la ruta/nombre de archivo a abrir. Ej: "../Lab3/Data_base/natural.txt"
Lee un archivo. (Lo abre en binario)
Retorna un string con toda la informacion que hay en el texto.
*/

void writeArchivo(char *name, char *cad, unsigned long long tam);
/*
name->Cadena de caracteres. Es el nombre del archivo a escribir
cad->Cadena de caracteres que se escribiran en el texto.
tam->tam de cad, o hasta que posicion se va a escribir.
Escribe una cadena de caracteres en un texto.
El texto se abre en modo binario.
*/

void writeArchivo(string name, string str);
/*
name->string. Es la Ruta/nombre del archivo a escribir
str->string que se escribira en el texto.
Escribe un string en un texto.
El texto se abre en modo binario.
*/

bool archivosIguales(char *name1, char *name2); //Hice esta funcion para hacer pruebas.
/*
name1 y name2 ruta/nombre de los archivos a comprar
retorna true si son iguales, de lo contrario retorna false
*/

bool archivosIguales(string name1, string name2); //Hice esta funcion para hacer pruebas.
/*
name1 y name2 ruta/nombre de los archivos a comparar
retorna true si los archivos son iguales, de lo contrario retorna false
*/

bool *getBits(char *cad, unsigned long long tamCad);
/*
*cad->Recibe una cadena de caracteres
tamCad->Tamaño de cad
Guarda cada uno de los bits totales de cad de manera individual en un arreglo
de booleanos
*/

bool *getBits(string str);
/*
*str->Recibe un string
Guarda cada uno de los bits de str de manera individual en un arreglo
de booleanos
*/

char *bits2Byte(bool *arrBits, unsigned long long tamArrBits);
/*
arrBits->arreglo bits.
tamBits->tamaño de arrBits
Agrupa 8 bits para formar 1 byte del mas al menos significativo por cada bloque.
Retorna una cadena de caracteres formado por los bytes resultantes.
*/

string bits2ByteStr(bool *arrBits, unsigned long long tamArrBits);
/*
arrBits->arreglo de bits.
tamBits->tamaño de arrBits
Agrupa 8 bits para forma un byte por cada bloque.
Retorna un string formado por los bytes resultantes.
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

void metodo2C(unsigned long long semilla, string inName, string outName);
/*
semilla->Numero entero necesario para la codificacion.
inName->Ruta/nombre del archivo que se codificara.
outName->Ruta/nombre del archivo donde se guardara la informacion encriptada.
Lee un archivo, lo codifica y guarda la informacion encriptada en otro archivo.
*/

void metodo2D(unsigned long long semilla, string inName, string outName);
/*
semilla->Numero entero
inName->Ruta/nombre del archivo que se decodificara
outName->Ruta/nombre del archivo donde se guardara la informacion decodificada
lee un archivo, lo decodifica y guarda la informacion en otro archivo
*/

string getInfo(unsigned long long semilla, string inName);
/*
Retorna un string con la info decodificada de un texto.
*/

#endif // MANEJOARCHIVO_H

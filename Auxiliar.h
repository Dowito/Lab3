#ifndef AUXILIAR_H
#define AUXILIAR_H
#include <iostream>
using namespace std;

unsigned long long lenCad(char *cad); //Reutilizacion funcion del lab2.
/*
cad -> Es una cadena de caracteres
Retorna el tamaño de la cadena sin incluir su ultimo caracter nulo
*/

unsigned long long lenCad(string cad);
/*
cad -> Es una cadena de caracteres
Retorna el tamaño de la cadena sin incluir su ultimo caracter nulo
*/

bool ifCadSame(char *cad1, char *cad2); //Para poder hacer archivosIguales()
/*
cad1 y cad2 cadenas de caracteres a comparar
retorna true si cad1 y cad2 son iguales de lo contrario retorna false
*/

bool ifCadSame(string str1, string str2); //Para poder hacer archivosIguales()
/*
str1 y str2 strings a comparar
retorna true si str1 y str2 son iguales de lo contrario retorna false
*/

#endif // AUXILIAR_H

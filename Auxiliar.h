#ifndef AUXILIAR_H
#define AUXILIAR_H

unsigned long long lenCad(char* cad); //Reutilizacion funcion del lab2.
/*
cad -> Es una cadena de caracteres
Retorna el tamaño de la cadena sin incluir su ultimo caracter nulo
*/

bool ifArrSame(char *arreglo1, char *arreglo2, unsigned long long tam1, unsigned long long tam2); //Codigo lab2
/*
 * arreglo1->Arreglo de char
 * arreglo2->Arreglo de char
 * tam1-> cantidad de elementos del arreglo1
 * tam2-> cantidad de elementos del arreglo2
 * Retorna true si cada uno de los elementos del arreglo1 y del arreglo2 son iguales
 */



#endif // AUXILIAR_H

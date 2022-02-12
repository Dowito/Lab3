#ifndef AUXILIAR_H
#define AUXILIAR_H

unsigned long long lenCad(char* cad); //Reutilizacion funcion del lab2.
/*
cad -> Es una cadena de caracteres
Retorna el tamaño de la cadena sin incluir su ultimo caracter nulo
*/

bool *getBits(char *cad);
/*
*cad->Recibe una cadena de caracteres
Guarda cada uno de los bits totales de cad de manera individual en un arreglo
de booleanos
*/

#endif // AUXILIAR_H

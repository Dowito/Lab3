#ifndef CAJERO_H
#define CAJERO_H

#include <manejoArchivo.h>

bool validarAdmin(unsigned long long semilla, short metodo, string sudo);
/*
semilla->semilla para la decodificacion de la contraseña de admin.
metodo->Metodo de codificiacion/decodificacion a usar.
sudo->archivo donde se encuentra la contraseña del admin encriptada.
retorna true si se ingreso como arminsitrador exitosamente, de lo contrario retorna false
*/

void addUser(unsigned long long semilla, string users, string str);
/*
semilla->semilla para la decodificacion
users->Archivo donde estasn los usuarios almacenados de forma ecriptada
str-> string con formato: "cedula, clave, saldo (COP)\n"
*/

#endif // CAJERO_H

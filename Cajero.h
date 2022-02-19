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

bool validarCedula(string infoUsers, string cedula, unsigned long long &pos);
/*
infoUsers->String con la informacion de todos los usuarios
cedula->Cedula que se buscara en inforUsers
pos->variable donde se guardara la posicion de la cedula
retorna true si encuentra la cedula dentro de infoUsers, y por referencia a pos le asigna el valor
de la posicion de la primera coindicencia.
retorna false si no hay coincidencia
*/

bool validarClave(string infoUsers, string clave, unsigned long long &pos);
/*
infoUsers->string con la informacion de todos los usuarios
clave->contraseña del usuario
pos->posicion donde empieza la cedula del usuario
Apartir de infoUsers[pos] se verifica si la contraseña de dicho usuario y la que se ingreso
coinciden.
retorna true si hay coindidencia, false de lo contrario
*/

void impSaldo(string infoUsers, unsigned long long &pos);
/*
Imprime el saldo de un usuario
*/

bool validarUsuario(unsigned long long semilla, string inName, unsigned long long &pos);
/*
semilla->Semilla para la decodificacion
inName->ruta, nombre de la base de datos de los usuarios
*/
#endif // CAJERO_H

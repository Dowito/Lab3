#ifndef CAJERO_H
#define CAJERO_H

#include <manejoArchivo.h>

bool validarAdmin(unsigned long long semilla, short metodo, string sudo, string Contra);
/*
semilla->semilla para la decodificacion de la contraseña de admin.
metodo->Metodo de codificiacion/decodificacion a usar.
sudo->archivo donde se encuentra la contraseña del admin encriptada.
retorna true si se ingreso como arminsitrador exitosamente, de lo contrario retorna false
*/

void addUser(unsigned long long semilla, string users, string str);
/*
semilla->semilla para la decodificacion
users->Archivo donde estan los usuarios almacenados de forma ecriptada
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

bool validarUsuario(unsigned long long semilla, string inName, string *CC,unsigned long long &pos);
/*
semilla->Semilla para la decodificacion
inName->ruta/nombre de la base de datos de los usuarios
&pos->variable que se modificara por referencia. se inicia en 0
retorna true si un usuario a ingresado con exito de lo contrario
retorna false
*/

void impSaldo(unsigned long long semilla, string inName, unsigned long long pos);
/*
semilla->semilla para la codificacion
inName->nombre del texto con la informacion de los usuarios encriptada
pos->posicion correspondiente al saldo del usuario a imprimir
Imprime el saldo de un usuario.
*/

void retirarSaldo(unsigned long long semilla, string inName, unsigned long long retiro, unsigned long long pos);
/*
semilla->semilla para la codificacion
inName->nombre del archivo donde esta  la informacion de los usuarios encriptada
retiro->cantidad que se va a retirar
pos->posicion correspondiente al saldo del usuario
retira saldo de un usuario.
*/

void cobro(unsigned long long semilla, string outName, string infoUsers, unsigned long long pos);
/*
semilla->semilla para la codificacion
infoUsers->string con la informacion de todos los usuarios
&pos->posicion correspondiente al saldo del usuario
retirar saldo de un usuario
*/

string formatoUsuario();
/*
Retorna un string con el formato necesario para ingresar un usuario en la base de datos
*/

string *cedulaClave();
/*
retorna un arreglo de strings que se ingresa por consola
*/

#endif // CAJERO_H

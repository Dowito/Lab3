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
#endif // CAJERO_H

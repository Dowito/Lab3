#include <manejoArchivo.h>
#include <Cajero.h>
//Cajero automatico.
//Contra cacatua
int main()
{
    unsigned long long semilla = 5;
    short metodo = 2;
    string natural = "../Lab3/Data_base/natural.txt";
    string codificado = "../Lab3/Data_base/codificado.dat";
    string sudotxt = "../lab3/Data_base/sudo.txt";
    string usuariodat = "../lab3/Data_base/usuario.dat";
    string pruebas = "../lab3/Data_base/pruebas.txt";

    addUser(semilla, usuariodat, "1039473685, 123, saldo (10)");
    metodo2D(semilla, usuariodat, pruebas);
    return 0;
}





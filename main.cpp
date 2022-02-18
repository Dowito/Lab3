#include <manejoArchivo.h>
#include <Cajero.h>
//Cajero automatico.
//Contra cacatua
int main()
{
    unsigned long long semilla = 4;
    short metodo = 2;
    string natural = "../Lab3/Data_base/natural.txt";
    string codificado = "../Lab3/Data_base/codificado.dat";
    string sudotxt = "../lab3/Data_base/sudo.txt";
    string usuariodat = "../lab3/Data_base/usuario.dat";
    string pruebas = "../lab3/Data_base/pruebas.txt";

    natural =inString();
    addUser(semilla, usuariodat, "AbCd");
    metodo2D(semilla, usuariodat, pruebas);
    return 0;
}





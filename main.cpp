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

    cout << "Ingrese contraseña:\n->";
    if(validarAdmin(semilla, metodo, sudotxt)) cout<<"sos un peludoto\n";
    else cout << "valiste pura verga";
    return 0;
}





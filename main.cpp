#include <manejoArchivo.h>

int main()
{
    unsigned long long semilla = 6;
    short metodo = 1;
    char natural[] = "../Lab3/Data_base/natural.txt";
    char codificado[] = "../Lab3/Data_base/codificado.dat";
    char M1S6txt[] = "../Lab3/Data_base/M1S6.txt";
    char M1S6dat[] = "../Lab3/Data_base/M1S6.dat";

    metodo1C(semilla, M1S6txt, codificado);
    metodo1D(semilla, codificado, natural);

    if(archivosIguales(M1S6dat, codificado)){
        cout << "Son iguales" << endl;
    }
    else cout << "No son iguales" << endl;

    if(archivosIguales(M1S6txt, natural)){
        cout << "Son iguales" << endl;
    }
    else cout << "No son iguales" << endl;
    return 0;
}





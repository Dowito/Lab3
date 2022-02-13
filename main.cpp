#include <manejoArchivo.h>

int main()
{
    //Pruebas intensivas :)
    //Probare el ejemplo de la guia
    unsigned long long semilla = 6;
    short metodo = 1;
    char natural[] = "../Lab3/Data_base/natural.txt";
    char codificado[] = "../Lab3/Data_base/codificado.dat";
    char M1S6txt[] = "../Lab3/Data_base/M1S6.txt";
    char M1S6dat[] = "../Lab3/Data_base/M1S6.dat";
    char ejGuia[5] = {'A','b','C','d','\0'};

    metodo1(semilla, natural, codificado);
    return 0;
}





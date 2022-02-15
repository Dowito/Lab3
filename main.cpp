#include <manejoArchivo.h>

//Solucionar problema de funciones con lenCad, Si hay un '\0' en medio del texto se jode
int main()
{
    unsigned long long semilla = 5;
    short metodo = 2;
    string natural = "../Lab3/Data_base/natural.txt";
    string codificado = "../Lab3/Data_base/codificado.dat";
    string M1S6txt = "../Lab3/Data_base/M1S6.txt";
    string M1S6dat = "../Lab3/Data_base/M1S6.dat";
    string M2S17txt = "../Lab3/Data_base/M2S17.txt";
    string M2S17dat = "../Lab3/Data_base/M2S17.dat";
    string prueba = "../Lab3/Data_base/prueba.txt";
    string pruebaCod = "../Lab3/Data_base/pruebaCod.dat";
    string ejGuia = {"AbCd"};

    char Cprueba[] = "../Lab3/Data_base/prueba.txt";
    char CpruebaCod[] = "../Lab3/Data_base/pruebaCod.dat";

    //Pruebas metodo1
    metodo1C(semilla, Cprueba, CpruebaCod);
    metodo1D(semilla, CpruebaCod, Cprueba);
    //Pruebas metodo2

    metodo2C(semilla, prueba, pruebaCod);
    metodo2D(semilla, pruebaCod, prueba);
    metodo2C(semilla, M2S17txt, codificado);
    metodo2D(semilla, M2S17dat, natural);
    if(archivosIguales(M2S17dat, codificado)) cout <<"Son iguales\n";
    if(archivosIguales(M2S17txt, natural)) cout <<"Son iguales\n";

    /*
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
    */


    return 0;
}





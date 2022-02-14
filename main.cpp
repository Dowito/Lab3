#include <manejoArchivo.h>

int main()
{
    unsigned long long semilla = 4;
    short metodo = 2;
    char naturalCad[] = "../Lab3/Data_base/natural.txt";
    string natural = "../Lab3/Data_base/natural.txt";
    //char codificado[] = "../Lab3/Data_base/codificado.dat";
    string codificado = "../Lab3/Data_base/codificado.dat";
    //char M1S6txt[] = "../Lab3/Data_base/M1S6.txt";
    string M1S6txt = "../Lab3/Data_base/M1S6.txt";
    //char M1S6dat[] = "../Lab3/Data_base/M1S6.dat";
    string M1S6dat = "../Lab3/Data_base/M1S6.dat";
    char ejGuiaCad[] = {'A','b','C','d','\0'};
    string ejGuia = {"AbCd"};
    //Pruebas metodo2
    unsigned long long tam = lenCad(ejGuia);//tamaño

    string info = readArchivo(natural);
    char *infoCad = readArchivo(naturalCad);
    /*
    bool *infoBits = getBits(ejGuia);//Separar en bits
    bool *infoEncript = codificacionMetodo2(semilla, infoBits, 8*tam);//Codificacion
    infoBits = decodificacionMetodo2(semilla, infoEncript, 8*tam);//Codificacion
    */

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





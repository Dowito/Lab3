#include <manejoArchivo.h>

int main()
{
    unsigned long long semilla = 17;
    short metodo = 2;
    string natural = "../Lab3/Data_base/natural.txt";
    string codificado = "../Lab3/Data_base/codificado.dat";
    string M1S6txt = "../Lab3/Data_base/M1S6.txt";
    string M1S6dat = "../Lab3/Data_base/M1S6.dat";
    string M2S17txt = "../Lab3/Data_base/M2S17.txt";
    string M2S17dat = "../Lab3/Data_base/M2S17.dat";
    string ejGuia = {"AbCd"};

    //Pruebas metodo2
    //metodo2C(semilla, M2S17txt, codificado);
    if(archivosIguales(M2S17dat, codificado)) cout <<"Son iguales\n";


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





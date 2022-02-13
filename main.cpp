#include <manejoArchivo.h>

int main()
{
    //Pruebas intensivas :)
    //Probare el ejemplo de la guia
    unsigned long long semilla = 4;
    short metodo = 1;
    char natural[] = "../Lab3/Data_base/natural.txt";
    char codificado[] = "../Lab3/Data_base/codificado.dat";
    char ejGuia[5] = {'A','b','C','d','\0'};

    //----Convertir a Bits----------------------------OK
    bool *ejGuiaBits = getBits(ejGuia);

    //----Codificacion---------------------------------OK
    bool *ejGuiaEncript = codificacionMetodo1(semilla, ejGuiaBits, 8*lenCad(ejGuia));

    //----Agrupar en Bytes-----------------------------OK
    char *ejGuiaBytes = bits2Byte(ejGuiaEncript, 8*lenCad(ejGuia));

    //----Escribir en .dat-----------------------------OK
    writeArchivo(codificado, ejGuiaBytes);

    delete[] ejGuiaBits;
    delete[] ejGuiaEncript;
    delete[] ejGuiaBytes;

    //----Leer .dat------------------------------------OK
    ejGuiaBytes = readArchivo(codificado);

    //----Bytes a Encript---------------------------------OK
    ejGuiaEncript = getBits(ejGuiaBytes);

    //----Decodificaciones---------------------------------OK
    ejGuiaBits = decodificacionMetodo1(semilla, ejGuiaEncript, 8*lenCad(ejGuia));

    //----bits a Char--------------------------------------OK
    char *ejGuia2 = bits2Byte(ejGuiaBits, 8*lenCad(ejGuia));

    //----escribir en natural---------------------------------
    writeArchivo(natural, ejGuia2);

    return 0;
}

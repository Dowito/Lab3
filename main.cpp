#include <manejoArchivo.h>

//lacad que returna rArchivo lleva un '\0' no se que problemas me genero eso

int main()
{
    unsigned long long semilla = 4;
    char cad[] = "../Lab3/Data_base/natural.txt";
    char *cadArchivo = rArchivo(cad);
    cout << *cadArchivo << endl;
    char EjGuia[5] = {'A','b','C','d','\0'};
    bool *EjGuiaBits = getBits(EjGuia);
    bool *pruebaBits = getBits(cadArchivo);
    unsigned long long tamPrueba = lenCad(cadArchivo);
    unsigned long long tamEjGuia = lenCad(EjGuia);
    for (unsigned long long i=0; i<8*tamPrueba; i++) {
        cout << pruebaBits[i];
    }
    cout << endl;
    unsigned int num = 0;
    unsigned int convernum = 0;
    unsigned long long indx = 0;

    //Pseudo transformador de bits a char, lo hiso para probar si el programa estaba bueno
    while(indx<8*tamEjGuia){
        for (short i=0; i<8; i++) {
            convernum = EjGuiaBits[indx] << (7-i);
            num += (EjGuiaBits[indx] << (7-i));
            indx++;
        }
        cout << (char)num;
        num = 0;
    }
    bool *EjGuiaEncript;
    EjGuiaEncript = CodificacionMet1(4, EjGuiaBits, 8*tamEjGuia);


    return 0;
}

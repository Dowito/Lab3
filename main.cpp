#include <manejoArchivo.h>

//lacad que returna rArchivo lleva un '\0' no se que problemas me genero eso

int main()
{
    //char cadArr[] = "Mierdas";
    //char *cadPtr = new char [8]{'M','i','e','r','d','a','s','\0'};
    unsigned long long semilla = 4;
    char cad[] = "../Lab3/Data_base/natural.txt";
    char *cadArchivo = rArchivo(cad);
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

    /*Pseudo transformador de bits a char, lo hiso para probar si el programa estaba bueno
    while(indx<8*tamPrueba){
        for (short i=0; i<8; i++) {
            convernum = pruebaBits[indx] << (7-i);
            num += (pruebaBits[indx] << (7-i));
            indx++;
        }
        cout << (char)num;
        num = 0;
    }*/
    bool *EjGuiaEncript;
    EjGuiaEncript = CodificacionMet1(4, EjGuiaBits, 8*tamEjGuia);

    //Pruebas a bits2Byte
    //Con EjGuiaBits
    cout << "De bits->bytes->caracteres EjGuia: \n";
    char *arrBytes = bits2Byte(EjGuiaBits, 8*tamEjGuia);
    for (unsigned long long i=0; i<tamEjGuia; i++) {
        cout << arrBytes[i];
    }
    cout << endl;
    //Con pruebaBits
    cout << "De bits->bytes->caracteres prueba: \n";
    char *arrBytesPrueba = bits2Byte(pruebaBits, 8*tamPrueba);
    for (unsigned long long int i=0; i<tamPrueba; i++) {
        cout << arrBytesPrueba[i];
    }

    return 0;
}

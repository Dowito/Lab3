#include <manejoArchivo.h>

//lacad que returna rArchivo lleva un '\0' no se que problemas me genero eso

int main()
{
    char cad[] = "../Lab3/Data_base/natural.txt";
    char *cadArchivo = rArchivo(cad);
    cout << *cadArchivo << endl;
    char arr[5] = {'A','b','C','d','\0'};
    bool *bits = getBits(arr);
    bool *pruebaBits = getBits(cadArchivo);
    unsigned long long tam = lenCad(cadArchivo);
    for (unsigned long long i=0; i<8*tam; i++) {
        cout << pruebaBits[i];
    }
    cout << endl;
    unsigned int num = 0;
    unsigned int convernum = 0;
    unsigned long long indx = 0;

    //Pseudo transformador de bits a char, lo hiso para probar si el programa estaba bueno
    while(indx<8*tam){
        for (short i=0; i<8; i++) {
            convernum = pruebaBits[indx] << (7-i);
            num += (pruebaBits[indx] << (7-i));
            indx++;
        }
        cout << (char)num;
        num = 0;
    }


    return 0;
}

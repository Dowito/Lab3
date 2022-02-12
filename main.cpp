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

    return 0;
}

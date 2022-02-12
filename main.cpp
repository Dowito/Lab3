#include <manejoArchivo.h>

//lacad que returna rArchivo lleva un '\0' no se que problemas me genero eso

int main()
{
    char cad[] = "../Lab3/Data_base/natural.txt";
    char *cadArchivo = rArchivo(cad);
    cout << *cadArchivo << endl;
    char arr[4] = {'A','b','C','d'};
    return 0;
}

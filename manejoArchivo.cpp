#include <manejoArchivo.h>

char *rArchivo(char *cad)
{
    fstream archivo;
    archivo.open(cad, fstream::out | fstream::binary);
}

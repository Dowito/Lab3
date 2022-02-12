#include <manejoArchivo.h>
#include <fstream>

char *rArchivo(char *cad)
{
    fstream archivo;
    archivo.open(cad, fstream::out | fstream::binary);
}

#include <Auxiliar.h>



unsigned long long lenCad(char *cad)
{
    unsigned int tam = 0;
    for (unsigned int i = 0; cad[i] != 0; i++) tam++;
    return tam;
}

bool ifArrSame(char *arreglo1, char *arreglo2, unsigned long long tam1, unsigned long long tam2)
{
    for (unsigned int i = 0; i < tam1; i++) {
        for (unsigned int j = 0; j < tam2; j++) { //
            if(arreglo1[i] != arreglo2[j]) return false; //se compara el elemento i del arreglo1 con cada uno de los elemento del arreglo2
        }
    }
    return true;
}

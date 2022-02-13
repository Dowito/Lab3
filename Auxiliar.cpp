#include <Auxiliar.h>

unsigned long long lenCad(char *cad)
{
    unsigned int tam = 0;
    for (unsigned int i = 0; cad[i] != 0; i++) tam++;
    return tam;
}

bool ifCadSame(char *cad1, char *cad2)
{
    if(lenCad(cad1) != lenCad(cad2)) return false;
    for (unsigned int i = 0; i < lenCad(cad1); i++) {
        if(cad1[i] != cad2[i]) return false;
    }
    return true;
}

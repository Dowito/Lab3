#include <Auxiliar.h>

unsigned long long lenCad(char *cad)
{
    unsigned int tam = 0;
    for (unsigned int i = 0; cad[i] != 0; i++) tam++;
    return tam;
}

unsigned long long lenCad(string cad)
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

bool ifCadSame(string str1, string str2)
{
    unsigned long long tam1 = lenCad(str1);
    unsigned long long tam2 = lenCad(str2);
    if(lenCad(str1) != lenCad(str2)) return false;
    for (unsigned int i = 0; i < lenCad(str1); i++) {
        if(str1[i] != str2[i]) return false;
    }
    return true;
}

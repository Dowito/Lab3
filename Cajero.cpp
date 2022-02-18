#include <Cajero.h>
bool validarAdmin(unsigned long long semilla, short metodo, string sudo)
{
    if(metodo == 1){

    }
    else if (metodo == 2) {
        string inContra = inString();
        string sudoDeco = getInfo(semilla, sudo);
        if(sudoDeco.compare(inContra) == 0) return true;
        else return false;
    }
}

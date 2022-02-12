#include <manejoArchivo.h>

char *rArchivo(char *direccion)
{
    fstream Archivo;
    Archivo.open(direccion, fstream::in | fstream:: binary |fstream::ate);  //Mode oout->Lectura  ate->abre poniendo el cursor en el ultimo archivo
    if(Archivo.is_open()){ //Procedemos a guardar el archivo en un arreglo de char
        unsigned long long tam = Archivo.tellg();//Retorna la ultima posicion del archivo
        Archivo.seekg(0); //curso en 0
        char *cad = new char [tam+1] {'\0'}; //Reservamos suficiente espacio para guardar el archivo en el heap
        Archivo.read(cad, tam); //cad guarda el archivo
        Archivo.close();
        return cad;
    }
    else{
        cout << "El archivo no existe.";
        char cad[] = "Error";
        return cad;
    }
}

bool *CodificacionMet1(unsigned long long n, bool *arrBits, unsigned long long tamArrBits)
{
    bool *datosEncript = new bool [tamArrBits];
    for (unsigned long long i=0; i<n; i++) {//se invierte el primer grupo de n bits
        datosEncript[i] = !arrBits[i];
    }
    return datosEncript;
}

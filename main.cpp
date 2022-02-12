#include <manejoArchivo.h>

//nombre archivo sin codificar y codificado natural.txt
//codificado codificado.dat
//Creacion rama desarrollo metodo1

char* readArchivo(char *cad)
{
    fstream archivo;
    archivo.open("../Lab3/Data_base/codificado.dat", fstream::out | fstream::binary);
}

int main()
{
    fstream archivo;
    archivo.open("../Lab3/Data_base/codificado.dat", fstream::out | fstream::binary);
    if(archivo.is_open()) cout << "El archivo se abrio." << endl;
    else cout << "El archivo no se abrio";
    archivo.close();
    return 0;
}

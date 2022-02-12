#include <manejoArchivo.h>

char *rArchivo(char *direccion)
{
    fstream Archivo;
    Archivo.open(direccion, fstream::in | fstream::ate);  //Mode oout->Lectura  ate->abre poniendo el cursor en el ultimo archivo
    if(Archivo.is_open()){ //Procedemos a guardar el archivo en un arreglo de char
        unsigned long long tam = Archivo.tellg();//Retorna la ultima posicion del archivo
        Archivo.seekg(0); //curso en 0
        char *cad = new char [tam] {'\0'}; //Reservamos suficiente espacio para guardar el archivo en el heap
        Archivo.read(cad, tam); //cad guarda el archivo
        Archivo.close();
        return cad;
    }
    else{
        cout << "No se pudo leer el archivo.";
        char cad[] = "Error";
        return cad;
    }
}

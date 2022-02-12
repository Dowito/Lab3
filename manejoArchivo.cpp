#include <manejoArchivo.h>

unsigned long long tamArchivo(char *direccion)
{
    fstream Archivo;
    Archivo.open(direccion, fstream::in | fstream:: binary |fstream::ate);
    if(Archivo.is_open()){
        unsigned long long tamArchivo = Archivo.tellg();//Retorna la ultima posicion del archivo
        Archivo.close();
        return tamArchivo;
    }
    else{
        cout << "El archivo no existe." << endl;
        return 0;
    }
}

char *rArchivo(char *direccion)
{
    fstream Archivo;
    Archivo.open(direccion, fstream::in | fstream:: binary |fstream::ate);  //Mode oout->Lectura  ate->abre poniendo el cursor en el ultimo archivo
    if(Archivo.is_open()){ //Procedemos a guardar el archivo en un arreglo de char
        unsigned long long tam = tamArchivo(direccion);//Retorna la ultima posicion del archivo
        char *cad = new char [tam+1] {'\0'}; //Reservamos suficiente espacio para guardar el archivo en el heap
        Archivo.read(cad, tam); //cad guarda el archivo
        Archivo.close();
        return cad;
    }
    else{
        cout << "El archivo no existe.";
        return 0;
    }
}

bool *CodificacionMet1(unsigned long long n, bool *arrBits, unsigned long long tamArrBits)
{
    bool *datosEncript = new bool [tamArrBits];
    for (unsigned long long i=0; i<n; i++) {//se invierte el primer grupo de n bits
        datosEncript[i] = !arrBits[i];
    }
    unsigned long long indxBits = 0;
    unsigned long long ceros=0, unos=0;
    unsigned long long pasos=1;
    for (unsigned long long indxEncript=n; indxEncript<tamArrBits; indxEncript++) {
        while(indxBits<indxEncript){ //Se cuentan los 1s y 0s del bloque anterior
            if(arrBits[indxBits]==0) ceros++;
            else unos++;
            indxBits++;
        }//Cuando sale del while es por que termino de contar los ceros del bloque anterior y indxBits=indxEncript y se empieza con las condciones de la codificacion
        if(unos==ceros) datosEncript[indxEncript] = !arrBits[indxBits];

        else if(unos<ceros){
            if((pasos%2)==0) datosEncript[indxEncript] = !arrBits[indxBits];//Invierte bit cada dos pasos
            else datosEncript[indxEncript] = arrBits[indxBits];
        }
        else if(unos>ceros){
            if((pasos%3)==0) datosEncript[indxEncript] = !arrBits[indxBits];//Invierte bit cada dos pasos
            else datosEncript[indxEncript] = arrBits[indxBits];
        }
        indxBits++, pasos++;
        if(pasos>n){//Si pasos>n se termino de recorrer un bloque
            indxBits -= n; //El indxBits se devuelve al inicio del bloque que se acaba de recorrer
            pasos = 1; //Pasos se reinicia
            unos = 0; ceros = 0; //se reinicia el conteo de unos y ceros
        }
    }
    return datosEncript;
}

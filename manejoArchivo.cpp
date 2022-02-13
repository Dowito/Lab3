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

char *readArchivo(char *name)
{
    unsigned long long tam = tamArchivo(name);
    fstream Archivo;
    Archivo.open(name, fstream::in | fstream:: binary);  //Mode in->Lectura
    if(Archivo.is_open()){ //Procedemos a guardar el archivo en un arreglo de char
        char *cad = new char [tam+1] {'\0'}; //Reservamos suficiente espacio para guardar el archivo en el heap
        Archivo.read(cad, tam); //Se guarda archivo en cad
        Archivo.close();
        return cad;
    }
    else{
        cout << "El archivo no existe.";
        return 0;
    }
}

void writeArchivo(char *name, char *cad)
{
    unsigned long long tam = lenCad(cad);
    fstream Archivo;
    Archivo.open(name, fstream::out | fstream::binary);
    if (Archivo.is_open()) {
        Archivo.write(cad, tam);
        Archivo.close();
    }
    else cout << "Archivo no existe";
}

char *bits2Byte(bool *arrBits, unsigned long long tamArrBits)
{
    char *arrBytes = new char [(tamArrBits/8)+1]{'\0'};
    unsigned long long indxBits=0, indxBytes=0;
    char byte = 0;
    while(indxBits<tamArrBits){ //se recorre todo arrbits
        for (short i=0; i<8; i++) { //Proceso para agrupar bits en un byte desde el mas al menor significativo
            byte = byte | (arrBits[indxBits] << (7-i));//se hace un corrimiento de bits y se usa OR. Esto es equivalente a multiplicar por 0b0X*2^(7-i) y luego sumar.
            indxBits++;
        }
        arrBytes[indxBytes] = byte;//El byte obtenido se almacena
        indxBytes++;
        byte = 0;
    }
    return arrBytes;
}

bool *codificacionMetodo1(unsigned long long n, bool *arrBits, unsigned long long tamArrBits)
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

bool *decodificacionMetodo1(unsigned long long n, bool *arrEncript, unsigned long long tamArrEncript)
{
    bool *arrBits = new bool [tamArrEncript];
    for (unsigned long long i=0; i<n; i++) {//se invierte el primer grupo de n bits
        arrBits[i] = !arrEncript[i];
    }
    unsigned long long indxBits = 0;
    unsigned long long ceros=0, unos=0;
    unsigned long long pasos=1;
    /*La decodificacion es practicamente lo mismo, lo unico que cambia son las asignaciones
        Ya que ahora se trataran son los bits codificados. Los bits que fueron invertidos
        siguen estando en las mismas posiciones, es como si se detectaran dichos bits y se
        hiciera el proceso inverso*/
    for (unsigned long long indxEncript=n; indxEncript<tamArrEncript; indxEncript++) {
        while(indxBits<indxEncript){ //Se cuentan los 1s y 0s del bloque anterior
            if(arrBits[indxBits]==0) ceros++;
            else unos++;
            indxBits++;
        }//Cuando sale del while es por que termino de contar los ceros del bloque anterior y indxBits=indxEncript y se empieza con las condciones de la codificacion
        if(unos==ceros) arrBits[indxBits] = !arrEncript[indxEncript]; //Se cambio el orden de asignacion.

        else if(unos<ceros){
            if((pasos%2)==0) arrBits[indxBits] = !arrEncript[indxEncript];//Invierte bit cada dos pasos
            else arrBits[indxBits] = arrEncript[indxEncript];
        }
        else if(unos>ceros){
            if((pasos%3)==0) arrBits[indxBits] = !arrEncript[indxEncript];//Invierte bit cada tres pasos
            else arrBits[indxBits] = arrEncript[indxEncript];
        }
        indxBits++, pasos++;
        if(pasos>n){//Si pasos>n se termino de recorrer un bloque
            indxBits -= n; //El indxBits se devuelve al inicio del bloque que se acaba de recorrer
            pasos = 1; //Pasos se reinicia
            ceros = 0; unos = 0; //se reinicia el conteo de unos y ceros
        }
    }
    return arrBits;
}

void metodo1(unsigned long long semilla)
{

}

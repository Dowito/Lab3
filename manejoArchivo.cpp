#include <manejoArchivo.h>

unsigned long long tamArchivo(char *name)
{
    fstream Archivo;
    Archivo.open(name, fstream::in | fstream:: binary |fstream::ate);
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

unsigned long long tamArchivo(string name)
{
    fstream Archivo;
    Archivo.open(name, fstream::in | fstream:: binary |fstream::ate);
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

string readArchivo(string name)
{
    unsigned long long tam = tamArchivo(name);
    fstream Archivo;
    Archivo.open(name, fstream::in | fstream:: binary);  //Mode in->Lectura
    if(Archivo.is_open()){ //Procedemos a guardar el archivo en un string
        string info;
        for (unsigned long long i=0; i<tam; i++) {
            info.push_back(Archivo.get());
        }
        Archivo.close();
        return info;
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

void writeArchivo(string name, string str)
{
    unsigned long long tam = str.size();//str.size();
    fstream Archivo;
    Archivo.open(name, fstream::out | fstream::binary);
    if (Archivo.is_open()) {
        for (unsigned long long i=0; i<tam; i++) {
            Archivo.put(str[i]);
        }
        Archivo.close();
    }
    else cout << "Archivo no existe";
}

bool archivosIguales(char *name1, char *name2)
{
    char *info1 = readArchivo(name1);
    char *info2 = readArchivo(name2);
    bool filolais = ifCadSame(info1, info2);
    return filolais;
}

bool archivosIguales(string name1, string name2)
{
    string info1 = readArchivo(name1);
    string info2 = readArchivo(name2);
    bool filolais = ifCadSame(info1, info2);
    return filolais;
}

bool *getBits(char *cad)
{
    unsigned long long tamCad = lenCad(cad);
    bool *arrBits = new bool [8*tamCad]; //Los bits totales seran 8*tamCad
    //Transformar cada char de cad en bits y guardarlos desde el mas al menos significativo
    unsigned long long indxBits = 0;
    bool bit;//Se guardaran dia bit a bit
    char copyChar;
    for (unsigned long long indxCad = 0; indxCad<tamCad; indxCad++) {
        copyChar = cad[indxCad]; //copia del Caracter al que le sacaremos los bits
        for (short i = 0; i<8; i++) {
            bit = copyChar & 0b01; //se saca el bit menos significativo
            arrBits[indxBits+(7-i)] = bit; //Se iran guardando de esta manera {8,7,6,5,4,3,2,1} ya que vamos sacando dia bit menos significativo y tenemos que guarlos en el arrBits en ese mismo orden
            copyChar = copyChar>>1; //Corrimiento de bit hacia la derecha.
        }
        indxBits+=8;//Saltamos al siguiente bloque
    }
    return arrBits;
}

bool *getBits(string str)
{
    unsigned long long tamStr = lenCad(str);
    bool *arrBits = new bool [8*tamStr];
    unsigned long long indxBits = 0;
    bool bit;//Se guarda bit a bit
    char copyChar;
    for (unsigned long long indxStr = 0; indxStr<tamStr; indxStr++) {
        copyChar = str[indxStr]; //copia del Caracter al que le sacaremos los bits
        for (short i = 0; i<8; i++) {
            bit = copyChar & 0b01; //se saca el bit menos significativo
            arrBits[indxBits+(7-i)] = bit; //Se iran guardando de esta manera {8,7,6,5,4,3,2,1} ya que vamos sacando dia bit menos significativo y tenemos que guarlos en el arrBits en ese mismo orden
            copyChar = copyChar>>1; //Corrimiento de bit hacia la derecha.
        }
        indxBits+=8;//Saltamos al siguiente bloque
    }
    return arrBits;
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

string bits2ByteStr(bool *arrBits, unsigned long long tamArrBits)
{
    string arrBytes;
    unsigned long long indxBits=0; //indxBytes=0;
    char byte = 0;
    while(indxBits<tamArrBits){ //se recorre todo arrbits
        for (short i=0; i<8; i++) { //Proceso para agrupar bits en un byte desde el mas al menor significativo
            byte = byte | (arrBits[indxBits] << (7-i));//se hace un corrimiento de bits y se usa OR. Esto es equivalente a multiplicar por 0b0X*2^(7-i) y luego sumar.
            indxBits++;
        }
        arrBytes.push_back(byte);//arrBytes[indxBytes] = byte;//El byte obtenido se almacena
        //indxBytes++;
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

void metodo1C(unsigned long long semilla, char *inName, char *outName)
{
    unsigned long long tam = tamArchivo(inName);//tamaño
    char *info = readArchivo(inName);//Lectura
    bool *infoBits = getBits(info);//Separar en bits
    delete[] info;
    bool *infoEncript = codificacionMetodo1(semilla, infoBits, 8*tam);//Codificacion
    delete[] infoBits;
    char *infoEncriptBytes = bits2Byte(infoEncript, 8*tam);//Convertir a bytes.
    delete [] infoEncript;
    writeArchivo(outName, infoEncriptBytes);//Escritura
    delete [] infoEncriptBytes;
}

void metodo1D(unsigned long long semilla, char *inName, char *outName)
{
    unsigned long long tam = tamArchivo(inName);//tamaño
    char *infoEncriptBytes = readArchivo(inName);//Lectura
    bool *infoEncript = getBits(infoEncriptBytes);//Separar en bits
    delete[] infoEncriptBytes;
    bool *infoBits = decodificacionMetodo1(semilla, infoEncript, 8*tam);//decodificacion
    delete[] infoEncript;
    char *info = bits2Byte(infoBits, 8*tam);//Convertir a bytes.
    delete [] infoBits;
    writeArchivo(outName, info);//Escritura
    delete [] info;
}

bool *codificacionMetodo2(unsigned long long n, bool *arrBits, unsigned long long tamArrBits)
{
    bool *arrEncript = new bool [tamArrBits];
    unsigned long long pasos=1;
    unsigned long long indxEncript, indxBits;
    for (indxBits=0; indxBits<tamArrBits; indxBits++) {
        if(pasos == 1) indxEncript = indxBits+1; //Corrimiento de bit hacia la derecha
        if (indxBits == (tamArrBits-1)) { //Aqui se trata el ultimo bit del arreglo
            indxEncript -= pasos; //Se retrocede para imprimir ese ultimo bit en el inicio del bloque codificado
            arrEncript[indxEncript] = arrBits[indxBits];
        }//Asi funciona cuando el ultimo bloque de bits es de menor tamaño.

        else { //mientras no sea el ultimo bits del arreglo
            if (pasos != n) {
                arrEncript[indxEncript] = arrBits[indxBits];
                pasos++;
                indxEncript++;
            }
            else {//pasos==n
                indxEncript -= n;
                arrEncript[indxEncript] = arrBits[indxBits];
                pasos = 1;//se termina de codificar un bloque
            }
        }
    }
    return arrEncript;
}

bool *decodificacionMetodo2(unsigned long long n, bool *arrEncript, unsigned long long tamArrEncript)
{
    //Es lo mismo que la codificacion, lo unico que cambia es el orden de asignacion
    bool *arrBits = new bool [tamArrEncript];
    unsigned long long pasos=1;
    unsigned long long indxEncript, indxBits;
    for (indxBits=0; indxBits<tamArrEncript; indxBits++) {
        if(pasos == 1) indxEncript = indxBits+1; //Corrimiento de bit hacia la derecha

        if (indxBits == (tamArrEncript-1)) { //Aqui se trata el ultimo bit del arreglo
            indxEncript -= pasos; //Se retrocede para imprimir ese ultimo bit en el inicio del bloque codificado
            arrBits[indxBits] = arrEncript[indxEncript];
        }//Asi funciona cuando el ultimo bloque de bits es de menor tamaño.

        else { //mientras no sea el ultimo bits del arreglo
            if (pasos != n) {
                arrBits[indxBits] = arrEncript[indxEncript];
                pasos++;
                indxEncript++;
            }
            else {//pasos==n
                indxEncript -= n;
                arrBits[indxBits] = arrEncript[indxEncript];
                pasos = 1;//se termina de codificar un bloque
            }
        }
    }
    return arrBits;
}

void metodo2C(unsigned long long semilla, string inName, string outName)
{
    unsigned long long tam = tamArchivo(inName);//tamaño
    string info = readArchivo(inName);//Lectura
    bool *infoBits = getBits(info);//Separar en bits
    bool *infoEncript = codificacionMetodo2(semilla, infoBits, 8*tam);//Codificacion
    delete[] infoBits;
    string infoEncriptBytes = bits2ByteStr(infoEncript, 8*tam);//Convertir a bytes.
    delete [] infoEncript;
    writeArchivo(outName, infoEncriptBytes);//Escritura
}

void metodo2D(unsigned long long semilla, string inName, string outName)
{
    unsigned long long tam = tamArchivo(inName);//tamaño
    string info = readArchivo(inName);//Lectura
    bool *infoBits = getBits(info);//Separar en bits
    bool *infoDeco = decodificacionMetodo2(semilla, infoBits, 8*tam);//Decodificacion
    delete[] infoBits;
    string infoDecoBytes = bits2ByteStr(infoDeco, 8*tam);//Convertir a bytes.
    delete [] infoDeco;
    writeArchivo(outName, infoDecoBytes);//Escritura
}

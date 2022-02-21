#include <Cajero.h>
bool validarAdmin(unsigned long long semilla, short metodo, string sudo, string Contra)
{
    if(metodo == 1){

    }
    else if (metodo == 2) {
        unsigned long long tam = tamArchivo(sudo);
        string sudoEncript = readArchivo(sudo);
        string sudoDeco = encript2Info(semilla, sudoEncript, tam);
        if(sudoDeco.compare(Contra) == 0) return true;//La funcion compare retorna 0 si ambos caracteres son iguales.
        else return false;
    }
    return 0;
}


void addUser(unsigned long long semilla, string users, string newUser)
{
    unsigned long long tam = tamArchivo(users); //Tamaño de users
    string usersEncript = readArchivo(users); //Lee archivo
    string usersDeco = encript2Info(semilla, usersEncript, tam); //Lo decodifica
    usersDeco.append(newUser); //Agrega al nuevo usuario y al final pone un salto de linea
    usersEncript = info2Encript(semilla, usersDeco, usersDeco.size());//Vuelve a encriptarlo pero con el nuevo usuario agregado
    writeArchivo(users, usersEncript);//Guarda todo en users con los usuario encriptados
}

bool validarCedula(string infoUsers, string cedula, unsigned long long &pos)
{
    unsigned long long i=0;
    string buffer;
    pos=i;
    while(i<infoUsers.size()){
        for (i; infoUsers[i]!=','; i++) {//Se recorre todo infoUsers
            buffer.push_back(infoUsers[i]); //extraigo la cedula que llega hasta ','
        }
        if(buffer==cedula) return true;
        //Se hace proceso para extraer la siguiente cedula
        i=infoUsers.find(')',i);
        while (infoUsers[i]==')' || infoUsers[i]=='\n') {
            i++;
        }
        pos=i;//Posicion de la siguiente cedula
        buffer.assign("");//reiniciamos el buffer
    }
    return false;
}


bool validarClave(string infoUsers, string clave, unsigned long long &pos)
{
    pos = (infoUsers.find(' ', pos)+1);
    unsigned long long indx = 0;
    while (infoUsers[pos]!=',') {
        if (infoUsers[pos] == clave[indx]) {
            pos++; indx++;
        }
        else return false;
    }
    return true;
}

bool validarUsuario(unsigned long long semilla, string inName, string *CC, unsigned long long &pos)
{
    string infoUsersEncript = readArchivo(inName);
    string infoUsers = encript2Info(semilla, infoUsersEncript, infoUsersEncript.size());
    if(validarCedula(infoUsers, CC[0], pos)) { //Si el usuario esta registrado
        if(validarClave(infoUsers, CC[1], pos)){
            return true;
        }
        else{
            cout << "clave no valida.\n";
        }
    }
    else {
        cout << "Cedula no valida.\n";
    }
    return false;
}

unsigned long long reSaldo(unsigned long long semilla, string inName, unsigned long long pos)
{
    string infoUsers = fEncript2StrDeco(semilla, inName);
    pos = (infoUsers.find('(', pos)+1); //El saldo estara despues de '('
    cout << "Su saldo es de ";
    while (infoUsers[pos] != ')') { //Llega hasta ')'
        cout << infoUsers[pos];
        pos++;
    }
    cout << " COP.";
}

void retirarSaldo(unsigned long long semilla, string inName, unsigned long long retiro, unsigned long long pos)
{
    string infoUsers = fEncript2StrDeco(semilla, inName);
    pos = (infoUsers.find('(', pos)); //El saldo en COP empieza desde '('
    string infoRetiro;
    for (unsigned long long i = 0; i<=pos; i++) { //se crea un nuevo string que va hasta antes del saldo a modificar
        infoRetiro.push_back(infoUsers[i]);
    }
    pos++;
    string saldo;
    while (infoUsers[pos]!=')') { //Hasta ahi llega el saldo
        saldo.push_back(infoUsers[pos]); //Se separa el saldo
        pos++;
    }
    unsigned long long saldoNum;
    saldoNum = str2Num(saldo);//se convierte el saldo a numero
    saldoNum -= retiro;
    saldo = num2Str(saldoNum); //El nuevo saldo se convierte a str
    infoRetiro.append(saldo); //se agrega el nuevo saldo al str que luego escribiremos
    unsigned long long posF = infoUsers.size()-1; //posicion final de infoUsers
    infoRetiro.append(infoUsers, pos, (posF-(pos-1))); //terminamos de agregar el resto de infoUsers desde donde se dejo
    infoRetiro = info2Encript(semilla, infoRetiro, infoRetiro.size()); //Encriptamos la info con el nuevo saldo
    writeArchivo(inName, infoRetiro);
}

void cobro(unsigned long long semilla, string outName, string infoUsers, unsigned long long pos)
{
    pos = (infoUsers.find('(', pos));
    string infoRetiro;
    for (unsigned long long i = 0; i<=pos; i++) { //se crea un nuevo string que va hasta antes del saldo a modificar
        infoRetiro.push_back(infoUsers[i]);
    }
    pos++;
    string saldo;
    while (infoUsers[pos]!=')') { //Hasta ahi llega el saldo
        saldo.push_back(infoUsers[pos]); //Se separa el saldo
        pos++;
    }
    unsigned long long saldoNum;
    saldoNum = str2Num(saldo);//se convierte el saldo a numero
    cout << "Cuanto desea retirar:\n->";
    saldoNum -= 1000;//La condicion de que se cobra 1000 por cada retiro
    saldo = num2Str(saldoNum); //El nuevo saldo se convierte a str
    infoRetiro.append(saldo); //se agrega el nuevo saldo al str que luego escribiremos
    unsigned long long posF = infoUsers.size()-1; //posicion final de infoUsers
    infoRetiro.append(infoUsers, pos, (posF-(pos-1))); //terminamos de agregar el resto de infoUsers desde donde se dejo
    infoRetiro = info2Encript(semilla, infoRetiro, infoRetiro.size()); //Encriptamos la info con el nuevo saldo
    writeArchivo(outName, infoRetiro);
}

string formatoUsuario()
{
    string cedula;
    string clave;
    string saldo;
    string usuario;
    cout << "Ingrese cedula.\n->";
    cedula = inString();
    clean();
    cout << "Ingrese clave.\n->";
    clave = inString();
    clean();
    cout << "Ingrese saldo (COP).\n->";
    saldo = inString();
    clean();
    usuario = cedula+", "+clave+", saldo ("+saldo+")\n";
    return usuario;
}

string *cedulaClave()
{
    string *CC = new string [2];
    string cedula;
    string clave;
    cout << "Ingrese cedula:\n->";
    cedula = inString();
    clean();
    cout << "Ingrese clave:\n->";
    clave = inString();
    clean();
    CC[0] = cedula;
    CC[1] = clave;
    return CC;
}

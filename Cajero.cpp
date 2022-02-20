#include <Cajero.h>
bool validarAdmin(unsigned long long semilla, short metodo, string sudo)
{
    if(metodo == 1){

    }
    else if (metodo == 2) {
        unsigned long long tam = tamArchivo(sudo);
        string Contra = inString();
        string sudoDeco = readArchivo(sudo);
        sudoDeco = encript2Info(semilla, sudo, tam);
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
    usersDeco.append(newUser+"\n"); //Agrega al nuevo usuario y al final pone un salto de linea
    usersEncript = info2Encript(semilla, usersDeco, usersDeco.size());//Vuelve a encriptarlo pero con el nuevo usuario agregado
    writeArchivo(users, usersEncript);//Guarda todo en users con los usuario encriptados
}

bool validarCedula(string infoUsers, string cedula, unsigned long long &pos)
{
    pos = infoUsers.find(cedula);
    if (pos != -1) { //la funcion find retorna -1 si no encuentra coincidencia.
        return true;
    }
    else return false;
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

bool validarUsuario(unsigned long long semilla, string inName, unsigned long long &pos)
{
    string infoUsersEncript = readArchivo(inName);
    string infoUsers = encript2Info(semilla, infoUsersEncript, infoUsersEncript.size());
    cout << "Ingrese su cedula:\n->";
    string cedula = inString();
    clean();
    if(validarCedula(infoUsers, cedula, pos)) { //Si el usuario esta registrado
        cout << "Ingrese su clave:\n->";
        string clave = inString();
        clean();
        if(validarClave(infoUsers, clave, pos)){
            return true;
        }
        else{
            cout << "clave no valida.";
        }
    }
    else {
        cout << "Cedula no valida.";
    }
    return false;
}

void impSaldo(string infoUsers, unsigned long long pos)
{
    pos = (infoUsers.find('(', pos)+1); //El saldo estara despues de '('
    cout << "Su saldo es de ";
    while (infoUsers[pos] != ')') { //Llega hasta ')'
        cout << infoUsers[pos];
        pos++;
    }
    cout << "COP\n";
}

void retirarSaldo(unsigned long long semilla, string outName, string infoUsers, unsigned long long pos)
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
    unsigned long long retiro;
    saldoNum = str2Num(saldo);//se convierte el saldo a numero
    cout << "Cuanto desea retirar:\n->";
    cin >> retiro;
    saldoNum -= retiro;
    saldoNum -= 1000;//La condicion de que se cobra 1000 por cada retiro
    saldo = num2Str(saldoNum); //El nuevo saldo se convierte a str
    infoRetiro.append(saldo); //se agrega el nuevo saldo al str que luego escribiremos
    unsigned long long posF = infoUsers.size()-1; //posicion final de infoUsers
    infoRetiro.append(infoUsers, pos, (posF-(pos-1))); //terminamos de agregar el resto de infoUsers desde donde se dejo
    infoRetiro = info2Encript(semilla, infoRetiro, infoRetiro.size()); //Encriptamos la info con el nuevo saldo
    writeArchivo(outName, infoRetiro);
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

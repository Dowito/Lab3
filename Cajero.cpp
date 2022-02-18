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
        if(sudoDeco.compare(Contra) == 0) return true;
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

bool findCedula(string infoUsers, string cedula, unsigned long long &pos)
{
    unsigned long long posCedula = infoUsers.find(cedula);
    if (posCedula != -1) { //la funcion find retorna -1 si no encuentra coincidencia.
        pos = posCedula;
        return true;
    }
    else return false;
}


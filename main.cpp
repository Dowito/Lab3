#include <manejoArchivo.h>
#include <Cajero.h>
//Cajero automatico.
//Contra cacatua
int main()
{
    unsigned long long semilla = 4;
    short metodo = 2;
    string natural = "../Lab3/Data_base/natural.txt";
    string codificado = "../Lab3/Data_base/codificado.dat";
    string sudotxt = "../lab3/Data_base/sudo.txt";
    string usuariodat = "../lab3/Data_base/usuario.dat";
    string pruebas = "../lab3/Data_base/pruebas.txt";

    string usuario = "1230974, berengena, saldo(100)";

    unsigned long long pos;
    if(validarUsuario(semilla, usuariodat, pos)) cout << "Usuario valido" << endl;
    clean();
    string infoUsers = fEncript2StrDeco(semilla, usuariodat);
    unsigned long long posUser = pos;
    retirarSaldo(semilla, usuariodat, infoUsers, pos);
    //Pra probar luegoimpSaldo(infoUsers, posUser);

    metodo2D(semilla, usuariodat, pruebas);

    //addUser(semilla, usuariodat, "1230974, berengena, saldo(100)");
    //metodo2D(semilla, usuariodat, pruebas);
    return 0;
}






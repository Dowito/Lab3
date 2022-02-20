#include <manejoArchivo.h>
#include <Cajero.h>
//Cajero automatico.
//Contra cacatua
int main()
{
    unsigned long long semilla = 4;
    short metodo = 2;
    string ruta = "../Lab3/Data_base/";

    string natural = "natural.txt";
    string codificado = "codificado.dat";
    string sudotxt = "..sudo.txt";
    string usuariodat = "usuario.dat";
    string pruebas = "pruebas.txt";

    pruebas.insert(0, ruta);
    usuariodat.insert(0, ruta);

    string usuario = "1230974, berengena, saldo(100)";

    unsigned long long pos;
    if(validarUsuario(semilla, usuariodat, pos)){
        cout << "Usuario valido" << endl;
        clean();
        string infoUsers = fEncript2StrDeco(semilla, usuariodat);
        impSaldo(infoUsers, pos);
        retirarSaldo(semilla, usuariodat, infoUsers, pos);


        metodo2D(semilla, usuariodat, pruebas);
    }
    else cout << "Te jodiste perro";


    //addUser(semilla, usuariodat, "1230974, berengena, saldo(100)");
    //metodo2D(semilla, usuariodat, pruebas);
    return 0;
}






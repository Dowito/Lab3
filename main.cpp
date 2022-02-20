#include <manejoArchivo.h>
#include <Cajero.h>

int main()
{
    unsigned long long esp = 3; //no me funciono para usar una macro :,(
    string natural = "natural.txt";
    string codificado = "codificado.dat";
    string sudotxt = "..sudo.txt";
    string usuariodat = "usuario.dat";
    string pruebas = "pruebas.txt";

    unsigned long long semilla = 0;
    short metodo;
    string ruta = "../Lab3/Data_base/";
    pruebas.insert(0, ruta);
    usuariodat.insert(0, ruta);

    short select;
    cout << "1) Codificacion / Decodificacion.\n"
            "2) Cajero\n"
            "Ingrese programa a ejecutar.\n->";
    select = inUnsignedLongLong();
    clean();
    switch (select) {
    case 1://Codificacion--------------------------------------------
        short select;
        cout << "1) Codificacion metodo 1.\n"
                "2) Decodificacion metodo 1.\n"
                "3) Codificacion metodo 2.\n"
                "4) Decodificacion metodo 2.\n"
                "Ingrese codificacion o decodificacion a ejecutar.\n->";
        select = inUnsignedLongLong();
        clean();
        switch (select) {
        case 1: //Codificacion metodo 1->Cad

            break;
        case 2: //Decodificacion metodo 1->Cad

            break;

        case 3: //Codificacion metodo 2->String

            break;

        case 4: //Decodificacion metodo 2->String

            break;

        default:
            cout << "Vuelva a intentar ingresando metodo valido (1, 2, 3 o 4)";
            break;
        }

        break;

    case 2://Cajero-------------------------------------------------------

        break;

    default:
        cout << "Vuelva a intentar ingresando un programa valido (1 o 2)";
        break;
    }

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






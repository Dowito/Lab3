#include <manejoArchivo.h>
#include <Cajero.h>

int main()
{
    string natural = "natural.txt";
    string codificado = "codificado.dat";
    string sudotxt = "..sudo.txt";
    string usuariodat = "usuario.dat";
    string pruebas = "pruebas.txt";

    unsigned long long semilla = 0;
    string ruta = "../Lab3/Data_base/";
    string inName;
    string outName;
    char *inNamecad;
    char *outNamecad;
    inNamecad = inCad();
    outNamecad = inCad();
    short select;
    cout << "1) Codificacion / Decodificacion.\n"
            "2) Cajero\n"
            "Ingrese programa a ejecutar.\n->";
    select = inUnsignedLongLong();
    clean();
    switch (select) {
    case 1:
        cout << "1) Codificacion metodo 1.\n"
                "2) Decodificacion metodo 1.\n"
                "3) Codificacion metodo 2.\n"
                "4) Decodificacion metodo 2.\n"
                "Ingrese codificacion o decodificacion a ejecutar.\n->";
        select = inUnsignedLongLong();
        clean();
        if (select==1){

        }
        else if (select==2) {

        }
        else if(select==3){
            cout << "Ingrese la semilla para la codificacion.\n->";
            semilla = 17;//inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inName = inString();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outName = inString();
            clean();
            inName.insert(0,ruta);
            outName.insert(0,ruta);
            metodo2C(semilla, inName, outName);
            cout << "Sea codificado usando el metodo 2 exitosamente.";
        }
        else if (select==4) {
            cout << "Ingrese la semilla para la decodificacion.\n->";
            semilla = inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inName = inString();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outName = inString();
            clean();
            inName.insert(0,ruta);
            outName.insert(0,ruta);
            metodo2D(semilla, inName, outName);
            cout << "Sea decodificado usando el metodo 2 exitosamente.";
        }
        else cout << "vuelva a intentarlo ingresando un metodo valido (1, 2, 3 o 4)";

        break;

    case 2:
        break;

    default:
        cout << "Vuelva a intentarlo ingresando un programa valido. (1 o 2)";
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






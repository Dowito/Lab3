#include <manejoArchivo.h>
#include <Cajero.h>
//semilla = 5 para el cajero
int main()
{
    unsigned long long semilla = 5;
    string natural = "natural.txt";
    string codificado = "codificado.dat";

    string sudotxt = "../Lab3/Data_base/sudo.txt";
    string usuariodat = "../Lab3/Data_base/usuario.dat";
    string pruebas = "../Lab3/Data_base/pruebas.txt";

    string rutaStr = "../Lab3/Data_base/";
    char rutaCad[] = "../Lab3/Data_base/";
    string inNameStr;
    string outNameStr;
    char *inNameCad;
    char *outNameCad;
    //metodo2D(semilla, usuariodat, pruebas);
    short select;
    cout << "1) Codificacion / Decodificacion.\n"
            "2) Cajero\n"
            "Ingrese programa a ejecutar.\n->";
    select = 2;//inUnsignedLongLong();
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
            cout << "Ingrese la semilla para la codificacion.\n->";
            semilla = inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inNameCad = inCad();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outNameCad = inCad();
            clean();
            inNameCad = insert(inNameCad, 0, rutaCad);
            outNameCad = insert(outNameCad, 0, rutaCad);
            metodo1C(semilla, inNameCad, outNameCad);
            cout << "Se ha codificado usando el metodo 1 exitosamente.";
        }
        else if (select==2) {
            cout << "Ingrese la semilla para la codificacion.\n->";
            semilla = inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inNameCad = inCad();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outNameCad = inCad();
            clean();
            inNameCad = insert(inNameCad, 0, rutaCad);
            outNameCad = insert(outNameCad, 0, rutaCad);
            metodo1D(semilla, inNameCad, outNameCad);
            cout << "Se ha decodificado usando el metodo 1 exitosamente.";
        }
        else if(select==3){
            cout << "Ingrese la semilla para la codificacion.\n->";
            semilla = inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inNameStr = inString();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outNameStr = inString();
            clean();
            inNameStr.insert(0,rutaStr);
            outNameStr.insert(0,rutaStr);
            metodo2C(semilla, inNameStr, outNameStr);
            cout << "Se ha codificado usando el metodo 2 exitosamente.";
        }
        else if (select==4) {
            cout << "Ingrese la semilla para la decodificacion.\n->";
            semilla = inUnsignedLongLong();
            clean();
            cout << "Ingrese el archivo de entrada (Ej: name.txt / name.dat).\n->";
            inNameStr = inString();
            clean();
            cout << "Ingrese el archivo de salida (Ej: name.txt / name.dat).\n->";
            outNameStr = inString();
            clean();
            inNameStr.insert(0,rutaStr);
            outNameStr.insert(0,rutaStr);
            metodo2D(semilla, inNameStr, outNameStr);
            cout << "Se ha decodificado usando el metodo 2 exitosamente.";
        }
        else cout << "Vuelva a intentarlo ingresando un metodo valido (1, 2, 3 o 4)";

        break;

    case 2:
        cout << "1) Ingresar como Administrador.\n"
                "2) Ingresar como Usuario\n"
                "Ingrese 1 para entrar como administrador o 2 para entrar como usuario.\n->";
        select = 1;//inUnsignedLongLong();
        clean();
        if (select == 1){//Ingresar como Aministrador
            cout << "Ingrese clave de arministrador.\n->";
            string contra = "Arfiler";//inString();
            clean();
            if(validarAdmin(semilla, 2, sudotxt, contra)){//Agregar usuario
                cout << "1) Agregar usuario.\n"
                        "2) Salir.\n"
                        "Ingrese 1 para agregar usuario o 2 para salir.\n->";
                select = 1;//inUnsignedLongLong();
                clean();
                if (select == 1) {//Agregando usuario
                    string usuario = formatoUsuario();
                    addUser(semilla, usuariodat, usuario);
                    cout << "Nuevo usuario agregado con exito";
                }
                else cout << "Gracias por usar nuestros servicios, tenga un buen dia";
            }
            else cout << "Clave no valida, intentelo de nuevo";
        }
        else if (select == 2) {//Ingresar como usuario

        }
        else cout << "Vuelva a intendar ingresando una opcion valida (1 o 2).";
        break;

    default:
        cout << "Vuelva a intentarlo ingresando un programa valido (1 o 2).";
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






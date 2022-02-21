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
        select = 2;//inUnsignedLongLong();
        clean();
        if (select == 1){//Ingresar como Aministrador
            cout << "Ingrese clave de arministrador.\n->";
            string contra = inString();
            clean();
            if(validarAdmin(semilla, 2, sudotxt, contra)){//Agregar usuario
                cout << "1) Agregar usuario.\n"
                        "2) Salir.\n"
                        "Ingrese 1 para agregar usuario o 2 para salir.\n->";
                select = inUnsignedLongLong();
                clean();
                if (select == 1) {//Agregando usuario
                    string usuario = formatoUsuario();
                    addUser(semilla, usuariodat, usuario);
                    cout << "Nuevo usuario agregado con exito";
                }
                else cout << "Gracias por usar nuestros servicios, tenga un buen dia.\n";
            }
            else cout << "Clave no valida, intentelo de nuevo";
        }
        else if (select == 2) {//Ingresar como usuario
            unsigned long long pos;
            string *CC = cedulaClave();
            if(validarUsuario(semilla, usuariodat, CC, pos)){
                cout << "1) Ver saldo.\n"
                        "2) Retirar saldo.\n"
                        "3) Salir.\n"
                        "Ingrese 1 para ver saldo, 2 para retirar saldo o 3 para salir.\n->";
                select = inUnsignedLongLong();
                clean();
                if (select == 1) { //Ver saldo
                    reSaldo(semilla, usuariodat, pos);
                    retirarSaldo(semilla, usuariodat, 1000, pos);
                    cout << "\nVer saldo tuvo un coste de 1000 COP.\n"
                            "Gracias por usar nuestros servicios, tenga un buen dia";
                }
                else if (select == 2) {//retirar saldo
                    reSaldo(semilla, usuariodat, pos);
                    cout << "\nCuanto desea retirar?\n->";
                    unsigned long long retiro = inUnsignedLongLong();
                    clean();
                    retirarSaldo(semilla, usuariodat, (retiro+1000), pos);
                    cout << "->Se han retirado " << retiro << " COP con exito.\n";
                    cout << "Retirar saldo tuvo un coste de 1000 COP.\n";
                    cout << "Gracias por usar nuestros servicios, tenga un buen dia.\n";
                }
                else cout << "Gracias por usar nuestros servicios, tenga un buen dia.\n";
            }
            else cout << "Vuelva a intentarlo.\n";
        }
        else cout << "Vuelva a intentarlo ingresando una opcion valida (1 o 2).\n";
        break;

    default:
        cout << "Vuelva a intentarlo ingresando un programa valido (1 o 2).\n";
        break;
    }
    return 0;
}

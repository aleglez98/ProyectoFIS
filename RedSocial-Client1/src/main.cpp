#include <iostream>
<<<<<< master
#include "../include/clientcontroller.h"
#include "../include/profile.h"
#include "../include/socket.h"

using namespace std;

int menu_inicio(){
    int opcion;
    do {
        system("clear");
        cout << "Bienvenido a nuestra red social " << endl;
        cout << "1.- Iniciar sesion" << endl;
        cout << "2.- Crear cuenta " << endl;
        cout << "0.- Salir " << endl;

        cout << ">> ";
        cin >> opcion;
        std::getchar();
    }while((opcion > 2) || (opcion < 0));

    return opcion;
}


int iniciar_sesion(ClientController client){

    InfoUser usuario;
    cout << " > Inicion de sesion" << endl;
    cout << " Intr. el nombre de usuario: ";
    cin >> usuario.name;
    cout << " Intr. la contraseña: ";
    cin >> usuario.passwd;

        return client.ControlLogin(usuario);
}



int crear_cuenta( ClientController client){

    InfoUser cuenta;

    cout << " > Crear cuenta " << endl;

    cout << " Intr. el usuario: ";
    cin >> cuenta.name;
    cout << " Intr. la contraseña: ";
    cin >> cuenta.passwd;
    cout << " Intr. la edad: ";
    cin >> cuenta.edad;

        return client.CrearCuenta(cuenta);

}

int main()
{
    string IP = "";
    cout << "Especificar IP del servidor" << std::endl;
    cin >> IP;

    ClientController client(IP);

    int opcion;
        do {
            opcion = menu_inicio();             //Login, etc
            switch(opcion){
                case 0:{
                    atomic<bool> condition;
                    condition = false;
                    client.UserSend(condition);
                    cout << "Saliendo..." << endl;
                    break;
                }
                case 1:{
                    cout << " 1- Iniciar sesion" << endl;
                        if(iniciar_sesion(client) == 0)
                            //Pedir opciones de cuenta
                            cout << "Cuenta iniciada correctamente" << endl;

                        else
                            cout << " Error al iniciar sesion" << endl;

                    break;
                }
                case 2:{
                    cout << " 2.- Crear cuenta" << endl;
                        if(crear_cuenta(client) == 0)
                            cout << " Cuenta creada correctamente " << endl;
                        else
                            cout << " Error al crear la cuenta" << endl;

                    break;
                }
                default:
                    cout << " opcion " << opcion << " no valida " << endl;

            }
        }while( opcion != 0);
======

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
>>>>>>master
}

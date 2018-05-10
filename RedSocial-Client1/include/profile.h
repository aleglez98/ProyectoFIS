#ifndef PROFILE_H
#define PROFILE_H

#include "socket.h"
/*

namespace FIS{

struct InfoUser{
    std::string name;     //Nombre comun de usuario
    std::string passwd;   //Contraseña -> El cifrado y los asuntos de seguridad los dejaría para más adelante
    int edad;             //Duh

    InfoUser():edad(0){}
};

struct User{

    std::string name;
    std::string passwd;
};

class Profile{
private:
    InfoUser data_;

    int TLFD_;          //TimeLine file descriptor, porque somos bilingües
        //La idea es que almacene los identificadores de los mensajes propios
    std::vector<Message> MensajesUsu_;

public:
    Profile(const std::string& nombre, const std::string& passwd);          //Recibir -> Datos de usuario, se le solicitan al crear la cuenta
    ~Profile();         //Dudo que tenga que hacer gran cosa

    //Getters y setters para atributos y posibles cambios de datos que quiera hacer el usuario
        //      El proceso de login probablemente vaya en el main
        //      + Opciones de solicitar cambios en su perfil y todas las funciones de interacción con la red social

    //Función añadir mensaje
    void ActualizarPerfil(const std::string& nombre, const std::string& passwd, int edad);

};

*/
#endif // PROFILE_H

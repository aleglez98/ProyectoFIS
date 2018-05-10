#ifndef PROFILE_H
#define PROFILE_H

#include "message.h"

namespace FIS{

class Profile{
private:
    int UserID_;        //Identificador numerico de usuario
    InfoUser data_;

    int TLFD_;          //TimeLine file descriptor, porque somos bilingües
        //La idea es que almacene los identificadores de los mensajes propios
    std::vector<FIS::Message> MensajesUsu_;

public:
    Profile(std::string nombre, std::string passwd, int UserID);          //Recibir -> Datos de usuario, se le solicitan al crear la cuenta
    ~Profile();         //Dudo que tenga que hacer gran cosa

    //Getters y setters para atributos y posibles cambios de datos que quiera hacer el usuario

};

}

#endif // PROFILE_H

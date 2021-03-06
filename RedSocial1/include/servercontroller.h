#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include "message.h"

namespace FIS{
struct Identificador{
    std::string username;
    std::string password;
};

class ServerController{
private:

    FIS::History history_;
    FIS::Socket socket_;        //El socket probablemente vaya en el main. Está por ver
    std::mutex mutex_;

public:
    ServerController(const sockaddr_in &address);
    ~ServerController();

    //Se suprime user_list -> lo tenemos almacenado en un fichero
    //Se suprime la referencia a History, pues es un atributo de la clase
    //Se suprime la referencia a Socket, pues forma parte de la clase
    void serverReceive(std::atomic<bool>& quit);
    //Procedimiento para recibir publicaciones simples

    void serverSend(std::atomic<bool>& quit, const std::string& username);
    //Envia info necesaria al cliente

    void ControlLogin(void);
    void Register(void);
};

}

#endif // SERVERCONTROLLER_H

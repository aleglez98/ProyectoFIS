#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <mutex>
//#include <set>
#include <utility>
#include <cstdlib>

#include "message.h"

namespace FIS{
struct Identificador{
    std::string username;
    std::string password;
};

class ServerController{
private:

    //FIS::History history_;
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

     void ControlLogin(std::atomic<bool>& quit, const std::string& username, const std::string& passwd){
        quit=ControlRegistro(username,passwd);
        serverSend(quit,username);
    }
    bool ControlRegistro(const std::string& username, const std::string& passwd){
        bool quit=false;
        string prueba;
        ifstream registro("basddatos.txt");
        while(quit==false){
            getline(registro,prueba);
            if(prueba.find(username)!= -1){
                if(prueba.find(",") != -1){
                    if(prueba.find(passwd)!= -1){
                        cout << "Usuario correcto\n";
                        Identificador.username=username;
                        Identificador.password=passwd;
                        exito=true;
                        serverSend(exito,username);
                        return exito;
                        }
                    }
                   else{
                    serverSend(exito,username);
                    return exito;
                    }
                }
            else{
                    serverSend(exito,username);
                    return exito;
                }
            }
        }
    }
};

}

#endif // SERVERCONTROLLER_H

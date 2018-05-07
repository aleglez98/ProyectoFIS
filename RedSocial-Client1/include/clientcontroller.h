#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <mutex>
#include <set>
#include <utility>
#include <cstdlib>

#include "profile.h"

namespace FIS{

void procesamiento_de_opciones( sockaddr_in &dir_servidor, sockaddr_in &dir_cliente,int argc, char* argv[]);
sockaddr_in make_ip_address(const std::string& ip_address, int port);

class ClientController{
private:

    FIS::Profile ClientProfile_;
    Socket socket_;        
    std::mutex mutex_;
    sockaddr_in dir_servidor{};
    sockaddr_in dir_cliente{};

public:
    ClientController();
    ~ClientController();

    int UserSend(std::atomic<bool>& quit);

     int ControlLogin(const User&);
     int CrearCuenta(const InfoUser& );
     //void SolicitarAcceso();   //-> señal a server
};

}

#endif // CLIENTCONTROLLER_H

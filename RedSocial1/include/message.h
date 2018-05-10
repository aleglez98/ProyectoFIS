#ifndef MESSAGE_H
#define MESSAGE_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cerrno>               //errno
#include <cstring>
#include <cstdio>               //Funciones tipo C
#include <cstdlib>
#include <unistd.h>
#include <system_error>         //Errores de sistema
#include <exception>
#include <thread>
#include <atomic>
#include <pthread.h>
#include <cxxabi.h>
#include <getopt.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <system_error>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <algorithm>
#include <mutex>
#include <set>
#include <utility>
#include <cstdlib>
#include <vector>

namespace FIS{

sockaddr_in make_ip_address(std::string ip_address, int port);
void procesamiento_de_opciones(bool& help_option, std::string& port_option, int argc, char* argv[]);
struct Message{

    Message() {}
    char username[90];          //El campo de username tiene una longitud de caracteres arbitraria
    char text[281];

    unsigned int ID;            //El campo es necesario para la organización de los mensajes en la base de datos
    int TimeOfLife;             //El campo es necesario para la posible implementación de un orden cronológico

    //Campos para MG, RT y Comments ... FUTURA IMPLEMENTACION
};

struct InfoUser{

    std::string name;
    std::string passwd;
    int edad;
};

class Socket
{
    int fd_;        //FILE DESCRIPTOR
    int result_;    //BIND RESULT

public:
    Socket();
    Socket(const sockaddr_in& address);
    ~Socket();

    int get_fd(){ return fd_; }
    int get_result(){ return result_; }

    void send_to(const Message& message, const sockaddr_in& remote_address);    ///<@brief Sends message to a certain address
    void recieve_from(Message& message, sockaddr_in& address);          ///<@brief Recieves message from a certain address

    void recieve_userInfo(int fd, InfoUser &userI, sockaddr_in &remote_address);

};

}

#endif // MESSAGE_H

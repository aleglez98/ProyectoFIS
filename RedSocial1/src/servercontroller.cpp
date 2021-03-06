#include "../include/servercontroller.h"

using namespace FIS;

ServerController::ServerController(const sockaddr_in &address){

    socket_ = Socket(address);
}

ServerController::~ServerController(){

}
void ServerController::Register(void){
    InfoUser userI;
    sockaddr_in rem_address{}
    socket_.recieve_userInfo(socket_.get_fd(), userI, rem_address);
    bool reg=hist_.register(userI.name,userI.passwd);
    if(reg==false){
        std::cout << "fallo en la creacion del usuario\n";}
    else{
        std::cout << "El usuario se ha creado perfectamente\n";}
}
void ServerController::ControlLogin(void){
    InfoUser userI;
    sockaddr_in rem_address{}
    socket_.recieve_userInfo(socket_.get_fd(), userI, rem_address);
    hist_.register(userI.name,userI.passwd);
    return;
}

void ServerController::serverSend(std::atomic<bool> &quit, const std::string &username){

    Message message;
    std::string message_text;
    while(!quit){

    }
}

void ServerController::serverReceive(std::atomic<bool> &quit){

    InfoUser userI;
    Message msg;
    sockaddr_in rem_address{};
    while(!quit){

        std::cout << "Caca" << std::endl;

        /*socket_.recieve_userInfo(socket_.get_fd(), userI, rem_address);

        std::cout << "NOMBRE: " << userI.name << std::endl;
        std::cout << "PASSWD: " << userI.passwd << std::endl;
        */
        socket_.recieve_from(msg, rem_address);
        std::cout << "NOMBRE: " << msg.username << std::endl;
        std::cout << "TEXTOS: " << msg.text << std::endl;
    }
}

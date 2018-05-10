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
    fstream fs;
    fs.open("basddatos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << userI.name << ",";
    fs << userI.passwd << "," << endl;
    fs.close();
    socket_.send_infoUser(userI,rem_address);
}
void ServerController::ControlLogin(void){
    InfoUser userI;
    sockaddr_in rem_address{}
    socket_.recieve_userInfo(socket_.get_fd(), userI, rem_address);
    ifstream registro("basddatos.txt");
    bool exito=false;
    while(exito==false){
        getline(registro,prueba);
        if(prueba.find(userI.name)!= -1){
            if(prueba.find(",") != -1){
                if(prueba.find(userI.passwd)!= -1){
                    cout << "Usuario correcto\n";
                    exito=true;
                }
            }
        }
    }
    socket_.send_infoUser(userI,rem_address);
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

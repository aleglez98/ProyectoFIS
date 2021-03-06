<<<<<< master
#include "../include/clientcontroller.h"
#include "../include/profile.h"
#include "../include/socket.h"
======
>>>>>> master


sockaddr_in ClientController::make_ip_address(const std::string& ip_address, int port){

    sockaddr_in local_address{};                            //inicializacion a 0
    local_address.sin_family = AF_INET;                     //dominio local
    if(ip_address == ""){
        local_address.sin_addr.s_addr = htonl(INADDR_ANY);      //32 bits
    }
    else{
        local_address.sin_addr.s_addr = inet_addr(ip_address.c_str());
    }
    local_address.sin_port = htons(port);                       //16 bits

    return local_address;

}

ClientController::ClientController(std::string ip_server)
{

    dir_cliente = make_ip_address("", 8888);
    dir_servidor = make_ip_address(ip_server, 7777);
    Socket _socket_(dir_cliente);
    socket_ = _socket_;

}
ClientController::~ClientController(){}

void ClientController::UserSend(std::atomic<bool> &quit ){

    Message message;
    std::string message_text;
    while(!quit){
        message_text.clear();
        memset(message.text,'\0',strlen(message.text));
        std::cout << ">" ;
        std::getline(std::cin, message_text);

        if(message_text == "/quit")
            quit = true;
        else{
            message_text.copy(message.text,sizeof(message.text)-1,0);
            socket_.send_to(message, dir_servidor);
        }

    }
}

<<<<<< master
void ClientController::UserRecieve(std::atomic<bool>& quit){
    
    Message message;
    
    while(!quit){
        socket_.recieve_from(message,dir_servidor);
        
        if(message.text[0] != '\0'){
            
               // Mostrar el mensaje recibido en la terminal
 /*   */           char* remote_ip = inet_ntoa(dir_servidor.sin_addr);
              int remote_port = ntohs(dir_servidor.sin_port);
         message.text[280] = '\0';
          std::cout << "\n"
                    << "\nUsuario " << message.username
                   // << "\nHora: " << message.tiempo
                    << "\nDireccion " << remote_ip << ":" << remote_port
                    << "\nMensaje '" << message.text << "'\n";

        
        }
        
   }
}

int ClientController::ControlLogin(void){
    InfoUser Info,Info1;
    cout << "Ha elegido iniciar sesion" << endl;
    cout << "Introduzca su nombre de usuario:";
    cin >> Info.name;
    cout << "Introduzca su password:";
    cin >> Info.passwd;
    socket_.send_infoUser(Info, dir_servidor);
    std::string confir = "";
    socket_.recieve_confir(confir, dir_servidor);
    if(!confir.empty()){
        socket_.receive_infoUser(Info1,dir_servidor);
        if((Info.name==Info1.name)&&(Info.passwd==Info1.passwd)){
            cout << "Usuario comprobado correctamente";
            return 0;
            }
            }
    return -1;
}

<<<<<< master


======
int ClientController::CrearCuenta(InfoUser& info){
    cout << "Ha elegido crear cuenta" << endl;
    cout << "Dime tu nombre de usuario:";
    cin >> info.username;
    cout << "Dime tu password:";
    cin >> Info.password;
    socket_.send_infoUser(infoUser, dir_servidor);
    std::string confir = "";
    socket_.recieve_confir(confir, dir_servidor);
    if(!confir.empty()){
        socket_.receive_infoUser(Info1,dir_servidor);
        if((Info.name==Info1.name)&&(Info.passwd==Info1.passwd)){
            cout << "Usuario creado correctamente";
            return 0;
            }
        //ahora habria que redireccionarlo a perfil o a un menu inicial
    }
    
        
    return -1;

}


#include "../include/servercontroller.h"

//Vaina para cancelar hilos
void request_cancellation(std::thread& hilo){
    pthread_cancel(hilo.native_handle());
}

int main(int argc, char* argv[]){

    FIS::Message msg;
    const int SERVER_PORT = 7777;
    sockaddr_in my_addr{};

    try{
        my_addr = FIS::make_ip_address("", SERVER_PORT);     //MAKE_IP_ADDR usará INADDR_ANY -> Acepta conexiones a cualquier IP del server
        std::atomic<bool> quit(false);

        FIS::ServerController server(my_addr);

        std::string username("Matias");
        std::thread hilo1(&FIS::ServerController::serverReceive, &server, std::ref(quit));
        //std::thread hilo2(&FIS::ServerController::serverSend, &server, std::ref(quit), std::ref(username));

        hilo1.join();
        /*if(quit){
            request_cancellation(hilo2);
            hilo2.join();
        }*/

    }catch(std::system_error& e){
        std::cerr << program_invocation_name << ": " << e.what() << '\n';
        return 6;
    }
    catch(int e){
        std::cerr << "Error " << e << ": problemilla\n";
    }

    return 0;
}

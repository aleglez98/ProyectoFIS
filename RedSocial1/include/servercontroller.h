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

    struct ControlLogin(std::atomic<bool>& quit, const std::string& username, const std::string& passwd){
        string 
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
                        return &Identificador;
                        }
                    }
                }
            else{
                cout <<"Comprueba las credenciales"<<endl;
                cout << "Introduzca su nombre de usuario:";
                cin >> usuario;
                //cout << endl;
                cout << "Introduzca contraseña:";
                cin >> pass;
            }
            }
    }
    struct ControlRegistro(const std::string& username, const std::string& passwd){
        ofstream registro("basddatos.txt");
        cout << "introduce tu nombre:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu apellido:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu nombre de usuario:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu contraseña";
        cin >> resp;
        registro << resp << ",";
        registro << endl;
    }
    //Comprueba si credenciales existen, si no, manda a crear un usuario nuevo y da acceso a la red

    /*
     * void EditarPerfil(//indice de perfil a editar, //a quién se lo muestro);
     * void MostrarPerfil(//indice de perfil a mostrar, //a quién se lo muestro);
     * void MostrarTimeline(//mostrar timeline de quién, //a quién se lo muestro,);
     *                      //Manejar dentro de manera interactiva si muestra la general, me gustas o retweets
    */
};

}

#endif // SERVERCONTROLLER_H

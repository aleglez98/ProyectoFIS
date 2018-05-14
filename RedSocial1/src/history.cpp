#include"../include/history.h"

bool FIS::Register(string &user,string &passwd){
   ifstream registro("login.txt");
   bool exito=false,encontrado=false;
   i=1;
   while(exito==false){
      getline(registro,prueba);
      if(prueba.find(usuario)!= -1){
        if(prueba.find(",") != -1){
          if(prueba.find(pass)!= -1){
            cout << "Usuario correcto\n";
            exito=true;
            return exito;
            }
          }
        }
      if((exito==false)&&(i<=3)){
        cout <<"Comprueba las credenciales"<<endl;
        cout << "Introduzca su nombre de usuario:";
        cin >> user;
        cout << "Introduzca contraseña:";
        cin >> passwd; 
        }
      if else((exito==false)&&(i>3)){
        cout<<"no esta logeado por favor cree una cuenta"<<endl;
        return exito;
        }
      i++;
            }
}

bool FIS::Login(std::string name,std::string passwd){
    std::fstream fs;
    fs.open("login.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << name << ",";
    fs << passwd << "," << endl;
    fs.close();
    return true;
}
void FIS::AddMessage(const Message& message){
   std::fstream fs;
   fs.open("tweets.txt", std::fstream::in | std::fstream::out | std::fstream::app);
   fs << message.username << std::endl;
   fs << message.passwd << std::endl;
   fs << message.text << std::endl;
   profile.insertar(message,UserID,user);  //Funcion para insertar en la cuenta del usuario sus tweets
}

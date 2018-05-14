#include"../include/history.h"

bool FIS::Register(string &user,string &passwd){
   ifstream registro("basddatos.txt");
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

bool FIS::Login(string name,string passwd){
    fstream fs;
    fs.open("basddatos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << name << ",";
    fs << passwd << "," << endl;
    fs.close();
    return true;
}

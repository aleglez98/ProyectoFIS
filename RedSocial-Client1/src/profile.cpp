#include "../include/profile.h"

using namespace FIS;

Profile::Profile(const std::string& nombre, const std::string& passwd){

    data_.name = nombre;
    data_.passwd = passwd;

    //Copiar datos a la cache

}

Profile::~Profile(){}

void Profile::ActualizarPerfil(std::string& nombre, const std::string& passwd, int edad){
    //...
}

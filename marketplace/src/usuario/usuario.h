//Usuario.h
//Definición de la clase Usuario
#ifndef PERSON_H
#define PERSON_H
#include <string>


class Usuario{
    private:
        unsigned usuario_;
        std::string nombre_;
        std::string apellidos_;
        std::string dni_;
        std::string correo_;
        std::string rol_;
    public:
        Usuario(unsigned usuario, std::string nombre, std::string apellidos, 
        std::string dni, std::string correo, std::string rol) : 
        usuario_(usuario), nombre_(nombre), apellidos_(apellidos),
        dni_(dni), correo_(correo), rol_(rol) {}
};

#endif
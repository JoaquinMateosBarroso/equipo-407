//Usuario.h
//Definición de la clase Usuario
#ifndef PERSON_H
#define PERSON_H
#include <string>


class Usuario{
    private:
        unsigned usuario;
        std::string nombre;
        std::string apellidos;
        std::string dni;
        std::string correo;
        std::string rol;
};

#endif
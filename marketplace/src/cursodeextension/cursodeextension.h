#ifndef CURSOEEXTENSION_H
#define CURSOEEXTENSION_H
//person.h
//A simple person class

#include <string>
#include <list>
#include "usuario.h"

class CursodeExtension: public Usuario{
    private:
        int codigo;
        std::string nombre;           //DNI de la persona
        std::list<Usuario> participantes;
    public:
    void añadir_usuario(Usuario const u);
};


#endif
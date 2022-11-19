#ifndef CURSOEEXTENSION_H
#define CURSOEEXTENSION_H
//person.h
//A simple person class

#include <string>
#include <list>
#include "usuario.h"

class CursodeExtension{
    private:
        int _codigo;
        std::string _nombre;           //DNI de la persona
        std::list<Usuario> _participantes;
    public:
    CursodeExtension(int codigo, std::string nombre);
    inline std::string get_nombre() {return _nombre;}
    inline int get_codigo() {return _codigo;}
    inline void añadir_usuario(Usuario const u){_participantes.push_back(u);}
};


#endif
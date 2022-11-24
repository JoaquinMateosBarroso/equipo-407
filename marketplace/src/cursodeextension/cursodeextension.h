#ifndef CURSOEEXTENSION_H
#define CURSOEEXTENSION_H
//person.h
//A simple person class

#include <string>
#include <list>
#include <repositoriousuarios.h>
#include "usuario.h"

class CursodeExtension{
    private:
        int _codigo;
        std::string _nombre;
        std::string _descripcion;
        std::string _coordinador;
        RepositorioUsuarios _participantes;
    public:
    //Constructor por parametros
    CursodeExtension(int codigo, std::string nombre, std::string decripcion);

    inline std::string get_nombre() {return _nombre;}

    inline std::string get_descripcion() {return _descripcion;}
    
    inline RepositorioUsuarios get_participantes() {return _participantes;}

    inline int get_codigo() {return _codigo;}

    inline void añadir_usuario(Usuario const u){_participantes.push_back(u);}

};


#endif
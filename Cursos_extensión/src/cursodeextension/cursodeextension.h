#ifndef CURSOEEXTENSION_H
#define CURSOEEXTENSION_H


#include <string>
#include <list>
#include <repositoriousuarios.h>
#include <repositoriorecursos.h>
#include "usuario.h"

class CursodeExtension{
    private:
        int _codigo;
        int _max;
        std::string _nombre;
        std::string _descripcion;
        std::string _coordinador;
        RepositorioUsuarios _participantes;
        RepositorioUsuarios _lista_espera;
        RepositorioRecursos _lista_recursos;
    public:
    //Constructor por parametros
    CursodeExtension(int codigo, std::string nombre, std::string decripcion, int max);

    inline std::string get_nombre() {return _nombre;}

    inline std::string get_descripcion() {return _descripcion;}
    
    inline RepositorioUsuarios get_participantes() {return _participantes;}

    inline int get_codigo() {return _codigo;}

    bool añadir_usuario(Usuario const u);
    bool añadir_recurso(std::string recurso) {return _lista_recursos.push_back(recurso);};

    // implementar estadisticas
    // hacer un get_estadisticas que sea un map

};


#endif
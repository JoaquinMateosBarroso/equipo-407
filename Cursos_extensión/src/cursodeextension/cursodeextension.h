#ifndef CURSOEEXTENSION_H
#define CURSOEEXTENSION_H


#include <string>
#include <list>
#include <map>
#include <repositoriousuarios.h>
#include <repositoriorecursos.h>
#include "usuario.h"
//#include <database.h>

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
    inline RepositorioUsuarios get_lista_espera() {return _lista_espera;}
    inline RepositorioRecursos get_recursos() {return _lista_recursos;}

    inline int get_codigo() {return _codigo;}
    inline int get_max() {return _max;}

    bool añadir_usuario(Usuario const u);
    bool añadir_recurso(std::string recurso) {return _lista_recursos.push_back(recurso);};



};


#endif
#include <string.h>
#include <list>
#include <iostream>
#include <cursodeextension.h>
#include <usuario.h>
#include "database.h"

Database::Database(std::list<CursodeExtension> cursos_extension, std::list<Usuario> usuarios_registrados){
    _cursos_extension = cursos_extension;
    _usuarios_registrados = usuarios_registrados;
}

CursodeExtension Database::buscar_curso(std::string const nombre) {
    for (auto it = _cursos_extension.begin(); it == _cursos_extension.end(); it++)
    {
        if (it->get_nombre() == nombre) {
            return *it;
        }
    }
    return CursodeExtension(0, "empty", "empty");
}

CursodeExtension Database::buscar_curso(int const codigo) {
    for (auto it = _cursos_extension.begin(); it == _cursos_extension.end(); it++)
    {
        if (it->get_codigo() == codigo) {
            return *it;
        }
    }
    return CursodeExtension(0, "empty", "empty");
}

bool Database::dar_alta_curso(Usuario usuario, CursodeExtension curso)
{
    // if (usuario.rol_=="Coordinador cursos"){

    // }
    //comprobar que usuario.rol == "Coordinador cursos"


    //Al final del if devuelves true junto con el _cursos_extension.pushback(curso)

    //Si algún curso se llama igual devolver false también

    //return false si no
}
#include <string.h>
#include <list>
#include <iostream>
#include <cursodeextension.h>
#include <usuario.h>
#include "database.h"


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
    //comprobar que usuario.rol == "Coordinador cursos"


    //Al final del if devuelves true

    //Si algún curso se llama igual devolver false también
    // Lo puedes comprobar con _cursos_extension.buscar_curso(curso.get_nombre())
    
    
    //return false si no

    
    
    
    //###########################################################################################################

    // Miguel, lo de abajo es solo para la prueba de persistencia. Cuando hagas esta funcion quita a partir de aqui
    _cursos_extension.push_back(curso);
    return true;
}
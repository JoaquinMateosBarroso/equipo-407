#include <string.h>
#include <list>
#include <iostream>
#include <cursodeextension.h>
#include <usuario.h>
#include "database.h"


int Database::dar_alta_curso(Usuario usuario, std::string nombre_curso, std::string descripcion_curso)
{
    // if (usuario.rol_=="Coordinador cursos"){

    // }
    //comprobar que usuario.rol == "Coordinador cursos"


    //Al final del if devuelves true junto con el _cursos_extension.pushback(curso)

    //Si algún curso se llama igual devolver false también
    // Lo puedes comprobar con _cursos_extension.buscar_curso(curso.get_nombre())
    
    
    //return false si no

    
    
    
    //*************************************************************************

    // Miguel, lo de abajo es solo para pruebas. Cuando hagas esta funcion quita el return
    return 2;
}


bool Database::login_usuario(const std::string &dni, const std::string &contrasena, Usuario &usuario){
    if (_usuarios_registrados.existe_usuario_contrasena(dni, contrasena)) { usuario = _usuarios_registrados.buscar_usuario(dni); return true;}
    else {return false;}
}
#include <string.h>
#include <list>
#include <iostream>
#include <cursodeextension.h>
#include <usuario.h>
#include "database.h"


int  Database::dar_alta_curso(Usuario usuario, std::string nombre_curso, std::string descripcion_curso, int max)
{
      if (_cursos_extension.buscar_curso(nombre_curso).get_codigo()!=0){
        return -1;
    }
        int n = get_n_cursos()+1;
        _cursos_extension.push_back(CursodeExtension(n, nombre_curso,descripcion_curso, max ));
        return n;

}


bool Database::login_usuario(const std::string &dni, const std::string &contrasena, Usuario &usuario){
    if (_usuarios_registrados.existe_usuario_contrasena(dni, contrasena)) { usuario = _usuarios_registrados.buscar_usuario(dni); return true;}
    else {return false;}
}
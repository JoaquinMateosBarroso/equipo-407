#include <string>
#include <list>
#include <iostream>
#include <cursodeextension.h>
#include <usuario.h>
#include "database.h"
#include <cmath>


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


std::map <std::string, std::string> Database::get_estadisticas(CursodeExtension &curso)
{
    std::map <std::string, std::string> estadisticas;
    int n_total_usuarios = 0;
    for (auto i = begin(); i != end(); i++){
        n_total_usuarios += i->get_participantes().get_n_usuarios();
    }

    estadisticas["Porcentaje de aforo cubierto"] = (curso.get_max() == 0) ? "1" : std::to_string(round( float(curso.get_participantes().get_n_usuarios()) / float(curso.get_max()) * 100 )).substr(0, 4) + "%";
    estadisticas["Porcentaje de usuarios de la página inscritos en el curso"] = (get_n_usuarios() == 0) ? "0" : std::to_string(round( float(curso.get_participantes().get_n_usuarios()) / get_n_usuarios() * 100)).substr(0, 4) + "%";



    return estadisticas;
}
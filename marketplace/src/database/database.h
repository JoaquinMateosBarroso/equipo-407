#ifndef DATABSE_H
#define DATABSE_H
//person.h
//A simple person class

#include <string>
#include <list>
#include <usuario.h>
#include <cursodeextension.h>
#include <repositoriocursos.h>
#include <repositoriousuarios.h>


class Database{
    private:
        RepositorioCursos _cursos_extension;
        RepositorioUsuarios _usuarios_registrados;
    public:
        Database():_cursos_extension("cursos"), _usuarios_registrados("usuarios"){};
        inline void registrar_usuario(Usuario const usuario) {_usuarios_registrados.push_back(usuario);}
        Usuario login_usuario(std::string const dni);
        inline CursodeExtension buscar_curso(std::string const nombre){return _cursos_extension.buscar_curso(nombre);}
        inline CursodeExtension buscar_curso(int const codigo){return _cursos_extension.buscar_curso(codigo);}
        bool dar_alta_curso(Usuario usuario, CursodeExtension curso);
};


#endif
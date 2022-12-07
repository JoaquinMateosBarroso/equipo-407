#ifndef DATABSE_H
#define DATABSE_H


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
        Database() : _cursos_extension("cursos"), _usuarios_registrados("usuarios"){}
        //Usuarios
        // Devuelve true si lo ha podido registrar y false si ya existia
        bool inline registrar_usuario(Usuario const &usuario) {return _usuarios_registrados.push_back(usuario);}
        bool login_usuario(const std::string &dni, const std::string &contrasena, Usuario &usuario);
        int get_n_usuarios() {return _usuarios_registrados.get_n_usuarios();}

        //Cursos
        inline CursodeExtension buscar_curso(std::string const nombre){return _cursos_extension.buscar_curso(nombre);}
        inline CursodeExtension buscar_curso(int const codigo){return _cursos_extension.buscar_curso(codigo);}
        int dar_alta_curso(Usuario usuario, std::string nombre_curso, std::string descripcion_curso);
        inline std::list<CursodeExtension>::iterator begin() {return _cursos_extension.begin();}
        inline std::list<CursodeExtension>::iterator end() {return _cursos_extension.end();}
        int get_n_cursos() {return _cursos_extension.get_n_cursos();}

};


#endif
#ifndef DATABSE_H
#define DATABSE_H
//person.h
//A simple person class

#include <string>
#include <list>
#include <usuario.h>
#include <cursodeextension.h>

class Database{
    private:
        std::list<CursodeExtension> _cursos_extension;
        std::list<Usuario> _usuarios_registrados;
    public:
        Database() {}
        inline void registrar_usuario(Usuario const usuario) {_usuarios_registrados.push_back(usuario);}
        Usuario login_usuario(std::string const dni);
        CursodeExtension buscar_curso(std::string const nombre);
        CursodeExtension buscar_curso(int const codigo);
        bool dar_alta_curso(Usuario usuario, CursodeExtension curso);
};


#endif
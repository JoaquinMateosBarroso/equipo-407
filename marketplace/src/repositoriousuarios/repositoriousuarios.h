#ifndef REPOSITORIOUSUARIOS_H
#define REPOSITORIOUSUARIOS_H
//person.h
//A simple person class

#include <string>
#include <list>
#include <usuario.h>
#include <cursodeextension.h>

class RepositorioUsuarios{
    private:
        // Nombre del archivo
        std::string _nombre;
        // Los cursos en RAM
        std::list<Usuario> _usuarios;

        // Para anadir un curso al fichero
        void persistir_usuario(Usuario usuario);
        
    public:
        RepositorioUsuarios(std::string nombre_fichero);
        int get_n_usuarios() {return _usuarios.size();}
        void push_back(Usuario usuario);
        inline std::list<Usuario>::iterator begin() {return _usuarios.begin();}
        inline std::list<Usuario>::iterator end() {return _usuarios.end();}
        Usuario buscar_usuario(std::string const dni);
        bool existe_usuario_contrasena(const std::string &dni,const std::string &contrasena);

        //Esto es lentísimo pero estoy cansado de que todo vaya mal, mientras no haya 10k cursos todo va a ir bien
        std::list<Usuario> lista_entera() {return _usuarios;}
};


#endif
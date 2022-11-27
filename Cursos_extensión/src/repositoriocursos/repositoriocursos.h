#ifndef REPOSITORIOCURSOS_H
#define REPOSITORIOCURSOS_H
//person.h
//A simple person class

#include <string>
#include <list>
#include <usuario.h>
#include <cursodeextension.h>

class RepositorioCursos{
    private:
        std::string _nombre;
        // Los cursos en RAM
        std::list<CursodeExtension> _cursos_extension;
        // Para anadir un curso al fichero
        void persistir_curso(CursodeExtension curso);
    public:
        RepositorioCursos(std::string nombre_fichero);
        void push_back(CursodeExtension curso);
        inline std::list<CursodeExtension>::iterator begin() {return _cursos_extension.begin();}
        inline std::list<CursodeExtension>::iterator end() {return _cursos_extension.end();}
        CursodeExtension buscar_curso(std::string const nombre);
        CursodeExtension buscar_curso(int const codigo);
        inline int get_n_cursos(){return _cursos_extension.size();}

};


#endif
#ifndef REPOSITORIORECURSOS_H
#define REPOSITORIORECURSOS_H
//person.h
//A simple person class

#include <string>
#include <list>

class RepositorioRecursos{
    private:
        // Nombre del archivo
        std::string _nombre;
        // Los cursos en RAM
        std::list<std::string> _recursos;

        // Para anadir un curso al fichero
        void persistir_recurso(std::string recurso);
        
    public:
        RepositorioRecursos(std::string nombre_fichero);
        inline int get_n_recursos() {return _recursos.size();}
        bool push_back(std::string recurso);
        inline std::list<std::string>::iterator begin() {return _recursos.begin();}
        inline std::list<std::string>::iterator end() {return _recursos.end();}
        bool existe_recurso(std::string const recurso);

        std::list<std::string> lista_entera() {return _recursos;}
};


#endif
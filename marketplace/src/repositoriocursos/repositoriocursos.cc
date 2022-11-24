#include <string.h>
#include <list>
#include <iostream>
#include <fstream>
#include <cursodeextension.h>
#include <usuario.h>
#include "repositoriocursos.h"

// ###########################################################################################
//                                      F I C H E R O S

// Constructor que recoge al ser ejecutado recoge los datos del fichero dado por nombre, si no existe, lo crea
RepositorioCursos::RepositorioCursos(std::string nombre_fichero){
    _nombre = nombre_fichero;
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs = fopen(nombre_archivo.c_str(), "r")){
        int codigo;
        char nombre[255], descripcion[255];
        while(std::fscanf(fs, "%i;%254[^;];%254[^;];\n", &codigo, nombre, descripcion) != EOF){
            CursodeExtension c(codigo, std::string(nombre), std::string(descripcion));
            _cursos_extension.push_back(c);
        };
        fclose(fs);
    } else
    {
        fs = fopen(nombre_archivo.c_str(), "w");
        fclose(fs);
    }
    
}
// Funcion que guarda en fichero el curso
void RepositorioCursos::persistir_curso(CursodeExtension curso){
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs=fopen(nombre_archivo.c_str(), "a"))
    {
        fprintf(fs, "%i;%s;%s;\n", 
                curso.get_codigo(),
                curso.get_nombre().c_str(),
                curso.get_descripcion().c_str());
        fclose(fs);
    }else
    {
        std::cout << "Error al persistir datos" << std::endl;
    }  
}

// ###########################################################################################


CursodeExtension RepositorioCursos::buscar_curso(std::string const nombre) {
    for (auto it = _cursos_extension.begin(); it != _cursos_extension.end(); it++)
    {
        if (it->get_nombre() == nombre) {
            return *it;
        }
    }
    return CursodeExtension(0, "empty", "empty");
}

CursodeExtension RepositorioCursos::buscar_curso(int const codigo) {
    for (auto it = _cursos_extension.begin(); it != _cursos_extension.end(); it++)
    {
        if (it->get_codigo() == codigo) {
            return *it;
        }
    }
    return CursodeExtension(0, "empty", "empty");
}

void RepositorioCursos::push_back(CursodeExtension curso) {
    CursodeExtension encontrado = buscar_curso(curso.get_nombre());
    if (encontrado.get_codigo() == 0)
    {
        persistir_curso(curso);
        _cursos_extension.push_back(curso);
    }
    
}
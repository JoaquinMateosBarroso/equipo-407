#include <string.h>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "repositoriorecursos.h"

// ###########################################################################################
//                                      F I C H E R O S

// Constructor que recoge al ser ejecutado recoge los datos del fichero dado por nombre
RepositorioRecursos::RepositorioRecursos(std::string nombre_fichero){
    _nombre = nombre_fichero;
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs = fopen(nombre_archivo.c_str(), "r")){
        char recurso[255];
        while(std::fscanf(fs, "%254[^;];\n", recurso) != EOF){
            _recursos.push_back(recurso);
        };
        fclose(fs);
    } else
    {
        fs = fopen(nombre_archivo.c_str(), "w");
        fclose(fs);
    }
}

// Funcion que guarda en fichero
void RepositorioRecursos::persistir_recurso(std::string recurso){
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs=fopen(nombre_archivo.c_str(), "a"))
    {
        fprintf(fs, "%s;\n", recurso.c_str());
        fclose(fs);
    }else
    {
        std::cout << "Error al persistir datos" << std::endl;
    }  
}

// ###########################################################################################

bool RepositorioRecursos::existe_recurso(std::string const recurso) {
    for (auto it = _recursos.begin(); it != _recursos.end(); it++)
    {
        if (recurso == *it) {
            return true;
        }
    }
    return false;
}

bool RepositorioRecursos::push_back(std::string recurso) {
    if (!existe_recurso(recurso)){
        persistir_recurso(recurso);
        _recursos.push_back(recurso);
        return true;
    }
    return false;
}

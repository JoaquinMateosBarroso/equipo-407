#include <string.h>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cursodeextension.h>
#include <usuario.h>
#include "repositoriousuarios.h"

// ###########################################################################################
//                                      F I C H E R O S

// Constructor que recoge al ser ejecutado recoge los datos del fichero dado por nombre
RepositorioUsuarios::RepositorioUsuarios(std::string nombre_fichero){
    _nombre = nombre_fichero;
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs = fopen(nombre_archivo.c_str(), "r")){
        unsigned* usuario = (unsigned*)std::malloc(sizeof(unsigned));
        char dni[255], nombre[255], apellidos[255], correo[255], contrasena[255], rol[255];
        while(std::fscanf(fs, "%u;%254[^;];%254[^;];%254[^;];%254[^;];%254[^;];%254[^;];\n", 
                            usuario, 
                            dni, 
                            nombre, 
                            apellidos, 
                            correo,
                            contrasena,
                            rol) != EOF){
            Usuario u(*usuario, std::string(nombre), std::string(apellidos), std::string(dni), std::string(correo), std::string(contrasena), std::string(rol));
            _usuarios.push_back(u);
        };
        fclose(fs);
    } else
    {
        fs = fopen(nombre_archivo.c_str(), "w");
        fclose(fs);
    }
}

// Funcion que guarda en fichero
void RepositorioUsuarios::persistir_usuario(Usuario usuario){
    std::string nombre_archivo = _nombre + ".txt";
    std::FILE *fs;
    if (fs=fopen(nombre_archivo.c_str(), "a"))
    {
        fprintf(fs, "%u;%s;%s;%s;%s;%s;%s;\n", 
                usuario.get_usuario(), 
                usuario.get_dni().c_str(), 
                usuario.get_nombre().c_str(), 
                usuario.get_apellidos().c_str(), 
                usuario.get_correo().c_str(), 
                usuario.get_contrasena().c_str(),
                usuario.get_rol().c_str());
        fclose(fs);
    }else
    {
        std::cout << "Error al persistir datos" << std::endl;
    }  
}

// ###########################################################################################

Usuario RepositorioUsuarios::buscar_usuario(std::string const dni) {
    for (auto it = _usuarios.begin(); it != _usuarios.end(); it++)
    {
        if (it->get_dni() == dni) {
            return Usuario(
                it -> get_usuario(),
                it -> get_nombre(),
                it -> get_apellidos(),
                it -> get_dni(),
                it -> get_correo(),
                it -> get_contrasena(),
                it -> get_rol()
            );
        }
    }
    return Usuario(0, "empty", "empty", "empty", "empty", "empty", "empty");
}

void RepositorioUsuarios::push_back(Usuario usuario) {
    Usuario encontrado = buscar_usuario(usuario.get_dni());
    if (encontrado.get_usuario() == 0){
        persistir_usuario(usuario);
        _usuarios.push_back(usuario);
    }
}


bool RepositorioUsuarios::existe_usuario_contrasena(const std::string &dni,const std::string &contrasena){
    for (auto it = _usuarios.begin(); it != _usuarios.end(); it++)
    {
        if (it->get_dni() == dni) {
            if (it->get_contrasena() == contrasena) {return true;}
            else {return false;}
        }
    }
    return false;
}
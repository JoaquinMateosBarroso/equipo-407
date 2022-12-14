#include <list>
#include <iostream>
#include "cursodeextension.h"
#include <usuario.h>
#include <repositoriousuarios.h>

CursodeExtension::CursodeExtension(int codigo, std::string nombre, std::string descripcion, int max):
    _participantes("participantes_"  + std::to_string(codigo)),
    _lista_espera("lista_espera_"  + std::to_string(codigo)),
    _lista_recursos("recursos_"  + std::to_string(codigo)) 
{
    _codigo = codigo;
    _nombre = nombre;
    _descripcion = descripcion;
    _max = max;
}

bool CursodeExtension::añadir_usuario(Usuario const u){
    if (_participantes.get_n_usuarios() == _max){
        _lista_espera.push_back(u);
        return false;
    }
    else{
        _participantes.push_back(u);
        return true;
    }
}
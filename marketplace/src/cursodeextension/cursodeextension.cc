#include <string.h>
#include <list>
#include <iostream>
#include "cursodeextension.h"
#include <usuario.h>
#include <repositoriousuarios.h>

CursodeExtension::CursodeExtension(int codigo, std::string nombre, std::string descripcion):
    _participantes("participantes_"  + std::to_string(codigo)) 
{
    _codigo = codigo;
    _nombre = nombre;
    _descripcion = descripcion;
}
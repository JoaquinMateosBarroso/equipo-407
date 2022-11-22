#include <string.h>
#include <list>
#include <iostream>
#include "cursodeextension.h"
#include <usuario.h>

CursodeExtension::CursodeExtension(int codigo, std::string nombre, std::string descripcion) {
    _codigo = codigo;
    _nombre = nombre;
    _descripcion = descripcion;
    _participantes = std::list<Usuario>();
}
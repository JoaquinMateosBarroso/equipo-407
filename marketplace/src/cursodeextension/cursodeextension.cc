#include <string.h>
#include <list>
#include <iostream>
#include "cursodeextension.h"
#include <usuario.h>

CursodeExtension::CursodeExtension(int codigo, std::string nombre) {
    _codigo = codigo;
    _nombre = nombre;
    _participantes = std::list<Usuario>();
}
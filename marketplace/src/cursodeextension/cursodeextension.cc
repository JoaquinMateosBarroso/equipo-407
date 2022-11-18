#include <string.h>
#include <list>
#include <iostream>
#include "cursodeextension.h"
#include "usuario.h"

void CursodeExtension::añadir_usuario(Usuario const u){
    participantes.push_back(u);
}
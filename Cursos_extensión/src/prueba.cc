#ifndef MAIN_CC
#define MAIN_CC

#include <list>
#include <iostream>
#include <usuario.h>
#include <cursodeextension.h>
#include <database.h>


int main(int argc, char const *argv[])
{
    std::cout<<"Empieza la prueba"<<std::endl;
    Usuario coordinador = Usuario(1, "fulanito", "fulanito", "fulanito", "fulanito", "abc", "Coordinador de curso de extension");
    Usuario participante1 = Usuario(2, "menganito", "menganito", "menganito", "menganito", "abc", "Participante");
    Usuario participante2 = Usuario(3, "otro", "otro", "otro", "otro", "abc", "Participante");

    std::cout<<"Se crea la base de datos"<<std::endl;
    
    Database* db = new Database();

    std::cout<<"Se registran los usuarios"<<std::endl;

    // Estos usuarios deberian estar en usuarios.txt
    db -> registrar_usuario(coordinador);
    db -> registrar_usuario(participante1);
    db -> registrar_usuario(participante2);

    std::cout<<"El usuario coordinador da de alta 4 cursos"<<std::endl;


    // Estos cursos deberian estar en cursos.txt
    db -> dar_alta_curso(coordinador, "Curso de Python", "descriptcion");
    db -> dar_alta_curso(coordinador, "Curso de Docker", "descriptcion");
    db -> dar_alta_curso(coordinador, "Curso de TypeScript", "descriptcion");
    db -> dar_alta_curso(coordinador, "Curso de Cocina", "descriptcion");

    std::cout<<"El participante 1 se inscribe en el curso 2"<<std::endl;

    // Este usuario deberia estar en participantes_2.txt
    db -> buscar_curso(2).añadir_usuario(participante1);

    std::cout<<"El participante 2 se inscribe en el curso 2"<<std::endl;


    // Este usuario deberia estar en participantes_4.txt
    db -> buscar_curso(2).añadir_usuario(participante2);

    std::cout<<"Finaliza la prueba"<<std::endl;

    return 0;
}

#endif
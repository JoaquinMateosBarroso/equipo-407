#ifndef MAIN_CC
#define MAIN_CC

#include <list>
#include <iostream>
#include <usuario.h>
#include <cursodeextension.h>
#include <database.h>

int main(int argc, char const *argv[])
{
    std::list<Usuario> usuarios_registrados = std::list<Usuario>();
    std::list<CursodeExtension> lista_cursos = std::list<CursodeExtension>();

    lista_cursos.push_back(CursodeExtension(1, "Curso de Python"));
    lista_cursos.push_back(CursodeExtension(2, "Curso de Docker"));
    lista_cursos.push_back(CursodeExtension(3, "Curso de TypeScript"));
    lista_cursos.push_back(CursodeExtension(4, "Curso de Cocina"));

    
    Database db = Database(lista_cursos, usuarios_registrados);

    std::string nombre, apellidos, dni, correo;

    std::cout << "Introduzca su nombre: " << std::endl;
    std::cin >> nombre;
    std::cout << "Introduzca sus apellidos: " << std::endl;
    std::cin >> apellidos;
    std::cout << "Introduzca su dni: " << std::endl;
    std::cin >> dni;
    std::cout << "Introduzca su correo: " << std::endl;
    std::cin >> correo;

    Usuario u = Usuario(1, nombre, apellidos, dni, correo, "Participante");

    db.registrar_usuario(u);
    while(true){

        std::cout << "Seleccione a que curso de extension se desea apuntar: "<< std::endl;

        unsigned opcion;
        std::cout << "1. Curso de Python" << std::endl;
        std::cout << "2. Curso de Docker" << std::endl;
        std::cout << "3. Curso de TypeScript" << std::endl;
        std::cout << "4. Curso de Cocina" << std::endl;
        std::cout << "5. SALIR" << std::endl;
        std::cin >> opcion;

        if (opcion==5)
        {
            exit(0);
        }
        
        db.buscar_curso(opcion).añadir_usuario(u);
    }


    return 0;
}

#endif
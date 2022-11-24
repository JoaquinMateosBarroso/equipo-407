#ifndef MAIN_CC
#define MAIN_CC

#include <list>
#include <iostream>
#include <usuario.h>
#include <cursodeextension.h>
#include <database.h>

#define MAX_LONGITUD 100

using namespace std;


//crear Database de manera global
Database database = Database();



bool dar_alta_curso(Usuario &usuario)
{

    //pedir datos

    //crear curso de extensión con los datos


    //return database.dar_alta_curso(usuario, curso);

}

void inicio_sesion()
{
    cout << "Entrar como:" << endl;
    cout << "1.- Usuario" << endl;
    cout << "2.- Coordinador de cursos de extensión" << endl;
}


int main(int argc, char const *argv[])
{   


    std::string nombre, apellidos, dni, correo;
    char aux[MAX_LONGITUD];

    std::cout << "Introduzca su nombre: " << std::endl;
    std::cin.getline(aux, MAX_LONGITUD, '\n');
    nombre = aux;
    std::cout << "Introduzca sus apellidos: " << std::endl;
    std::cin.getline(aux, MAX_LONGITUD, '\n');
    apellidos = aux;
    std::cout << "Introduzca su dni: " << std::endl;
    std::cin >> dni;
    std::cout << "Introduzca su correo: " << std::endl;
    std::cin >> correo;

    Usuario u = Usuario(1, nombre, apellidos, dni, correo, "Participante");

    database.registrar_usuario(u);
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
        
        database.buscar_curso(opcion).añadir_usuario(u);
    }


    return 0;
}

#endif
#ifndef MAIN_CC
#define MAIN_CC

#include <list>
#include <iostream>
#include <usuario.h>
#include <cursodeextension.h>
#include <database.h>
#include <string>

#define MAX_LONGITUD 100

#define ENTER 13
#define BACKSPACE 8

using namespace std;


#ifdef _WIN32
  #include<windows.h>
#endif  

void cls()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}



//crear Database de manera global
Database database = Database();
Usuario usuario;


char inicio_sesion()
{
    cls();
    cout << "Entrar como:" << endl;
    cout << "0.- Visitante" << endl;
    cout << "1.- Usuario" << endl;
    cout << "2.- Coordinador de cursos de extensión" << endl;
    char n;
    cin.getline(&n, 5, '\n');
    if (n != '0'){
        string dni, contrasena;
        cout << "Introduzca su dni:";
        getline(cin, dni);
        cout << "Introduzca su contrasena:";
        getline(cin, contrasena);

        if (!database.login_usuario(dni, contrasena, usuario)){
            cout << "Usuario o contrasena incorrecto, se procede a salir del programa" << endl;
            exit(EXIT_SUCCESS);}
    }
    return n;
}


void registrar_usuario()
{
    cls();
    cout << "Registrar a un:" << endl;
    cout << "1.- Usuario" << endl;
    cout << "2.- Coordinador de cursos de extensión" << endl;
    char n;
    cin.getline(&n, 5, '\n');
    string rol;
    switch (n){
        case '1': rol = "Usuario"; break;
        case '2': rol = "Coordinador Cursos"; break;

        default: cout << "Erróneo"; exit(EXIT_FAILURE);
    }

    string dni, nombre, apellidos, contrasena, correo;
    cout << "Introduzca su dni:";
    getline(cin, dni);
    cout << "Introduzca su nombre:";
    getline(cin, nombre);
    cout << "Introduzca sus apellidos:";
    getline(cin, apellidos);
    cout << "Introduzca su correo:";
    getline(cin, correo);
    cout << "Introduzca su contrasena:";
    getline(cin, contrasena);

    database.registrar_usuario(Usuario(database.get_n_usuarios(),
                nombre, apellidos, dni, correo, contrasena, rol));

        
}


char pagina_coordinador_cursos()
{    
    cout << "¿Qué quiere hacer?" << endl;
    cout << "1.- Dar de alta un nuevo curso" << endl;
    cout << "2.- Ver información de cursos" << endl;
    char n;
    cin.getline(&n, 100, '\n');
    cls();
    return n;
}


char pagina_usuario()
{    
    cout << "¿Qué quiere hacer?" << endl;
    cout << "1.- Ver información de cursos" << endl;
    char n;
    cin.getline(&n, 100, '\n');
    cls();
    return n;
}


void dar_alta_curso()
{

    //pedir datos
    string nombre_curso;
    string descripcion;

    cout << "Introduzca el nombre del curso de extension: ";
    getline(cin, nombre_curso);
    cout << "Introduzca una descripción del curso de extension: ";
    getline(cin, descripcion);
    int codigo;
    if ((codigo = database.dar_alta_curso(usuario, nombre_curso, descripcion)) == -1){
        cout << "Ya existe otro curso con el mismo nombre, no se ha podido insertar el curso";
        exit(EXIT_SUCCESS);
    }
    else
    {
        cout << "Se ha creado el curso de extensión y se le ha asignado el código: " << codigo << endl;
        exit(EXIT_SUCCESS);
    }
}


int lista_cursos(){
    cls();
    cout << "¿De qué curso quiere ver información?: "<<endl;
    int j=1;
    for (auto i = database.begin(); i!=database.end(); i++)
    {
        cout << j << ".- " << i->get_nombre() << endl;
        j++;
    }
    char n;
    cin.getline(&n, 100, '\n');
    return atoi(&n);
}


void lista_usuarios(list<CursodeExtension>::iterator i)
{
    cout << endl << "Usuarios:" << endl;
    int k = 1;
    auto lista = i->get_participantes().lista_entera();
    for (auto j = lista.begin(); j!= lista.end(); j++){
        cout << k << ".- " << j->get_nombre() << " " << j->get_apellidos() << 
        ", de dni: " << j->get_dni() << endl;
    }
    cout << endl;
}


bool anyadir_usuario(int codigo){
    for (auto i = database.begin(); i != database.end(); i++)
    {
        if (i->get_codigo() == codigo){i->añadir_usuario(usuario); return true;}
    }
    return false;
}


void informacion_curso(int n){
    cls();
    int j=1;
    CursodeExtension cursoextension(0, "empty", "empty");
    for (auto i = database.begin(); i!=database.end(); i++)
    {
        if (j==n){
            cursoextension = *i;
            cout << "Código: " << i->get_codigo() << endl;
            cout << "Nombre: " << i->get_nombre() << endl;
            cout << "Descripcion: " << i->get_descripcion() << endl;
            if (usuario.get_rol() == "Coordinador Cursos"){
                lista_usuarios(i);
            }
            if (usuario.get_rol() == "Usuario"){
                cout << "\nIntroduzca \"R\" para registrarse en este curso\n";
            }
        }
        j++;
    }
    if (usuario.get_rol() == "Usuario"){
        string curso;
        getline(cin, curso);
        if (curso[0] == 'R' or curso[0] == 'r'){
            cursoextension.añadir_usuario(usuario);
            cout << "Usuario anyadido" << endl; exit(0);
        }
    else{cout << "No se reconoce el texto introducido \n"; exit(0);}
    }

    
    else{
        cout << endl << "Pulsa enter para salir de la página";
        cin.ignore(); 
        exit(0);
    }
}




int main(int argc, char const *argv[])
{
    cls();


    database.registrar_usuario(Usuario(2, "Joaquin", "mateos", "459","parapa", "123", "Usuario"))
;

    cout << "1.-Entrar a la página" << endl;
    cout << "2.-Registrar un nuevo usuario" << endl;
    char n;
    cin.getline(&n, 100, '\n');
    switch (n){
        case '1':
            switch (inicio_sesion())
            {
                case '0':
                    informacion_curso(lista_cursos());exit(1);
                //Usuario
                case '1':
                    switch (pagina_usuario()){
                        case '1': 
                            informacion_curso(lista_cursos()); break;
                        case '2': break;
                    }
                    break;

                //Coordinador Cursos    
                case '2':
                    switch (pagina_coordinador_cursos()){
                        case '1':
                            dar_alta_curso(); exit(1);
                        case '2':
                            informacion_curso(lista_cursos()); exit(1);
                    }
                default: cout << "Error en introducción de datos" << endl; exit(1);
            }
        case '2':
            registrar_usuario(); break;
        default: cout << "Error de elección" << endl; exit(0);
    }


    // std::string nombre, apellidos, dni, correo;
    // char aux[MAX_LONGITUD];

    // std::cout << "Introduzca su nombre: " << std::endl;
    // std::cin.getline(aux, MAX_LONGITUD, '\n');
    // nombre = aux;
    // std::cout << "Introduzca sus apellidos: " << std::endl;
    // std::cin.getline(aux, MAX_LONGITUD, '\n');
    // apellidos = aux;
    // std::cout << "Introduzca su dni: " << std::endl;
    // std::cin >> dni;
    // std::cout << "Introduzca su correo: " << std::endl;
    // std::cin >> correo;

    // Usuario u = Usuario(1, nombre, apellidos, dni, correo, "Participante");

    // database.registrar_usuario(u);
    // while(true){

    //     std::cout << "Seleccione a que curso de extension se desea apuntar: "<< std::endl;

    //     unsigned opcion;
    //     std::cout << "1. Curso de Python" << std::endl;
    //     std::cout << "2. Curso de Docker" << std::endl;
    //     std::cout << "3. Curso de TypeScript" << std::endl;
    //     std::cout << "4. Curso de Cocina" << std::endl;
    //     std::cout << "5. SALIR" << std::endl;
    //     std::cin >> opcion;

    //     if (opcion==5)
    //     {
    //         exit(0);
    //     }
        
    //     database.buscar_curso(opcion).añadir_usuario(u);
    // }


    return 0;
}

#endif
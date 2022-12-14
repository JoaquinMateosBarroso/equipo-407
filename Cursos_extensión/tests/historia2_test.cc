// historia2_test.cc
//
//

#include <database.h>

#include <filesystem>
#include <cstdlib>

#include "gtest/gtest.h"


using namespace std;

#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <string.h>


using namespace std;

void eliminarTXT() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("./")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            string nombreArchivo = ent->d_name;
            if (nombreArchivo.length() >= 4 && nombreArchivo.substr(nombreArchivo.length() - 4) == ".txt") {
            remove(nombreArchivo.c_str());
            }
        }
        closedir(dir);
        } else {
        cout << "No se puede acceder a la carpeta actual" << endl;
    }
}

TEST(Database, Registrar_usuario_en_curso) {
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 2;

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    Usuario participante_1(1, "usuario1", "Garcia", "234", "hola1@gmail.com", "123", "Usuario");
    Usuario participante_2(2, "usuario2", "Garcia", "345", "hola2@gmail.com", "123", "Usuario");
    Usuario participante_3(3, "usuario3", "Garcia", "456", "hola3@gmail.com", "123", "Usuario");



    EXPECT_EQ(db.begin() -> añadir_usuario(participante_1), true);

    EXPECT_EQ(db.begin() -> añadir_usuario(participante_2), true);
    
    
    eliminarTXT();
}

TEST(Database, Comprobar_registro_usuario) {
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 2;

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    Usuario participante_1(1, "usuario1", "Garcia", "234", "hola1@gmail.com", "123", "Usuario");
    Usuario participante_2(2, "usuario2", "Garcia", "345", "hola2@gmail.com", "123", "Usuario");
    Usuario participante_3(3, "usuario3", "Garcia", "456", "hola3@gmail.com", "123", "Usuario");

    EXPECT_EQ(db.buscar_curso(codigo).añadir_usuario(participante_1), true);

    db.registrar_usuario(participante_1);



    EXPECT_EQ(db.begin() -> añadir_usuario(participante_1), true);
    EXPECT_EQ(db.begin() -> get_participantes().buscar_usuario("234").get_nombre(), participante_1.get_nombre());


    EXPECT_EQ(db.begin() -> añadir_usuario(participante_2), true);
    EXPECT_EQ(db.begin() -> get_participantes().buscar_usuario("345").get_nombre(), participante_2.get_nombre());
    
    
    eliminarTXT();
}

TEST(Database, Comprobar_aforo_maximo) {
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 2;

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    Usuario participante_1(1, "usuario1", "Garcia", "234", "hola1@gmail.com", "123", "Usuario");
    Usuario participante_2(2, "usuario2", "Garcia", "345", "hola2@gmail.com", "123", "Usuario");
    Usuario participante_3(3, "usuario3", "Garcia", "456", "hola3@gmail.com", "123", "Usuario");

    EXPECT_EQ(db.buscar_curso(codigo).añadir_usuario(participante_1), true);



    db.begin() -> añadir_usuario(participante_1);
    db.begin() -> añadir_usuario(participante_2);

    EXPECT_EQ(db.begin() -> añadir_usuario(participante_3), false);
    EXPECT_EQ(db.begin() -> get_participantes().buscar_usuario("456").get_nombre(), "empty");
    
    
    eliminarTXT();
}




int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

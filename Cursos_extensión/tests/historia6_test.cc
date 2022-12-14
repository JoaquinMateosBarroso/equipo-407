// historia4_test.cc
//
//

#include <database.h>

#include <filesystem>
#include <cstdlib>

#include "gtest/gtest.h"

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
      exit(1);
    }
}


TEST(Database, estadisticas_con_curso_vacio) {
  
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 2;

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    auto estadisticas = db.get_estadisticas(*(db.begin()));

    EXPECT_NEAR(stof(estadisticas["Porcentaje de aforo cubierto"]), 0.0, 0.001);

    EXPECT_NEAR(stof(estadisticas["Porcentaje de usuarios de la página inscritos en el curso"]), 0.0, 0.001);



    eliminarTXT();
}


TEST(Database, estadisticas_con_aforo_0) {
  
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 0;

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    auto estadisticas = db.get_estadisticas(*(db.begin()));

    EXPECT_NEAR(stof(estadisticas["Porcentaje de aforo cubierto"]), 1.0, 0.001);

    EXPECT_NEAR(stof(estadisticas["Porcentaje de usuarios de la página inscritos en el curso"]), 0.0, 0.001);



    eliminarTXT();
}


TEST(Database, estadisticas_caso_habitual) {
  
    eliminarTXT();
    Database db;

    Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
    db.registrar_usuario(coordinador);

    string nombre_curso = "Curso introductorio de Python";
    string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
    int max = 5;

    Usuario participante_1(1, "usuario1", "Garcia", "234", "hola1@gmail.com", "123", "Usuario");
    Usuario participante_2(2, "usuario2", "Garcia", "345", "hola2@gmail.com", "123", "Usuario");
    Usuario participante_3(3, "usuario3", "Garcia", "456", "hola3@gmail.com", "123", "Usuario");

    int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);

    db.registrar_usuario(participante_1);
    EXPECT_EQ(db.begin() -> añadir_usuario(participante_1), true);


    db.registrar_usuario(participante_2);
    EXPECT_EQ(db.begin() -> añadir_usuario(participante_2), true);

    db.registrar_usuario(participante_3);
    EXPECT_EQ(db.begin() -> añadir_usuario(participante_3), true);


    // db.registrar_usuario(Usuario(6, "vinuela", "afldsk", "4356534", "hola@gmail.com", "password", "Usuario"));



    auto estadisticas = db.get_estadisticas(*(db.begin()));



    EXPECT_NEAR(stof(estadisticas["Porcentaje de aforo cubierto"]), 60, 0.001);


    EXPECT_NEAR(stof(estadisticas["Porcentaje de usuarios de la página inscritos en el curso"]), 75, 0.001);


    eliminarTXT();
}






int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
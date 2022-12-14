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


TEST(Database, Coordinadorrecursos_anyade_recurso) {
  eliminarTXT();
  Database db;

  Usuario coordinador(0, "José", "Pepito", "123459", "hola@gamil.com", "123", "Coord");
  string nombre_curso = "Curso avanzado de Docker";
  string descripcion = "En este curso veremos las bases de docker, base de gran parte del backend y muy usado en para asegurar fácil portabilidad de sistemas por empresas de todo el mundo.";
  int max = 2;

  int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);
    


  EXPECT_EQ(true, db.begin() -> añadir_recurso("Televisión"));
  EXPECT_EQ(true, db.begin() -> añadir_recurso("Radio"));
  EXPECT_EQ(false, db.begin() -> añadir_recurso("Radio"));


  eliminarTXT();
}

TEST(Database, observacion_recursos) {
  
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



  EXPECT_EQ(true, db.begin() -> añadir_recurso("Televisión"));
  EXPECT_EQ(true, db.begin() -> añadir_recurso("Radio"));
  EXPECT_EQ(false, db.begin() -> añadir_recurso("Radio"));

  EXPECT_EQ(2, db.begin()->get_recursos().get_n_recursos());
  
  EXPECT_EQ("Televisión", *(db.begin()->get_recursos().begin()));
  EXPECT_EQ("Televisión", *(db.begin()->get_recursos().begin()++));

    eliminarTXT();
}




int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
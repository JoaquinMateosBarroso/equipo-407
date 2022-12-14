// historia1_test.cc
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

TEST(Database, Dar_alta_y_observar_curso) {
  eliminarTXT();
  Database db;

  Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
  string nombre_curso = "Curso introductorio de Python";
  string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
  int max = 2;

  int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);
    


  EXPECT_EQ(descripcion, db.buscar_curso(codigo).get_descripcion());
  EXPECT_EQ(max, db.buscar_curso(codigo).get_max());
  EXPECT_EQ(0, db.buscar_curso(codigo).get_lista_espera().get_n_usuarios());
  EXPECT_EQ(0, db.buscar_curso(codigo).get_participantes().get_n_usuarios());



  eliminarTXT();
}

TEST(Database, comprobar_codigo) {
  
  eliminarTXT();
  Database db;

  Usuario coordinador(0, "Pepe", "Vinuesa", "123459", "hola@gamil.com", "123", "Coordinador");
  string nombre_curso = "Curso introductorio de Python";
  string descripcion = "En este curso veremos las bases del leguaje Python, base de gran parte del backend y muy usado en análisis de datos por empresas de todo el mundo.";
  int max = 2;

  int codigo = db.dar_alta_curso(coordinador, nombre_curso, descripcion, max);
  


  EXPECT_EQ(nombre_curso, db.buscar_curso(codigo).get_nombre());
  EXPECT_EQ(codigo, db.buscar_curso(nombre_curso).get_codigo());

  eliminarTXT();
}




int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
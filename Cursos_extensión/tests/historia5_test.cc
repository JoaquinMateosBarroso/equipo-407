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


TEST(Database, datos_administrador) {
  
    eliminarTXT();
    Database db;

    EXPECT_EQ(db.datos_administrador, "Correo: correoadmin@gmail.com\nNumero de telefono: 123456");

    for (int i = 0; i < 20; i++)
    {
        db.registrar_usuario(Usuario(8*i, "hola", "dajf", "456674" + i, "hola@kfsdjd", "password", "Usuario"));
    }

    EXPECT_EQ(db.datos_administrador, "Correo: correoadmin@gmail.com\nNumero de telefono: 123456");

    Usuario aux;
    for (int i = 0; i < 20; i++)
    {
        db.login_usuario("456674" + i, "password", aux);
    }

    EXPECT_EQ(db.datos_administrador, "Correo: correoadmin@gmail.com\nNumero de telefono: 123456");

}






int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
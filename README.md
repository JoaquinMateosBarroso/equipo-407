# Edufy - Sistema de gestión de cursos de extensión

![Logo de la empresa](/Docs/logo.jpeg)

El proyecto ha sido realizado en el lenguaje C++, haciendo uso de la herramienta de construcción <i>CMAKE</i>. Las pruebas del mismo han sido realizadas con la libreria <i>googletest</i>.

### Compilación
Para compilar el proyecto creamos un directorio `/build` en la raiz
```cmd
mkdir build
cd build
```
Una vez nos encontramos en dicho directorio, ejecutamos los siguientes comandos
```cmd
cmake ..
make
```

Esto compilará todo el proyecto, cuyo punto de entrada se encuentra en `/build/src/main`.

### Tests
Para ejecutar toda la suite de test unitarios, en `/build` ejecutamos
```cmd
ctest
```
Si queremos ejecutar algún test en especifico y ver su salida en detalle ejecutamos los binarios que se encuentran en `/build/src/tests`

### Material audiovisual
Con fin de facilitar la experiencia y el entendimiento del software para los usuarios se ha añadido material audiovisual en la carpeta `/Docs`.

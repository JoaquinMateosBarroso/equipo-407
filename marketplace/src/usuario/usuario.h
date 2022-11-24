//Usuario.h
//Definición de la clase Usuario
#ifndef PERSON_H
#define PERSON_H
#include <string>


class Usuario{
    private:
        unsigned usuario_;
        std::string nombre_;
        std::string apellidos_;
        std::string dni_;
        std::string correo_;
        std::string rol_;
    public:
        Usuario(unsigned usuario, std::string nombre, std::string apellidos, 
        std::string dni, std::string correo, std::string rol) : 
        usuario_(usuario), nombre_(nombre), apellidos_(apellidos),
        dni_(dni), correo_(correo), rol_(rol) {}
        inline unsigned get_usuario(){return usuario_;}
        inline std::string get_nombre(){return nombre_;}
        inline std::string get_apellidos(){return apellidos_;}
        inline std::string get_dni(){return dni_;}
        inline std::string get_correo(){return correo_;}
        inline std::string get_rol(){return rol_;}

};

#endif
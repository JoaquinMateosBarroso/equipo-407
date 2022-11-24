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
        std::string contrasena_;
        std::string rol_;
    public:
        Usuario() : usuario_(0) {}
        Usuario(unsigned usuario, std::string nombre, std::string apellidos, 
        std::string dni, std::string correo, std::string contrasena, std::string rol) : 
        usuario_(usuario), nombre_(nombre), apellidos_(apellidos),
        dni_(dni), correo_(correo), contrasena_(contrasena), rol_(rol) {}

        inline unsigned get_usuario(){return usuario_;}
        inline std::string get_nombre(){return nombre_;}
        inline std::string get_apellidos(){return apellidos_;}
        inline std::string get_dni(){return dni_;}
        inline std::string get_correo(){return correo_;}
        inline std::string get_contrasena(){return contrasena_;}
        inline std::string get_rol(){return rol_;}

        inline void set_usuario(int usuario){usuario_ = usuario;}
        inline void set_nombre(std::string &a){nombre_ = a;}
        inline void set_apellidos(std::string &a){apellidos_ = a;}
        inline void set_dni(std::string &a){dni_ = a;}
        inline void set_correo(std::string &a){correo_ = a;}
        inline void set_contrasena(std::string &a){contrasena_ = a;}
        inline void set_rol(std::string &a){rol_ = a;}

};

#endif
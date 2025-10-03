#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Publicacion; // forward
class Comentario;  // forward

class Usuario {
    private:
        std::string nombreUsuario;
        std::vector<Publicacion*> publicaciones; // el usuario "posee" las publicaciones

    public:
        Usuario(const std::string& nombre);
        ~Usuario(); // liberamos memoria de publicaciones creadas

        std::string getNombreUsuario() const;

        // crea una nueva publicación (se reserva dinámicamente y se guarda el puntero)
        void crearPublicacion(const std::string& urlImagen, const std::string& descripcion);

        // acciones sobre publicaciones (se pasa puntero)
        void darLike(Publicacion* pub);
        void comentar(Publicacion* pub, const std::string& texto);

        // muestra todas las publicaciones del usuario
        void mostrarPublicaciones() const;
};

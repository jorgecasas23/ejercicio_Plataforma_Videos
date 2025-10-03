#include "usuario.h"
#include "Publicacion.h"
#include "Comentario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre)
    : nombreUsuario(nombre)
{}

Usuario::~Usuario() {
    // liberar las publicaciones creadas por este usuario
    for (Publicacion* p : publicaciones) {
        delete p;
    }
    publicaciones.clear();
}

std::string Usuario::getNombreUsuario() const {
    return nombreUsuario;
}

void Usuario::crearPublicacion(const std::string& urlImagen, const std::string& descripcion) {
    Publicacion* nueva = new Publicacion(urlImagen, descripcion);
    publicaciones.push_back(nueva);
}

void Usuario::darLike(Publicacion* pub) {
    if (!pub) return;
    pub->incrementarLikes();
}

void Usuario::comentar(Publicacion* pub, const std::string& texto) {
    if (!pub) return;
    // crear un comentario referenciando a este usuario como autor
    Comentario c(texto, this);
    pub->agregarComentario(c);
}

void Usuario::mostrarPublicaciones() const {
    if (publicaciones.empty()) {
        std::cout << nombreUsuario << " no tiene publicaciones." << std::endl;
        return;
    }

    std::cout << "Publicaciones de " << nombreUsuario << ":" << std::endl;
    for (const Publicacion* p : publicaciones) {
        if (p) p->mostrarInfo();
    }
}

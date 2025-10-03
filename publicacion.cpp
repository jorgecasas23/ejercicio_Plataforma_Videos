#include "Publicacion.h"
#include <iostream>

Publicacion::Publicacion(const std::string& url, const std::string& desc)
    : urlImagen(url), descripcion(desc), cantidadLikes(0)
{}

std::string Publicacion::getUrlImagen() const {
    return urlImagen;
}

std::string Publicacion::getDescripcion() const {
    return descripcion;
}

int Publicacion::getCantidadLikes() const {
    return cantidadLikes;
}

void Publicacion::incrementarLikes() {
    ++cantidadLikes;
}

void Publicacion::agregarComentario(const Comentario& comentario) {
    comentarios.push_back(comentario);
}

const std::vector<Comentario>& Publicacion::getComentarios() const {
    return comentarios;
}

void Publicacion::mostrarInfo() const {
    std::cout << "Publicacion: " << descripcion << std::endl;
    std::cout << "URL: " << urlImagen << std::endl;
    std::cout << "Likes: " << cantidadLikes << std::endl;

    if (comentarios.empty()) {
        std::cout << "Comentarios: (ninguno)" << std::endl;
    } else {
        std::cout << "Comentarios:" << std::endl;
        for (const auto& c : comentarios) {
            c.mostrarComentario();
        }
    }
    std::cout << "------------------------" << std::endl;
}

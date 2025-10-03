#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <vector>
#include "Comentario.h"

class Publicacion {
private:
    std::string urlImagen;
    std::string descripcion;
    int cantidadLikes;
    std::vector<Comentario> comentarios;

public:
    Publicacion(const std::string& url, const std::string& desc);

    std::string getUrlImagen() const;
    std::string getDescripcion() const;
    int getCantidadLikes() const;

    void incrementarLikes();

    // agrega un comentario (se copia)
    void agregarComentario(const Comentario& comentario);

    // devuelve referencia constante al vector de comentarios
    const std::vector<Comentario>& getComentarios() const;

    void mostrarInfo() const;
};

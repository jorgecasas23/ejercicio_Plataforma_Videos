#include "Comentario.h"
#include <iostream>
#include "Usuario.h"

Comentario::Comentario(const std::string& txt, Usuario* user)
    : texto(txt), autor(user)
{}

std::string Comentario::getTexto() const {
    return texto;
}

Usuario* Comentario::getAutor() const {
    return autor;
}

void Comentario::mostrarComentario() const {
    std::cout << "- " << texto;
    if (autor) {
        std::cout << " (por: " << autor->getNombreUsuario() << ")";
    }
    std::cout << std::endl;
}
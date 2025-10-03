#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>

class Usuario;

class Comentario {
    private:
        std::string texto;
        Usuario* autor; // no poseemos al autor, solo referenciamos

    public:
        Comentario(const std::string& txt, Usuario* user);

        std::string getTexto() const;
        Usuario* getAutor() const;

        void mostrarComentario() const;
};

#endif // COMENTARIO_H
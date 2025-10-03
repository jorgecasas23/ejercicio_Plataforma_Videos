#include <iostream>
#include "Usuario.h"
#include "Publicacion.h"
#include "Comentario.h"
#include <iostream>

int main() {
    Usuario u1("simon");
    Usuario u2("mateo");

    u1.crearPublicacion("http://img1.jpg", "Mi primera foto");
    // u1.crearPublicacion(...) crea y almacena la publicación internamente

    // Supongamos que queremos referenciar la primera publicación de u1:
    // (esto es solo para test; en código real sería mejor obtener punteros/ids)
    // Aquí sabrías la publicación porque la guardaste o la buscaste.
    // Para este ejemplo, accederemos por reflexión mínima (no incluida).
    // En proyecto real añade métodos para obtener punteros a publicaciones.

    // Alternativamente, para pruebas rápidas, crear publicaciones externas:
    Publicacion* p = new Publicacion("http://otra.jpg", "Foto externa");
    u2.darLike(p);     // u2 da like (aunque p no pertenece a u2)
    u2.comentar(p, "Muy buena!");

    p->mostrarInfo();

    delete p; // recuerda liberar si creas con new fuera del usuario

    u1.mostrarPublicaciones();
    u2.mostrarPublicaciones();

    return 0;
}

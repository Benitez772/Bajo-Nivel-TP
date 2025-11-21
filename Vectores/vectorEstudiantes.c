#include "vectorEstudiantes.h"
#include <stdlib.h>
#include <string.h>

void estudiantes_init(VectorEstudiantes* v) {
    v->data = NULL;
    v->tamanio = 0;
    v->capacidad = 0;
}

static int estudiantes_resize(VectorEstudiantes* v, int nueva_capacidad) {
    Estudiante* nuevo = realloc(v->data, nueva_capacidad * sizeof(Estudiante));
    if (!nuevo) return 0;
    v->data = nuevo;
    v->capacidad = nueva_capacidad;
    return 1;
}

int estudiantes_agregar(VectorEstudiantes* v, Estudiante e) {
    if (v->tamanio == v->capacidad) {
        int cap_nueva = (v->capacidad == 0) ? 2 : v->capacidad * 2;
        if (!estudiantes_resize(v, cap_nueva)) return 0;
    }
    v->data[v->tamanio++] = e;
    return 1;
}

Estudiante* estudiantes_buscar_por_legajo(VectorEstudiantes* v, int legajo) {
    for (int i = 0; i < v->tamanio; ++i) {
        if (v->data[i].legajo == legajo) return &v->data[i];
    }
    return NULL;
}

int estudiantes_modificar(VectorEstudiantes* v, int legajo, Estudiante* nuevo) {
    Estudiante* e = estudiantes_buscar_por_legajo(v, legajo);
    if (!e) return 0;
    return estudiante_modificar(e, nuevo);
}

int estudiantes_eliminar(VectorEstudiantes* v, int legajo) {
    int i, j;
    for (i = 0; i < v->tamanio; i++) {
        if (v->data[i].legajo == legajo) {
            // desplazar todos los elementos posteriores hacia atrás
            for (j = i; j < v->tamanio - 1; j++) {
                v->data[j] = v->data[j + 1];
            }
            v->tamanio--;
            return 1; // eliminado con éxito
        }
    }
    return 0; // no encontrado
}

void estudiantes_clear(VectorEstudiantes* v) {
    free(v->data);
    v->data = NULL;
    v->tamanio = 0;
    v->capacidad = 0;
}

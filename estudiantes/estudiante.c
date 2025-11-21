#include "estudiante.h"
#include <string.h>

//El legajo es valido solo si tiene 6 digitos
static int legajo_valido(int legajo) {
    return (legajo >= 100000 && legajo <= 999999);
}

int estudiante_init(Estudiante* e, int legajo, const char* nombre, const char* apellido, int edad) {
    if (!legajo_valido(legajo)) return 0;
    if (edad <= 0 || edad > 100) return 0;
    e->legajo = legajo;
    strncpy(e->nombre, nombre, sizeof(e->nombre));
    strncpy(e->apellido, apellido, sizeof(e->nombre));
    e->edad = edad;
    return 1;
}

int estudiante_modificar(Estudiante* e, const Estudiante* nuevo) {
    if (!estudiante_es_valido(nuevo)) return 0;
    e->legajo = nuevo->legajo;
    estudiante_set_nombre(e, nuevo->nombre);
    estudiante_set_apellido(e, nuevo->apellido);
    e->edad = nuevo->edad;
    return 1;
}

int estudiante_es_valido(const Estudiante* e) {
    if (!e) return 0;
    if (!legajo_valido(e->legajo)) return 0;
    if (e->edad <= 0 || e->edad > 100) return 0;
    if (e->nombre[0] == '\0') return 0; // "(e->nombre[0] == '\0')" ve si el primer caracter de nombre es nulo
    if (e->apellido[0] == '\0') return 0;
    return 1;
}

int estudiante_set_legajo(Estudiante* e, int legajo) {
    if (!legajo_valido(legajo)) return 0;
    e->legajo = legajo;
    return 1;
}

void estudiante_set_nombre(Estudiante* e, const char* nombre) {
    strncpy(e->nombre, nombre, sizeof(e->nombre));
}

void estudiante_set_apellido(Estudiante* e, const char* apellido) {
    strncpy(e->apellido, apellido, sizeof(e->apellido));
}


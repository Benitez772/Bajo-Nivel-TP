#include "materia.h"
#include "string.h"

int materia_init(Materia* m, unsigned int id, const char* nombre){
    ListaCorrelativas lista;
    m->id = id;
    strncpy(m->nombre, nombre, 60);
    lista_inicializar(&lista);
    m->correlativas = lista;
}

void materia_agregar_correlativa(Materia* m, int idCorrelativa){
    lista_agregar(&m->correlativas, idCorrelativa);
}

int materia_eliminar_correlativa(Materia* m, int idCorrelativa){
    return lista_eliminar(&m->correlativas, idCorrelativa);
}



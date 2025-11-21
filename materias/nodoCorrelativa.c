#include "nodoCorrelativa.h"
#include <stdlib.h>

NodoCorrelativa* nodo_init(int idMateria){
    NodoCorrelativa* nodo = malloc(sizeof(NodoCorrelativa));
    if (!nodo) return NULL;

    nodo->idMateria = idMateria;
    nodo->next = NULL;
    return nodo;
}
#include "listaCorrelativas.h"
#include <stdlib.h>

void lista_inicializar(ListaCorrelativas* lista) {
    lista->head = NULL;
    lista->tamanio = 0;
}

void lista_agregar(ListaCorrelativas* lista, int idMateria) {
    NodoCorrelativa* nuevo = nodo_crear(idMateria);
    if (!nuevo) return;

    nuevo->next = lista->head;
    lista->head = nuevo;
    lista->tamanio++;
}

int lista_eliminar(ListaCorrelativas* lista, int idMateria) {
    NodoCorrelativa* actual = lista->head;
    NodoCorrelativa* previo = NULL;

    while (actual != NULL) {
        if (actual->idMateria == idMateria) {
            if (previo == NULL)
                lista->head = actual->next;
            else
                previo->next = actual->next;

            free(actual);
            lista->tamanio--;
            return 1;
        }

        previo = actual;
        actual = actual->next;
    }
    return 0;
}

int lista_obtener(ListaCorrelativas* lista, int indice) {
    if (indice < 0 || indice >= lista->tamanio)
        return -1;

    NodoCorrelativa* actual = lista->head;
    for (int i = 0; i < indice; i++) {
        actual = actual->next;
    }
    return actual->idMateria;
}

int* lista_ids(ListaCorrelativas* lista) {
    if (lista->tamanio == 0) return NULL;

    int* vec = malloc(sizeof(int) * lista->tamanio);
    if (!vec) return NULL;

    NodoCorrelativa* actual = lista->head;
    for (int i = 0; i < lista->tamanio; i++) {
        vec[i] = actual->idMateria;
        actual = actual->next;
    }

    return vec;
}

void lista_clear(ListaCorrelativas* lista) {
    NodoCorrelativa* actual = lista->head;
    while (actual != NULL) {
        NodoCorrelativa* sig = actual->next;
        free(actual);
        actual = sig;
    }

    lista->head = NULL;
    lista->tamanio = 0;
}
#include "nodoCorrelativa.h"

//ListaCorrelativas es una lista enlazada que contiene todas las correlativas
//a una materia.
typedef struct {
    NodoCorrelativa* head;
} ListaCorrelativas;

// Funciones de la lista
void lista_inicializar(ListaCorrelativas* lista);
void lista_agregar(ListaCorrelativas* lista, int idMateria);
int lista_eliminar(ListaCorrelativas* lista, int idMateria);
int lista_buscar(ListaCorrelativas* lista, int idMateria);
void lista_liberar(ListaCorrelativas* lista);
//Devuelve el id de la materia que se encuentra en el indice.
//Util para buscar todas las correlativas de una materia
int lista_obtener(ListaCorrelativas* lista, int indice);
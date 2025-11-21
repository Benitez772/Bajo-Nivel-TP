#include "nodoCorrelativa.h"

//ListaCorrelativas es una lista enlazada que contiene todas las correlativas
//a una materia.
typedef struct {
    NodoCorrelativa* head;
    int tamanio;
} ListaCorrelativas;

// Inicia la lista vacia
void lista_inicializar(ListaCorrelativas* lista);

//Agrega un NodoCorrelativa al comienzo de la lista
void lista_agregar(ListaCorrelativas* lista, int idMateria);

//Elimina el nodo con el idMateria solicitado de la lista reemplazandolo con el previo
//(o con el siguiente en caso que sea head).
int lista_eliminar(ListaCorrelativas* lista, int idMateria);

//Libera de la memoria a todos los nodos de la lista.
void lista_clear(ListaCorrelativas* lista);

//Devuelve el id de la materia que se encuentra en el indice.
int lista_obtener(ListaCorrelativas* lista, int indice);

//Devuelve un vector con todos los ids de las materias correlativas.
//Utiliza tamanio para saber cuanta memoria asignar al vector.
int* lista_ids(ListaCorrelativas* lista);
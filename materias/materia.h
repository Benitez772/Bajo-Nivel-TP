#include "listaCorrelativas.h"

typedef struct
{
    //Es el identificador unico de la materia. Se utiliza al momento de procesar una inscripcion.
    int id;
    //Es el nombre de la materia.
    char nombre[60];
    //Es una lista enlazada con las correlativas de la materia.
    ListaCorrelativas correlativas;
}Materia;

// Inicializa materia
int materia_init(Materia* m, int id, const char* nombre);

// Agregar/Eliminar correlativa
void materia_agregar_correlativa(Materia* m, int idCorrelativa);
int materia_eliminar_correlativa(Materia* m, int idCorrelativa);

// Validar
int materia_es_valida(const Materia* m);

// Liberar memoria (libera la lista de correlativas)
void materia_liberar(Materia* m);
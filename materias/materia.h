#include "listaCorrelativas.h"

typedef struct
{
    //Es el identificador unico de la materia. 
    //Se utiliza al momento de procesar una inscripcion.
    //siempre es positiva
    unsigned id;
    //Es el nombre de la materia.
    char nombre[60];
    //Es una lista enlazada con las correlativas de la materia.
    ListaCorrelativas correlativas;
}Materia;

// Inicializa materia
int materia_init(Materia* m, unsigned int id, const char* nombre);

// Agregar/Eliminar correlativa
void materia_agregar_correlativa(Materia* m, int idCorrelativa);
int materia_eliminar_correlativa(Materia* m, int idCorrelativa);

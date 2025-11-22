#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras.h"
#include "materias.h"
#include "inscripciones.h"

Materia *listaMat = NULL;

void agregarMateria(int id, char *nombre)
{
    Materia *aux = listaMat;
    while (aux)
    {
        if (aux->id == id)
        {
            printf("\n\nYa existe una materia con ese ID\n");
            return;
        }
        aux = aux->sig;
    }

    Materia *nuevo = (Materia *)malloc(sizeof(Materia));
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->sig = listaMat;
    listaMat = nuevo;
}

Materia *buscarMatPorId(int id)
{
    Materia *aux = listaMat;
    while (aux)
    {
        if (aux->id == id)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void listarMaterias()
{
    Materia *aux = listaMat;
    if (!aux)
    {
        printf("\n\nNo hay materias\n");
        return;
    }
    while (aux)
    {
        printf("\n\nID: %d - Nombre: %s\n", aux->id, aux->nombre);
        aux = aux->sig;
    }
}

void eliminarInscripcionesPorMateria(int idMat);

void eliminarMateria(int id)
{
    Materia *cur = listaMat;
    Materia *prev = NULL;

    while (cur)
    {
        if (cur->id == id)
        {
            if (prev == NULL)
                listaMat = cur->sig;
            else
                prev->sig = cur->sig;

            free(cur);
            eliminarInscripcionesPorMateria(id);
            printf("\n\nMateria eliminada (y se borraron inscripciones asociadas)\n");
            return;
        }
        prev = cur;
        cur = cur->sig;
    }
    printf("\n\nNo se encontro la materia\n");
}

void modificarMateria(int id, char *nuevoNombre)
{
    Materia *m = buscarMatPorId(id);
    if (m == NULL)
    {
        printf("\n\nLa materia no existe\n");
        return;
    }
    strcpy(m->nombre, nuevoNombre);
    printf("\n\nMateria modificada\n");
}
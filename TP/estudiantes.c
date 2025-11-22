#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "estudiantes.h"
#include "inscripciones.h"

Estudiante *listaEst = NULL;

void agregarEstudiante(int legajo, char *nombre, int edad)
{
    Estudiante *aux = listaEst;
    while (aux)
    {
        if (aux->legajo == legajo)
        {
            printf("\n\nYa existe un estudiante con ese legajo\n");
            return;
        }
        aux = aux->sig;
    }

    Estudiante *nuevo = (Estudiante *)malloc(sizeof(Estudiante));
    nuevo->legajo = legajo;
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    nuevo->sig = listaEst;
    listaEst = nuevo;
}

Estudiante *buscarEstPorLegajo(int legajo)
{
    Estudiante *aux = listaEst;
    while (aux)
    {
        if (aux->legajo == legajo)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void listarEstudiantes()
{
    Estudiante *aux = listaEst;
    if (!aux)
    {
        printf("\n\nNo hay estudiantes\n");
        return;
    }
    while (aux)
    {
        printf("\n\nLegajo: %d - Nombre: %s - Edad: %d\n",
               aux->legajo, aux->nombre, aux->edad);
        aux = aux->sig;
    }
}

void eliminarInscripcionesPorEstudiante(int legajo);

void eliminarEstudiante(int legajo)
{
    Estudiante *cur = listaEst;
    Estudiante *prev = NULL;

    while (cur)
    {
        if (cur->legajo == legajo)
        {
            if (prev == NULL)
                listaEst = cur->sig;
            else
                prev->sig = cur->sig;

            free(cur);
            eliminarInscripcionesPorEstudiante(legajo);
            printf("\n\nEstudiante eliminado (y se borraron inscripciones asociadas)\n");
            return;
        }
        prev = cur;
        cur = cur->sig;
    }
    printf("\n\nNo se encontro el estudiante\n");
}

void buscarEstudiantePorNombre(char *nombre)
{
    Estudiante *aux = listaEst;
    int encontrado = 0;
    while (aux)
    {
        if (strcmp(aux->nombre, nombre) == 0)
        {
            printf("\n\nEncontrado -> Legajo: %d | Nombre: %s | Edad: %d\n",
                   aux->legajo, aux->nombre, aux->edad);
            encontrado = 1;
        }
        aux = aux->sig;
    }
    if (!encontrado)
        printf("\n\nNo se encontro estudiante con ese nombre\n");
}

void buscarEstudiantesPorRangoEdad(int min, int max)
{
    Estudiante *aux = listaEst;
    int encontrado = 0;
    while (aux)
    {
        if (aux->edad >= min && aux->edad <= max)
        {
            printf("\n\nLegajo: %d - Nombre: %s - Edad: %d\n",
                   aux->legajo, aux->nombre, aux->edad);
            encontrado = 1;
        }
        aux = aux->sig;
    }
    if (!encontrado)
        printf("\n\nNo se encontraron estudiantes en ese rango\n");
}
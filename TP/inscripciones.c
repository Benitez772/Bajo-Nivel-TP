#include <stdio.h>
#include <stdlib.h>
#include "inscripciones.h"
#include "materias.h"
#include "estudiantes.h"

Inscripcion *listaIns = NULL;

void agregarInscripcion(int legajo, int idMat, int nota)
{
    Inscripcion *nuevo = malloc(sizeof(Inscripcion));
    nuevo->legajoEst = legajo;
    nuevo->idMat = idMat;
    nuevo->nota = nota;
    nuevo->sig = listaIns;
    listaIns = nuevo;
}

Inscripcion *buscarInscripcion(int legajo, int idMat)
{
    Inscripcion *aux = listaIns;
    while (aux)
    {
        if (aux->legajoEst == legajo && aux->idMat == idMat)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void listarInscripciones()
{
    Inscripcion *aux = listaIns;
    if (!aux)
    {
        printf("\n\nNo hay inscripciones\n");
        return;
    }

    while (aux)
    {
        Materia *m = buscarMatPorId(aux->idMat);
        if (m)
            printf("Legajo: %d - Materia: %d (%s) - Nota: %d\n",
                   aux->legajoEst, aux->idMat, m->nombre, aux->nota);
        else
            printf("Legajo: %d - Materia: %d (NA) - Nota: %d\n",
                   aux->legajoEst, aux->idMat, aux->nota);

        aux = aux->sig;
    }
}

void eliminarInscripcionesPorMateria(int idMat)
{
    Inscripcion *cur = listaIns;
    Inscripcion *prev = NULL;

    while (cur)
    {
        if (cur->idMat == idMat)
        {
            Inscripcion *del = cur;

            if (prev == NULL)
                listaIns = cur->sig;
            else
                prev->sig = cur->sig;

            cur = (prev ? prev->sig : listaIns);
            free(del);
            continue;
        }
        prev = cur;
        cur = cur->sig;
    }
}

void eliminarInscripcionesPorEstudiante(int legajo)
{
    Inscripcion *cur = listaIns;
    Inscripcion *prev = NULL;

    while (cur)
    {
        if (cur->legajoEst == legajo)
        {
            Inscripcion *del = cur;

            if (prev == NULL)
                listaIns = cur->sig;
            else
                prev->sig = cur->sig;

            cur = (prev ? prev->sig : listaIns);
            free(del);
            continue;
        }
        prev = cur;
        cur = cur->sig;
    }
}

void rendirMateria(int legajo, int idMat, int nota)
{
    Estudiante *e = buscarEstPorLegajo(legajo);
    if (!e)
    {
        printf("\n\nNo existe el estudiante\n");
        return;
    }

    Materia *m = buscarMatPorId(idMat);
    if (!m)
    {
        printf("\n\nNo existe la materia\n");
        return;
    }

    Inscripcion *ins = buscarInscripcion(legajo, idMat);
    if (ins)
    {
        ins->nota = nota;
        printf("\n\nNota actualizada\n");
    }
    else
    {
        agregarInscripcion(legajo, idMat, nota);
        printf("\n\nInscripcion creada\n");
    }
}

void listarMateriasDeEstudiante(int legajo)
{
    Estudiante *e = buscarEstPorLegajo(legajo);
    if (!e)
    {
        printf("\n\nNo existe el estudiante\n");
        return;
    }

    Inscripcion *aux = listaIns;
    int ok = 0;

    while (aux)
    {
        if (aux->legajoEst == legajo)
        {
            Materia *m = buscarMatPorId(aux->idMat);
            printf("\nMateria ID: %d | %s | Nota: %d\n",
                   aux->idMat,
                   m ? m->nombre : "(no existe)",
                   aux->nota);
            ok = 1;
        }
        aux = aux->sig;
    }

    if (!ok)
        printf("\n\nNo tiene materias inscriptas\n");
}
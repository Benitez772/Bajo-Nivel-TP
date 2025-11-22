#ifndef INSCRIPCIONES_H
#define INSCRIPCIONES_H

#include "estructuras.h"

void agregarInscripcion(int legajo, int idMat, int nota);
Inscripcion *buscarInscripcion(int legajo, int idMat);
void listarInscripciones();
void eliminarInscripcionesPorEstudiante(int legajo);
void eliminarInscripcionesPorMateria(int idMat);
void rendirMateria(int legajo, int idMat, int nota);
void listarMateriasDeEstudiante(int legajo);

#endif
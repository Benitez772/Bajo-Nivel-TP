#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include "estructuras.h"

void agregarEstudiante(int legajo, char *nombre, int edad);
Estudiante *buscarEstPorLegajo(int legajo);
void listarEstudiantes();
void eliminarInscripcionesPorEstudiante(int legajo);
void eliminarEstudiante(int legajo);
void buscarEstudiantePorNombre(char *nombre);
void buscarEstudiantesPorRangoEdad(int min, int max);

#endif
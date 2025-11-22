#ifndef MATERIAS_H
#define MATERIAS_H

#include "estructuras.h"

void agregarMateria(int id, char *nombre);
Materia *buscarMatPorId(int id);
void listarMaterias();
void eliminarInscripcionesPorMateria(int idMat);
void eliminarMateria(int id);
void modificarMateria(int id, char *nuevoNombre);

#endif
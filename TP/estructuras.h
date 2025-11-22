#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct Estudiante
{
    int legajo;
    char nombre[50];
    int edad;
    struct Estudiante *sig;
} Estudiante;

typedef struct Materia
{
    int id;
    char nombre[50];
    struct Materia *sig;
} Materia;

typedef struct Inscripcion
{
    int legajoEst;
    int idMat;
    int nota;
    struct Inscripcion *sig;
} Inscripcion;

extern Estudiante *listaEst;
extern Materia *listaMat;
extern Inscripcion *listaIns;

#endif
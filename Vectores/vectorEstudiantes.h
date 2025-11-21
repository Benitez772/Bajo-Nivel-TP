#include "estudiante.h"
//VectorEstudiantes es un arreglo dinamico del struct Estudiantes. 
typedef struct {
    Estudiante* data;
    //tamanio es la cantidad de estudiantes que se encuentran adentro de VectorEstudiantes.
    //Se llama "tamanio" y no "tamaño" para evitar conflictos con la ñ.
    int tamanio;
    //capacidad es el espacio maximo que tiene VectorEstudiantes, al ser un arreglo dinamico puede ser modificado.
    int capacidad;
}VectorEstudiantes;

void estudiantes_init(VectorEstudiantes* v);
void estudiantes_clear(VectorEstudiantes* v);
int estudiantes_agregar(VectorEstudiantes* v, Estudiante e);
int estudiantes_modificar(VectorEstudiantes* v, int legajo, Estudiante* nuevo);
int estudiantes_eliminar(VectorEstudiantes* v, int id);
Estudiante* estudiantes_buscar_por_legajo(VectorEstudiantes* v, int legajoestudiante);
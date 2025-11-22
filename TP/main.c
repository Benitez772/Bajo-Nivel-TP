#include <stdio.h>
#include "validaciones.h"
#include "estudiantes.h"
#include "materias.h"
#include "inscripciones.h"
#include <string.h>

int main()
{
    int opcion;
    // Datos ramdom
    agregarEstudiante(10, "Alexander", 20);
    agregarEstudiante(20, "Lautaro", 20);

    agregarMateria(1, "Programacion");
    agregarMateria(2, "Bajo Nivel");

    agregarInscripcion(10, 1, 4);
    agregarInscripcion(10, 2, 4);
    agregarInscripcion(20, 1, 4);
    agregarInscripcion(20, 2, 4);

    do
    {
        printf("\n       MENU\n");
        printf("1. Nuev@ estudiante\n");
        printf("2. Lista de estudiantes\n");
        printf("3. Nueva materia\n");
        printf("4. Lista de materias\n");
        printf("5. Inscribir estudiante a materia\n");
        printf("6. Lista de inscripciones\n");
        printf("7. Buscar estudiante por nombre\n");
        printf("8. Buscar estudiantes por rango de edad\n");
        printf("9. Modificar materia\n");
        printf("10. Eliminar materia\n");
        printf("11. Modificar estudiante\n");
        printf("12. Eliminar estudiante\n");
        printf("13. Rendir materia\n");
        printf("14. Listar materias de un estudiante\n");
        printf("0. Salir\n");
        printf("Elija un numero: ");

        if (!leerEnteroSeguro(&opcion))
            continue;

        if (opcion == 1)
        {
            int legajo, edad;
            char nombre[50];

            printf("Legajo: ");
            if (!leerEnteroSeguro(&legajo))
                continue;

            printf("Nombre: ");
            leerNombreSeguro(nombre);
            if (nombre[0] == '\0')
                continue;

            printf("Edad: ");
            if (!leerEnteroSeguro(&edad))
                continue;

            agregarEstudiante(legajo, nombre, edad);
        }
        else if (opcion == 2)
            listarEstudiantes();

        else if (opcion == 3)
        {
            int id;
            char nombre[50];

            printf("ID materia: ");
            if (!leerEnteroSeguro(&id))
                continue;

            printf("Nombre materia: ");
            leerNombreSeguro(nombre);
            if (nombre[0] == '\0')
                continue;

            agregarMateria(id, nombre);
        }
        else if (opcion == 4)
            listarMaterias();

        else if (opcion == 5)
        {
            int legajo, idMat, nota;

            printf("Legajo estudiante: ");
            if (!leerEnteroSeguro(&legajo))
                continue;

            if (!buscarEstPorLegajo(legajo))
            {
                printf("\n\nNo existe el estudiante\n");
                continue;
            }

            printf("ID materia: ");
            if (!leerEnteroSeguro(&idMat))
                continue;

            if (!buscarMatPorId(idMat))
            {
                printf("\n\nNo existe la materia\n");
                continue;
            }

            printf("Nota: ");
            if (!leerEnteroSeguro(&nota))
                continue;

            if (buscarInscripcion(legajo, idMat))
            {
                printf("\n\nYa existe inscripcion\n");
                continue;
            }

            agregarInscripcion(legajo, idMat, nota);
        }
        else if (opcion == 6)
            listarInscripciones();

        else if (opcion == 7)
        {
            char nombre[50];
            printf("Nombre a buscar: ");
            leerNombreSeguro(nombre);
            if (nombre[0] == '\0')
                continue;
            buscarEstudiantePorNombre(nombre);
        }
        else if (opcion == 8)
        {
            int min, max;
            printf("Edad minima: ");
            if (!leerEnteroSeguro(&min))
                continue;

            printf("Edad maxima: ");
            if (!leerEnteroSeguro(&max))
                continue;

            buscarEstudiantesPorRangoEdad(min, max);
        }
        else if (opcion == 9)
        {
            int id;
            char nuevo[50];

            printf("ID materia: ");
            if (!leerEnteroSeguro(&id))
                continue;

            printf("Nuevo nombre: ");
            leerNombreSeguro(nuevo);
            if (nuevo[0] == '\0')
                continue;

            modificarMateria(id, nuevo);
        }
        else if (opcion == 10)
        {
            int id;
            printf("ID materia a eliminar: ");
            if (!leerEnteroSeguro(&id))
                continue;
            eliminarMateria(id);
        }
        else if (opcion == 11)
        {
            int legajo;
            char nuevo[50];
            int edad;

            printf("Legajo estudiante: ");
            if (!leerEnteroSeguro(&legajo))
                continue;

            Estudiante *e = buscarEstPorLegajo(legajo);
            if (!e)
            {
                printf("\n\nNo existe\n");
                continue;
            }

            printf("Nuevo nombre: ");
            leerNombreSeguro(nuevo);
            if (nuevo[0] == '\0')
                continue;

            printf("Nueva edad: ");
            if (!leerEnteroSeguro(&edad))
                continue;

            strcpy(e->nombre, nuevo);
            e->edad = edad;
        }
        else if (opcion == 12)
        {
            int legajo;
            printf("Legajo: ");
            if (!leerEnteroSeguro(&legajo))
                continue;
            eliminarEstudiante(legajo);
        }
        else if (opcion == 13)
        {
            int legajo, id, nota;

            printf("Legajo: ");
            if (!leerEnteroSeguro(&legajo))
                continue;

            printf("ID materia: ");
            if (!leerEnteroSeguro(&id))
                continue;

            printf("Nota: ");
            if (!leerEnteroSeguro(&nota))
                continue;

            rendirMateria(legajo, id, nota);
        }
        else if (opcion == 14)
        {
            int legajo;
            printf("Legajo: ");
            if (!leerEnteroSeguro(&legajo))
                continue;
            listarMateriasDeEstudiante(legajo);
        }

    } while (opcion != 0);

    return 0;
}
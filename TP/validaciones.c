#include <stdio.h>
#include <string.h>
#include "validaciones.h"

int contieneNumero(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= '0' && s[i] <= '9')
            return 1;
    return 0;
}

int leerEnteroSeguro(int *valor)
{
    if (scanf("%d", valor) != 1)
    {
        printf("\nRepita\nSolo se permiten numeros\n");
        while (getchar() != '\n')
            ;
        return 0;
    }
    while (getchar() != '\n')
        ;
    return 1;
}

void leerNombreSeguro(char *dest)
{
    scanf(" %[^\n]", dest);

    if (contieneNumero(dest))
    {
        printf("\n\nRepita\nNombre solo con letras\n");
        dest[0] = '\0';
    }
}
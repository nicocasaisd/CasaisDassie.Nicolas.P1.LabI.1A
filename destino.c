#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int listarDestinos(eDestino destinos[], int tam)
{
    int todoOk = 0;
    if(destinos != NULL && tam > 0)
    {
        printf(" Id  \t  Destino \t Precio \n");
        printf("------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d \t %s \t %6.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPorIdDestino(eDestino vec[], int tam, int id, int* indice)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && indice != NULL)
    {
        *indice = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *indice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarDestino(eDestino vec[], int tam, int id)
{
    int esValido;
    int indice;
    buscarPorIdDestino(vec, tam, id, &indice);
    if(indice == -1)
    {
        esValido = 0;
    }
    else
    {
        esValido = 1;
    }
    return esValido;
}

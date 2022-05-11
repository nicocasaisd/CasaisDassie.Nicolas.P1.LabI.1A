#include "tipo.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0)
    {
        printf(" Id  \t  Tipo\n");
        printf("------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d \t %s\n", tipos[i].id, tipos[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;
    if(tipos != NULL && tam > 0 && descripcion != NULL)
    {
        buscarPorIdTipo(tipos, tam, id, &indice);
        if(indice != -1){
            strcpy(descripcion, tipos[indice].descripcion);
            todoOk = 1;
        }

    }
    return todoOk;
}

int buscarPorIdTipo(eTipo vec[], int tam, int id, int* indice)
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

int validarTipo(eTipo vec[], int tam, int id)
{
    int esValido;
    int indice;
    buscarPorIdTipo(vec, tam, id, &indice);
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

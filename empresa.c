#include "empresa.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listarEmpresas(eEmpresa empresas[], int tam)
{
    int todoOk = 0;
    if(empresas != NULL && tam > 0)
    {
        printf(" Id  \t  Empresa\n");
        printf("------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d \t %s\n", empresas[i].id, empresas[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;
    if(empresas != NULL && tam > 0 && descripcion != NULL)
    {
        buscarPorIdEmpresa(empresas, tam, id, &indice);
        if(indice != -1){
            strcpy(descripcion, empresas[indice].descripcion);
            todoOk = 1;
        }

    }
    return todoOk;
}

int buscarPorIdEmpresa(eEmpresa vec[], int tam, int id, int* indice)
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

int validarEmpresa(eEmpresa vec[], int tam, int id)
{
    int esValido;
    int indice;
    buscarPorIdEmpresa(vec, tam, id, &indice);
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


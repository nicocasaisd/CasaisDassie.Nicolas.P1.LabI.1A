#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"
#include "destino.h"
#include "micro.h"
#include "my_lib.h"

int pedirAltaViaje(eViaje viajes[], int tamV, eMicro vec[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* nextId)
{
    int todoOk = 0;
    int indice;
    //int flagAuto = 0;
    eViaje nuevaStruct;
    eFecha fecha;

    if(vec != NULL && tam > 0 && nextId != NULL)
    {
        buscarViajeLibre(viajes, tamV, &indice);
        if(indice == - 1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            // aca caigo cuando haya lugar

            mostrarLista(vec, tam, empresas, tamE, tipos, tamT);
            printf("Ingrese id del micro: ");
            scanf_int("%d", &nuevaStruct.idMicro);
            while(!validarMicro(vec, tam, nuevaStruct.idMicro))
            {
                printf("\nId invalida. Reingrese id de empresa: ");
                scanf_int("%d", &nuevaStruct.idMicro);
            }

            listarDestinos(destinos, tamD);
            printf("\nIngrese id de destino: ");
            scanf_int("%d", &nuevaStruct.idDestino);
            while(!validarDestino(destinos, tam, nuevaStruct.idDestino))
            {
                printf("\nId invalida. Reingrese id de destino: ");
                scanf_int("%d", &nuevaStruct.idDestino);
            }

            printf("\nIngrese fecha (dd/mm/aaaa): ");
            if(scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio) == 0)
            {
                __fpurge(stdin);
                printf("Error. Valor no numerico\n");
            }
            while(!validarFecha(fecha))
            {
                printf("Fecha invalida. Reingrese fecha (dd/mm/aaaa): ");
                if(scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio) == 0)
                {
                    __fpurge(stdin);
                    printf("Error. Valor no numerico\n");
                }
            }
            nuevaStruct.fecha = fecha;


            nuevaStruct.isEmpty = 0;
            nuevaStruct.id = *nextId;
            *nextId += 1;

            viajes[indice] = nuevaStruct;
            todoOk = 1;
        }
    }
    return todoOk;
}


int buscarViajeLibre(eViaje vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarViajes(eViaje vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarElementoViaje(eViaje e)
{
    int todoOk = 0;

    printf("%4d \t    %4d \t    %4d \t %02d/%02d/%02d \n",
           e.id,
           e.idMicro,
           e.idDestino,
           e.fecha.dia,
           e.fecha.mes,
           e.fecha.anio
           );
    todoOk = 1;

    return todoOk;
}


int mostrarListaViajes(eViaje vec[], int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        //system("clear");
        //printf("          *** Lista ***\n\n");
        printf(" Id  \t   Micro \t  Destino\t  Fecha\n");
        printf("------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarElementoViaje(vec[i]);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay elementos que mostrar");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

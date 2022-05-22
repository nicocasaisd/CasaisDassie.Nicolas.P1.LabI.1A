#include "my_lib.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strlwr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = tolower((unsigned char) *tmp);
    }

    return s;
}

char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = toupper((unsigned char) *tmp);
    }

    return s;
}

int utn_gets(char vec[], int tam)
{
    int retorno = 0;
    char aux[100];
    // validaciones
    if(vec != NULL && tam > 0){
        __fpurge(stdin);
        fgets(aux, 100, stdin);
        // limpiamos el '\n' de fgets
        for(int i=0; i<100; i++){
            if(aux[i]=='\n'){
                aux[i] = '\0';
                break;
            }
        }
        while(strlen(aux) >= tam){
            printf("La cadena ingresada es demasiado larga. Reingrese: ");
            __fpurge(stdin);
            fgets(aux, 100, stdin);
            // limpiamos el '\n' de fgets
            for(int i=0; i<100; i++){
                if(aux[i]=='\n'){
                    aux[i] = '\0';
                    break;
            }
        }
        }
        strcpy(vec, aux);
        retorno = 1;
    }
    return retorno;
}

int scanf_int(char masc[], int* pInt)
{
    int todoOk = 0;
    int scanf_return;
    scanf_return = scanf(masc, pInt);
    while(scanf_return == 0)
    {
        __fpurge(stdin);
        printf("Error.Ingrese un valor numerico: ");
        scanf_return = scanf(masc, pInt);
    }

    return todoOk;
}

void pausar()
{
    char auxPausa;
    __fpurge(stdin);
    printf("\n\nPresione una tecla para continuar...");
    scanf("%c", &auxPausa);
}

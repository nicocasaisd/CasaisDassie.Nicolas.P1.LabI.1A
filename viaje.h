#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "fecha.h"
#include "micro.h"
#include "destino.h"

typedef struct{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;
}eViaje;

#endif // VIAJE_H_INCLUDED

int pedirAltaViaje(eViaje viajes[], int tamV, eMicro vec[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* nextId);
int buscarViajeLibre(eViaje vec[], int tam, int* pIndex);
int inicializarViajes(eViaje vec[], int tam);
int mostrarListaViajes(eViaje vec[], int tam);
int mostrarElementoViaje(eViaje e);

#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
typedef struct{
    int id;
    char descripcion[26];
    float precio;
}eDestino;


#endif // DESTINO_H_INCLUDED

int listarDestinos(eDestino destinos[], int tam);
int buscarPorIdDestino(eDestino vec[], int tam, int id, int* indice);


// VALIDACIONES

int validarDestino(eDestino vec[], int tam, int id);

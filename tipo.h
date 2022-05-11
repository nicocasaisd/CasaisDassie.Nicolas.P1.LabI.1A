#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eTipo;


#endif // TIPO_H_INCLUDED

int listarTipos(eTipo tipos[], int tam);
int buscarPorIdTipo(eTipo vec[], int tam, int id, int* indice);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);

// VALIDACIONES
int validarTipo(eTipo vec[], int tam, int id);

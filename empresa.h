#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED

int listarEmpresas(eEmpresa empresas[], int tam);
int buscarPorIdEmpresa(eEmpresa vec[], int tam, int id, int* indice);
int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int id, char descripcion[]);

// VALIDACIONES
int validarEmpresa(eEmpresa vec[], int tam, int id);

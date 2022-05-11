#include "fecha.h"




int validarFecha(eFecha fecha){
    int esValido;
    if( validarDia(fecha)
    ||  (fecha.mes < 1 || fecha.mes > 12)
    ||  (fecha.anio < 2000 || fecha.anio > 2022)  )
    {
        esValido = 0;
    }
    else
    {
        esValido = 1;
    }
    return esValido;
}

int validarDia(eFecha fecha)
{
    int esValido;
    if( // meses de 31 dias
    (
    (fecha.dia >= 1 && fecha.dia <= 31) &&
    (fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 ||
     fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12)
    )
    ||  // meses de 30 dias
    (
    (fecha.dia >= 1 && fecha.dia <= 30) &&
    (fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 ||
     fecha.mes == 11)
    )
    ||  // febrero
    (
        (fecha.dia >= 1 && fecha.dia <= 28) &&
    (fecha.mes == 2)
        )
     )
    {
        esValido = 0;
    }
    else
    {
        esValido = 1;
    }
    return esValido;
}

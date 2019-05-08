#include "Fecha.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFecha(Fecha* input, char message[], char eMessage[], int attemps)
{
    int result=-1;
    Fecha aux;
    int i;
    int retornoDia;
    int retornoMes;
    int retornoAnio;

    printf("%s", message);

    for(i=0;i<attemps;i++)
    {
        retornoDia = getInt(&aux.dia, "\nIngrese el dia[1-31]: ", "\nIngreso invalido\n\n", 1, 31, attemps);
        retornoMes = getInt(&aux.mes, "\nIngrese el mes[1-12]: ", "\nIngreso invalido\n\n", 1, 12, attemps);
        retornoAnio = getInt(&aux.anio, "\nIngrese el anio: ", "\nIngreso invalido\n\n", 1810, 2019, attemps);

        if(retornoDia==0 && retornoMes==0 && retornoAnio==0)
        {
            *input=aux;
            result=0;
            break;
        }
    }

    return result;
}

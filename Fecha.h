#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

#endif // FECHA_H_INCLUDED

int getFecha(Fecha* input, char message[], char eMessage[], int attemps);

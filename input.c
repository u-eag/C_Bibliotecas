#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit, int attemps)
{
    int result=-1; // si obtuvo el número devuelve [0] si no [-1]
    int aux; // almacena temporalmente el numero ingresado
    int i;

    for(i=0;i<attemps;i++)
    {
        printf("%s", message);
        scanf("%d", &aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux; // si el número ingresado cumple los requisitos se lo carga en la variable pasada por parámetro
            result=0;
            break;
        }
        else
        {
            printf("%s", eMessage);
        }
    }

    return result;
}

int getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit, int attemps)
{
    int result=-1; // si obtuvo el número devuelve [0] si no [-1]
    float aux;
    int i;

    for(i=0;i<attemps;i++)
    {
        printf("%s", message);
        scanf("%f", &aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux;
            result=0;
            break;
        }
        else
        {
            printf("%s", eMessage);
        }
    }

    return result;
}

int getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit, int attemps)
{
    int result=-1; // si obtuvo el caracter [0] si no [-1]
    char aux;
    int i;

    for(i=0;i<attemps;i++)
    {
        printf("%s", message);
        fflush(stdin); // fpurge(stdin) para Linux y OSx
        scanf("%c", &aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux;
            result=0;
            break;
        }
        else
        {
            printf("%s",eMessage);
        }
    }

    return result;
}

int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit, int attemps)
{
    int result=-1; // si obtuvo la cadena [0] si no [-1]
    char aux[hiLimit];
    int len; // para saber cuánto mide la cadena ingresada
    int i;

    for(i=0;i<attemps;i++)
    {
        printf("%s", message);
        fflush(stdin); //fpurge(stdin) para Linux y OSx
        gets(aux);

        len=strlen(aux);

        if(len>=lowLimit && len<=hiLimit)
        {
            strcpy(input, aux);
            result=0;
            break;
        }
        else
        {
            printf("%s", eMessage);
        }
    }

    return result;
}

int getGender(char* input, char message[], char eMessage[], int attemps)
{
    int result=-1; // si obtuvo el caracter [0] si no [-1]
    char aux;
    int i;

    for(i=0;i<attemps;i++)
    {
        printf("%s", message);
        fflush(stdin); // fpurge(stdin) para Linux y OSx
        scanf("%c", &aux);

        if(aux=='F' || aux=='M')
        {
            *input=aux;
            result=0;
            break;
        }
        else
        {
            printf("%s",eMessage);
        }

    }

    return result;
}

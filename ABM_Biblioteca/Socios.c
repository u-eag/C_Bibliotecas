#include "Socios.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initSocios(Socios* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    if(len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        result=0;
    }

    return result;
}

int printSocios(Socios* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    printf("\n\t id \t Nombre\t Apellido\t Sexo\t Telefono\t eMail\t Fecha de ingreso \n\n");

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {

            printf("\t%d \t%s \t%s \t%c \t%s \t%s \t%d/%d/%d \n\n", list[i].idSocios, list[i].nombre, list[i].apellido, list[i].sexo,
                list[i].telefono, list[i].mail, list[i].fechaAsociado.dia, list[i].fechaAsociado.mes, list[i].fechaAsociado.anio);
        }
    }

    return result;
}

int findEmptyIndexSocios(Socios* list, int len, int* index)
{
    int result=-1;
    int i;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            *index=i;
            result=0;
            break;
        }
    }

    return result;
}

int altaSocios(Socios* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int emptyIndex;
    int flagIndex=0; // para saber si se encontró un índice libre
    Socios aux; // para guardar los datos ingresados

    // primero busco un lugar libre:
    if((findEmptyIndexSocios(list, len, &emptyIndex))==0)
    {
        flagIndex=1;
    }
    else
    {
        printf("\nNo existen lugares libres para ingresar una nueva alta\n");
    }

    // si encuentro un lugar libre pido los datos
    if(flagIndex && list!=NULL && len>0)
    {
        if(getString(aux.nombre, "\nIngrese el nombre: \n", "\nIngreso invalido\n", 1, 31, 2) == 0) // nombre[31]
        {
            if(getString(aux.apellido, "\nIngrese el apellido: \n", "\nIngreso invalido\n", 1, 31, 2) == 0) // apellido[31]
            {
                if(getGender(&aux.sexo, "\nIngrese el sexo[F][M]: \n", "\nIngreso invalido\n", 2) == 0) // sexo[F][M]
                {
                    if(getString(aux.telefono, "\nIngrese el telefono: \n", "Ingreso invalido\n", 4, 16, 2) == 0) // telefono[16]
                    {
                        if(getString(aux.mail, "\nIngrese el eMail: ", "\nIngreso invalido", 6, 31, 2) == 0) // mail[31]
                        {
                            if(getInt(&aux.fechaAsociado.dia, "\nIngrese dia de asociacion: ", "\nIngreso invalido", 1, 31, 2) == 0) // fechaAsociado.dia
                            {
                                if(getInt(&aux.fechaAsociado.mes, "\nIngrese mes de asociacion [1-12]: ", "\nIngreso invalido", 1, 12, 2) == 0) // fechaAsociado.mes
                                {
                                    if(getInt(&aux.fechaAsociado.anio, "\nIngrese anio de asociacion: ", "\nIngreso invalido", 1810, 2019, 2) == 0) // fechaAsociado.anio
                                    {
                                        // campo isEmpty
                                        aux.isEmpty=0; // ya no está más vacío

                                        // idSocios
                                        aux.idSocios=emptyIndex;

                                        // si está todo bien, asigno los datos:
                                        list[emptyIndex]=aux;

                                        result=0;

                                        printf("\nAlta ingresada exitosamente\n\n");
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    return result;
}

int buscarSocios(Socios* list, int len, int* input)
{
    int result=-1;
    int idSocioBuscado;
    int i;

    printf("\nIngrese el id del socio: ");
    scanf("%d", &idSocioBuscado);

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && list[i].idSocios==idSocioBuscado)
        {
            *input=i;
            result=0;
            break;
        }
    }

    return result;
}

int bajaSocios(Socios* list, int len)
{
    int result=-1;
    int idSocioBaja;

    if(buscarSocios(list, len, &idSocioBaja) == 0)
    {
        list[idSocioBaja].isEmpty=1;
        result = 0;
        printf("\nSe dio de baja a %s %s\n\n", list[idSocioBaja].nombre, list[idSocioBaja].apellido);

    }
    else
    {
        printf("\nNo se encontro socio con ese id\n\n");
    }

    return result;
}

int ordenarSocios(Socios* list, int len)
{
    int result=-1;
    Socios aux;
    int i;
    int j;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(strcmp(list[i].apellido, list[j].apellido)>0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
                result=0;
            }
        }
    }

    return result;
}

int modificarSocios(Socios* list, int len)
{
    int result=-1;
    int idSocioBuscado;
    int menuModificar;

    if(buscarSocios(list, len, &idSocioBuscado)==0)
    {
        result=0;
        do{
            system("cls");

            printf("*** MENU MODIFICAR - SOCIO: %s %s ***\n\n", list[idSocioBuscado].nombre, list[idSocioBuscado].apellido);
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Sexo\n");
            printf("4. Telefono\n");
            printf("5. eMail\n");
            printf("6. Volver al menu principal\n");

            getInt(&menuModificar, "\nSeleccione una opcion del menu: ", "\nOpcion no valida\n\n", 1, 6, 1);

            switch(menuModificar)
            {
                case 1: // modificar nombre
                    getString(list[idSocioBuscado].nombre, "\nIngrese el nuevo nombre: ", "\nIngreso invalido\n\n", 1, 31, 2);
                    system("pause");
                    break;

                case 2: // modificar apellido
                    getString(list[idSocioBuscado].apellido, "\nIngrese el nuevo apellido: ", "\nIngreso invalido\n\n", 1, 31, 2);
                    system("pause");
                    break;

                case 3: // modificar sexo
                    getGender(&list[idSocioBuscado].sexo, "\nIngrese nuevo sexo: ", "\nIngreso invalido\n\n", 2);
                    system("pause");
                    break;

                case 4: // modificar telefono
                    getString(list[idSocioBuscado].telefono, "\nIngrese nuevo telefono: ", "\n Ingreso invalido\n\n", 5, 16, 2);
                    system("pause");
                    break;

                case 5: // modificar mail
                    getString(list[idSocioBuscado].mail, "\nIngrese nuevo eMail: ", "\nIngreso invalido\n\n", 5, 31, 2);
                    system("pause");
                    break;
            }
        }while(menuModificar!=6);
    }

    return result;
}

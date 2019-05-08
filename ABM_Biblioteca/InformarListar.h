#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "Autores.h"
#include "Fecha.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"

int informarListar (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);
int unLibroMuchosSocios (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);
int unSocioMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);
int unaFechaMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);
int buscarDia(Prestamos* listPrestamos, int lenPrestamos, int* input);
int buscarMes(Prestamos* listPrestamos, int lenPrestamos, int* input);
int buscarAnio(Prestamos* listPrestamos, int lenPrestamos, int* input);
int unaFechaMuchosSocios(Prestamos* listPrestamos, int lenPrestamos, Socios* listLibros, int lenSocios);

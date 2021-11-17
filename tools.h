#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double **GeneraMatriz(int fil, int col);  // Generará un arreglo de tamaño fil*col (filas por columna)
double norma(int n, double *vector1,double *vector2);
double *MetodoJacobi(int n, double **A, double *b, double tolerancia, int niteraciones); // Método de Jacobi
double *SumarVectores(int n, double *vector1, double *vector2);



#endif
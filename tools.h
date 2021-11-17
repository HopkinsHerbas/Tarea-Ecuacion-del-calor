#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double **GeneraMatriz(int fil, int col);  // generará un arreglo de tamaño fil*col (filas por columna)
double *MetodoJacobi(int n, double **A, double *b, double *xi, double tolerancia); // método de Jacobi
double *ProductoMatrizVector(int n, double **mat, double *arr);
double *SumarVectores(int n, double *vector1, double *vector2);

#endif
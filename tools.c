#include "tools.h"

// GeneraMatriz crea un "arreglo rectangular" (con dimensión) fil*col en la memoria con entradas Null. Se llenará de acuerdo a los datos que el usuario necesite.
double **GeneraMatriz(int fil, int col){
	int i;
	double **arreglo=NULL;
	arreglo = (double**)malloc(fil*sizeof(double*));
	for (i=0; i<fil; i++){
		arreglo[i] = (double*)malloc(col*sizeof(double)); //llenando filas con Null col veces
		if(arreglo[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);
		}
	}
	
	return arreglo; // regresa la matriz con entradas Null
}



// Método de Jocobi para resolver sistemas lineales de ecuaciones. Se programó de acuerdo al algoritmo clásico que aparece en textos e internet.
double *MetodoJacobi(int n, double **A, double *b, double tolerancia, int niteraciones){
	// aquí xi es la solución inicial y xk es la solución aproximada actualizada.
	int i, j, k;
	double *xk=NULL;  //Nuevo Vector a formar 
	xk = (double *) malloc(n * sizeof(double));
	if (xk==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	double *xi=NULL;
	xi = (double *) malloc(n * sizeof(double));
	if (xi==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	double error=0, diferencia;
	for(i=0;i<n;i++){
		xk[i]=0;
	}
	for (k=0;k< niteraciones;k++){
		for (i = 0; i < n; i++){
			
			
			xi[i] = b[i];
			for (j = 0; j < n; j++){
				if(i!=j){
					xi[i]=xi[i]-A[i][j]*xk[j];
				}
			}
			
		
		}
		
		for(i=0;i<n;i++){
			xk[i]=xi[i]/A[i][i];
		}
		
		// corte con límite de tolerancia
		diferencia = xk[k]-xi[k];
		error = error + diferencia*diferencia;
		if (error < tolerancia){
			break;
			}
	}
	free(xi); // liberamos memoria
	return xk; // regresa solución aproximada del sistema "la mejor"
}


// SumaVectores suma vectores de la misma dimensión (entrada a entrada)
double *SumarVectores(int n, double *vector1, double *vector2){
	int i;
	double *resultado=NULL;
	resultado = (double *) malloc(n * sizeof(double));
	if (resultado==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<n;i++){
		resultado[i]=vector1[i]+vector2[i];
	}
	
	return resultado; // regresa el vector resultado de la suma
}

#include "tools.h"


double **GeneraMatriz(int fil, int col){
	int i;
	double **arreglo=NULL;
	arreglo = (double**)malloc(fil*sizeof(double*));
	for (i=0; i<fil; i++){
		arreglo[i] = (double*)malloc(col*sizeof(double));
		if(arreglo[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);
		}
	}
	
	return arreglo;
}


double *MetodoJacobi(int n, double **A, double *b, double tolerancia, int niteraciones){
	
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
		diferencia = xk[k]-xi[k];
		error = error + diferencia*diferencia;
		if (error < tolerancia){
			break;
			}
	}
	free(xi);
	return xk;
}



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
	
	return resultado;
}
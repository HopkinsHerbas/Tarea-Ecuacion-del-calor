#include "tools.h"


double **GeneraMatriz(int fil, int col){
	int i;
	double **arreglo=NULL;
	arreglo = (double * *)malloc(fil * sizeof(double*));
	for (i=0; i<fil; i++){
		arreglo[i] = (double *) malloc(col*sizeof(double) );
		if(arreglo[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);
		}
	}
	
	return arreglo;
}

double *MetodoJacobi(int n, double **A, double *b, double *xi, double tolerancia, int niteraciones){
	
	int i, j, k = 0;
	double *xk=NULL;  //Nuevo Vector a formar 
	xk = (double *) malloc(n * sizeof(double));
	if (xk==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	double error;

	while (k <= niteraciones,k++){
		for (i = 0; i < n; i++){
			double suma, diferencia;
			
			suma = b[i];
			for (j = 0; j < n; j++){
				suma = suma - A[i][j]*xi[j];
			}
			
			suma = suma + A[i][i]*xi[i];
			xk[i] = suma/A[i][i];
			diferencia = xk[i] - xi[i];
			error = error + diferencia*diferencia;
		}
		
		if (error < tolerancia){
			break;
			
		}

		else{
			xi[i] = xk[i];
			}	
		}

    free(xk);
	return xi;
}

double *ProductoMatrizVector(int n, double **mat, double *arr){
	
	int i, k;
	double *resu=NULL;
	resu = (double *) malloc(n * sizeof(double));
	if (resu==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<n;i++){
		
		double sum = 0;
		
		for(k=0;k<n;k++){
			sum+=mat[i][k]*arr[k];	
		}
		
		resu[i]=sum;
	}
	
	return resu;

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
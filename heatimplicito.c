#include "tools.h"

double funcion(double x, double t);




int main(){
	double h = 0.01, k=0.0005; //k es deltaT y h es deltaX
	double lambda = k/h*h;
	double *x,*t;
	int i,j;
	int tmax=1;
	int n=1000,m=1000; // particion espacial vs temporal
	double tolerancia = 0.001;
	
	
	
	//Vector de posición x (discretización espacial)
	x = (double *) malloc( n * sizeof(double) );

	x[0] = 0;
	x[n-1] = 1;
	for( i = 1; i < n-1; i++ ){
      	x[i] = x[i-1] + h ;
		//printf("%f",x[i]);
	}

	//Vector de tiempo t  (discretización temporal)
	t = (double *) malloc(m * sizeof(double));
	
	t[0] = 0;
	t[m-1] = tmax;
	for( i = 1; i < m-1; i++ ) {
      	t[i] = t[i-1] + k ; 
		//printf("%f",t[i]);
	}
	
	//Generando la matriz de coeficientes (1,...,n/1,....,n)
	double **matrix = GeneraMatriz(m,n);
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			if (i==j){
				matrix[i][j]=(1+2*lambda);
				}
			else if (j==i+1){
				matrix[i][j]=-lambda;
				}
			else if(j==i-1){
				matrix[i][j]=lambda;
				}
			}
	}
	
	//Generando la matriz para valores de la funcion (1,....,n/1,...,n)
	double **matrixq = GeneraMatriz(m,n);
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			matrixq[i][j]=k*funcion(x[i],t[j]);
			}
	}
	
	double **m_result = GeneraMatriz(m,n); //Declarando la matriz de resultados
	
	
	
	for (j=0; j<n; j++){
		if(j==0){
			m_result[0][j]=0;
		}
		else if(j==n-1){
			m_result[0][j]=0;
		}
		else{
			m_result[0][j]=exp(x[j]); 	
		}
	}
		


	for (i=0; i<m-1; i++){
	
		m_result[i+1]=MetodoJacobi(n,matrix,SumarVectores(n,m_result[i],matrixq[i+1]),tolerancia,20);

	}
	
	
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			printf("%f",m_result[i][j]);	
		} 
		printf("\n");	
	}
	
	
	
	
	// registros de datos
	
	
	FILE *dataimplicito = fopen("dataimplicito.dat", "w");
	for (i = 0; i < m; i++){
		for (j=0; j<n; j++){
    		fprintf(dataimplicito, "%f %f %f", t[i], x[j],m_result[i][j]);
    		fprintf(dataimplicito, "\n");
		}
	}
	fclose(dataimplicito);
	
	
	
	free(m_result);
	free(matrixq);
}

double funcion(double x, double t){
		return cos(M_PI*t)*sin(2*M_PI*x);
	}
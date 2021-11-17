#include "tools.h"

//Implicit


double funcion(double x, double t);


int main(){
	double h = 0.01, k=0.00005; //k es deltaT y h es deltaX
	double lambda = k/h*h;
	double *x,*t,*b,*frontera;
	int i,j;
	int tmax=1;
	int n,m=10;
	double tolerancia = 0.001;
	
	
	b = (double *) malloc(n * sizeof(double));
	frontera = (double *) malloc(n+1 * sizeof(double));
	
	
	//Vector de posición x (discretización espacial)
	x = (double *) malloc( n * sizeof(double) );

	x[0] = 0;
	x[n] = 1;
	for( i = 1; i < n; i++ ) {
      	x[i] = x[i-1] + h ;
	}

	//Vector de tiempo t  (discretización temporal)
	t = (double *) malloc(m * sizeof(double));
	
	t[0] = 0;
	t[m] = tmax;
	for( i = 1; i < m; i++ ) {
      	t[i] = t[i-1] + k ; 
	}
	
	//Generando la matriz de coeficientes 
	double **matrix = GeneraMatriz(m,n);
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if (i==j){
				matrix[i][j]=(1+2*lambda);
				}
			else if (j=i+1){
				matrix[i][j]=-lambda;
				}
			else if(j=i-1){
				matrix[i][j]=lambda;
				}
			}
	}
	
	//Generando la matriz para valores de la funcion
	double **matrixq = GeneraMatriz(m+1,n);
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			matrixq[i][j]=k*funcion(x[i],t[i]);
			}
	}
	
	double **m_result = GeneraMatriz(m+1,n); //Declarando la matriz de resultados
	
	// Obteniendo el vector frontera y solución
	for (i=0; i<m+1; i++){
		frontera[i] = exp(x[i]);
	}
	
	for (j=0; j<n; j++){
		m_result[0][j]=frontera[j]; 
	}
	
	
	for (i=0; i<n; i++){
		b[i] = exp(x[i]);
	}
	
	


	
	double *suma;
	suma=(double *) malloc(n * sizeof(double));
	for (i=0; i<m; i++){
		suma=SumarVectores(n,m_result[i],matrixq[i+1]);
		m_result[i+1]=MetodoJacobi(n,matrix,suma,b,tolerancia);
		free(suma);
	}
	
	
	for (i = 0; i < m; i++){
		for (j=0; j<n; j++){
			printf("%f %f %f", t[i], x[j],m_result[i][j]);
			}
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
	
}

double funcion(double x, double t){
		return cos(M_PI*t)*sin(2*M_PI*x);
	}
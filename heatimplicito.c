#include "tools.h"  // llamando a la libraría tools

double funcion(double x, double t); // definimos (declaración) nuestra función q de la ecuación del calor


int main(){
	
	// declaración de variables
	double *x,*t;  
	int i,j;
	int tmax=1;
	int n=100,m=100; // particion espacial vs temporal
	double tolerancia = 0.01;
	double h = 0.01, k=0.01; //k es deltaT y h es deltaX
	double lambda = k/h*h;
	//*************************************************************************************************************
	//h=1/n;  // tamaño de paso de discretización espacial
	//k=1/m; // tamaño de paso de discretización temporal
	
	//Vector de posición x (discretización espacial)
	x = (double *) malloc(n* sizeof(double) );
	x[0] = 0;
	x[n-1] = 1;
	for(i= 1; i < n-1; i++ ){
      	x[i] = x[i-1] + h ;
	}
	
	//Vector de tiempo t  (discretización temporal)
	t = (double *) malloc(m * sizeof(double));
	
	t[0] = 0;
	t[m-1] = tmax;
	for( i = 1; i < m-1; i++ ) {
		t[i] = t[i-1] + k ; 
		//printf("%f",t[i]);
	}
	//***************************************************************************************************
	//Generando la matriz de coeficientes (Matriz A del problema discretizado de la ecuación del calor)
	//Matriz identidad-lamda*matriz K
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
            else{
				matrix[i][j]=0;
      }
			}
	}
	//***********************************************************************************************
	
	//Generando la matriz para valores de la funcion (Evaluación de q, es decir (x,t))
	double **matrixq = GeneraMatriz(m,n);
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			matrixq[i][j]=k*funcion(x[i],t[j]);
			}
	}
	
	
	//***********************************************************************************************
	
	double **m_result = GeneraMatriz(m,n); //Declarando la matriz de resultados donde llenamos los resultado de T (solución discreta)
	
	// llenamos la primera fila
	for (i=0; i<n; i++){
		m_result[0][i] = exp(x[i]);
	}

    for (j=0; j<m; j++){
		m_result[j][0] = 0;
	}

	for (j=0; j<m; j++){
		m_result[j][n-1] = 0;
	}
	
	

    // llenando las filas restantes
	for (i=0; i<m-1; i++){
		double *b;
		b = SumarVectores(n,m_result[i],matrixq[i+1]);
		m_result[i+1]=MetodoJacobi(n,matrix,b,tolerancia,20);
		// como se tiene que tener la misma temperatura en los extremos de la varilla ....
		m_result[i+1][0]=0;
		m_result[i+1][n-1]=0;
		free(b);
	}
	
	//************************************************************************************************
	

	
	//Registros de datos (los cuales usaremos para graficar)
	
	
	FILE *dataimplicito = fopen("data.dat", "w");
	for (i = 0; i < m; i++){
		for (j=0; j<n; j++){
    		fprintf(dataimplicito, "%f %f %f", t[i], x[j],m_result[i][j]);
    		fprintf(dataimplicito, "\n");
		}
	}
	fclose(dataimplicito);
	// ******************************************************************************************************
	
	
	//Librando memoria
	for (i=0;i<n;i++){
		free(m_result[i]);
  }
	
	free(m_result);

    for (i=0;i<n;i++){
		free(matrix[i]);
	}
	free(matrix);
	
    for (i=0;i<n;i++){
		free(matrixq[i]); } 
	free(matrixq);
	free(x);
	free(t);
	
	//*************************************************************************************************************
  return 0;
}
//*****************************************************************************************************************

// definición de la función q
double funcion(double x, double t){
		return cos(M_PI*t)*sin(2*M_PI*x);
	}
#include "tools.h"

double q(double x, double t);
double T0(double x);
double Ta(double t);
double Tb(double t);

int main(void){

  double *x=NULL, *t=NULL; //Vectores posición y tiempo, respectivamente
	int i,j,n=100,tMax=1,m=10001; //i,j utilizados para recorrer vectores y matrices; n son las subdivisiones del eje de posiciones; t son las subdivisiones del eje de tiempo

  //tMax es el límite superior del intervalo del eje del tiempo para resolver la EDP, este puede ser modificado

	double dx=0.01, dt=0.00005;
	double **T = GeneraMatriz(n,m);	//Matriz solución

  
  x = (double*)malloc(n*sizeof(double)); //x \in [0,1]
  t = (double*)malloc(m*sizeof(double));

  //Discretización de espacio y tiempo:
  //Modificar vector posición
  x[0] = 0;
	x[n-1] = 1;
	for(i=1; i<n-1; i++){
      	x[i]=x[i-1]+dx;
	}

  //Modificar vector tiempo
  t[0] = 0;
	t[m-1] = tMax;
	for(j=1; j<m-1; j++){
      	t[j]=t[j-1]+dt; 
	}

  //Establecer condiciones iniciales y de frontera
  for (i=0; i<n; i++){
		T[i][0] = T0(x[i]);
	}

  for (j=0; j<m; j++){
		T[0][j] = Ta(t[j]);
	}

	for (j=0; j<m; j++){
		T[n-1][j] = Tb(t[j]);
	}


  //Método explícito de Euler

  for (j=0;j<m-1;j++){
    for (i=1;i<n-1;i++){
      T[i][j+1]=(1-2*dt/(dx*dx))*T[i][j]+(dt/(dx*dx))*T[i-1][j]+(dt/(dx*dx))*T[i+1][j]+dt*q(x[i],t[j]);
    }
  }
  

   
  //Registro de datos para gráficas: Creación de archivo
  FILE *eulerExp = fopen("datosEE.txt","w");
  for (i=0;i<n;i++){
    for (j=(m-1)/5;j<m;j++){
      fprintf(eulerExp,"%f,%f,%f\n",x[i],t[j],T[i][j]);
    }
  } 
  fclose(eulerExp);


//Liberación de memoria
  
  for (i=0;i<n;i++){
    free(T[i]);
  }
  free(T);
  free(x);
  free(t);

  return 0;
}


// Funciones para condiciones iniciales y de de frontera

double q(double x, double t){
  return cos(M_PI*t)*sin(2*M_PI*x);
}

double T0(double x){
  return exp(x);
}

double Ta(double t){
  return 0;
}

double Tb(double t){
  return 0;
}


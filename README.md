# Problema de la ecuación de Calor: Método explícito e implícito 🚀
El contenido de este repositorio tiene la finalidad de brindar una solución numérica para resolver la ecuación de calor. Cada archivo tiene una funcionalidad distinta las cuales explicaremos a continuación. 📋
Empezamos describiendo nuestra librería conformada por los archivos: tools.c y tools.h
## tools.c 🛠️
Es una librería que tiene almacenada las siguientes funciones:
```python
GeneraMatriz() #Su función es generar una matriz dinámica, es decir, una matriz con memoria reservada.
MetodoJacobi() #Método de Jacobi para matrices, utilizado para resolver sistemas de ecuaciones de manera de iterativa.
ProductoMatrizVector() #Producto matriz-vector.
SumarVectores() #Suma de vectores.
```
## tools.h 📌
En este archivo se encuentran los encabezados de las funciones creadas en tools.c
## heatExp.c
Este archivo contiene la programación de la solución de la ecuación de calor aplicando el método explícito de Euler, usando la función que calcula el producto Matriz-vector.
## heatImplicito.c
En este archivo se tiene el programa principal del desarrollo de la solución de la ecuación de calor aplicando el método implícito, se hizó uso del método de Jacobi, el cual resuelve sistemas de ecuaciones lineales de manera iterativa.
## makefile

### Instrucciones:

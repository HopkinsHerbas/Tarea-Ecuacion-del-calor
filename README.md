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
## tools.h :hammer:
En este archivo se encuentran los encabezados de las funciones creadas en tools.c
## heatExp.c :fire: :hotsprings:	
Este archivo contiene la programación de la solución de la ecuación de calor aplicando el método explícito de Euler, usando la función que calcula el producto Matriz-vector.
## heatImplicito.c :fire: :hotsprings:	
En este archivo se tiene el programa principal del desarrollo de la solución de la ecuación de calor aplicando el método implícito, se hizó uso del método de Jacobi, el cual resuelve sistemas de ecuaciones lineales de manera iterativa.
## makefile :person_in_tuxedo:
El programa se va a ejecutar en este archivo, aquí llamamos a los objetos para encontrar la solución de la ecuación de calor por medio de los métodos.
### Instrucciones: :straight_ruler:	
1.- Descargar Archivos:
* Damo click en la opción Code y luego pulsamos el botón "Download ZIP". Recuerden descomprimir los archivos en la carpeta o directorio donde usted trabaja.

2.-Compilar y ejecutar en el entorno que sea de su gusto.

## Expresiones de Gratitud 🎁
* Invite un café ☕ a alguien del equipo en muestra de agradecimiento :clown_face:. 
* Da las gracias públicamente 🤓.

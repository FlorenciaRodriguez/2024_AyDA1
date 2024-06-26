# Programación Dinámica

La programación dinámica resuelve problemas combinando soluciones parciales de subproblemas. Esta técnica se aplica cuando los subproblemas se superponen, es decir, cuando los subproblemas comparten subsubproblemas; a diferencia de
la técnica divide y conquista que divide el problema en subproblemas separados, resuelve los subproblemas de forma recursiva y luego combina sus soluciones para resolver el problema original. De hecho, la técnica programación dinámica es aplicada a situaciones de solapamiento de subproblemas, en cambio, un algoritmo de divide y conquista resuelve reiteradas veces los subsubproblemas que se repiten.

En general, la programación dinámica se aplica a problemas que requieren soluciones algoritmicas de gran costo computacional. Mediante esta técnica, la solución óptima a un problema puede ser definida mediante soluciones óptimas a subproblemas de menor tamaño.
En otras palabras, la técnica permite resolver problemas a partir de la combinación de la solución de subproblemas idénticos al original y que, en general, tienen una *sub-estructura óptima*. 

La programación dinámica utiliza un enfoque _botton-upp_ para obtener la solución: 

i. primero calcula la solución óptima de cada subproblema.

ii. utilizando dichas soluciones, encuentra soluciones a problemas de mayor tamaño.


Para evitar repetir calculo, usualmente se utiliza una matriz que se llena conforme las soluciones a los subproblemas son calculados. 
Antes de resolver un subproblema *Q*, se chequea en la matriz para ver si ya se resolvió. Si no se resolvió, se resuelve. Si ya está resuelto, se recupera la solución, evitando recalcular. Antes de devolver la solución de *Q*, ésta se guarda.


## Pasos para desarrollar un algoritmo basado en programación dinámica

1. Caracterizar la estructura de una solución óptima.
   
2. Definición de la solución optima. Definir el calculo de la solución óptima en función de valores de soluciones para subproblemas de tamaño menor.
   
3. Calcular el valor de la solución óptimal utilizando un enfoque descendente:
   
   - Determinar el conjunto de subproblemas distintos a resolver (tamaño de la tabla)
     
   - Identificar sub problemas con solución trivial.
     
   - Obtener los valores con un enfoque ascendente y almacenar los valores que vamos a calculando en la tabla.
     
   - En estapas posteriores se utilizarán los valores previamente calculados.
     
4. Construir solución óptima a partir de la información previamente calculada.

## Principales elementos de la programación dinámica

### Subestructura óptima

El primer paso para resolver un problema de optimización mediante programación dinámica es caracterizar la estructura de una solución óptima. 
Un problema presenta una subestructura óptima si una solución óptima al problema contiene soluciones óptimas a los subproblemas.

> *Principio de optimalidad de Bellman*: la solución óptima  cualquier instancia no trivial de un problema es una combinación de soluciones ótpimas de las sub-instancias

<!--
Se podría definir una serie de pasos para ayudar a descubrir la subestructura óptima: 
1. Una solución al problema consiste en hacer una elección, como elegir un índice en el cual dividir la cadena de la matriz. Hacer esta elección deja uno o más subproblemas por resolver.
2. Se supone que, para un problema determinado, tenemos "la opción" que conduce a una solución óptima. No se sabe aún cómo determinar esta elección. Simplemente asumimos que está.
3. Dada esta "opción", determinar qué subproblemas surgen y cómo caracterizar mejor el espacio de subproblemas resultante.
4. Mostrar que las soluciones a los subproblemas utilizadas dentro de una solución óptima al problema deben ser óptimas mediante el uso de una técnica de _cortar & pegar_. Para ello, supongamos que cada una de las soluciones de los subproblemas no es óptima; entonces tenemos que llegar a una contradicción.
En particular, al "cortar" la solución no óptima de cada subproblema y "pegar" la óptima, demuestra que puede obtener una mejor solución al problema original, contradiciendo así la suposición de que ya tenía una solución óptima. Si una solución óptima da lugar a más de un subproblema, normalmente son tan similares que se puede modificar el argumento de cortar y pegar para que uno se aplique a los demás con poco esfuerzo.
-->
### Subproblemas superpuestos 

El espacio de los subproblemas debe ser "pequeño" en el sentido de que un algoritmo recursivo para el problema resuelve los mismos subproblemas una y otra vez, en lugar de generar siempre nuevos subproblemas. Normalmente, el número total de subproblemas distintos es un polinomio en el tamaño de entrada. Cuando un algoritmo recursivo revisa el mismo problema repetidamente, decimos que el problema de optimización tiene subproblemas superpuestos.
El enfoque de divide y conquista genera nuevos problemas en cada paso. En cambio, los algoritmos de programación dinámica aprovechan esta superposición resolviendo cada subproblema una vez y luego almacenando la solución parcial en una tabla donde se puede consultar cuando sea necesario, utilizando un tiempo constante para buscar.

### Reconstrucción de la solución óptima 

Como cuestión práctica, a menudo almacenamos en una tabla separada la "elección" que se hizo en cada subproblema para no tener que reconstruir esta información a partir de la tabla de costos.

### Memorización 

Se mantiene una tabla con soluciones de subproblemas, donde cada entrada de la tabla almacena la solución de cada subproblema. Inicialmente, cada entrada de la tabla contiene un valor especial para indicar que el subproblema aún no se ha procesado. Cuando el subproblema se encuentra por primera vez, la solución se calcula y luego se almacena en la tabla.

# Bilbliografía

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). _Introduction to algorithms_. MIT press.
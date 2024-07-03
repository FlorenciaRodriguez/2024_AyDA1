# Divide y conquista

El método divide y conquista es una estrategia para diseñar algoritmos.

Mediante esta técnica se resuelve un problema determinado (instancia) de forma recursiva. Si el problema es lo suficientemente pequeño (el caso base), simplemente lo resuelve directamente. De lo contrario, en el caso recursivo, se realizan tres pasos característicos:

1. Dividir el problema en uno o más subproblemas que sean instancias más pequeñas del mismo problema.

2. Conquistar los subproblemas resolviéndolos recursivamente.

3. Combinar las soluciones de los subproblemas para formar una solución al problema original.

Un algoritmo de divide y conquista divide un problema grande en subproblemas más pequeños, que a su vez pueden ividirse en subproblemas aún más pequeños, y así sucesivamente. La recursividad termina cuando llega a un caso base y el subproblema es lo suficientemente pequeño como para resolverlo directamente sin seguir con la recursión (cuando se llega al caso base).

<!--
## Recurrencia

Para analizar algoritmos recursivos de divide y conquista, necesitaremos algunas herramientas matemáticas. Una recurrencia es una ecuación que describe una función en términos de su valor en otros argumentos, normalmente más pequeños. Las recurrencias van de la mano con el método de divide y conquista porque nos brindan una forma natural de caracterizar matemáticamente los tiempos de ejecución de los algoritmos recursivos.

La forma general de una recurrencia es una ecuación o desigualdad que describe una función sobre números enteros o reales utilizando la función misma. Contiene dos o más casos, según el argumento. Si un caso implica la invocación recursiva de la función en diferentes entradas (normalmente más pequeñas), es un caso recursivo. Si un caso no implica una invocación recursiva, es un caso base. Puede haber cero, una o muchas funciones que satisfagan la declaración de recurrencia. La recurrencia está bien definida si hay al menos una función que la satisface, y mal definida en caso contrario.

-->

## Mergesort

El algoritmo mergesort es el clásico ejemplo de ul algoritmo de divide y conquista. Dado un arreglo, en cada paso, ordena un subarreglo, comenzando por el arreglo completo y llamando recursivamente con subarreglos cada vez más pequeños. Así es como funciona el ordenamiento:

1. Dividir el subarreglo en dos subarreglos adyacentes, cada uno de la mitad del tamaño. Para hacerlo, calcular el punto medio.

2. Conquista ordenando cada uno de los dos subarreglos de forma recursiva mediante ordenación por combinación.

3. Combinar fusionando los dos subarreglos ordenados nuevamente en el más grande, produciendo el arreglo ordenada

La recursividad _bottoms out_ llega al caso base cuando el subarreglo a ordenar tiene solo 1 elemento: un subarreglo que comprende un solo elemento siempre está ordenado. 

La operación clave del algoritmo ocurre en el paso de combinar, que fusiona dos subarreglos ordenados adyacentes. La operación de fusión se realiza mediante un procedimiento auxiliar. El procedimiento supone que los subarreglos adyacentes ya estaban ordenados recursivamente. Combina los dos subarreglos ordenados para formar un único subarreglo ordenado que reemplaza el subarreglo actual.

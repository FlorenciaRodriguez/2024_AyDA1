# Pila

Una pila es una estructura lineal tal que las inserciones, las consultas y las eliminaciones solo se permiten en un único punto. La pila puede no tener nada, situación que se denomina pila vacía.

En una pila, el elemento eliminado es el que se insertó más recientemente: la pila implementa una política de último en entrar, primero en salir o LIFO. De manera similar, en una fila, el primero en entrar es el primero en salir (FIFO). Hay varias formas eficientes de implementar pilas y filas. 

Se puede usar un arreglo, teniendo en cuenta que las inserciones y los borrados ocurren sólo en la parte superior.
También se puede hacer una secuencia enlzada de nodos, insertando y borrando elementos al principio de la secuencia.

## Especificación formal

```
CLASS Pila [Elemento]
BASIC CONSTRUCTORS inicPila, apilar
EFFECTIVE
TYPES Pila
FUNCTIONS
inicPila: -> Pila
apilar: Pila x Elemento -> Pila
vaciaPila: Pila -> Boolean
topePila: Pila (p) -> Elemento
            pre: not vaciaPila (p)
desapilar: Pila (p) -> Pila 
             pre: not vaciaPila (p)
AXIOMS p:Pila; e: Elemento
vaciaPila (inicPila) = True
vaciaPila (apilar (p,e) ) = False
topePila (apilar (p, e) ) = e
desapilar (apilar (p, e)) = p
END-CLASS
```

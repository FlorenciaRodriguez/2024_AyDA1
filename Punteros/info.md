## Organización del programa en memoria
En memoria se almacenan los diferentes valores que se generan al ejecutar un programa. Cuando ejecutamos un programa, nuestro sistema operativo le asigna un proceso con algo de memoria principal, llamada _memoria virtual_, donde ejecutarse.
Para cada programa en la memoria principal se carga:
1. Instrucciones del programa. Las instrucciones que sigue el procesador para ejecutar el programa. Tambien se llama segmento de código. Es de solo lectura.
2. Datos: contiene la inicializacion de las variables estáticas, golbales y estáticas locales. Esta memoria es administrada por el **sistema**.
3. Heap: Contiene memoria reservada dinámicamente por el **programador**. No tiene un tamaño fijo, es decir que la cantidad de memoria del _heap_ puede variar durante la ejecución del programa.
4. Stack: pila de llamadas (_call stack_). Donde se almacenan los argumentos pasados al programa, argumentos de las funciones, variables locales no inicializadas, registro de llamada de funciones y el retorno. Administrada por el **sistema**.

## Memoria
- La memoria se organiza como un conjunto de _celdas_, cada una de ellas contiene una cadena de ceros y unos. Cada elemento de la cadena (0 ó 1) se llama bit (b).
- En casi todas las computadoras, las celdas de memoria contienen ocho bits, que equivale a 1 byte (B).
- Cada celda de la memoria se identifica por su dirección, a través de un número hexadecimal. Dentro de cada celda se guarda un valor.
- Los diferentes tipos usados en los programas ocupan diferente cantidad de bytes. La memoria se agrupa en bloques.
- El bloque de memoria necesario para almacenar un valor asociado a un tipo, dado que necesitará de una determinada cantidad de celdas y una determinada disposición de éstas.

## Acceso a memoria
- El nombre que le asignamos a las variables se traduce en la dirección de memoria donde está almacenado el valor de esa variable.
- La lectura de una variable consiste en enviar a la memoria los bits que codifican la dirección, y la memoria devuelve los ocho bits que corresponden al valor. 
- La operación de escritura consisten en enviar a la memoria los bits que codifican una dirección (nombre de la variable) y ocho bits de datos con el valor, y éstos últimos se almacenan en la dirección especificada.

## Punteros
- Los punteros (o apuntadores) son variables que se utilizan para almacenar direcciones de memoria. 
- Se puede declarar un puntero para almacenar la dirección de memoria correspondiente a una variable de tipo primitivo, es decir, se puede "apuntar" un puntero a la variable. 
- Para apuntar un puntero a una variable se utilizan el operador de asignación =, el operador & y la variable a la que se quiere apuntar. 
- El tipo de dato del puntero debe ser obligatoriamente el mismo tipo de dato de la variable a la que se pretende apuntar.
Ejemplo:

```C++
int var = 14; 
int *ptr_var = &var;
cout << "Direccion donde esta var: " <<ptr_var; 
cout << "Valor almacenado en var: " << *ptr_var;
cout << "Direccion donde esta ptr_var: " << &ptr_var;	
```
> [!Note]
> Stack: memoria que es administrada por el **sistema**.
> 
> Heap: memoria que es administrada por el **programador** (_memoria dinámica_, que no es lo mismo que _programación dinámica_). 

## Memoria dinámica

- Los datos en el heap existen mientras el programador no los elimine.
- Cuando no necesitemos más la información deberemos vaciar el espacio utilizando la palabra reservada `delete`, haciendo que el programa devuelva la memoria al sistema operativo.
`delete ptr_var`; 
- Se sugiere que luego le asignamos el puntero `nullptr` para indicar en el código un reseteo.
`ptr_var = nullptr;`

También podemos usar los punteros para obtener bloques contiguos de memoria. En ese caso el puntero guardará en el _stack_ la dirección de la primera celda del bloque. Es una referencia al _heap_ (notemos que fue creada con `new`).
```C++
int * ptr_block = new int[4]; // crea variable entera ptr_block en el stack. en el heap reserva 4 espacios contiguos para 4 enteros. en ptr_block se guarda la dirección del heap que contiene el primer bloque.
*ptr_block  = {11, 22, 44, 55}; // dentro de los bloques del heap asigna los valores {11, 22, 44, 55}
*ptr_block[2] = 10; // cambia el 44 por el 10
*(ptr_block + 2) = 70; // cambia el 10 por 70
delete [] ptr_block: // libera la memoria del heap
ptr_block = nullptr; // para que ptr_block no quede referenciando una dirección inválida
```

## Arreglos
- Cuando declaramos un arreglo, el arreglo se encuentra en el _stack_.
- Los conceptos de arreglo y puntero en el lenguaje C++ están íntimamente ligados.
- El nombre del arreglo es un puntero a la dirección de memoria del **stack** en la que se encuentra el primer elemento del arreglo.
- Al ser un puntero, cuando pasamos un arreglo como parámetro en una función, se pasa por referencia (en realidad se copia el puntero).
- Si queremos evitar modificaciones, podemos usar la palabra `const`.

```C++
  void inicializarArreglo(char arreglo[],unsigned int tamano) {
    for (int i = 0; i < tamano; ++i) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

void mostrarArreglo (const char arreglo[], unsigned int tamano) {
    cout << "El arreglo ingresado es: ";
    for (int i = 0; i < tamano; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
```

## Diferencias entre heap y stack
- Velocidad de acceso: la memoria del stack es de más rápido acceso en comparación con las del heap.
- Límite de tamaño: la memoria del stack se define antes de comenzar a ejecutar el programa (limitada), la del heap no.
- Redimensión: en el heap, la cantidad de bloques asignados a un puntero puede cambiar durante la ejecución. Si almacenamos nuestro arreglo en el stack (arreglo semiestatico), este tiene el mismo número de bloques asignados durante toda la ejecución del programa.
¿Cuándo utilizar el heap y cuando el stack?
No hay una arregla general, pero se recomienda usar el _heap_ cuando se necesita asignar un gran bloque de memoria, por ejemplo, o una estructura demasiado grande para mantener una variable durante mucho tiempo.
El _stack_ es mejor utilizarlo cuando se trabaja con variables relativamente pequeñas que solo se requieren mientras una función está viva, debido a que provee un acceso más fácil y rápido.

# Tipo de dato

Un tipo de datos define un conjunto de valores y las operaciones sobre esos valores. Existen los tipos de datos estructurados y los tipos de datos abstractos.

- Tipos de datos estructurados. Para estos tipos de datos se crea una estructura que los almacena. Sirven para dar solución a un problema específico.

- Tipos de datos abstractos. Tienen una semántica definida a través de una estructura y el comportamiento porpio del tipo de dato abstracto (TDA). Son creados por el programador. Se accede a ellos a tráves de representaciones. El conjunto de operaciones o funciones responde al tipo de dato abstracto y son accesibles para los usuarios. La estructura y la implementación en independiente del TDA y no debería ser visible al usuario.

# Tipos de datos abstractos

Formalmente, un TDA es un modelo matemático con una serie de operaciones definidas sobre ese modelo. Un ejemplo de TDA son los conjuntos de números enteros con las operaciones de unión, intersección y diferencia (TDA Conjunto).

Una vez definido un TDA, éste se puede utilizar como si fuese un tipo de dato primitivo, sin preocuparse por cual sea su implementación.

A grandes rasgos, tenemos dos tipos de TDAs, los TDAs simples, como los tipos primitivos, y los TDAs contenedores, como por ejemplo las colecciones, listas, filas, arreglos, árboles.

Un TDA debe tener pocas operaciones, bien definidas y precisas. Se debe fijar si son contenedores o simples; el tamaño (size).

Respecto a la estructura, antes de analizar si la elegida es adecuada o no, hay que chequear si es necesario un tipo genérico. Por ejemplo, el TDA Lista debería poder permitir hacer lista de arreglos, lista de matrices, lista de números, lista de caracteres, etc.; así que debe necesitar un tipo genérico, debe ser parametrizada.

## Especificaciones algebraicas

El álgebra tienen una representación y un conjunto de operaciones que trabajan sobre esa representación; eso hace que el álgebra sea similar al TDA. Para los TDAs usamos álgebras heterogeneas, las cuales nos sirven para las relaciones con otros TDAs.

Una especificación formal da el _nombre_ del tipo junto con el _dominio_ donde tomarán valores las entidades del TDA, la _sintaxis_ (conjunto de operaciones del tipo, operaciones o funciones que tienen un dominio y una imagen) y la _semántica_ (el comportamiento, definido a tráves de fórmulas). La semántica se describe por medio de axiomas: lógica de predicado de primer orden, recursividad.

### Dominio de un TDA

Si el dominio es finito y pequeño, éste puede ser enumerado. Por ejemplo, el dominio del tipo booleano es {true, false}.

Se puede hacer referencia a un dominio conocido de objetos matemáticos. Por ejemplo, el conjunto de los números negativos.

Se puede definir constructivamente. Enumerando unos cuantos miembros básicos del dominio y proporcionando reglas para generar o construir los miembros restantes a partir de los enumerados.

Ejemplo. Dominio de las cadenas de caracteres:

1. Cualquier letra es una cadena.

2. Cualquier cadena seguida de una letra es una cadena.

Este tipo de definiciones se llama también definiciones recursivas, ya que hacen referencia a los elementos del dominio definido para crear nuevos elementos.

### Especificación sintáctica de un TDA

Consiste en determinar como hay que escribir las operaciones de un TDA, dando el tipo de operandos y el resultado.

El tipo entero se puede especificar sintácticamente, enumerando las siguientes operaciones:

´´´

+ : entero x entero -> entero

- : entero x entero -> entero

> : entero x entero -> boolean

abs: entero -> entero
´´´
### Especificación semántica de un TDA

Para un TDA se dan definiciones para llegar a su implementación. Hay tres maneras de definir un TDA:

- especificiación de manera informal, a través de lenguaje natural

- especificación formal, usando lenguajes formales para garantizar que no hay ambiguedad (lenguajes algebraicos, BNF, lenguajes lógicos).

- modelos abstractos, describiendo el dominio de un tipo en términos de otro tipo y, entonces, usar las operaciones del segundo tipo para describir las operaciones del que estamos definiendo.

En la especificación semántica de cada operación se usa:

- un lenguaje matemático 

- precondiciones y postcondiciones 

La precondición es la condición previa para poder aplicar una operación y la postcondición especifica el resultado de la operación. Bajo el cumplimiento de las precondiciones, se podrá ejecutar la operación y tras su ejecución se debe cumplir la postcondición.

No se afirma nada en el caso de que no se cumplan las precondiciones, puede dar un resultado indeterminado o error.
Lo ideal es que diese error advirtiéndose de esta forma el mal uso de la operación.

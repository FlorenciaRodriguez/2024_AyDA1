# Triangulación minimal de polígonos convexos

[Explicación previa](https://github.com/FlorenciaRodriguez/2024_AyDA1/tree/main/Dinamica#readme)


Dados los vértices de un polígono convexo se trata de seleccionar un conjunto de cuerdas (líneas entre vértices no adyacentes) de modo que ningún par de cuerdas se cruce entre sí y que todo el polígono quede dividido en triángulos. Además, la longitud total de las cuerdas debe ser mínima (triangulación minimal).

Utilidad: se puede emplear para sombrear objetos tridimensionales en una imagen virtual (bidimensional).

![Posibles triangulaciones para un polígono P](img/img1.png)

- Tenemos un polígono P definido como un conjunto de N vértices ordenados en sentido antihorario P = <v<sub>0</sub>, v<sub>1</sub>, \... , v<sub>n-1</sub>>

- En toda triangulación de un polígono de más de 3 vértices, cada par de vértices adyacentes es tocado al menos por una diagonal. Si v<sub>i</sub> y v<sub>j</sub> no son adyacentes, entonces el segmento v<sub>i</sub>; v<sub>i</sub> es una cuerda.
  
- Si v<sub>i</sub> y v<sub>j</sub> definen una diagonal (v<sub>i</sub>, v<sub>j</sub>) debe existir un v<sub>k</sub> / (v<sub>i</sub>,v<sub>k</sub>) y (v<sub>k</sub>,v<sub>j</sub>) son lados o diagonal (i, j, k < N && v<sub>i</sub>, v<sub>j</sub>, v<sub>k</sub> ∈ P)
  
- Si v<sub>i</sub> y v<sub>j</sub> son lados del poligono, la distancia es cero.
  
## Subestructura óptima

Sea S<sub>i,s</sub> el subproblema de tamaño s partiendo del vértice v<sub>i</sub>, es decir, el problema de la triangulación
minimal del polígono formado por los s vértices que comienzan en v<sub>i</sub> y siguen en el sentido de las agujas del reloj (v<sub>i</sub>, v<sub>i+1</sub>, \..., v<sub>i+s-1</sub>), contando con la cuerda (v<sub>i</sub>,v<sub>i</sub>).

![Polígono P con cuerda v6;v5](img/img2.png)

Ahora, para triangular el polígono S<sub>i,s</sub>, hay tres posibilidades: 

![Posibles cuerdas para P luego de añadir cuerda v6;v5](img/img3.png)

a) Tomar el vértice v<sub>i+1</sub> para formar un triángulo con las cuerdas (v<sub>i</sub>,v<sub>i+s-1</sub>) y (v<sub>i+1</sub>,v<sub>i+s-1</sub>) y con el tercer lado (v<sub>i</sub>,v<sub>i+1</sub>), y después resolver el subproblema S<sub>i+1,s-1</sub>. 

b) Tomar el vértice v<sub>i+s-2</sub> para formar un triángulo con las cuerdas (v<sub>i</sub>,v<sub>i+s-1</sub>) y (v<sub>i</sub>,v<sub>i+s-2</sub>) y con el tercer lado (v<sub>i+s-2</sub>,v<sub>i+s-1</sub>), y después resolver el subproblema S<sub>i,s-1</sub>. 

c) Para algún k entre 2 y s-3, tomar el vértice v<sub>i+k</sub> y formar un triángulo con lados (v<sub>i</sub>,v<sub>i+k</sub>), (v<sub>i+k</sub>,v<sub>i+s-1</sub>) y (v<sub>i</sub>,v<sub>i+s-1</sub>), y después resolver los subproblemas S<sub>i,k+1</sub>y S<sub>i+k,s-k</sub>.

Por tanto, si denotamos por C<sub>i,s</sub> el coste de la triangulación S<sub>i,s</sub>, se obtiene la siguiente formula: 

C<sub>i,s</sub>= min<sub>1≤k≤s−2</sub>C<sub>i,k+1</sub> +{ C<sub>i+k,s-k</sub> +D(v<sub>i</sub> ,v<sub>i+k</sub>) +D(v<sub>i+k</sub> ,v<sub>i+s-1</sub>)}
para 0≤i≤N-1, 4≤s≤N; 

donde: D(v<sub>p</sub>,v<sub>q</sub>) es la longitud de la cuerda entre los vértices v<sub>p</sub> y v<sub>q</sub>


si v<sub>p</sub> y v<sub>q</sub> no son vértices adyacentes en el polígono P; y D(v<sub>p</sub>,v<sub>q</sub>) es 0 si v<sub>p</sub> y v<sub>q</sub> son adyacentes. Además, C<sub>i,s</sub> = 0 para 0≤i≤N-1, 2≤s<4.

### Subproblemas superpuestos 

Los subproblemas se superponen porque el cálculo de la triangulación mínima de un subpolígono de v<sub>i</sub> a v<sub>j</sub> puede requerir resolver los mismos subproblemas múltiples veces.

### Reconstrucción de la solución óptima 

Utilizamos matrices para reconstruir la solución óptima.

## Seguimiento para el polígono dado (hasta s = 5, i =2)

![](img/img4.png)

![](img/img5.png)

![](img/img7.png)

![](img/img6.png)



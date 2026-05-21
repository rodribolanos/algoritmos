# Indicaciones

- Resolver cada ejercicio en C++ o Python en un único archivo llamado `apellido-<i>.cpp` (C++) o `apellido-<i>.py`, donde `<i>` denota el número de ejercicio.
- Cada ejercicio tiene un limite temporal de un segundo y un límite espacial de 512MB de memoria para su ejecución.
- Subir el archivo en el campus en la entrega correspondiente y avisar de su actualización a los profesores.
- Los profesores ejecutarán un test de caja negra (juez) para reportar el resultado de la ejecución (aprobado, resultado erroneo, tiempo o memoria excedida, error de formato).
- Se puede reentregar el mismo ejercicio todas la veces que sean necesarias hasta obtener el aprobado o hasta que se termine el tiempo del examen.

Fundamental: en el caso en que el estilo de código sea muy diferente al usual de la universidad, los profesores pueden solicitar una defensa oral instantánea del código.  En caso de no poder defender el codigo se supondrá que el mismo fue generado con herramientas externas y el parcial será considerado desaprobado en forma instantánea.

Se deja constancia de que se puede utilizar cualquier snippet de código visto en clase **sin modificaciones** y los profesores no indagaran sobre dicho código.  En el caso en que algún snippet fuera cambiado, los profesores pueden solicitar la justificación de los cambios.

# Ejercicio 1

Dada un multiconjunto $X = \{x_0, \ldots, x_{n-1}\}$ de números entre $0$ y $100$, retornar un *prime ring* formado únicamente por elementos de $X$ y cuya longitud sea máxima.  Recordar que un *prime ring* es una secuencia circular $y_0, \ldots, y_{k-1}$ tal que $y_i + y_{i+1}$ es primo para todo $0 \leq i < k$ (donde el índice $i+1$ se interpreta módulo $k$). Consideramos que la secuencia vacía es un prime ring de longitud 0.

**Ayuda:** los números primos hasta el 200 en código C++ son:

```
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
```

mientras que en código Python son:

```
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]
```

## Input

El número $n \leq 20$ seguido de los $n$ números que pertenecen al conjunto.

## Output

La cantidad de elementos del *prime ring* seguido de los elementos que lo componen.  En caso en que existan múltiples *prime rings* de máxima longitud, debe reportar el que sea lexicográficamente mínimo.

## Ejemplos

```
Input:
1
4

Output:
0

Input:
1
1

Output:
1


Input:
6
1 2 3 4 5 6

Output:
6
1 4 3 2 5 6

Input:
6
6 5 4 3 2 1

Output:
6
1 4 3 2 5 6

Input:
4
1 2 3 5

Output:
2
2 5
```

# Ejercicio 2

Un supermercado ofrece un descuento del 20% por pagos con QR hasta un tope de gasto de $k$ pesos.  Para aprovechar el descuento al máximo, puede ser conveniente para una pareja dividir la compra en dos.  Escribir un programa para indicar cómo conviene separar los productos para la compra.

## Input

La primera linea contiene la cantidad $n$ de productos a comprar seguido del monto máximo de gasto $k$.  La segunda linea contiene el precio de los $n$ productos separados por espacios.  Se sabe que cada producto tiene un precio entero y que $nS/2 < 10^7$ donde $S$ es la suma de los precios de los productos.

## Output

Una linea conteniendo el costo total de la compra multiplicado por $10$, seguido de una linea que indica la cantidad de productos de la primera compra junto con el precio de cada producto comprado.  En caso de que hayan múltiples soluciones puede reportar cualquiera de ellas.

## Ejemplos

```
Input:
3 10
5 6 4

Output:
120
1 5

Input:
3 10
11 4 5

Output:
162
1 11

Input:
4 10
7 6 8 5

Ouput:
220
2 7 6

Input:
6 100
33 33 40 40 40 33

Output:
1790
3 33 33 40
```

# Ejercicio 3

Escribir un programa que, dada una matriz $M$ de números enteros con $m$ filas y $n$ columnas, encuentre el camino de suma mínima que empieza en la entrada $M[0,0]$ y termina en la entrada $M[m-1,n-1]$ y se obtiene avanzando de cada entrada $[i,j]$ a una de las tres entradas $[i+1, j]$, $[i,j+1]$ o $[i+1,j+1]$ (es decir, dibujando la matriz en forma estándar, los movimientos permitidos consisten en bajar de fila, pasar a la columna de la derecha, o moverse en diagonal a la fila de abajo llegando a la columna de la derecha).

## Input

Los números $m$ y $n$ seguidos de $m$ reglones que contienen los $n$ números de cada fila de la matriz.  La primera entrada corresponde a la posición $[0,0]$ de la matriz.  Se sabe que $nm < 10^7$ y que el costo del camino mínimo entra en 64 bits.

## Output

El costo del camino mínimo.

## Ejemplos

```
Input:
3 1
5
4
2

Ouptut:
11


Input:
1 3
5 4 2

Output:
11

Input:
3 3
0 1 -3
4 -1 2
-1 -1 1

Output:
-1
```
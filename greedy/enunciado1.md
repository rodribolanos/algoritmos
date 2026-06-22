# Ejercicio 1

En un juego de defensa de plataformas, un jugador debe ubicar un conjunto de defensores en distintas plataformas para repeler un ataque. Cada plataforma se representa como un segmento horizontal en una grilla rectangular y no se superpone con ninguna otra.

Cuando un defensor se ubica en una plataforma, este puede defender de forma inmediata su propia plataforma y cualquier otra plataforma con la que comparta al menos una coordenada horizontal (columna), independientemente de la altura y de si existen plataformas en filas intermedias que compartan la misma columna. Por ejemplo, si un defensor se ubica en la plataforma A, que se extiende horizontalmente desde la posición $5$ hasta la $8$ en la altura $3$, entonces puede defender también un ataque a:

- La plataforma B que se extiende desde la posición $7$ hasta la $16$ en la atura $2$,
- La plataforma C  que se extiende desde la posición $3$ hasta la $9$ en la atura $1$, o
- La plataforma D que se extiende desde la posición $2$ hasta la $6$ en la altura $4$

Implementar un algoritmo para determinar la mínima cantidad de defensores que se necesitan ubicar en las plataformas

## Input

Un numero $n$ que indica la cantidad de plataformas, seguido de $n$ triplas de números $(a, b, c)$ que indica que hay una plataforma que va de $a$ hasta $b$ ($a < b$) en la altura $c$. Puede suponer que ninguna plataforma se superpone con otra y que los números $a$, $b$ de todas las plataformas son distintos.  Como restricción, $1 \leq n \leq 100000$ y $1 \leq a, b, c \leq 10^9$

## Output

La cantidad mínima de defensores necesarias para repeler un ataque a una única plataforma.  En el anteúltimo ejemplo, ubicamos un defensor en la plataforma $(3, 6, 2)$, que defiende tambien las plataformas $(1, 4, 1)$ y (5, 8, 1)$, y un defensor en la plataforma $(9, 12, 2)$ que defiende tambien a la plataforma $(7, 10, 3)$

## Ejemplos

```
Input:
1
1 2 1

Output:
1

Input:
2
1 2 1
3 4 1

Output:
2

Input:
3
1 5 1
2 6 2
3 7 3

Output:
1

Input:
5
1 4 1
3 6 2
5 8 1
7 10 3
9 12 2

Output:
2

Input:
5
1 4 1
3 6 2
5 8 1
7 10 3
9 12 2

Output:
2

```
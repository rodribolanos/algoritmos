# Teoría: Backtracking

Fuentes: Skiena cap. 7 · Laaksonen cap. 5 · Halim §3.2.2

---

### resumen teoría en clase:
permite explorar todas las posibles soluciones de un problema, descartando las que no sirven, incluso antes de terminar una rama
buscar solucion recorriendo el arbol, la "poda" de las ramas es trivial
backtracking es el nombre de las técnica, a veces no se poda nada, pero se hace *bracktracking* igual

- pensamos en problema como un arbol
- cada nodo es decisón
- cada camino posible solución
- ramas se descartan antes de completarse
- buscamos evitar recorrer todo, descartando inviables

## El paradigma

Backtracking construye la solución incrementalmente. En cada paso elige una opción, la agrega a la solución parcial, y si en algún momento la solución parcial no puede extenderse a una solución válida, **deshace** ese paso (backtrack) y prueba la siguiente opción.

```
backtrack(parcial):
    si es solución completa → registrar/imprimir
    para cada extensión posible e:
        si es_factible(parcial + e):
            agregar e a parcial
            backtrack(parcial + e)
            sacar e de parcial
```

La eficiencia depende casi completamente de cuán temprano se poda.

---

## Tipos de poda

### Poda de factibilidad
Cortar cuando la solución parcial viola alguna restricción. No tiene sentido seguir si ya sabemos que ninguna extensión será válida.
- Ejemplo: en N-reinas, si dos reinas se atacan → cortar.
- Ejemplo: en clique, si el nuevo vértice no es adyacente a todos los anteriores → cortar.

### Poda de optimalidad (branch & bound)
Cortar cuando la mejor solución posible a partir del estado actual no puede superar la mejor encontrada hasta ahora.
- Requiere calcular una **cota superior** del valor alcanzable desde el estado actual.
- Ejemplo: en max clique, `|parcial| + upper_bound(candidatos) <= mejor` → cortar.
- Ejemplo: en subset sum / CD, `valor_actual > N` → cortar.

Cuanto más ajustada la cota, más se poda. El costo de calcularla debe valer la pena.

---

## Representación del estado

Dos enfoques principales:

**Árbol binario** (incluir/no incluir):
- Cada nodo decide si un elemento entra o no.
- Natural para subconjuntos.
- Ejemplo: UVA 624 CD, Apple Division.

**Árbol de permutaciones** (elegir el siguiente):
- Cada nodo elige el próximo elemento de una permutación.
- Candidatos = elementos aún no usados.
- Ejemplo: N-reinas, Prime Ring, Dominoes.

---

## Ordenamiento de candidatos (Skiena / Halim)

El orden en que se exploran las ramas afecta fuertemente la eficiencia de la poda:
- Explorar primero las ramas más prometedoras eleva `best` rápido → poda más agresiva.
- En max clique: ordenar vértices por grado creciente pone los más conectados al final, que son los más prometedores.
- En backtracking de permutaciones: el "fail-first principle" sugiere probar primero los candidatos más restrictivos.

---

## Complejidad

El peor caso es exponencial: O(k^n) donde k es el factor de ramificación y n la profundidad. La poda no cambia el peor caso teórico, pero cambia drásticamente el comportamiento práctico.

Regla práctica (Halim): con poda bien implementada, backtracking es competitivo hasta n ≈ 20–30 para subconjuntos y n ≈ 10–12 para permutaciones.

---

## Problemas clásicos y sus podas clave

| Problema | Árbol | Poda clave |
|---|---|---|
| N-reinas / Bishops | permutación por fila | columnas y diagonales usadas (bitmask) |
| Prime Ring | permutación | suma con el anterior no es prima → cortar |
| Dominoes | permutación | extremo derecho no coincide con siguiente → cortar |
| Grid Paths | permutación (celdas) | conectividad: >2 transiciones libre↔bloq → cortar |
| Robots on Ice | ídem + checkpoints | distancia Manhattan + paridad → cortar |
| Apple Division | subconjunto | n≤20 → bitmask fuerza bruta (sin poda necesaria) |
| CD (UVA 624) | subconjunto | valor > N → cortar |
| Max Clique | subconjunto | upper_bound por coloreo greedy |

---

## Meet in the Middle (Laaksonen)

Cuando n ≤ 40 y O(2^n) es demasiado pero O(2^(n/2)) es viable:
1. Dividir los elementos en dos mitades.
2. Generar todas las soluciones parciales de cada mitad (2^(n/2) cada una).
3. Combinar eficientemente (ordenar + búsqueda binaria o two-pointer).

Útil para subset sum con n grande.

---

## Heurísticas (Skiena cap. 7 — solo referencia)

Para problemas NP-difíciles donde el backtracking exacto es inviable:
- **Simulated annealing**: acepta movimientos malos con probabilidad decreciente (escape de mínimos locales).
- **Algoritmos genéticos**: selección + crossover + mutación sobre una población de soluciones.

En competitive programming casi nunca se usan (los problemas tienen restricciones que permiten soluciones exactas o aproximadas determinísticas).

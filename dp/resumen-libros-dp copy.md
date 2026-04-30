# Teoría: Programación Dinámica

Fuentes: Cormen et al. cap. 15 · Skiena cap. 8

---

## El paradigma

DP aplica cuando el problema tiene:
1. **Subestructura óptima**: la solución óptima del problema contiene soluciones óptimas de sus subproblemas.
2. **Subproblemas solapados**: los mismos subproblemas se resuelven múltiples veces en la recursión ingenua.

La idea: resolver cada subproblema una sola vez y guardar el resultado.

---

## Memoización vs tabulation (bottom-up)

**Memoización (top-down):**
```cpp
map<estado, resultado> memo;
int solve(estado e) {
    if (memo.count(e)) return memo[e];
    // calcular resultado desde subproblemas
    return memo[e] = resultado;
}
```
- Natural de implementar: se escribe la recursión directa y se agrega el cache.
- Solo resuelve los subproblemas que realmente se necesitan.

**Tabulation (bottom-up):**
```cpp
vector<int> dp(n+1, 0);
for (int i = 1; i <= n; i++)
    dp[i] = f(dp[i-1], dp[i-2], ...);
```
- Llena una tabla en orden de subproblemas crecientes.
- Sin overhead de recursión. Más eficiente en tiempo y memoria en la práctica.
- Requiere saber el orden correcto de llenado.

---

## Cómo identificar que un problema es DP

- "Mínimo / máximo número de operaciones para..."
- "Cantidad de formas de..."
- "¿Es posible llegar a X?"
- La respuesta de un estado depende de respuestas de estados más pequeños.
- Fuerza bruta tiene subproblemas repetidos → DP los elimina.

---

## Problemas clásicos

### Coin Change — mínimo de monedas (CSES 1634)
```
dp[0] = 0
dp[i] = min(dp[i-c] + 1) para toda moneda c ≤ i
```
Complejidad: O(n * x)

### Coin Change — cantidad de formas
```
dp[0] = 1
dp[i] += dp[i-c]  para toda moneda c ≤ i
```

### Caminos en grilla (CSES 1638)
```
dp[0][0] = 1
dp[i][j] = dp[i-1][j] + dp[i][j-1]  si celda libre
```
Complejidad: O(n²)

### Edit Distance / Levenshtein (CSES 1639)
```
dp[i][0] = i,  dp[0][j] = j
dp[i][j] = dp[i-1][j-1]                          si s[i]==t[j]
         = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])  si no
```
Complejidad: O(|s| * |t|)

### Rectangle Cutting (CSES 1744)
```
dp[i][i] = 0
dp[i][j] = min sobre cortes v y h de (dp[v][j] + dp[i-v][j] + 1)
                                       (dp[i][h] + dp[i][j-h] + 1)
```
Complejidad: O(a*b*(a+b))

### Knapsack 0/1 (Skiena / Cormen)
```
dp[i][w] = max valor usando los primeros i items con capacidad w
dp[i][w] = max(dp[i-1][w],  dp[i-1][w-peso[i]] + valor[i])
```
Complejidad: O(n * W)

### Longest Common Subsequence (Cormen)
```
dp[i][j] = LCS de s[0..i-1] y t[0..j-1]
dp[i][j] = dp[i-1][j-1] + 1          si s[i-1]==t[j-1]
         = max(dp[i-1][j], dp[i][j-1])  si no
```
Complejidad: O(|s| * |t|)

### Longest Increasing Subsequence
```
dp[i] = largo del LIS que termina en i
dp[i] = 1 + max(dp[j]) para todo j < i con a[j] < a[i]
```
O(n²) con DP directo, O(n log n) con búsqueda binaria + patience sorting.

---

## Recuperar la solución (no solo el valor)

Guardar en cada celda la decisión tomada (`de dónde vengo`), luego reconstruir hacia atrás:
```cpp
// al calcular dp[i][j], guardar:
from[i][j] = {i-1, j};  // vino de arriba
// al terminar, hacer traceback desde dp[n-1][m-1]
```

---

## Optimización de memoria

Si solo se necesita el valor final (no la reconstrucción), muchas veces basta con mantener la fila anterior:
- Edit distance: de O(n*m) → O(min(n,m)) guardando solo dos filas.
- Coin change: O(x) en lugar de O(n*x).

---

## Subestructura óptima — por qué funciona (Cormen)

Para que DP sea correcto, la elección óptima para el problema completo debe componerse de elecciones óptimas para los subproblemas. Si esto no se cumple (hay dependencias cruzadas entre subproblemas), DP no aplica.

Contraejemplo clásico: camino más largo simple en un grafo con ciclos — no tiene subestructura óptima porque el camino más largo de A a C puede no pasar por el camino más largo de A a B.

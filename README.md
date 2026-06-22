# 💻 Algoritmos - UNQ
> Repositorio dedicado a la materia **Algoritmos** (Universidad Nacional de Quilmes).  
> **Ciclo:** 2026 - Primer Cuatrimestre (2026S1)

---

## 🛠 Compilación Sugerida
Para asegurar que tu código sea compatible con el **Juez Online** y evitar errores comunes, utiliza el siguiente comando en la terminal:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow algo.cpp -o programa



lower_bound: Busca el primer elemento que es mayor o igual (≥) al valor buscado.

upper_bound: Busca el primer elemento que es estrictamente mayor (>) al valor buscado

Si el valor buscado no existe en el contenedor, ambas funciones devuelven exactamente el mismo iterador: el del primer elemento mayor al buscado. Si todos los elementos son menores, ambas devuelven v.end()
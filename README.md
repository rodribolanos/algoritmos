# Algoritmos
Repositorio dedicado a la materia Algoritmos de la Universidad Nacional de Quilmes.
2026S1

Compilar programas:
g++ -std=c++17 -O2 -Werror -Wall -Wextra -Wpedantic -Wnull-dereference -Wlogical-op -Wduplicated-cond -Wshadow -Wconversion algo.cpp -o programa

-std=c++11 sirve para indicar qué versión del lenguaje se usa y es necesario para no usar aspectos del lenguaje posteriores a lo que acepta el juez para el problema
-O2 es para activar las optimizaciones que suele usar el juez online (tener en cuenta que elimina los símbolos de debug)
-Wall -Werror -Wshadow es lo mínimo que debería activarse en un código razonable; el resto es opcional.

Reemplazar algo.cpp por el archivo .cpp a compilar.
Reemplazar programa por el nombre que tendra el .exe

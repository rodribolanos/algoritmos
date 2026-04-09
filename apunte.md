Apunte sobre como generar, acceder y recorrer estructuras de datos en C++ y sus complejidades

Array

- Declaracion e inicializacion:

int notas[5];                    // Tamaño 5, valores basura.
int notas[5] = {10, 8, 9, 5, 7}; // Tamaño 5, inicializado.
int notas[] = {1, 2, 3};         // El compilador deduce tamaño 3.

crea un array de tipo tipo con la referencia nombre de tamanio n

recorrido con for de i = 0 a n haciendo nombre[i]. O(N)


Vector - Array dinamico
vector<tipo> referencia(n, p);

crea un array dinamico de tamanio n, con todos los valores seteados en p.

vector<tipo> referencia(n);

crea un array dinamico de tamanio n.

Operaciones y Complejidad:
    - Acceso: v[i] o v.at(i) -> O(1)
    - Insertar al final: v.push_back(valor) -> O(1) (amortizado)
    - Insertar al inicio/medio: v.insert(pos, valor) -> O(n)
    - Eliminar al final: v.pop_back() -> O(1)
    - Tamaño actual: v.size()

Recorrido:
for (auto it = v.begin(); it != v.end(); ++it) {
    *it accede al valor en la posicion
}

Recorrido del reves:
v.rbegin(): Apunta al último elemento real.
v.rend(): Apunta a la posición antes del primero.

for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " "; // Imprime el vector al revés
}


list - Lista doblemente enlazada
Necesario #include <list>
lista vacia
list<int> listaVacia;

lista con 1 elemento
list<int> unElemento = {10};
o
list<int> unElemento(1, 10);

lista con varios elementos
list<int> 3Elementos = {1, 2, 3};

Recorrido:
for (list<int>::iterator it = miLista.begin(); it != miLista.end(); ++it) {
    cout << *it << " "; // Accedemos al valor con el asterisco
}


Operaciones y Complejidad:
    - Busqueda: O(N)
    - Insercion al final. lista.push_back(x) O(1)
    - Insercion al principio. lista.push_front(x) O(1)
    - Eliminar el primero. lista.pop_front() 
    - Insertar en posicion. lista.insert(iterador, valor) O(1)

Iterador:
    - begin() devuelve un iterador al principio de la lista
    - end() devuelve un iterador a la posicion size de la lista (vacia)
    - insert
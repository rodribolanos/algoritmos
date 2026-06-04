#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


long cantPeliculas(vector<pair<long, long>>& peliculas, multiset<long>& personas) {
    long cantPeliculas = 0;

    for (pair<long, long> movie: peliculas) {

        auto bestTime = personas.upper_bound(movie.second);
        // si el primero es el mayor o igual, no hay nadie que la pueda ver
        if (bestTime != personas.begin()) {
            // si existe aumento peliculas y muevo los elementos
            cantPeliculas++; // aumento la cantidad de peliculas
            // a esta altura esta el correcto
            bestTime--;
            // actualizar el tiempo para respetar el invariante
            personas.erase(bestTime);
            // como peliculas esta ordenado, pusheo al final para seguir el invariante
            personas.insert(movie.first);    
        }
    }

    return cantPeliculas;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n, k; cin >> n >> k;
    // personas representa una cola con los tiempos donde terminan sus peliculas cada personas.
    // si hay 2 personas viendo una pelicula que termina en 5, y hay uno que no ve nada, la lista se vera 0 5 5
    multiset<long> personas;
    vector<pair<long, long>> movies(n);
    
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        // guardamos el fin primero para el ordenamiento lexicografico
        movies[i] = {b, a};
    }

    // ordenamos
    sort(movies.begin(), movies.end());

    for (int p = 0; p < k; p++) {
        // pusheamos k 0s como timepos de las personas
        personas.insert(0);
    }

    long cantidadPeliculas = cantPeliculas(movies, personas);
    

    cout << cantidadPeliculas;
    return 0;
}
#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

struct Pelicula {
    long end;
    long start;
    bool watched;

    // Default sorting logic: sort by price
    bool operator<(const Pelicula& other) const {
        if (end == other.end) {
            return start < other.start;
        } else {
            return end < other.end;
        }        
    }
};

long cantPeliculas(vector<Pelicula>& peliculas) {
    long limit = 0;
    long cantPeliculas = 0;

    for (Pelicula movie: peliculas) {
        if (!movie.watched && movie.start >= limit) {
            limit = movie.end;
            movie.watched = true;
            cantPeliculas++; 
        }
    }

    return cantPeliculas;
}

int main() {
    long n, k; cin >> n >> k;

    vector<Pelicula> movies(n);

    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        // guardamos el fin primero para el ordenamiento lexicografico
        movies[i] = {b, a, false};
    }

    // ordenamos
    sort(movies.begin(), movies.end());

    long cantidadPeliculas = 0;
    for (int i = 0; i < k; i++) {
        cantidadPeliculas += cantPeliculas(movies);
    }

    cout << cantidadPeliculas << "\n";
    return 0;
}
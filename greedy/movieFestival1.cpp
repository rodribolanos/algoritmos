#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n; cin >> n;

    vector<pair<long, long>> movies(n);

    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        // guardamos el fin primero para el ordenamiento lexicografico
        movies[i] = {b, a};
    }
    // ordenamos
    sort(movies.begin(), movies.end());

    long limit = 0;
    long cantPeliculas = 0;

    for (pair<long, long> movie: movies) {
        if (movie.second >= limit) {
            limit = movie.first;
            cantPeliculas++; 
        }
    }

    cout << cantPeliculas << "\n";
    return 0;
}
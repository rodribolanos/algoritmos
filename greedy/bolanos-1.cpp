#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long, long>> tables;


long mejorEntre(long index1, long index2) {
    if (tables[index1].second > tables[index2].second) {
        return index1;
    } else {
        return index2;
    }
}

int main() {
    long n;
    long long a, b, c;

    cin >> n;

    tables.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        tables[i] = {a, b};
    }
    // ordeno por fecha de comienzo
    sort(tables.begin(), tables.end());
    // index actual
    int i = 0;
    int def = 0;

    while (i < tables.size()) {
        long endACubrir = tables[i].second;
        
        long mejorCobertor = i;
        
        while ( i < tables.size() && endACubrir >= tables[i].first) {
            // mientras el second tables[i] empiece antes de que finalice lo que
            // tengo que cubrir
            mejorCobertor = mejorEntre(mejorCobertor, i);
            i++;

            //actualizo quien es el mejor segun quien es el que llega mas lejos.
        }
        // aca tengo que descartar todos los que empiezan despues que el ultimo que 
        // descubri, pero su comienzo esta en ese intervalo
        while (i < tables.size() && tables[mejorCobertor].second >= tables[i].first) {
            i++;
        }
        def++;
    }

    cout << def << "\n";
    return 0;
}
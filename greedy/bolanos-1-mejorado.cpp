#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long, long>> tables;


auto mejorEntre(auto index1, auto index2) {
    if (index1->second > index2->second) {
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
    auto it = tables.begin();
    int def = 0;

    while (it != tables.end()) {
        long endACubrir = it->second;
        
        auto mejorCobertor = it;
        
        while (it != tables.end() && endACubrir >= it->first) {
            // mientras el second tables[i] empiece antes de que finalice lo que
            // tengo que cubrir
            mejorCobertor = mejorEntre(mejorCobertor, it);
            it++;

            //actualizo quien es el mejor segun quien es el que llega mas lejos.
        }
        // aca tengo que descartar todos los que empiezan despues que el ultimo que 
        // descubri, pero su comienzo esta en ese intervalo
        pair<long, long> p = {mejorCobertor->second, 0L};
        it = upper_bound(it, tables.end(), p);
        def++;
    }

    cout << def << "\n";
    return 0;
}
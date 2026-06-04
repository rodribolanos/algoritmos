#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

/*
ALGORITMO DE ORDENAMIENTO TOPOLOGICO RESPETANDO ORDEN DE INPUT

*/
// representa los valores para cada bebida. Los values van siempre de 1 a n, siendo n la longitud de keys
map<string, long> indexs;

// G representa las relaciones para cada indice de cada bebida
vector<vector<long>> G;
vector<long> in_degre;

vector<string> drinks;
vector<long> toposort;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long k;
    long caseNumber = 0;
    while (cin >> k) {
        caseNumber++;
        indexs.clear();
        //resizes
        G.assign(k + 1, vector<long>());
        drinks.resize(k + 1);
        in_degre.assign(k + 1, 0);
        toposort.clear();


        // tomamos inputs
        for (int i = 1; i <= k; i++) {
            string drink; cin >> drink;
            // map para drink a number
            indexs.insert({drink, i});

            //vector para number a drink
            drinks[i] = drink;
        }

        long relations; cin >> relations;
        // relaciones
        for (int r = 0; r < relations; r++) {
            string d1, d2; cin >> d1 >> d2;
            // pusheo la relacion en el orden dirigido, dsp lo recorro al reves
            G[indexs[d1]].push_back(indexs[d2]);
            // a indexs de d2, le sumo 1, porque le llega una nueva flecha
            in_degre[indexs[d2]]++;
        }

        priority_queue<long, vector<long>, greater<long>> pq;

        // Se ponene en una cola todos los nodos que no tengan dependencias.
        for (long i = 1; i <= k; i++) {
            if (in_degre[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            long u = pq.top();
            pq.pop();
            
            toposort.push_back(u);

            // Recorremos los vecinos de la bebida que acabamos de tomar
            for (long nb : G[u]) {
                in_degre[nb]--; // resto 1 a las dependencias del vecino, porque estoy procesando el que lo apuntaba
                if (in_degre[nb] == 0) {
                    pq.push(nb); // Si ya esta libre, a la cola
                }
            }
        }

        cout << "Case #" << caseNumber << ": Dilbert should drink beverages in this order:";
        for (size_t t = 0; t < toposort.size(); t++) {
            cout << " " << drinks[toposort[t]]; 
        }

        cout << "." << "\n" << "\n";
    }

    return 0;
}
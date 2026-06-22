#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long> machineTimes;

const long INF = 1e10;

bool canEnter(long t, long k) {
    // pregunta si se pueden generar k elementos en t tiempo.
    long generatedItems = 0;
    for (int i = 0; i < machineTimes.size(); i++) {
        generatedItems += t / machineTimes[i]; // el tiempo dividido lo que tarda cada maquina es la cantidad de elementos generados 
    }

    // si los elementos generados son mas o iguales de los que necesito, true!
    return generatedItems >= k;
}
int main() {
    long kTimes, kElems;
    cin >> kTimes >> kElems;
    // inf para manejar minimos 
    long best = INF;

    machineTimes.assign(kTimes, -1);
    // tomo los tiempos d cada maquina
    for (int i = 0; i < kTimes; i++) {
        long time; 
        cin >> time;
        best = min(best, time);
        machineTimes[i] = time;
    }
    long l = 0; // el tiempo mas chico posible es 0
    long r = (best * kElems); // supongo que el peor tiempo de todos es poner la mejor maquina a hacer todos, sin tener concurrencia

    // busqueda [L; R], si 
    while (l < r) {
        long mid = (l + r) / 2;
        if (canEnter(mid, kElems)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << "\n";
    return 0;

}
#include <iostream>
#include <vector>

using namespace std;

vector<long long> pesos;
long long sum = 0;

const long long NEG_INF = -1e18;

/*
B1 + B2 = TOTAL
B1 = TOTAL - B2
lo maximo que puede ocupar b2, es total / 2, por invariante b1 >= b2
DIFERENCIA = B1 - B2 = (TOTAL - B2) - B2 = TOTAL - 2B2
*/ 

// el maximo peso que puede ocupar la bolsa b2 con un limite de peso l, usando los pesos desde pindex a pn
long long bolsa(size_t index, long long l) {
    if (l == 0) return 0;
    
    if (l < 0) return NEG_INF;

    if (index == pesos.size()) return 0;

    return max(
        pesos[index] + bolsa(index + 1, l - pesos[index]), // ponemos la manzana en la bolsa
        bolsa(index + 1, l) // no ponemos la manzana en la bolsa
    );
}

int main() {
    int n; cin >> n;

    pesos.resize(n);
    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        pesos[i] = pi;
        sum += pi; 
    }

    long long b2 = bolsa(0, sum / 2);

    cout << (sum - b2) - b2;
    return 0;
}
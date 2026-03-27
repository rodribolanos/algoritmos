#include <iostream>
#include <vector> 

using namespace std;

// URL: https://onlinejudge.org/external/12/1241.pdf

int walkovers() {
    int n;
    int m;
    
    cin >> n >> m;
    
    int players = 1 << n; //desplaza n bits a la izq, ej n = 3, 0001 -> 1000

    vector<bool> presentes(players, true);

    for (int i = 0; i < m; i++) {
        int player;
        cin >> player;
        presentes[player - 1] = false; // -1 para tomar indice 0.
    }
    
    int wo = 0;

    while (players > 1) {
        vector<bool> qualifiers;

        for (int player = 0; player < players; player += 2) {
            bool player1 = presentes[player];
            bool player2 = presentes[player + 1];

            if (player1 ^ player2) wo++;

            qualifiers.push_back(player1 || player2);
        }

        presentes = qualifiers;
        players /= 2;
    }

    return wo;
}

int main() {
    int t;

    // t = k test cases
    cin >> t;

    vector<int> wos(t);

    for (int i = 0; i < t; i++) {
        wos[i] = walkovers();
    }
    
    for (int ts = 0; ts < t; ts ++) {
        cout << wos[ts] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long>> G;
// vector de marcas para indicar con que color pintar
vector<long> levels;
vector<long> parents;


vector<long> dfs(long v, long level, long parent) {
    if ((levels[v] != -1) && (levels[v] % 2) == (level % 2)) return {}; // si el color de v ya es igual a lo que le queria poner, vamos bien!

    if (levels[v] != -1 && (levels[v] % 2) != (level % 2)) {
        vector<long> currentList;
        vector<long> newbieList;
        long newbieLevel = levels[parent];
        long newbie = parent;

        long current = parents[v]; 
        long currentLevel = levels[current]; // como v ya esta pintado, yo conozco el livel
        
        while (newbie != current) {
            while (newbieLevel != currentLevel) {
                if (newbieLevel > currentLevel) {
                    // si newbie tiene un nivel mayor, tengo que recorrer por current
                    newbieList.push_back(newbie);
                    newbie = parents[newbie];
                    newbieLevel = levels[newbie];
                } else {
                    // si current tiene nivel mayor tengo que recorrer current hasta achicarlo
                    currentList.push_back(current);
                    current = parents[current]; 
                    currentLevel = levels[current];
                }
            }

            // en este punto estamos al mismo nivel newbie y current. pusheo ambos a sus listas
            newbieList.push_back(newbie);
            currentList.push_back(current);
            // actualizo quien es quien
            newbie = parents[newbie];
            current = parents[current]; 
            // actualizo niveles
            newbieLevel = levels[newbie];
            currentLevel = levels[current];
        }
        currentList.push_back(current); // en este momento current y newbie son ambos el nodo de interseccion
        // reverse de la lista de current, fue el orden principal de recorrido. concatenado con la lista de newbie
        reverse(currentList.begin(), currentList.end());

        currentList.insert(currentList.end(), newbieList.begin(), newbieList.end());
        return currentList;
        
    }

    parents[v] = parent;
    levels[v] = level;

    for (long nb : G[v]) {
        // lo llamo con quien es su padre
        vector<long> cicleNb = dfs(nb, level + 1, v);
        if (cicleNb.size() > 0) {
            return cicleNb;
        } 
    }

    return {};
}


int main() {
    long n, m;

    cin >> n >> m;

    G.assign(n + 1, vector<long>()); // n + 1 para usar indice 1 
    levels.assign(n + 1, -1); // ninguno visitado
    parents.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<long> cicle;
    bool isCicle = false;
    for (int v = 1; v < n; v++) {
        // solo llamo si estoy iniciando una nueva cc
        if (levels[v] == -1) {
            cicle = dfs(v, 0, v);
        }

        if (cicle.size() > 0) {
            isCicle = true;
            break;
        }
    }

    if (isCicle) {
        cout << "NO " << cicle.size() << "\n";
        for (int c = 0; c < cicle.size(); c++) {
            cout << cicle[c] << " ";
        } 
    } else { 
        cout << "SI" << "\n";
        for (int b = 1; b < levels.size(); b++) {
            cout << levels[b] % 2 + 1 << " ";
        }
    }
}
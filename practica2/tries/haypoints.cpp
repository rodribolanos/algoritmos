#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Trie {

    struct Node {
        int value = 0;
        unordered_map<char, size_t> children;   // char -> node index
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    bool lookUpIterative(const string& s) {
        size_t curr = 0;
        for (char c : s) {
            auto it = tree[curr].children.find(c);
            if (it == tree[curr].children.end()) return 0;
            curr = it->second;
        }
        return tree[curr].value;
    }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, int valor, size_t i = 0, size_t n = 0) {
        if(i == s.size()) {
        // si es el final de la palabra marco + 1 en elem. es el proporcional a marcar true en un isWord si fuese un set
            tree[n].value = valor;
        } else {
        // si no es el final, debo seguir insertando
        // .insert() devuelve el par iterador (el obj char, size_t) y le pido despues el second para acceder a su posicion
        // y bool inserted. si inserted es true, es que la letra no estaba
            auto [it, inserted] = tree[n].children.insert({s[i], tree.size()});

            if(inserted)
                tree.push_back(Node());
            insert(s, valor, i+1, it->second);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    // m es la cantidad de palabras al diccionario
    // n es la cantidad de jobs descriptions
    cin >> m >> n;

    Trie dictionary;
    while (m--) {
        string word; int value; 
        cin >> word >> value;
        dictionary.insert(word, value);
    }

    while (n--) {
        int sum = 0;
        string w;
        while (cin >> w && w != ".") {
            sum = sum + dictionary.lookUpIterative(w);
        }

        cout << sum << "\n";
    }
    return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Trie {

    struct Node {
        bool isEnd = false;       // cantidad de veces que fue insertado (es un multiset)
        unordered_map<char, size_t> children;   // char -> node index
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    bool lookUp(const string& s, size_t i = 0, size_t n = 0) {
        if (i == s.size()) {
            // si llegue al final de la palabra que buscaba, tengo que fijarme si es una palabra final en el trie
            return tree[n].isEnd;    
        } else {
            // busco la letra "siguiente". caso base porque el vector
            auto it = tree[n].children.find(s[i]);
            if (it == tree[n].children.end()) {
                return false;
            }

            return lookUp(s, i + 1, it->second);
        }
    }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, size_t i = 0, size_t n = 0) {
        if(i == s.size()) {
        // si es el final de la palabra marco + 1 en elem. es el proporcional a marcar true en un isWord si fuese un set
            tree[n].isEnd = true;
        } else {
        // si no es el final, debo seguir insertando
        // .insert() devuelve el par iterador (el obj char, size_t) y le pido despues el second para acceder a su posicion
        // y bool inserted. si inserted es true, es que la letra no estaba
            auto [it, inserted] = tree[n].children.insert({s[i], tree.size()});

            if(inserted)
                tree.push_back(Node());
            insert(s, i+1, it->second);
        }
    }
};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        string palabra; cin >> palabra;
        int nFormadoras; cin >> nFormadoras;
        Trie palabrasTrie;
        vector<string> palabrasList;
        

        for(int i = 0; i < nFormadoras; i++) {
            string form; cin >> form;
            palabrasTrie.insert(form);
            palabrasList.push_back(form);
        }
        
        sort(palabrasList.begin(), palabrasList.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        int hits = 0;
        bool fail = false;
        for (int i = 0; i < palabra.size(); i++) {
            bool found = false;

            for (string &pal : palabrasList) {
                if (i + pal.size() <= palabra.size() &&
                palabra.substr(i, pal.size()) == pal) {

                hits++;
                i += pal.size() - 1;
                found = true;
                break;
            }
            }

            if (!found) {
                fail = true;
                break;
            }
        }

        cout << "Set " << t + 1 << ": ";
        if (fail) {
            cout << "Not possible.";
        } else {
            cout << hits << ".";
        }

        if (t + 1 != testCases) cout << "\n";
    }
}
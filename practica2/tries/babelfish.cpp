#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;
struct Trie {

    struct Node {
        string translate = "eh";
        unordered_map<char, size_t> children;   // char -> node index
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    string lookUp(const string& s, size_t i = 0, size_t n = 0) {
        if (i == s.size()) {
            // si llegue al final de la palabra que buscaba, tengo que fijarme si es una palabra final en el trie
            return tree[n].translate;    
        } else {
            // busco la letra "siguiente". caso base porque el vector
            auto it = tree[n].children.find(s[i]);
            if (it == tree[n].children.end()) {
                return "eh";
            }

            return lookUp(s, i + 1, it->second);
        }
    }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, string meaning, size_t i = 0, size_t n = 0) {
        if(i == s.size()) {
            tree[n].translate = meaning;
        } else {
        // si no es el final, debo seguir insertando
        // .insert() devuelve el par iterador (el obj char, size_t) y le pido despues el second para acceder a su posicion
        // y bool inserted. si inserted es true, es que la letra no estaba
            auto [it, inserted] = tree[n].children.insert({s[i], tree.size()});

            if(inserted)
                tree.push_back(Node());
            insert(s, meaning, i+1, it->second);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Trie dict;
    string line;
    while (getline(cin, line) && !line.empty()) {
        string english, foreign;
        stringstream ss(line);
        ss >> english >> foreign;
        dict.insert(foreign, english);
    }
    
    string messageWord;
    while (cin >> messageWord) {   
        cout << dict.lookUp(messageWord) << "\n";
    }

    return 0;
} 
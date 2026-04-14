#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;
struct Trie {

    struct Node {
        int count = 0;
        unordered_map<char, size_t> children;   // char -> node index
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, size_t i = 0, size_t n = 0) {
        if (n != 0) {
            tree[n].count++; 
        }
        if(i == s.size()) {
            return;
        } else {
            auto [it, inserted] = tree[n].children.insert({s[i], tree.size()});

            if(inserted)
                tree.push_back(Node());
            insert(s, i+1, it->second);
        }
    }

    long long countLetters(size_t n = 0, int depth = 0) {
        // Si este nodo solo le pertenece a UNA palabra, 
        // la longitud del prefijo único es la profundidad actual.
        if (tree[n].count == 1) {
            return depth;
        }

        long long total = 0;
        for (auto const& [character, childIndex] : tree[n].children) {
            total += countLetters(childIndex, depth + 1);
        }  
        return total;
    }
};

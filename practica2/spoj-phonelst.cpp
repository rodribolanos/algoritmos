/**
 * Author: Francisco Soulignac
 * Time in SPOJ: 320ms
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define SUBMIT

#ifndef SUBMIT
#include <cassert>
#endif

using namespace std;

struct Trie {

    struct Node {
        int elem = 0;       // cantidad de veces que fue insertado (es un multiset)
        unordered_map<char, size_t> children;   // char -> node index
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, size_t i = 0, size_t n = 0) {
        if(i == s.size()) {
        // si es el final de la palabra marco + 1 en elem. es el proporcional a marcar true en un isWord si fuese un set
            tree[n].elem += 1;
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

    size_t t; cin >> t;
    while(t--) {
#ifndef SUBMIT
        vector<string> input;
        bool naive_res = true;
#endif
        size_t n; cin >> n;

        Trie list;
        for(auto i = 0ul; i < n; ++i) {
            string number; cin >> number;
            list.insert(number);
#ifndef SUBMIT
            for(auto x : input)
                naive_res = naive_res and x != number.substr(0, x.size()) and number != x.substr(0, number.size());
            input.push_back(number);
#endif
        }

        auto res = count_if(list.tree.begin(), list.tree.end(), [](const Trie::Node& n) {
            return n.elem > 1 or (n.elem == 1 and not n.children.empty());
        }) == 0;

        cout << (res ? "YES\n" : "NO\n");
#ifndef SUBMIT
        if(res != naive_res)
            cerr << "fail: " << t << " res: " << res << " naive res: " << naive_res << endl;
#endif
    }

    return 0;
}

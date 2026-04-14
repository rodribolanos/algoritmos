#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;
struct Trie {

    struct Node {
        int comparisons = 0;
        unordered_map<char, size_t> children;   // char -> node index
        
        Node() {}
        Node(int c) {
            comparisons = c;
        }
    
    };
    vector<Node> tree;

    Trie()
      : tree(1) //nodo raiz sin elementos
    { }

    // inserta el string s[i:n] en el tree desde el nodo apuntado por n
    void insert(const string& s, size_t i = 0, size_t n = 0) {
        if(i == s.size()) {
            // la ultima letra no va a sufrir mas nada
            return;
        } else {
            int childAmmount = tree[n].children.size();
            auto [it, inserted] = tree[n].children.insert({s[i], tree.size()});

            if(inserted) {
                // Si no estaba, creo un nodo que se comparo con todos los de su misma altura.
                tree.push_back(Node(childAmmount));
            } else {
                // si estaba, tengo que actualizar que esa letra fue comparada con todos los de su altura
                tree[it->second].comparisons += childAmmount;
            }
            insert(s, i+1, it->second);
        }
    }

    int totalComparisons() {
        int sum = 0;
        // La raíz (tree[0]) no cuenta porque no representa un carácter comparado.
        for (size_t i = 1; i < tree.size(); ++i) {
            sum += tree[i].comparisons;
        }
        return sum;
}
};


/*
IDEA: Ir almacenando cada string ingresado, cada vez se ingresa uno nuevo, se compara con los que estan previamente.
El "comparar" implica sumar 1 comparacion a todos los existentes antes de insertar. En caso de que ya haya existido la letra, tambien
se agrega la comparacion, pero se sigue la rama
Ej:
Si tenia a-b, con ambos en 0
Ingreso c-a, ahora a tiene 1 comparacion, porque seria hijo de root
Ingreso c-b, a tiene 2 comparaciones, c tendria 1, y a (perteneciente a c-a) tendria otra, porque siguio la rama.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int cases = 0;
    while (cin >> n && n != 0) {
        cases++;
        Trie dict;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            dict.insert(s);
        }

        int sum = dict.totalComparisons();
        cout << "Case " << cases << ": " << sum << "\n";
    }

    return 0;
}

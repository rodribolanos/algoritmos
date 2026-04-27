#include <iostream>
#include<vector>

using namespace std;


int FREE = -1;
int n;

int countTable(int k, vector<vector<int>> ct, pair<int, int> position) {
    if (k == 0) return 1; //si nos quedamos sin piezas, es un caso valido para colocarlas.
    int column = position.first;
    int row = position.second;
    if (column == n && row == n) return (ct[column][row] == FREE && (k-1) == 0) ? 1 : 0; // si estamos en la ultima posicion para poner, solo es caso valido si 

    int countWithoutUsingPosition = countTable(k, ct, position<)
    return countTable(k,  )

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int k;

    while (cin >> n) {
        cin >> k;
        vector<vector<int>> chessTable(n, vector<int>(n, FREE) ); 
        cout << countTable(k, chessTable, {0, 0}) << "\n";
    }
}
#include <iostream>
#include <vector>

using namespace std;

/*
IDEA:
Reordenar los indices del [l;r), siendo l y r indices.
*/

vector<long> reorder(long start, long end) {

    if ((end - start) == 1) return {start};

    long mid = (start + end) / 2;

    vector<long> orderLeft = reorder(start, mid);
    vector<long> orderRight = reorder(mid, end);

    // como es cerrado-abierto, puedo llamar con mid a los dos
    vector<long> result;
    int i = 0;
    int j = 0;
    while (i < orderLeft.size() && j < orderRight.size()) {
        cout << "? " << orderLeft[i] << " " << orderRight[j] << "\n";
        string ans; cin >> ans;

        if (ans == "YES") {
            result.push_back(orderLeft[i]);
            i++;
        } else {
            result.push_back(orderRight[j]);
            j++;
        }
    }
    
    // si sali del bucle, puede ser porque i == oL.size o j == oR.size, en cada caso hay que agregar el restante
    // bucle para meter todos los que faltaron de left
    while (i < orderLeft.size()) {
        result.push_back(orderLeft[i]);
        i++;
    }
    // bucle para meter todos los que faltaron de right
    while (j < orderRight.size()) {
        result.push_back(orderRight[j]);
        j++;
    }

    return result;
}

int main() {
    long n; cin >> n;
    
    vector<long> nums(n);

    for (int i = 0; i < n; i ++) {
        nums[i] = i + 1;
    }

    vector<long> result = reorder(1, n + 1);
    vector<long> hiddenPermutation(n);
    int i = 1;
    for (long num : result) {
        // los numeros estan en base 1 
        hiddenPermutation[num - 1] = i;
        i++; 
    }

    cout << "! "; 
    for (long hid: hiddenPermutation) {
        cout << hid << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
using namespace std; 

// URL: https://onlinejudge.org/external/100/10038.pdf

const int MAX_SIZE = 3000;
string jollyjumper(const vector<int>& sequence) {
    int length = (int) sequence.size();
    if (length == 1) return "Jolly Jumper";

  vector<bool> seenDifferences(length, false);
  
  for (int i = 0; i < length - 1; i++) {
    int actualDifference = abs(sequence[i] - sequence[i + 1]);
    if (actualDifference >= 1 && actualDifference < length) {
      // si la diferencia es mayor al tamanio maximo no cumple con todos n a n-1, cuando el max size de n es limitado.
      seenDifferences[actualDifference] = true;
    }
  }

  for (int dif = 1; dif < length; dif++) {
    // comenzar de 1 para que 
    if (!seenDifferences[dif]) {
      return "Not Jolly Jumper";
    }
  }

  return "Jolly Jumper";
}

int main() {
    string line;
    cout << "Ingrese su secuencia (ej: 4 1 4 2 3) y presione Enter:" << endl;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        int num;
        vector<int> nums;

        while (ss >> num) {
            nums.push_back(num);
        }

        if (!nums.empty()) {
            cout << "Resultado: " << jollyjumper(nums) << endl;
        }
    }
    
    return 0;
}
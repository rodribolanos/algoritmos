#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

const int MAX_SIZE = 3000;
string jollyjumper(int length, int sequence[]) {
  if (length == 1) return "Jolly Jumper";

  bool isJolly = true;
  bool seenDifferences[MAX_SIZE] = {false};
  
  for (int i = 0; i < length - 1; i++) {
    int actualDifference = abs(sequence[i] - sequence[i + 1]);
    if (actualDifference >= 1 && actualDifference < length && actualDifference < MAX_SIZE) {
      // si la diferencia es mayor al tamanio maximo no cumple con todos n a n-1, cuando el max size de n es limitado.
      seenDifferences[actualDifference] = true;
    }
  }

  for (int dif = 1; dif < length; dif++) {
    // comenzar de 1 para que 
    if (!seenDifferences[dif]) {
      isJolly = false;
      break;
    }
  }

  return (isJolly) ? "Jolly Jumper" : "Not Jolly Jumper";
}

int main() {
    int length;

    cout << "PASO 1: Ingrese el largo: " << endl; 
    if (!(cin >> length)) return 0;

    int* nums = new int[length];
    
    cout << "PASO 2: Ingrese los " << length << " numeros: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> nums[i];
    }
    
    cout << "RESULTADO: " << jollyjumper(length, nums) << endl;
    
    delete[] nums;
    return 0;
}
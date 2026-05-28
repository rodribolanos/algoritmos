#include <iostream>

using namespace std;


void search(long start, long end, string startColor) {
    if ((end - start) == 1) {
        cout << "! " << start;
        return;
    }

    long mid = (start + end) / 2;
    cout << "? " << mid << "\n";
    string midAnswer; cin >> midAnswer;
    
    // pasamos como parametro el color que conocemos. en caso del start seguir siendo el mismo, pasamos ese
    // en caso de mid ser el nuevo start, pasamos el color de mid
    if (midAnswer == startColor) {
        if (((mid - start) % 2) != 0) {
            search(start, mid, startColor);
        } else {
            search(mid, end, midAnswer);
        }
    } else {
        if (((mid - start) % 2) != 0) {
            search(mid, end, midAnswer);
        } else {
            search(start, mid, startColor);
        }
    }
        
    return;
}

int main() {
    long n; cin >> n;

    cout << "? " << 1 << "\n";

    string sc; cin >> sc;
    search(1, n + 1, sc);
    return 0;
}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// URL: https://onlinejudge.org/external/119/11995.pdf
// Costo: O(n log n ). Por cada operacion, tengo que realizar operaciones constantes y log n para el caso de pop de las estructuras

// duda: O(n log n / 2)? Por codigo se que pop se ejecuta como maximo la misma cantidad de veces que push, por lo que no todos los n sufren log n 
int main() {
    bool isStack = true;
    bool isQueue = true;
    bool isPriorityQueue = true;
    int kOperations;
    cin >> kOperations;

    queue<int> q;
    stack<int> s;
    priority_queue<int> max_pq;


    for (int i = 0; i < kOperations; i++) {
        int operation;
        int value; 

        cin >> operation >> value;

        if (operation == 1) { 
            // O(1) 
            q.push(value); s.push(value);max_pq.push(value);
        } else {

            if (!q.empty()) { // O(1), puedo ver cualquiera de las 3 porque se inserta de forma paralela
                // top y front son O(1), pop es O(log n)
                isQueue = value == q.front() && isQueue;
                isStack = value == s.top() && isStack;
                isPriorityQueue = value == max_pq.top() && isPriorityQueue;

                q.pop(); s.pop(); max_pq.pop();
            }
        }
    }
    int possibles = (isStack ? 1 : 0) + (isQueue ? 1 : 0) + (isPriorityQueue ? 1 : 0);
    
    if (possibles == 0) {
        cout << "imposibble";
    } else if (possibles > 1) {
        cout << "not sure";
    } else if (isStack) {
        cout << "is stack";
    } else if (isQueue) {
        cout << "is queue";
    } else {
        cout << "is priority queue";
    }

    return 0;
}
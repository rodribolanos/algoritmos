#include <iostream>
#include <vector> 

using namespace std;

vector<int> make_fail(const string& p)
{
    vector<int> fail(p.size()+1, -1);
    for(int i = 0; i < p.size(); ++i) {
        fail[i+1] = fail[i] + 1;
        while(fail[i+1] > 0 and p[i] != p[fail[i+1]-1]) {
            fail[i+1] = fail[fail[i+1] - 1] + 1;
        }
    }
    return fail;
}

/*
IDEA: Buscar con KMP cual es el sufijo que tambien es prefijo. 
La falla del ultimo caracter nos dice la cantidad de caracteres que son sufijo, es decir, que se empiezan a repetir
Restarle la longitud, nos da exactamente el periodo que se repite

Si a esa longitud la dividimos por el periodo, el resto nos va a decir cuantos "de mas" hay
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string palabra; cin >> palabra;

        vector<int> fail = make_fail(palabra);
        int size = palabra.size();
        // no se busca -1 porque fail[0] es invalido.
        int periodo = size - fail[size];

        int exceso = size % periodo;
        
        for (int i = 0; i < 8; i++) {
            cout << palabra[exceso];
            exceso = (exceso + 1) % periodo; 
        }

        cout << "...\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int t, n; cin >> t >> n;
    while(t--){
        int sum = 0; // Suma de todos los elementos
        int x, mayor = 0; // Elemento actual, Elemento mayor
        for(int i=0; i<n; i++){
            cin >> x;
            sum += x; // Sumamos a "sum"
            mayor = max(mayor, x); // Revisamos quien es mayor
        }
        // Si la suma de todo menos "mayor", es igual a "mayor", cumple
        if(mayor == (sum - mayor)) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
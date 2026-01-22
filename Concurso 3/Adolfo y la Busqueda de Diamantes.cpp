#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int n; cin >> n;
    vector<int> bloques(n); // Guardar los tipos de bloques
    for(int i=0; i<n; i++){
        cin >> bloques[i];
    }

    int k; cin >> k; // Bloque que buscamos
    vector<int> res; // Para guardar las posiciones de los bloques
    for(int i=0; i<n; i++){
        // Si es el bloque que buscamos, guardamos su posicion
        if(bloques[i] == k) res.push_back(i);
    }
    
    cout << res.size() << '\n';
    for(auto x : res){
        cout << x << " ";
    }

    return 0;
}
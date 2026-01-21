#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int n; cin >> n;
    vector<pair<int, int>> clases(n); // Vector de pares <inicio, fin>
    for(int i=0; i<n; i++){
        cin >> clases[i].first >> clases[i].second;
    }
    sort(clases.begin(), clases.end()); // Ordenamos los pares (se ordenan conforme su .first <inicio>)

    vector<bool> solapados(n, false); // Vector de banderas
    
    int last_end = clases[0].second; // Ultimo extremo
    int last_idx = 0; // Ultimo indice

    // Iniciamos desde el segundo horario
    for(int i=1; i<n; i++){
        // Si la clase "i" comienza antes de que termine la actual
        if(clases[i].first <= last_end){
            solapados[i] = true; // Marcamos como "solapado"
            solapados[last_idx] = true; // Marcamos como "solapado"
            
            // Si la clase "i" termina despues de que termine la actual
            if(clases[i].second > last_end){
                last_end = clases[i].second; // Guardamos como el nuevo ultimo extremo
                last_idx = i; // Guardamos como el nuevo ultimo indice
            }
        // Si la clase "i" NO comienza antes de que termine la actual
        }else{
            last_end = clases[i].second; // Guardamos como el nuevo ultimo extremo
            last_idx = i; // Guardamos como el nuevo ultimo indice
        }
    }

    int res = 0; // Resultado
    for(bool x : solapados){
        if(x) res++; // Si se marco como "solapado", sumamos +1
    }
    cout << res << '\n';
    
    return 0;
}
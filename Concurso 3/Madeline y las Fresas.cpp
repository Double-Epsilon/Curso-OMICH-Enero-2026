#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n; cin >> n;
    vector<bool> mochila(n, false); // Vector de "n" posiciones iniciadas en "false"
    string acc; // Accion
    int x, faltan = n; // Numero de Fresa, Cantidad que faltan
    while(cin >> acc){
        // Accion "Fresa"
        if(acc == "Fresa"){
            cin >> x; // Numero de Fresa
            mochila[x-1] = true; // Marcamos como "encontrada"
            faltan--; // Una menos
        // Accion "Mochila"
        }else if(acc == "Mochila"){
            // Si faltan todas, no hemos encontrado nada
            if(faltan == n) cout << "-\n";
            else{
                // Imprimir todas las fresas que llevamos
                for(int i=0; i<n; i++){
                    // Si ya encontramos la fresa "i", imprimimos
                    if(mochila[i] == true) cout << i+1 << " ";
                }
                cout << '\n';
            }
            
            // Si faltan 0, ya encontramos todas
            if(faltan == 0) cout << "-\n";
            else{
                // Imprimir todas las fresas que faltan
                for(int i=0; i<n; i++){
                    // Si ya no hemos encontrado la fresa "i", imprimimos
                    if(mochila[i] == false) cout << i+1 << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}
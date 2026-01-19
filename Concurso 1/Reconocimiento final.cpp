#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n, m; cin >> n >> m;
    int mat[n][m]; // Matriz n*m
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    
    char atq; // Tipo de ataque
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> atq;
            
            // Si es ataque directo, hacemos 5 de daño al objetivo unico
            if(atq == 'X') mat[i][j] -= 5;
            // Si es ataque en area, hacemos 10 de daño a cada objetivo adyacente
            else if(atq == 'O'){
                mat[i][j] -= 10;
                // Antes de hacer daño, hay que revisar si no exceden los limites de la matriz
                if(i-1 >= 0) mat[i-1][j] -= 10;
                if(i+1 < n) mat[i+1][j] -= 10;
                if(j-1 >= 0) mat[i][j-1] -= 10;
                if(j+1 < m) mat[i][j+1] -= 10;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] > 0) cout << "A "; // Sobrevivio
            else cout << "D "; // Murio
        }
        cout << '\n';
    }

    return 0;
}
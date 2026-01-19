#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> mural(n, vector<int>(m, 0)); // Matriz n*m, todo iniciado en 0
    
    char dir; // Direccion
    int f, c, len; // Fila, Columna, Longitud
    for(int a=1; a<=q; a++){
        cin >> dir >> f >> c >> len;
        f--; c--; // Restamos 1 (para mantener 0-indexado)
        
        // Pintar horizontal
        if(dir == 'H'){
            // Iniciamos en c, mientras estemos en los limites y no excedamos la longitud
            for(int j=c; j<m && j<c+len; j++){
                mural[f][j] = a; // Pintar
            }
        // Pintar vertical
        }else if(dir == 'V'){
            // Iniciamos en f, mientras estemos en los limites y no excedamos la longitud
            for(int i=f; i<n && i<f+len; i++){
                mural[i][c] = a; // Pintar
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mural[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n; cin >> n;
    int mat[n][n]; // Matriz n*n
    // trSup = Triangular superior, trInf = Triangular inferior, id = Identidad, nul = Nula
    bool trSup = true, trInf = true, id = true, nul = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
            
            // Si i > j, estamos en el triangulo superior
            if(i > j && mat[i][j] != 0) trSup = false;
            
            // Si j > i, estamos en el triangulo inferior
            if(j > i && mat[i][j] != 0) trInf = false;
            
            // Si i == j, estamos en la diagonal principal
            if(i == j && mat[i][j] != 1) id = false;
            if(i != j && mat[i][j] != 0) id = false;
            
            if(mat[i][j] != 0) nul = false;
        }
    }
    
    if(nul) cout << "Nula";
    else if(id) cout << "Identidad Wuu";
    // Protip: si tiene triangulo inferior y superior, es diagonal
    else if(trInf && trSup) cout << "Diagonal";
    else if(trInf) cout << "Triangular inferior";
    else if(trSup) cout << "Triangular superior";

    return 0;
}
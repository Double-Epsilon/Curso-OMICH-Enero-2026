#include <bits/stdc++.h>
using namespace std;

int dx4[4] = {-1, 1, 0, 0}; // 4 direcciones adyacentes eje x
int dy4[4] = {0, 0, -1, 1}; // 4 direcciones adyacentes eje y

int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 8 direcciones adyacentes eje x
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 8 direcciones adyacentes eje y

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimzacion entrada/salida

    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m)); // Matriz n*m

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    int x; cin >> x; // Cantidad de dias

    while(x--){
        auto next = mat; // Creamos copia de la matriz original
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char cell = mat[i][j]; // Celda actual
                
                // Cultivo
                if(cell == 'c'){
                    // Recorremos las 4 direcciones adyacentes
                    for(int d=0; d<4; d++){
                        int ni = i + dx4[d];
                        int nj = j + dy4[d];
                        // Revisar si entra en limites y hay agua ("W")
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 'W'){
                            next[i][j] = 'C'; // Cambiar a cultivo crecido
                            break; // Siguiente casilla
                        }
                    }
                }
                // Árbol (si ya es "9", ignorar)
                else if(cell == 'a' || (cell >= '1' && cell <= '8')){
                    bool puede_crecer = true; // Bandera
                    // Recorremos las 8 direcciones adyacentes
                    for(int d=0; d<8; d++){
                        int ni = i + dx8[d];
                        int nj = j + dy8[d];
                        // Revisar si entra en limites
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                            // Revisar si hay piedra ("R") o maleza ("M")
                            if(mat[ni][nj] == 'R' || mat[ni][nj] == 'M'){
                                puede_crecer = false; // Ya no puede crecer
                                break; // Dejar de revisar
                            }
                        }
                    }
                    if(puede_crecer){ // Si puede crecer
                        // Si es "a", cambiar a "1"
                        if(cell == 'a') next[i][j] = '1';
                        // Si es numero, aumentar en 1
                        else next[i][j] = cell + 1;
                    }
                }
                // Maleza
                else if(cell == 'M'){
                    // Recorremos las 4 direcciones adyacentes
                    for(int d=0; d<4; d++){
                        int ni = i + dx4[d];
                        int nj = j + dy4[d];
                        // Revisar si entra en limites y esta vacia (".")
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == '.'){
                            next[ni][nj] = 'M'; // Cambiar a maleza
                        }
                    }
                }
            }
        }
        mat = next; // Guardar cambios en matriz original
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
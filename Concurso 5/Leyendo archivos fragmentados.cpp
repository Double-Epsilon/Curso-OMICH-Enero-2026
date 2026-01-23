#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int Q, B; cin >> Q >> B; // Numero de Bloques, Tamaño del Bloque
    
    string disco; cin >> disco; // Cadena de caracteres

    int N; cin >> N; // Cantidad de archivos
    vector<vector<int>> archivos(N); // Guardar los indices de cada archivo
    int I, C; // Indice del Archivo, Cantidad de Bloques que ocupa
    for(int i=0; i<N; i++){
        cin >> I >> C;
        archivos[I].resize(C); // Resizear archivo "I" a tamaño de "C"
        for(int j=0; j<C; j++){
            cin >> archivos[I][j]; // Leer indices
        }
    }

    int M; cin >> M; // Cantidad de consultas
    int K; // Posicion del caracter
    while(M--){
        cin >> I >> K;
        
        int bloque = K / B; // Obtener numero de bloque
        int offset = K % B; // Obtener posicion del bloque
        
        int bloque_real = archivos[I][bloque]; // Sacar indice correspondiente
        char resultado = disco[bloque_real * B + offset]; // Obtener caracter
        
        cout << resultado << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    priority_queue<int> playlist; // Playlist de canciones

    int q; cin >> q; // Numero de acciones
    string acc; // Accion
    int x; // Cancion
    while(q--){
        cin >> acc;

        // "Agregar" cancion
        if(acc == "AGREGAR"){
            cin >> x;
            playlist.push(x); // Agregar cancion a la playlist

        // "Play" cancion
        }else if(acc == "PLAY"){
            // Imprimir primera cancion
            cout << playlist.top() << '\n';
            // Eliminar de la playlist
            playlist.pop();
        }
    }

    return 0;
}
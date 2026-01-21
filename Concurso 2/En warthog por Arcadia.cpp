#include <bits/stdc++.h>
using namespace std;

// Funcion para sacar modulo a la posicion (mantenerla en el circulo)
int idx(int i, int &k){
    return (i % k + k) % k;
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    float s, d; cin >> s >> d; // Salud, Daño
    int v, r; cin >> v >> r; // Velocidad, Rango

    int k; cin >> k; // Estructuras
    vector<pair<float, float>> estructuras(k); // Vida, Daño
    int estVivas = k; // Inicialmente hay "k" estructuras vivas
    for(int i=0; i<k; i++){
        cin >> estructuras[i].first;
    }
    for(int i=0; i<k; i++){
        cin >> estructuras[i].second;
    }

    int pos; cin >> pos; // Posicion actual
    // Mientras tengamos vida y falten estructuras
    while(s > 0 && estVivas > 0){
        // Desde "pos - r" hasta "pos + r" (abarcar ambos lados del rango)
        for(int i=pos-r; i<=pos+r; i++){
            // Si la estructura tiene vida
            if(estructuras[idx(i, k)].first > 0){
                estructuras[idx(i, k)].first -= d; // Restamos vida
                // Si murio en este turno, una estructura viva menos
                if(estructuras[idx(i, k)].first <= 0) estVivas--;
            }
            // Restamos nuestra vida
            s -= estructuras[idx(i, k)].second;
        }
        pos += v; // Avanzamos "v" posiciones
        pos %= k; // Nos mantenemos enn el circulo
    }

    // Primero revisar si morimos nosotros Y las estructuras
    if(s <= 0 && estVivas <= 0) cout << "Forge lo ha logrado, pero a que costo?";
    else if(s <= 0) cout << "El sargento Forge ha desaparecido en combate";
    else if(estVivas <= 0) cout << "El sargento Forge lo ha logrado!";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

// Struct "Pokemon"
struct Pokemon{
    string nom; // Nombre
    int a, d, ae, de, v; // Ataque, Defensa, AtqEspecial, DefEspecial, Velocidad
    
    // Funcion para leer datos
    void leer(){
        cin >> nom >> a >> d >> ae >> de >> v;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n; cin >> n;
    vector<Pokemon> p(n); // Vector de Structs "Pokemon"
    for(int i=0; i<n; i++){
        p[i].leer(); // Leer datos de cada Pokemon
    }
    
    string est; cin >> est; // Estadistica conforme vamos a ordenar
    // Ordenamos con funcion lambda
    sort(all(p), [&](Pokemon a, Pokemon b){
        if(est == "Ataque" && a.a != b.a) return a.a > b.a; // Por Ataque
        else if(est == "Defensa" && a.d != b.d) return a.d > b.d; // Por Defensa
        else if(est == "AtqEspecial" && a.ae != b.ae) return a.ae > b.ae; // Por AtqEspecial
        else if(est == "DefEspecial" && a.de != b.de) return a.de > b.de; // Por DefEspecial
        else if(est == "Velocidad" && a.v != b.v) return a.v > b.v; // Por Velocidad
        return a.nom < b.nom; // En caso de empate en la estadistica, ordenamos por nombre
    });
    
    for(auto x : p){
        cout << x.nom << '\n';
    }

    return 0;
}